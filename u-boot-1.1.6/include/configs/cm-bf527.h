/*
 * U-boot - Configuration file for CM-BF527 board
 */

#ifndef __CONFIG_CM_BF527_H__
#define __CONFIG_CM_BF527_H__

#include <asm/blackfin-config-pre.h>


/*
 * Processor Settings
 */
#define CONFIG_BFIN_CPU             bf527-0.0
#define CONFIG_BFIN_BOOT_MODE       BFIN_BOOT_PARA


/*
 * Clock Settings
 *	CCLK = (CLKIN * VCO_MULT) / CCLK_DIV
 *	SCLK = (CLKIN * VCO_MULT) / SCLK_DIV
 */
/* CONFIG_CLKIN_HZ is any value in Hz					*/
#define CONFIG_CLKIN_HZ			25000000
/* CLKIN_HALF controls the DF bit in PLL_CTL      0 = CLKIN		*/
/*                                                1 = CLKIN / 2		*/
#define CONFIG_CLKIN_HALF		0
/* PLL_BYPASS controls the BYPASS bit in PLL_CTL  0 = do not bypass	*/
/*                                                1 = bypass PLL	*/
#define CONFIG_PLL_BYPASS		0
/* VCO_MULT controls the MSEL (multiplier) bits in PLL_CTL		*/
/* Values can range from 0-63 (where 0 means 64)			*/
#define CONFIG_VCO_MULT			21
/* CCLK_DIV controls the core clock divider				*/
/* Values can be 1, 2, 4, or 8 ONLY					*/
#define CONFIG_CCLK_DIV			1
/* SCLK_DIV controls the system clock divider				*/
/* Values can range from 1-15						*/
#define CONFIG_SCLK_DIV			4


/*
 * Memory Settings
 */
#define CONFIG_MEM_ADD_WDTH	9
#define CONFIG_MEM_SIZE		32

#define CONFIG_EBIU_SDRRC_VAL	0x3f8
#define CONFIG_EBIU_SDGCTL_VAL	0x9111cd
#define CONFIG_EBIU_SDBCTL_VAL	(EBSZ_32 | EBCAW_9 | EBE)

#define CONFIG_EBIU_AMGCTL_VAL	(AMBEN_ALL)
#define CONFIG_EBIU_AMBCTL0_VAL	(B1WAT_7 | B1RAT_11 | B1HT_2 | B1ST_3 | B0WAT_7 | B0RAT_11 | B0HT_2 | B0ST_3)
#define CONFIG_EBIU_AMBCTL1_VAL	(B3WAT_7 | B3RAT_11 | B3HT_2 | B3ST_3 | B2WAT_7 | B2RAT_11 | B2HT_2 | B2ST_3)

#define	CFG_MONITOR_LEN		(256 * 1024)	/* Reserve 256 kB for monitor */
#define	CFG_MALLOC_LEN		(128 * 1024)	/* Reserve 128 kB for malloc() */


/*
 * NAND Settings
 * (can't be used sametime as ethernet)
 */
/* #define CONFIG_BFIN_NFC */
#ifdef CONFIG_BFIN_NFC
#define CFG_BFIN_NFC_CTL_VAL	0x0033
#define CFG_NAND_BASE		0 /* not actually used */
#define CFG_MAX_NAND_DEVICE	1
#define NAND_MAX_CHIPS		1
#define ADI_CMDS_EXTRA		CFG_CMD_NAND
#endif


/*
 * Network Settings
 */
#if !defined(__ADSPBF522__) && !defined(__ADSPBF523__) && \
    !defined(__ADSPBF524__) && !defined(__ADSPBF525__) && !defined(CONFIG_BFIN_NFC)
#define ADI_CMDS_NETWORK	1
#define CONFIG_BFIN_MAC
#define CONFIG_BFIN_MAC_RMII
#define CONFIG_NETCONSOLE	1
#define CONFIG_NET_MULTI	1
#endif
#define CONFIG_HOSTNAME		CM-BF527
/* Uncomment next line to use fixed MAC address */
/* #define CONFIG_ETHADDR	02:80:ad:20:31:e8 */


/*
 * Flash Settings
 */
#define CFG_FLASH_BASE		0x20000000
#define CFG_FLASH_CFI		/* The flash is CFI compatible */
#define CFG_FLASH_CFI_DRIVER	/* Use common CFI driver */
#define CFG_FLASH_PROTECTION
#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CFG_MAX_FLASH_SECT	259	/* max number of sectors on one chip */

#if (CONFIG_BFIN_BOOT_MODE == BFIN_BOOT_SPI_MASTER)
#define CFG_ENV_IS_IN_EEPROM	1
#define CFG_ENV_OFFSET		0x4000
#else
#define	CFG_ENV_IS_IN_FLASH	1
#define CFG_ENV_ADDR		0x20002000
#define CFG_ENV_OFFSET		(CFG_ENV_ADDR - CFG_FLASH_BASE)
#endif
#define CFG_ENV_SIZE		0x2000
#define	CFG_ENV_SECT_SIZE	0x20000	/* Total Size of Environment Sector */
#define ENV_IS_EMBEDDED_CUSTOM

/* CONFIG_SPI_BAUD controls the SPI peripheral clock divider		*/
/* Values can range from 2-65535					*/
/* SCK Frequency = SCLK / (2 * CONFIG_SPI_BAUD)				*/
#define CONFIG_SPI
#define CONFIG_SPI_BAUD			2
#define CONFIG_SPI_BAUD_INITBLOCK	4


/*
 * I2C Settings
 */
#define CONFIG_HARD_I2C		1	/* I2C TWI */
#define CFG_I2C_SPEED		50000
#define CFG_I2C_SLAVE		0


/*
 * Misc Settings
 */
#define CONFIG_BAUDRATE		115200
#define CONFIG_MISC_INIT_R
#define CONFIG_RTC_BFIN
#define CONFIG_UART_CONSOLE	0

#define CONFIG_BFIN_COMMANDS \
	(CFG_BFIN_CMD_BOOTLDR | \
	 CFG_BFIN_CMD_CPLBINFO | \
	 CFG_BFIN_CMD_OTP)


/*
 * Pull in common ADI header for remaining command/environment setup
 */
#include <configs/bfin_adi_common.h>

#include <asm/blackfin-config-post.h>

#endif