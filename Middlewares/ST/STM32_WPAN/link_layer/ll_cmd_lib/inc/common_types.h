/*$Id: //dwh/bluetooth/DWC_ble154combo/firmware/rel/1.30a-SOW02PatchV1/firmware/public_inc/common_types.h#1 $*/
/**
 ********************************************************************************
 * @file    common_types.h
 * @brief   This file contains common includes for BLE FW LL.
 ******************************************************************************
 * @copy
 *
 *(C) COPYRIGHT 2023 SYNOPSYS, Inc. This Synopsys "product" and all associated documentation 
 *are proprietary to Synopsys, Inc. and may only be used pursuant to the terms and 
 *conditions of a written license agreement with Synopsys, Inc. All other use, 
 *reproduction, modification, or distribution of the Synopsys "product" or the associated 
 *documentation is strictly prohibited.
 *
 *
 * THE ENTIRE NOTICE ABOVE MUST BE REPRODUCED ON ALL AUTHORIZED COPIES.
 *
 * <h2><center>&copy; (C) (C) COPYRIGHT 2023 SYNOPSYS, INC.</center></h2>
 * <h2><center>&copy; 	ALL RIGHTS RESERVED</center></h2>
 *
 * \n\n<b>References</b>\n
 * -Documents folder .
 *
 * <b>Edit History For File</b>\n
 *  This section contains comments describing changes made to this file.\n
 *  Notice that changes are listed in reverse chronological order.\n
 * <table border>
 * </table>\n
 * * <tr>
 *   <td>  Add READ_BYTES and WIRTE_BYTES bytes macros(for endian      	  *     independence)</td>
 *   <td>  Add bit fields accessing macros</td>
 * </tr>
 * </table>\n
 */

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_
#include "_40nm_reg_files/DWC_ble154combo.h"
#include "bsp.h"
#include "ll_fw_config.h"
#include "mem_intf.h"
#include "os_wrapper.h"


/********************************************************************** */
/****************** BLE MAC COMBO Configurations*********************** */
/********************************************************************** */
#ifdef BLE
#define SUPPORT_BLE									1
#else
#define SUPPORT_BLE									0
#endif

#ifdef MAC
#define SUPPORT_MAC									1
#else
#define SUPPORT_MAC									0
#endif
#ifdef ANT_ROLE
#define SUPPORT_ANT								    1

#ifdef SUPPORT_ANT_TESTING
#define SUPPORT_ANT_HCI_UART								    1
#else
#define SUPPORT_ANT_HCI_UART								    0
#endif /* SUPPORT_ANT_HCI_UART*/

#else
#define SUPPORT_ANT								    0
#define SUPPORT_ANT_HCI_UART                                0
#endif

#ifdef MAC_LAYER
#define MAC_LAYER_BUILD 1
#else
#define MAC_LAYER_BUILD 0
#endif

#ifdef SUPPORT_MAC_HCI_UART
#define SUPPORT_MAC_HCI_UART       1
#else
#define SUPPORT_MAC_HCI_UART       0
#endif

#ifdef SUPPORT_AUG_MAC_HCI_UART
#define SUPPORT_AUG_MAC_HCI_UART       1
#else
#define SUPPORT_AUG_MAC_HCI_UART       0
#endif

#if((!SUPPORT_BLE)&&(SUPPORT_MAC || SUPPORT_AUG_MAC_HCI_UART)&&(RAL_NUMBER_OF_INSTANCE>1))
#error "BLE controller must be enabled to support MAC multiple Instances"
#endif

#if((SUPPORT_MAC)&&(SUPPORT_AUG_MAC_HCI_UART)&&(RAL_NUMBER_OF_INSTANCE<2))
#error "RAL_NUMBER_OF_INSTANCE must be 2 to support MAC and Augmented MAC"
#endif

#if((!SUPPORT_BLE)&&(SUPPORT_MAC)&&(SUPPORT_ANT))
#error "BLE controller must be enabled to support MAC and ANT Coexistence"
#endif

