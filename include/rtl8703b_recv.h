/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __RTL8703B_RECV_H__
#define __RTL8703B_RECV_H__

#define RECV_BLK_SZ 512
#define RECV_BLK_CNT 16
#define RECV_BLK_TH RECV_BLK_CNT

#if defined(CONFIG_USB_HCI)

#ifndef MAX_RECVBUF_SZ
#ifdef PLATFORM_OS_CE
#define MAX_RECVBUF_SZ (8192+1024) // 8K+1k
#else
	#ifndef CONFIG_MINIMAL_MEMORY_USAGE
		//#define MAX_RECVBUF_SZ (32768) // 32k
		//#define MAX_RECVBUF_SZ (16384) //16K
		//#define MAX_RECVBUF_SZ (10240) //10K
		#ifdef CONFIG_PLATFORM_MSTAR
			#define MAX_RECVBUF_SZ (8192) // 8K
		#else
		        #define MAX_RECVBUF_SZ (15360) // 15k < 16k
		#endif
		//#define MAX_RECVBUF_SZ (8192+1024) // 8K+1k
	#else
		#define MAX_RECVBUF_SZ (4000) // about 4K
	#endif
#endif
#endif //!MAX_RECVBUF_SZ

#endif

// Rx smooth factor
#define	Rx_Smooth_Factor (20)

#ifdef CONFIG_USB_HCI
int rtl8703bu_init_recv_priv(_adapter *padapter);
void rtl8703bu_free_recv_priv (_adapter *padapter);
void rtl8703bu_init_recvbuf(_adapter *padapter, struct recv_buf *precvbuf);
#endif


void rtl8703b_query_rx_desc_status(union recv_frame *precvframe, u8 *pdesc);

#endif /* __RTL8703B_RECV_H__ */

