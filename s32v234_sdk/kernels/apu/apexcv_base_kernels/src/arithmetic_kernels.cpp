/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2013 All right reserved.
 * 
 *  Confidential Information
 *
 *  All parts of the CogniVue Program Source are protected by copyright law
 *  and all rights are reserved.
 *  This documentation may not, in whole or in part, be copied, photocopied,
 *  reproduced, translated, or reduced to any electronic medium or machine
 *  readable form without prior consent, in writing, from CogniVue.
 *
 ******************************************************************************/
 
/*!
* \file arithmetic.cpp
* \addtogroup apexcv-arithmetic 
* \addtogroup arithmetic
* \ingroup arithmetic
* @{
* \brief arithmetic operations mimicking opencv
*/

/*!*********************************************************************************
*  @file arithmetic.c
*  @brief ACF metadata and wrapper function for arithmetic operations
***********************************************************************************/
 
#ifdef APEX2_EMULATE
#include "acf_kernel.hpp" // if using the ACF emulation library
using namespace APEX2;
#endif

#ifdef ACF_KERNEL_METADATA

#include "arithmetic_kernels.h"
/*!*********************************************************************************
*  \brief ACF metadata for the abs kernel
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ABS_08u_K)
(
	ABS_08u_KN,
   2,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08s),
          __e0_size(1, 1),
          __ek_size(1, 1)),  
   __port(__index(1),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the absdiff kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ABSDIFF_08u_K)
(
   ABSDIFF_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the accumulate kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ACCUM_16s_K)
(
   ACCUM_16s_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the accumulate squared kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ACCUM_SQRD_16s_K)
(
   ACCUM_SQRD_16s_KN,
   4,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)), 
   __port(__index(2),
          __identifier(ALPHA),
          __attributes(ACF_ATTR_SCL_IN_STATIC_FIXED),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),    
   __port(__index(3),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the accumulate weighted kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ACCUM_WGTD_08u_K)
(
   ACCUM_WGTD_08u_KN,
   4,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(2),
          __identifier(ALPHA),
          __attributes(ACF_ATTR_SCL_IN_STATIC_FIXED),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),  
   __port(__index(3),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the add kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ADD_08u_K)
(
   ADD_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the add kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(ADD_16s_K)
(
   ADD_16s_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)), 
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)),           
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the and kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(AND_08u_K)
(
   AND_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the and kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(AND_16u_K)
(
   AND_16u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the and kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(AND_32u_K)
(
   AND_32u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the clz kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(CLZ_08u_K)
(
   CLZ_08u_KN,
   2,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),  
   __port(__index(1),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the clz kernel (signed 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(CLZ_08s_K)
(
   CLZ_08s_KN,
   2,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08s),
          __e0_size(1, 1),
          __ek_size(1, 1)),  
   __port(__index(1),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the clz kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(CLZ_16u_K)
(
   CLZ_16u_KN,
   2,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),  
   __port(__index(1),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the clz kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(CLZ_16s_K)
(
   CLZ_16s_KN,
   2,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)),  
   __port(__index(1),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the magnitude kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(MAGNITUDE_16s_K)
(
   MAGNITUDE_16s_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)), 
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)),            
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the bitwise not kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(NOT_08u_K)
(
   NOT_08u_KN,
   2,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),    
   __port(__index(1),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the or kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(OR_08u_K)
(
   OR_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the or kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(OR_16u_K)
(
   OR_16u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the or kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(OR_32u_K)
(
   OR_32u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the sub kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(SUB_08u_K)
(
   SUB_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the sub kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(SUB_16s_K)
(
   SUB_16s_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)), 
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1)),           
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16s),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the threshold kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(THRESH_08u_K)
(
   THRESH_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_SCL_IN_STATIC_FIXED),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the threshold kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(THRESH_16u_K)
(
   THRESH_16u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_SCL_IN_STATIC_FIXED),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the threshold kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(THRESH_32u_K)
(
   THRESH_32u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_SCL_IN_STATIC_FIXED),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the xor kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(XOR_08u_K)
(
   XOR_08u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d08u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the xor kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(XOR_16u_K)
(
   XOR_16u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d16u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

/*!*********************************************************************************
*  \brief ACF metadata for the xor kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.2
***********************************************************************************/

#ifndef APEX2_EMULATE
static // declare as static only if the code is compiled by the Target compiler
#endif
KERNEL_INFO kernelInfoConcat(XOR_32u_K)
(
   XOR_32u_KN,
   3,
   __port(__index(0),
          __identifier(INPUT_0),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),
   __port(__index(1),
          __identifier(INPUT_1),
          __attributes(ACF_ATTR_VEC_IN),
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1)),      
   __port(__index(2),
          __identifier(OUTPUT_0),
          __attributes(ACF_ATTR_VEC_OUT), 
          __spatial_dep(0,0,0,0),
          __e0_data_type(d32u),
          __e0_size(1, 1),
          __ek_size(1, 1))
);