#define SUPPORT_COEXISTENCE							((SUPPORT_BLE&&SUPPORT_MAC) || (SUPPORT_BLE&&SUPPORT_ANT))
#define SUPPORT_ANT_COEXISTENCE						(SUPPORT_BLE&&SUPPORT_ANT)
/****************** User configuration **********************************/

#define SUPPORT_GNRC_SCHDLR_IF	              (1)




/********************* Macros **********************************/

#ifndef SUCCESS
#define		SUCCESS				0
#endif
#ifndef GENERAL_FAILURE
#define		GENERAL_FAILURE		-1
#endif
#ifndef GENERAL_ERROR_STATUS
#define		GENERAL_ERROR_STATUS		0xFF
#endif

#ifndef TRUE
#define TRUE				1
#endif /* TRUE */

#ifndef FALSE
#define FALSE				0
#endif /* FALSE */

#ifndef NULL
#define NULL				((void *)0)
#endif	/* NULL */

#define MEMSET(ptr_memory, value, memory_size)				ble_memset(ptr_memory, value, memory_size)
#define MEMCPY(ptr_destination, ptr_source, memory_size)	ble_memcpy(ptr_destination, ptr_source, memory_size)
#define MEMCMP(ptr_destination, ptr_source, memory_size)	ble_memcmp(ptr_destination, ptr_source, memory_size)





extern os_mutex_id g_ll_lock;
#define LL_LOCK()	os_rcrsv_mutex_wait(g_ll_lock,0xffffffff)
#define LL_UNLOCK()	os_rcrsv_mutex_release(g_ll_lock)

#if SUPPORT_MAC && SUPPORT_OPENTHREAD_1_2
/* compiler flag to control supporting of CSL transmitter , RADIO TX at specific time , 1  supported , 0 not supported */
#define CONFIG_MAC_CSL_TRANSMITTER_ENABLE                1
/* compiler flag to control supporting of CSL receiver , RADIO RX at specific time, 1  supported , 0 not supported */
#define CONFIG_MAC_CSL_RECEIVER_ENABLE                   1
/* compiler flag to control supporting of Radio security handling */
#define SUPPORT_RADIO_SECURITY_OT_1_2                    1
/* compiler flag to control supporting of Enhanced Ack Link metrics probing  */
#define SUPPORT_ENH_ACK_LINK_METRICS_PROBING_OT_1_2 	 1
/* compiler flag to control supporting of Time sync experimental feature of OT 1.2
 * (it is not a thread 1.2 shall not be added except for with OT 1.2 for testing purpose) */
#define SUPPORT_TIME_SYNC_OT_1_2						 1
#else
#define CONFIG_MAC_CSL_TRANSMITTER_ENABLE                0
#define CONFIG_MAC_CSL_RECEIVER_ENABLE                   0
#define SUPPORT_RADIO_SECURITY_OT_1_2           		 0
#define SUPPORT_ENH_ACK_LINK_METRICS_PROBING_OT_1_2 	 0
#define SUPPORT_TIME_SYNC_OT_1_2						 0
#endif /*SUPPORT_MAC && SUPPORT_OPENTHREAD_1_2 */

/* end of radio activity custom command flag */
#define END_OF_RADIO_ACTIVITY_REPORTING				1 /* Enable\Disable end of radio activity reporting feature. Enable:1 - Disable:0 */

/* Supported PHYs*/
typedef enum {
	LE_NO_CHANGE			= 0x00,
	LE_1M  					= 0x01,
	LE_2M 					= 0x02,
	LE_CODED_S8				= 0x03,
	LE_CODED 				= 0x04,
#if (SUPPORT_LE_POWER_CONTROL)
	LE_PHY_UNDEFINED		= 0xFC,
	NEW_PHY_CODED_S2		= 0xFD,
	NEW_PHY_CODED_S8		= 0xFE,
	NEW_PHY_CODED_COMBINED	= 0xFF,
#endif /* SUPPORT_LE_POWER_CONTROL */

	/* PHY Recommendations - Combined Values */
#if ((SUPPORT_CONNECTED_ISOCHRONOUS && SUPPORT_MASTER_CONNECTION) || SUPPORT_BRD_ISOCHRONOUS)
	RECOMMEND_1M_2M			= 0x03,
	RECOMMEND_1M_CODED		= 0x05,
	RECOMMEND_2M_CODED		= 0x06,
	RECOMMEND_1M_2M_CODED 	= 0x07,
#endif /* ((SUPPORT_CONNECTED_ISOCHRONOUS && SUPPORT_MASTER_CONNECTION) || SUPPORT_BRD_ISOCHRONOUS) */
} tx_rx_phy_e;


