/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2014 All right reserved.
 * 
 *  Confidential Information
 *
 *  All parts of the CogniVue Program Source are protected by copyright law
 *  and all rights are reserved.
 *  This documentation may not, in whole or in part, be copied, photocopied,
 *  reproduced, translated, or reduced to any electronic medium or machine
 *  readable form without prior consent, in writing, from CogniVue.
 ******************************************************************************/
/*!*********************************************************************************
*  \file apu_arithmetic.c
*  \brief APU basic arithmetic kernels.
***********************************************************************************/

#ifdef ACF_KERNEL_IMPLEMENTATION

#include "apu_arithmetic_impl.h"
#include <stdint.h>

/*! 
	Computes Square root of its input 
	\param a - [Input] Source value
	\return	   [Output] Square root of input value
*/
vec32u vsqrt_32(vec32u a)
{
	vec16u ah = (vec16u)(a >> 16);
	vec16u u = 0x4000, r = u + u;
	vec16u tmp;
	vec32u prod;
	vbool  c;
	vec32u res;
	vif(a > 1) {
		for (int i = 6; i >= 0; i--, u >>= 1){
			r = vasb(r, u, vmul_uhuh(r, r) <= ah);
		}

		for (int i = 7; i >= 0; i--, u >>= 1){
			prod = vec32u(vmul_uhuh(r, r), vmul_ulul(r, r));
			tmp = vmul_uhul(r, r);
			vacm(prod, tmp);
			vacm(prod, tmp);
			vsub(a, prod, c);
			r = vasb(r, u, ~c);/* prod <= a    ==     a >= prod, ergo a-prod does not carry. */
			/* r = vasb(r, u, prod <= a); */
		}

		prod = vec32u(vmul_uhuh(r, r), vmul_ulul(r, r));
		tmp = vmul_uhul(r, r);
		vacm(prod, tmp);
		vacm(prod, tmp);

		vsub(a, prod, c);
		res = (vec32u)vsubx(r, (vec16u)0, c);
	} velse{
		res = a;
	} vendif

	return res;
}

/*!
   Calculates the absolute value from one sources
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source value block pointer
   \param sstr  - [Input]  Source value block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_abs(    vec08u* dst, int dstr,
      const vec08s* src, int sstr,
                 int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = (vec08u)vabs(src[bx]);
      }
      src += sstr;
      dst += dstr;      
   }                    
}

/*!
   Calculates the absolute difference between two sources
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_absdiff(    vec08u* dst, int dstr,
         const vec08u* src1, int sstr1,
         const vec08u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = (vec08u)vabs_diffu(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }                    
}

/*!
   Calculates sum of two images
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 block pointer
   \param sstr1 - [Input]  Source 1 block stride
   \param src2  - [Input]  Source 2 block pointer
   \param sstr2 - [Input]  Source 2 block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
*/
void 
apu_accumulate(vec16s* dst,  int dstr,
               const vec08u* src1,  int sstr1,
               const vec08u* src2,  int sstr2,
               int bw, int bh) 
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
		  dst[bx] = (vec16s)src1[bx] + (vec16s)src2[bx];
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}

/*!
   Calculates squared sum of two images
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 block pointer
   \param sstr1 - [Input]  Source 1 block stride
   \param src2  - [Input]  Source 2 block pointer
   \param sstr2 - [Input]  Source 2 block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
   \param scale - [Input]  Image 2 Scale
*/
void 
apu_accumulate_squared(vec16s* dst,  int dstr,
               const vec08u* src1,  int sstr1,
               const vec08u* src2,  int sstr2,
                int bw, int bh, uint8_t scale) 
{
   vec16u s1i;
   vec16u s2i;
   vec16u tx;
   
   for ( int by = 0; by < bh; by++ ) chess_loop_range(1,) {
      for ( int bx = 0; bx < bw; ++bx ) chess_loop_range(1,) {
         s1i = (vec16u)src1[bx];
         s2i = (vec16u)src2[bx];
         tx = (vec16u)(s1i + ((s2i*s2i) >> scale));
		 
		 dst[bx] = (vec16s)vsat(tx, 0, 32767);
      }
   
      src1 += sstr1;
      src2 += sstr2;
      dst  += dstr;
   }                    
}

