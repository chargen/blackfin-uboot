/*
 * U-boot - Configuration file for BF609 EZ-Kit board
 */

#ifndef __CONFIG_BF609_EZKIT_H__
#define __CONFIG_BF609_EZKIT_H__

#include <asm/config-pre.h>


/*
 * Processor Settings
 */
#define __ADSPBF60x__ 1
#define __ADSPBF609__ 1
#undef __ADSPBF592__
#undef __ADSPBF59x__
#define CONFIG_BFIN_CPU             bf609-0.0
#define CONFIG_BFIN_BOOT_MODE       BFIN_BOOT_PARA


/*
 * Clock Settings
 *	CCLK = (CLKIN * VCO_MULT) / CCLK_DIV
 *	SCLK = (CLKIN * VCO_MULT) / SYSCLK_DIV
 *	SCLK0 = SCLK / SCLK0_DIV
 *	SCLK1 = SCLK / SCLK1_DIV
 */
/* CONFIG_CLKIN_HZ is any value in Hz					*/
#define CONFIG_CLKIN_HZ			40000000
/* CLKIN_HALF controls the DF bit in PLL_CTL      0 = CLKIN		*/
/*                                                1 = CLKIN / 2		*/
#define CONFIG_CLKIN_HALF		0
/* PLL_BYPASS controls the BYPASS bit in PLL_CTL  0 = do not bypass	*/
/*                                                1 = bypass PLL	*/
#define CONFIG_PLL_BYPASS		0
/* VCO_MULT controls the MSEL (multiplier) bits in PLL_CTL		*/
/* Values can range from 0-127 (where 0 means 128)			*/
#define CONFIG_VCO_MULT			16
/* CCLK_DIV controls the core clock divider				*/
/* Values can range from 0-31 (where 0 means 32)			*/
#define CONFIG_CCLK_DIV			1
/* SCLK_DIV controls the system clock divider				*/
/* Values can range from 0-31 (where 0 means 32)			*/
#define CONFIG_SYSCLK_DIV		5
/* Values can range from 0-7 (where 0 means 8)				*/
#define CONFIG_SCLK0_DIV		5
#define CONFIG_SCLK1_DIV		5
/* DCLK_DIV controls the DDR clock divider				*/
/* Values can range from 0-31 (where 0 means 32)			*/
#define CONFIG_DCLK_DIV			5
/* OCLK_DIV controls the output clock divider				*/
/* Values can range from 0-127 (where 0 means 128)			*/
#define CONFIG_OCLK_DIV			5

#define CONFIG_BFIN_GET_VCO CONFIG_CLKIN_HZ
#define CONFIG_BFIN_GET_CCLK (get_vco() / 6)
#define CONFIG_BFIN_GET_SCLK (get_cclk() / 4)
#define CONFIG_BFIN_GET_SCLK0 (get_cclk() / 4)
#define CONFIG_BFIN_GET_SCLK1 (get_cclk() / 4)


/*
 * Memory Settings
 */
#define CONFIG_MEM_SIZE		0

#define CONFIG_SMC_GCTL_VAL	0x00000010
#define CONFIG_SMC_B1CTL_VAL	0x01002001
#define CONFIG_SMC_B1TIM_VAL	0x08070977
#define CONFIG_SMC_B1ETIM_VAL	0x00092231

#define CONFIG_SYS_MONITOR_BASE (L1_DATA_A_SRAM_END)
#define CONFIG_SYS_MONITOR_LEN	(4 * 1024)
#define CONFIG_SYS_MALLOC_LEN	(4 * 1024)


/*
 * Network Settings
 */
#define CONFIG_CMD_NET
#define CONFIG_NET_MULTI
#define CONFIG_DESIGNWARE_ETH
#define CONFIG_DW_PORTS		3
#define CONFIG_DW_AUTONEG
/*#define CONFIG_DW_SEARCH_PHY*/
#define CONFIG_HOSTNAME		(bf609-ezkit)


/*
 * Flash Settings
 */
#define CONFIG_SYS_NO_FLASH
#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_JFFS2
#undef CONFIG_CMD_FLASH


/*
 * Env Storage Settings
 */
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE 0x400
#undef CONFIG_CMD_EXPORTENV
#undef CONFIG_CMD_IMPORTENV


/*
 * Misc Settings
 */
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_UART_CONSOLE	0
#define CONFIG_BAUDRATE 57600

#define CONFIG_DEBUG_DUMP	1
#define CONFIG_KALLSYMS		1

#define CONFIG_CMD_MEMORY
#undef CONFIG_GZIP
#undef CONFIG_ZLIB
#undef CONFIG_CMD_BOOTM
#undef CONFIG_BOOTM_RTEMS
#undef CONFIG_BOOTM_LINUX

#define CONFIG_UART_MEM 1024
#undef CONFIG_UART_CONSOLE
#undef CONFIG_JTAG_CONSOLE
#undef CONFIG_UART_CONSOLE_IS_JTAG

#endif