#ifdef PHY_40nm_2_50_a
/**
 * @brief Enumeration to represent different rates for continuous modulation mode
 */
typedef enum phy_cnt_mod_rate_e {
	PHY_CNT_MOD_1M_RATE,		/* Continuous modulation mode with 1M PHY*/
	PHY_CNT_MOD_2M_RATE,		/* Continuous modulation mode with 2M PHY*/
	PHY_CNT_MOD_CODED_RATE,		/* Continuous modulation mode with Coded PHY*/
	PHY_CNT_MOD_256K_RATE,		/* Continuous modulation mode with Zigbee PHY*/
#if SUPPORT_A_MAC
	PHY_CNT_MOD_125K_RATE,		/* Continuous modulation mode with zigbee 125K PHY*/
#endif /*SUPPORT_A_MAC*/
	PHY_CNT_MOD_UNSUPPORTED
} phy_cnt_mod_rate_t;
#endif /*PHY_40nm_2_50_a*/

/**
 * @brief time stamp structure.
 */
typedef struct time_st {
	uint32_t time_stamp_base;
	uint32_t time_stamp_fine;
} ble_time_t, *ble_time_p;
typedef enum dpslp_state {
	DEEP_SLEEP_ENABLE  = 0x01,
	DEEP_SLEEP_DISABLE = 0x00
} dpslp_state_e;

/**
 * @enum crypto_endian_enum_t
 * @brief States the available endian formats.
 *
 */
typedef enum {
	CRYPTO_LITTLE_ENDIAN,
	CRYPTO_BIG_ENDIAN
} crypto_endian_enum_t;

/**
 * @enum security_mode_enum_t
 * @brief Contains the available security modes.
 *
 * Note: The enum values should be the same as specified in the register
 *  address header file.
 */
typedef enum {
	ECB_DECRYPT	= 0,
	CCM_DECRYPT	= 1,
	ECB_ENCRYPT	= 2,
	CCM_ENCRYPT	= 3,
	CTR_ENCRYPT = 4,
	CTR_DECRYPT = 5,
	MODES_MAX_NUM
} security_mode_enum_t;

#if SUPPORT_MAC
typedef enum ral_phy_rate_enum {
#if SUPPORT_A_MAC
	RAL_RATE_125K = 0x00,
	RAL_RATE_1M   = 0x02,
	RAL_RATE_2M   = 0x03,
#endif
	RAL_RATE_256K  = 0x01
} ral_phy_rate_enum_t;
#endif /*SUPPORT_MAC*/
/**
 * @enum extrnl_evnt_priority_e
 * @brief External Event priority
 */
typedef enum _extrnl_evnt_priority_e
{
	PRIORITY_DEFAULT,
	PRIORITY_HIGH,
	PRIORITY_CRITICAL
}extrnl_evnt_priority_e;

/**
 * @enum extrnl_evnt_state_e
 * @brief External Event Blocked State and reason
 */
typedef enum _extrnl_evnt_state_e
{
	STATE_BLOCKED_UNKNOWN,
	STATE_BLOCKED_PRIORITY,
	STATE_BLOCKED_CANCELLED,
	STATE_BLOCKED_LATE,
	STATE_BLOCKED_DEADLINE,
	STATE_NOT_BLOCKED
}extrnl_evnt_state_e;

/**
  * @brief Enumeration of the source type used to drive the sleep timer.
  */
