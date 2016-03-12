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
/**
* \file     csi.h
* \brief    declarations for CSI driver
* \author   Tomas Babinec
* \version  0.1
* \date     29-May-2015
* \note
****************************************************************************/

#ifndef CSI_H
#define CSI_H

#ifdef __cplusplus 
extern "C" { 
#endif

// will be built run on desktop
//#define FDMA_DESK 

#if !defined(__STANDALONE__)
#include <linux/ioctl.h>
# endif // !defined(__STANDALONE__)

#include "isp_hw.h"
#include "csi_types.h"

/*****************************************************************************
* MACRO definitions
*****************************************************************************/

// IRQ GIC ids
#define CSI0_ERR_IRQ 123
#define CSI1_ERR_IRQ 124
#define CSI0_FRM_IRQ 125
#define CSI1_FRM_IRQ 126

// CSI driver return values
#define CSI_DRV_SUCCESS   0
#define CSI_DRV_FAILURE   -1

// I2C definitions if not Standalone
#ifndef __STANDALONE__
#define I2C0 0 
#define I2C1 1
#define I2C2 2
#endif // #ifndef __STANDALONE__

// name of the device file
#define CSI_DEVICE_NAME "csi"

// magic number for fDMA driver
#define CSI_IOC_MAGIC 'c'

#if !defined(__STANDALONE__)
#include "csi_ioctl.h"
#include "csi_types.h"
# endif // !defined(__STANDALONE__)

#ifdef __cplusplus 
} //extern "C" 
#endif

#endif // #ifndef CSI_H