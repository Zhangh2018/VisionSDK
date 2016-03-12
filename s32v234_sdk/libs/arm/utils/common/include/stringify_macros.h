/*****************************************************************************
*
* Freescale Confidential Proprietary
*
* Copyright (c) 2014 Freescale Semiconductor;
* All Rights Reserved
*
*****************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************/
#ifndef STRINGIFY_MACROS_H
#define STRINGIFY_MACROS_H

// Put name between ""
#define STR(s) #s

//Put expanded macro/define between ""
#define XSTR(s) STR(s)

// generate a filename from file_root and extension part
#define concat(name,ext) name.ext
#define plainConcat(a,b) a##b
#define kernelInfoConcat(a) plainConcat(_kernel_info_,a)

#define extKernelInfoDecl(a) extern KERNEL_INFO kernelInfoConcat(a)
#define processDescConcat(a) plainConcat(a,_apu_process_desc)

#define identity(s) s

// put the filename between ""
#define str_header(name,ext) XSTR(concat(name,ext))

#ifndef APEX2_EMULATE // to avoid the ifdefs all over the code
#define XREGISTER_ACF_KERNEL(Kernel)
#define REGISTER_PROCESS_TYPE(a, b)
#endif

#endif