typedef enum _slptmr_src_type_e {
	CRYSTAL_OSCILLATOR_SLPTMR	= 0x00,
#if (USE_NON_ACCURATE_32K_SLEEP_CLK)
	RCO_SLPTMR					= 0x01,
	RTC_SLPTMR					= 0x02
#endif /* USE_NON_ACCURATE_32K_SLEEP_CLK */
}slptmr_src_type_e;



/*
 * @brief structure that hold some information about the data transmitted across layers.
 */
typedef struct ble_buff_hdr_st {
	/* pointer to buffer allocated in TX/RX buffer*/
	uint8_t *buff_start;
	/* pointer to next ble_buff_hdr node */
	struct ble_buff_hdr_st *next_pkt;
	/* Total buffer size */
	uint16_t total_len;
	/* offset to data location from the packet start pointed to by buff_start */
	uint16_t data_offset;
	/* data size for the data pointed to by buff_start + data_offset*/
	uint16_t data_size;
	/* bit field flags to be used for identifying buffer type data/control buffer,
	 * for data is it a BLE/MAC/ANT, does it contain complete SDU packet of it is a fragment,
	 * if it is a fragment is it the start or continuation or last fragment. */
	uint8_t ble_hdr_flags;
} pkt_buff_hdr_t ,ble_buff_hdr_t, *ble_buff_hdr_p;

#if (SUPPORT_BRD_ISOCHRONOUS || SUPPORT_SYNC_ISOCHRONOUS ||  (SUPPORT_CONNECTED_ISOCHRONOUS && ( SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION)))
/**
 * @brief:  PDU info structure
 */
typedef struct _iso_pdu_buff_hdr_st {
	ble_buff_hdr_t  pkt;	/* PDU Packet */
#if(SUPPORT_CONNECTED_ISOCHRONOUS && (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION))
	uint8_t flsh_tmout_cnt;		/* flush timeout counter */
	uint8_t flsh_tmout_subevnt_cnt;		/* flush timeout subevent number */
#endif //(SUPPORT_CONNECTED_ISOCHRONOUS && (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION))
	uint8_t status;
} iso_pdu_buff_hdr_st;
/**
 * @brief:  SDU info structure
 */
typedef struct _sdu_buf_hdr_st {
	iso_pdu_buff_hdr_st* ptr_last_pdu_buff_hdr;		/* pointer to the last pdu buffer header pointed to this sdu */
	struct _sdu_buf_hdr_st* ptr_nxt_sdu_buff_hdr;	/* next sdu pointer */
	uint32_t*ptr_sdu_buffer;	/* pointer to SDU buffer in system memory for rx*/
	uint32_t time_stamp;	/* Time Stamp associated with this SDU */
	uint32_t time_offset;	/* Time Offset used only in framed SDUs */
	uint16_t pkt_sqnc_num;	/* Packet Sequence Number */
	uint16_t iso_sdu_len;	/* ISO SDU data real length */
	uint8_t  pkt_status_flag;
	uint8_t  pb_flag;      /* PB_flag used in rx */
	/*
	 * the first one will have the value 10 complete sdu until a new sdu fragment will be received then it will be 00 first fragment
	 * the subsequent one will have the value 11 last fragment until a new sdu fragment will be received then it will be 01 continuation fragment
	 *
	 * */
} iso_sdu_buf_hdr_st, *iso_sdu_buf_hdr_p;
#endif  /* (SUPPORT_BRD_ISOCHRONOUS || SUPPORT_SYNC_ISOCHRONOUSs ||  (SUPPORT_CONNECTED_ISOCHRONOUS && ( SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION))) */

/*
 * @brief   Transport layer event
 */
typedef enum {
	HCI_CMD_PCKT = 0x01,
	HCI_ACL_DATA_PCKT = 0x02,
	HCI_EVNT_PCKT = 0x04,
	HCI_ISO_DATA_PCKT = 0x05,
#if (SUPPORT_MAC && SUPPORT_MAC_HCI_UART)
	HCI_MAC_REQ = 0x0A,
	HCI_MAC_CFM = 0x0B,
#endif /* SUPPORT_MAC && SUPPORT_MAC_HCI_UART */
#if (SUPPORT_ANT_HCI_UART)
	HCI_ANT_REQ = 0x07,
	HCI_ANT_CFM = 0x08,
#endif /* SUPPORT_ANT_HCI_UART */
#if (SUPPORT_AUG_MAC_HCI_UART)
	AUG_HCI_MAC_REQ = 0x0C,
	AUG_HCI_MAC_CFM = 0x0D,
#endif /* SUPPORT_AUG_MAC_HCI_UART */

} event_t;