/*!
   Calculates weighted sum of two images
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 block pointer
   \param sstr1 - [Input]  Source 1 block stride
   \param src2  - [Input]  Source 2 block pointer
   \param sstr2 - [Input]  Source 2 block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
   \param alpha - [Input]  Weight between [0 and 256]
  
   ASSUMPTION: both sources are of same size. Weight is determined by alpha which ranges from [0-256].
               ie. ~70% weight is 179. Accuracy is lost if user of API wants exactly 70% but result is 
               accurate w.r.t alpha.
*/
void 
apu_accumulate_weighted(vec08u* dst,  int dstr,
                 const vec08u* src1,  int sstr1,
                 const vec08u* src2,  int sstr2,
                  int bw, int bh, uint8_t alpha) {
   
   // Normally: here would check source sizes and normalize if needed
   
   const vec08u* s1;
   const vec08u* s2;
   vec16u s1i;
   vec16u s2i;
   vec08u* d;

   s1 = (const vec08u*)src1;
   s2 = (const vec08u*)src2;
   d = (vec08u*)dst;
   
   for ( int by = 0; by < bh; by++ ) chess_loop_range(1,) {
   
      for ( int bx = 0; bx < bw; ++bx ) chess_loop_range(1,) {
         s1i = (vec16u)src1[bx] * (0x100 - alpha);
         s2i = (vec16u)src2[bx] * alpha;
         dst[bx] = (vec08u)((s1i + s2i) >> 8);
      }
   
      src1 += sstr1;
      src2 += sstr2;
      dst  += dstr;
   }
}

/*!
   Adds source 1 to source 2 (unsigned 8 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_add(        vec08u* dst, int dstr,
         const vec08u* src1, int sstr1,
         const vec08u* src2, int sstr2,
                     int bw, int bh) 
{
   vec08u d;
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
		  dst[bx] = (vec08u)vsat((vec16u)src1[bx] + (vec16u)src2[bx], vec16u(0), vec16u(255));
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }
}

/*!
   Adds source 1 to source 2 (signed 16 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_add(        vec16s* dst, int dstr,
         const vec16s* src1, int sstr1,
         const vec16s* src2, int sstr2,
                     int bw, int bh) 
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vadd_sat(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }
}

/*!
   Calculates the bitwise AND from two sources (unsigned 8 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_and(        vec08u* dst, int dstr,
         const vec08u* src1, int sstr1,
         const vec08u* src2, int sstr2,
                     int bw, int bh) 
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = (vec08u)vand(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }   
}                     
                     
/*!
   Calculates the bitwise AND from two sources (unsigned 16 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_and(        vec16u* dst, int dstr,
         const vec16u* src1, int sstr1,
         const vec16u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vand(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}                     

/*!
   Calculates the bitwise AND from two sources (unsigned 32 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_and(        vec32u* dst, int dstr,
         const vec32u* src1, int sstr1,
         const vec32u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vand(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}

/*!
   Counts leading zeros (signed 16 bit)

   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source value block pointer
   \param sstr  - [Input]  Source value block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void
apu_clz(       vec08u* dst, int dstr,
               const vec16s* src, int sstr,
               int bw, int bh)
{
    for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
        for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {
            dst[bx] = (vec08u)vclz(src[bx]);
        }
        src += sstr;
        dst += dstr;
    }
}

/*!
   Counts leading zeros (unsigned 16 bit)

   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source value block pointer
   \param sstr  - [Input]  Source value block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void
apu_clz(       vec08u* dst, int dstr,
               const vec16u* src, int sstr,
               int bw, int bh)
{
    for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
        for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {
            dst[bx] = (vec08u)vclz(src[bx]);
        }
        src += sstr;
        dst += dstr;
    }
}

/*!
   Counts leading zeros (signed 8 bit)

   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source value block pointer
   \param sstr  - [Input]  Source value block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
*/