#endif //#ifdef ACF_KERNEL_METADATA

#ifdef ACF_KERNEL_IMPLEMENTATION

#include "apu_arithmetic_impl.h"
#include <stdint.h>

/*!*********************************************************************************
*  \brief ACF wrapper function for the abs kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void abs_08u(kernel_io_desc lIn0, kernel_io_desc lOut0)
{
   vec08s* lpvIn0  = (vec08s*)lIn0.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_abs( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the absdiff kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void absdiff_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_absdiff( lpvOut0, lOut0.chunkSpan, 
                lpvIn0, lIn0.chunkSpan, 
                lpvIn1, lIn1.chunkSpan, 
                lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the accumulate kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void accumulate_16s(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec16s* lpvOut0 = (vec16s*)lOut0.pMem;
   
   apu_accumulate( lpvOut0, lOut0.chunkSpan/2, 
                lpvIn0, lIn0.chunkSpan, 
                lpvIn1, lIn1.chunkSpan, 
                lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the accumulate squared kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void accumulate_squared_16s(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lAlpha, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   uint8_t* lpAlpha = (uint8_t*)lAlpha.pMem;
   vec16s* lpvOut0 = (vec16s*)lOut0.pMem;
   
   apu_accumulate_squared( lpvOut0, lOut0.chunkSpan/2, 
                lpvIn0, lIn0.chunkSpan, 
                lpvIn1, lIn1.chunkSpan, 
                lIn0.chunkWidth, lIn0.chunkHeight,
                lpAlpha[0] );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the accumulate weighted kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void accumulate_weighted_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lAlpha, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   uint8_t* lpAlpha = (uint8_t*)lAlpha.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_accumulate_weighted( lpvOut0, lOut0.chunkSpan, 
                lpvIn0, lIn0.chunkSpan, 
                lpvIn1, lIn1.chunkSpan, 
                lIn0.chunkWidth, lIn0.chunkHeight,
                lpAlpha[0] );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the add kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void add_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_add( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lpvIn1, lIn1.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the add kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void add_16s(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec16s* lpvIn0  = (vec16s*)lIn0.pMem;
   vec16s* lpvIn1  = (vec16s*)lIn1.pMem;
   vec16s* lpvOut0 = (vec16s*)lOut0.pMem;
   
   apu_add( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lpvIn1, lIn1.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the and kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void and_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_and( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lpvIn1, lIn1.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the and kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void and_16u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec16u* lpvIn0  = (vec16u*)lIn0.pMem;
   vec16u* lpvIn1  = (vec16u*)lIn1.pMem;
   vec16u* lpvOut0 = (vec16u*)lOut0.pMem;
   
   apu_and( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lpvIn1, lIn1.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the and kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void and_32u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec32u* lpvIn0  = (vec32u*)lIn0.pMem;
   vec32u* lpvIn1  = (vec32u*)lIn1.pMem;
   vec32u* lpvOut0 = (vec32u*)lOut0.pMem;
   
   apu_and( lpvOut0, lOut0.chunkSpan / 4, 
            lpvIn0, lIn0.chunkSpan / 4, 
            lpvIn1, lIn1.chunkSpan / 4, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the clz kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void clz_08u(kernel_io_desc lIn0, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_clz( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the clz kernel (signed 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void clz_08s(kernel_io_desc lIn0, kernel_io_desc lOut0)
{
   vec08s* lpvIn0  = (vec08s*)lIn0.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_clz( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the clz kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void clz_16u(kernel_io_desc lIn0, kernel_io_desc lOut0)
{
   vec16u* lpvIn0  = (vec16u*)lIn0.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_clz( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the clz kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void clz_16s(kernel_io_desc lIn0, kernel_io_desc lOut0)
{
   vec16s* lpvIn0  = (vec16s*)lIn0.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_clz( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the magnitude kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void magnitude_16s(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec16s* lpvIn0  = (vec16s*)lIn0.pMem;
   vec16s* lpvIn1  = (vec16s*)lIn1.pMem;
   vec16u* lpvOut0 = (vec16u*)lOut0.pMem;
   
   
   apu_magnitude( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lpvIn1, lIn1.chunkSpan / 2,
            lIn0.chunkWidth, lIn0.chunkHeight );
            
}
            
/*!*********************************************************************************
*  \brief ACF wrapper function for the bitwise not kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void not_08u(kernel_io_desc lIn0, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_not( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the or kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void or_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_or( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lpvIn1, lIn1.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the or kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void or_16u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec16u* lpvIn0  = (vec16u*)lIn0.pMem;
   vec16u* lpvIn1  = (vec16u*)lIn1.pMem;
   vec16u* lpvOut0 = (vec16u*)lOut0.pMem;
   
   apu_or( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lpvIn1, lIn1.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the or kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void or_32u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec32u* lpvIn0  = (vec32u*)lIn0.pMem;
   vec32u* lpvIn1  = (vec32u*)lIn1.pMem;
   vec32u* lpvOut0 = (vec32u*)lOut0.pMem;
   
   apu_or( lpvOut0, lOut0.chunkSpan / 4, 
            lpvIn0, lIn0.chunkSpan / 4, 
            lpvIn1, lIn1.chunkSpan / 4, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}


/*!*********************************************************************************
*  \brief ACF wrapper function for the sub kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void sub_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec16s* lpvOut0 = (vec16s*)lOut0.pMem;
   
   apu_sub( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan, 
            lpvIn1, lIn1.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the sub kernel (signed 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void sub_16s(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec16s* lpvIn0  = (vec16s*)lIn0.pMem;
   vec16s* lpvIn1  = (vec16s*)lIn1.pMem;
   vec16s* lpvOut0 = (vec16s*)lOut0.pMem;
   
   apu_sub( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lpvIn1, lIn1.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the threshold kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void threshold_08u(kernel_io_desc lIn0, kernel_io_desc lThreshold, kernel_io_desc lOut0)
{
   vec08u* lpvIn0             = (vec08u*)lIn0.pMem;
   uint8_t* lpvThreshold      = (uint8_t*)lThreshold.pMem;
   vec08u* lpvOut0            = (vec08u*)lOut0.pMem;
   
   apu_threshold( lpvOut0, lOut0.chunkSpan, 
                  lpvIn0, lIn0.chunkSpan,       
                  lIn0.chunkWidth, lIn0.chunkHeight,
                  lpvThreshold[0] );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the threshold kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void threshold_16u(kernel_io_desc lIn0, kernel_io_desc lThreshold, kernel_io_desc lOut0)
{
   vec16u* lpvIn0             = (vec16u*)lIn0.pMem;
   uint16_t* lpvThreshold     = (uint16_t*)lThreshold.pMem;
   vec08u* lpvOut0            = (vec08u*)lOut0.pMem;
   
   apu_threshold( lpvOut0, lOut0.chunkSpan, 
                      lpvIn0, lIn0.chunkSpan / 2,       
                      lIn0.chunkWidth, lIn0.chunkHeight,
                      lpvThreshold[0] );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the threshold kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void threshold_32u(kernel_io_desc lIn0, kernel_io_desc lThreshold, kernel_io_desc lOut0)
{
   vec32u* lpvIn0             = (vec32u*)lIn0.pMem;
   uint32_t* lpvThreshold     = (uint32_t*)lThreshold.pMem;
   vec08u* lpvOut0            = (vec08u*)lOut0.pMem;
   
   apu_threshold( lpvOut0, lOut0.chunkSpan, 
                  lpvIn0, lIn0.chunkSpan / 4,       
                  lIn0.chunkWidth, lIn0.chunkHeight,
                  lpvThreshold[0] );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the xor kernel (unsigned 8 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void xor_08u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec08u* lpvIn0  = (vec08u*)lIn0.pMem;
   vec08u* lpvIn1  = (vec08u*)lIn1.pMem;
   vec08u* lpvOut0 = (vec08u*)lOut0.pMem;
   
   apu_xor( lpvOut0, lOut0.chunkSpan, 
            lpvIn0, lIn0.chunkSpan, 
            lpvIn1, lIn1.chunkSpan, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the xor kernel (unsigned 16 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void xor_16u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec16u* lpvIn0  = (vec16u*)lIn0.pMem;
   vec16u* lpvIn1  = (vec16u*)lIn1.pMem;
   vec16u* lpvOut0 = (vec16u*)lOut0.pMem;
   
   apu_xor( lpvOut0, lOut0.chunkSpan / 2, 
            lpvIn0, lIn0.chunkSpan / 2, 
            lpvIn1, lIn1.chunkSpan / 2, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

/*!*********************************************************************************
*  \brief ACF wrapper function for the xor kernel (unsigned 32 bit)
*  \see UG-10267-03 ACF User Guide, Section 3.2.3
***********************************************************************************/                                 
void xor_32u(kernel_io_desc lIn0, kernel_io_desc lIn1, kernel_io_desc lOut0)
{
   vec32u* lpvIn0  = (vec32u*)lIn0.pMem;
   vec32u* lpvIn1  = (vec32u*)lIn1.pMem;
   vec32u* lpvOut0 = (vec32u*)lOut0.pMem;
   
   apu_xor( lpvOut0, lOut0.chunkSpan / 4, 
            lpvIn0, lIn0.chunkSpan / 4, 
            lpvIn1, lIn1.chunkSpan / 4, 
            lIn0.chunkWidth, lIn0.chunkHeight );
}

#endif //#ifdef ACF_KERNEL_IMPLEMENTATION
/*! @} */