/*constant flags to be used with ble_buff_hdr_t:ble_hdr_flags*/
#define BLE_BUFF_HDR_STRT_PKT 			(1<<0)
#define BLE_BUFF_HDR_CNTRL_PKT 			(1<<1)
#define BLE_BUFF_HDR_BUFF_FRGMNTD 		(1<<2)
#define BLE_BUFF_HDR_EVNT_CMD_PCKT		(1<<3)
#define BLE_BUFF_HDR_ACL_DATA_PCKT		(1<<4)

#if ((SUPPORT_CONNECTED_ISOCHRONOUS && (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION)) \
		||(SUPPORT_BRD_ISOCHRONOUS || SUPPORT_SYNC_ISOCHRONOUS))
#define BLE_BUFF_HDR_NULL_PCKT		(1<<3)
/*
 * BLE_BUFF_HDR_ISO_DATA_PCKT_BIT1  : BLE_BUFF_HDR_ISO_DATA_PCKT_BIT0   = Mode
 * 1								: 1									= Unframed CIS Data PDU; end fragment of an SDU or a complete SDU. LLID (0b00)
 * 0								: 1									= Unframed CIS Data PDU; start or continuation fragment of an SDU.
 * 1								: 0									= Framed CIS Data PDU; one or more segments of an SDU.
 * */
#define BLE_BUFF_HDR_ISO_DATA_PCKT_BIT0		(1<<5)
#define BLE_BUFF_HDR_ISO_DATA_PCKT_BIT1		(1<<6)
#endif /* (SUPPORT_CONNECTED_ISOCHRONOUS && (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION)) */
#if (SUPPORT_MAC && SUPPORT_MAC_HCI_UART)
#define BLE_BUFF_HDR_MAC_CMD_PCK		(1<<6)
#endif /* (SUPPORT_MAC && SUPPORT_MAC_HCI_UART) */
#if (SUPPORT_ANT_HCI_UART)
#define BLE_BUFF_HDR_ANT_CMD_PCK		(1<<7)
#endif  /* SUPPORT_ANT_HCI_UART */
#if (SUPPORT_AUG_MAC_HCI_UART)
#define BLE_BUFF_HDR_AUG_MAC_CMD_PCK		((1<<7)|(1<<6))
#endif


/**
 * The default PHY periodic calibration period in second. this Macro can be set to any value , Zero means that phy periodic calibration is disabled
 */
#define DEFAULT_PHY_CALIBRATION_PERIOD        		10	/* Time period for PHY calibration = 10s */


#ifndef EXTERNAL_CUSTOM_CMDS
#define EXTERNAL_CUSTOM_CMDS						0	/* Indicates that an external custom HCI commands module exists */
#endif /* EXTERNAL_CUSTOM_CMDS */
#define SUPPORT_ZIGBEE_PHY_CERTIFICATION   1  /* 0 disable , 1 enable .. used to enable support of hci command required to implement zigbee phy Test cases*/


#if (!USE_HCI_TRANSPORT) && (SUPPORT_BLE)						  /* SUPPORT_HCI_EVENT_ONLY cannot be supported with default HCI_transport */
/* if this marco is enabled it will enable  the below features
 *  -Queue events - ACL - ISO - Reports into different queues
   -Allow host to register callback to refuse current controller event and receive it later with another callback*/
#define SUPPORT_HCI_EVENT_ONLY				1

#endif/* (!USE_HCI_TRANSPORT) && (SUPPORT_BLE) */

#define SUPPORT_HW_AUDIO_SYNC_SIGNAL        0
#endif /*COMMON_TYPES_H_*/