void
apu_clz(       vec08u* dst, int dstr,
               const vec08s* src, int sstr,
               int bw, int bh)
{    
    vec08u* src_08u = (vec08u*) src;
    for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
        for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {
            dst[bx] = (vec08u)(vclz((vec16s)src_08u[bx]) - 8);
        }
        src_08u += sstr;
        dst += dstr;
    }
    
}
/*!
   Counts leading zeros (unsigned 8 bit)

   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source value block pointer
   \param sstr  - [Input]  Source value block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void
apu_clz(       vec08u* dst, int dstr,
               const vec08u* src, int sstr,
               int bw, int bh)
{
    for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
        for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {
            dst[bx] = (vec08u)(vclz((vec16u)src[bx]) - 8);
        }
        src += sstr;
        dst += dstr;
    }
}


/*!
   Calculates magnitude of image matrix
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param srcx  - [Input]  Source x values block pointer
   \param sstrx - [Input]  Source x values block stride
   \param srcy  - [Input]  Source y values block pointer
   \param sstry - [Input]  Source y values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_magnitude( vec16u* dst, int dstr,
        const vec16s* srcx, int sstrx,
        const vec16s* srcy, int sstry,
                    int bw, int bh) {
   const vec16s* sx;
   const vec16s* sy;
   
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      sx = (const vec16s*) srcx;
      sy = (const vec16s*) srcy;
      
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {         
         // Compute magnitude       
         vec32u ax = (vec32u)vabs(sx[bx]);
         vec32u ay = (vec32u)vabs(sy[bx]);
         
         vec32u sx2 = (vec32u)ax * (vec32u)ax;
         vec32u sy2 = (vec32u)ay * (vec32u)ay;
                  
         vec32u s2 = sx2 + sy2;
         
         dst[bx] = (vec16u)vsqrt_32(s2);
      }
      srcx += sstrx;
      srcy += sstry;
      dst  += dstr;      
   }
}

/*!
   Calculates the bitwise NOT of the source.
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source values block pointer
   \param sstr  - [Input]  Source values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_not(       vec08u* dst, int dstr,
         const vec08u* src, int sstr,
                    int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = (vec08u)vcomplement(src[bx]);
      }
      src += sstr;
      dst += dstr;      
   }  
}

/*!
   Calculates the bitwise OR from two sources (unsigned 8 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_or(       vec08u* dst,  int dstr,
        const vec08u* src1, int sstr1,
        const vec08u* src2, int sstr2,
                    int bw, int bh) 
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = (vec08u)vor(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }   
}                     
                     
/*!
   Calculates the bitwise OR from two sources (unsigned 16 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_or(        vec16u* dst,  int dstr,
         const vec16u* src1, int sstr1,
         const vec16u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vor(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}                     

/*!
   Calculates the bitwise OR from two sources (unsigned 32 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_or(        vec32u* dst, int dstr,
        const vec32u* src1, int sstr1,
        const vec32u* src2, int sstr2,
                    int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vor(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}

/*!
   Subtracts source 2 from source 1 (unsigned 8 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_sub(       vec16s* dst,  int dstr,
         const vec08u* src1, int sstr1,
         const vec08u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vsub((vec16s)src1[bx], (vec16s)src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}        

/*!
   Subtracts source 2 from source 1 (signed 16 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_sub(       vec16s* dst,  int dstr,
         const vec16s* src1, int sstr1,
         const vec16s* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vsub_sat(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}         

/*!
   Calculates an unsigned 8 bit boolean output image based on threshold (input unsigned 8 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source values block pointer
   \param sstr  - [Input]  Source values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
   \param thres - [Input]  Threshold value
 */
void 
apu_threshold( vec08u* dst, int dstr,
             const vec08u* src, int sstr,
                int bw, int bh, uint8_t threshold) 
{ 
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {                 
		  dst[bx] = (vec08u)vselect((vec08u)0xFF, (vec08u) 0, src[bx] > threshold);
      }
      src += sstr;
      dst += dstr;      
   }
}

/*!
   Calculates an unsigned 8 bit boolean output image based on threshold (input unsigned 16 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source values block pointer
   \param sstr  - [Input]  Source values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
   \param thres - [Input]  Threshold value
 */
void 
apu_threshold( vec08u* dst, int dstr,
         const vec16u* src, int sstr,
            int bw, int bh, uint16_t threshold) 
{ 
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {                 
		  dst[bx] = (vec08u)vselect((vec08u) 0xFF, (vec08u)0, src[bx] > threshold);
      }
      src += sstr;
      dst += dstr;      
   }
}

/*!
   Calculates an unsigned 8 bit boolean output image based on threshold (input unsigned 32 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src   - [Input]  Source values block pointer
   \param sstr  - [Input]  Source values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
   \param thres - [Input]  Threshold value
 */
void 
apu_threshold( vec08u* dst, int dstr,
         const vec32u* src, int sstr,
            int bw, int bh, uint32_t threshold) 
{ 
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {                 
		  dst[bx] = (vec08u)vselect((vec08u)0xFF, (vec08u) 0, src[bx] > threshold);
      }
      src += sstr;
      dst += dstr;      
   }
}

/*!
   Calculates the bitwise XOR from two sources (unsigned 8 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_xor(        vec08u* dst, int dstr,
         const vec08u* src1, int sstr1,
         const vec08u* src2, int sstr2,
                     int bw, int bh) 
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = (vec08u)vxor(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }   
}                     
                     
/*!
   Calculates the bitwise XOR from two sources (unsigned 16 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_xor(        vec16u* dst, int dstr,
         const vec16u* src1, int sstr1,
         const vec16u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vxor(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}                     

/*!
   Calculates the bitwise XOR from two sources (unsigned 32 bit)
 
   \param dst   - [Output] Destination block pointer
   \param dstr  - [Input]  Destination block stride
   \param src1  - [Input]  Source 1 values block pointer
   \param sstr1 - [Input]  Source 1 values block stride
   \param src2  - [Input]  Source 2 values block pointer
   \param sstr2 - [Input]  Source 2 values block stride
   \param bw    - [Input]  Block width
   \param bh    - [Input]  Block height
 */
void 
apu_xor(        vec32u* dst, int dstr,
         const vec32u* src1, int sstr1,
         const vec32u* src2, int sstr2,
                     int bw, int bh)
{
   for (int by = 0; by < bh; by++) chess_loop_range(1,)  {
      for (int bx = 0; bx < bw; bx++) chess_loop_range(1,)  {  
         dst[bx] = vxor(src1[bx], src2[bx]);
      }
      src1 += sstr1;
      src2 += sstr2;
      dst += dstr;      
   }  
}

inline
vec16u
apu_sad_full(
         const vec08u* aTemplate,   const int32_t ts,
         const vec08u* aWindow,     const int32_t ws,
         const int32_t tw, const int32_t th
         )
{
   vec16u s = 0;

   for (int32_t y=0; y<th; ++y)
   {
      for (int32_t x=0; x<tw; ++x)
      {
         vec16s d = aTemplate[x] - aWindow[x];
         #if 1
         s += vabs(d);
         #else
         vif (d < 0)
             s -= d;
         velse
             s += d;
         vendif
         #endif
      }
      aTemplate += ts;
      aWindow   += ws;
   }

   return s;
}

/*!
   Calculate minimum SAD & location given a template and a window
 
   \param lpvIn0           - [Input]  Source template block pointer
   \param lStrideIn0       - [Input]  Template block stride
   \param lChunkWidthIn0   - [Input]  Template block width
   \param lChunkHeightIn0  - [Input]  Template block height
   \param lpvIn1           - [Input]  Source window block pointer
   \param lStrideIn1       - [Input]  Window block stride
   \param lChunkWidthIn1   - [Input]  Window block width
   \param lChunkHeightIn1  - [Input]  Window block height
   \param lpvOut0          - [Output] Destination block pointer
   \param lStrideOut0      - [Input]  Destination block stride
   \param lChunkWidthOut0  - [Input]  Template block width
   \param lChunkHeightOut0 - [Input]  Template block height
 */

void
apu_sad (vec08u* lpvIn0, int16_t lStrideIn0, int16_t lChunkWidthIn0, int16_t lChunkHeightIn0,
         vec08u* lpvIn1, int16_t lStrideIn1, int16_t lChunkWidthIn1, int16_t lChunkHeightIn1,
         vec32u* lpvOut0, int16_t lStrideOut0, int16_t lChunkWidthOut0, int16_t lChunkHeightOut0)
{
   //implementation
   vec08u xmin = 0xFF, ymin = 0xFF;
   vec16u smin = 0xFFFF;

   vec16u* aMinSAD = (vec16u*)lpvOut0;

   vec08u* aLocation0 = (((vec08u*)lpvOut0) + 2);
   vec08u* aLocation1 = (((vec08u*)lpvOut0) + 3);


   vec08u* aTemplate = lpvIn0;
   vec08u* aWindow   = lpvIn1;

   const int32_t tw = lChunkWidthIn0;
   const int32_t th = lChunkHeightIn0;
   const int32_t ts = lStrideIn0;

   const int32_t ww = lChunkWidthIn1;
   const int32_t wh = lChunkHeightIn1;
   const int32_t ws = lStrideIn1;
 
   for (int y=0; y<(wh-th+1); ++y) chess_loop_range(1,)
   {
      for (int x=0; x<(ww-tw+1); ++x) chess_loop_range(1,)
      {
         vec16u s = apu_sad_full(aTemplate, ts, aWindow+x+y*ws, ws, tw, th);

         vif (s < smin)
         {
            smin = s;
            xmin = x;
            ymin = y;
         }
         vendif
      } 
   }

   aMinSAD[0]    = smin;
   aLocation0[0] = xmin;
   aLocation1[0] = ymin;
}

#endif /* ACF_KERNEL_IMPLEMENTATION */
