#ifndef STM8S_H
#define STM8S_H

#include <stdint.h>

#define _MEM_(mem_addr)      (*(volatile uint8_t *)(mem_addr))
#define _SFR_(mem_addr)      (*(volatile uint8_t *)((mem_addr)))
#define _SFR16_(mem_addr)    (*(volatile uint16_t *)((mem_addr)))

/* PORT A */
#define PA_BASE_ADDRESS         0x5000
#define PA_ODR                  _SFR_(PA_BASE_ADDRESS + 0x00)
#define PA_IDR                  _SFR_(PA_BASE_ADDRESS + 0x01)
#define PA_DDR                  _SFR_(PA_BASE_ADDRESS + 0x02)
#define PA_CR1                  _SFR_(PA_BASE_ADDRESS + 0x03)
#define PA_CR2                  _SFR_(PA_BASE_ADDRESS + 0x04)

/* PORT B */
#define PB_BASE_ADDRESS         0x5005
#define PB_ODR                  _SFR_(PB_BASE_ADDRESS + 0x00)
#define PB_IDR                  _SFR_(PB_BASE_ADDRESS + 0x01)
#define PB_DDR                  _SFR_(PB_BASE_ADDRESS + 0x02)
#define PB_CR1                  _SFR_(PB_BASE_ADDRESS + 0x03)
#define PB_CR2                  _SFR_(PB_BASE_ADDRESS + 0x04)

/* PORT C */
#define PC_BASE_ADDRESS         0x500A
#define PC_ODR                  _SFR_(PC_BASE_ADDRESS + 0x00)
#define PC_IDR                  _SFR_(PC_BASE_ADDRESS + 0x01)
#define PC_DDR                  _SFR_(PC_BASE_ADDRESS + 0x02)
#define PC_CR1                  _SFR_(PC_BASE_ADDRESS + 0x03)
#define PC_CR2                  _SFR_(PC_BASE_ADDRESS + 0x04)

/* PORT D */
#define PD_BASE_ADDRESS         0x500F
#define PD_ODR                  _SFR_(PD_BASE_ADDRESS + 0x00)
#define PD_IDR                  _SFR_(PD_BASE_ADDRESS + 0x01)
#define PD_DDR                  _SFR_(PD_BASE_ADDRESS + 0x02)
#define PD_CR1                  _SFR_(PD_BASE_ADDRESS + 0x03)
#define PD_CR2                  _SFR_(PD_BASE_ADDRESS + 0x04)

/* PORT E */
#define PE_BASE_ADDRESS         0x5014
#define PE_ODR                  _SFR_(PE_BASE_ADDRESS + 0x00)
#define PE_IDR                  _SFR_(PE_BASE_ADDRESS + 0x01)
#define PE_DDR                  _SFR_(PE_BASE_ADDRESS + 0x02)
#define PE_CR1                  _SFR_(PE_BASE_ADDRESS + 0x03)
#define PE_CR2                  _SFR_(PE_BASE_ADDRESS + 0x04)

/* PORT F */
#define PF_BASE_ADDRESS         0x5019
#define PF_ODR                  _SFR_(PF_BASE_ADDRESS + 0x00)
#define PF_IDR                  _SFR_(PF_BASE_ADDRESS + 0x01)
#define PF_DDR                  _SFR_(PF_BASE_ADDRESS + 0x02)
#define PF_CR1                  _SFR_(PF_BASE_ADDRESS + 0x03)
#define PF_CR2                  _SFR_(PF_BASE_ADDRESS + 0x04)

/* PORT G */
#define PG_BASE_ADDRESS         0x501E
#define PG_ODR                  _SFR_(PG_BASE_ADDRESS + 0x00)
#define PG_IDR                  _SFR_(PG_BASE_ADDRESS + 0x01)
#define PG_DDR                  _SFR_(PG_BASE_ADDRESS + 0x02)
#define PG_CR1                  _SFR_(PG_BASE_ADDRESS + 0x03)
#define PG_CR2                  _SFR_(PG_BASE_ADDRESS + 0x04)

/* PORT H */
#define PH_BASE_ADDRESS         0x5023
#define PH_ODR                  _SFR_(PH_BASE_ADDRESS + 0x00)
#define PH_IDR                  _SFR_(PH_BASE_ADDRESS + 0x01)
#define PH_DDR                  _SFR_(PH_BASE_ADDRESS + 0x02)
#define PH_CR1                  _SFR_(PH_BASE_ADDRESS + 0x03)
#define PH_CR2                  _SFR_(PH_BASE_ADDRESS + 0x04)

/* PORT I */
#define PI_BASE_ADDRESS         0x5028
#define PI_ODR                  _SFR_(PI_BASE_ADDRESS + 0x00)
#define PI_IDR                  _SFR_(PI_BASE_ADDRESS + 0x01)
#define PI_DDR                  _SFR_(PI_BASE_ADDRESS + 0x02)
#define PI_CR1                  _SFR_(PI_BASE_ADDRESS + 0x03)
#define PI_CR2                  _SFR_(PI_BASE_ADDRESS + 0x04)

/* Flash */
#define FLASH_BASE_ADDRESS      0x505A
#define FLASH_CR1               _SFR_(FLASH_BASE_ADDRESS + 0x00)
#define FLASH_CR1_HALT          3
#define FLASH_CR1_AHALT         2
#define FLASH_CR1_IE            1
#define FLASH_CR1_FIX           0
#define FLASH_CR2               _SFR_(FLASH_BASE_ADDRESS + 0x01)
#define FLASH_CR2_OPT           7
#define FLASH_CR2_WPRG          6
#define FLASH_CR2_ERASE         5
#define FLASH_CR2_FPRG          4
#define FLASH_CR2_PRG           0
#define FLASH_NCR2              _SFR_(FLASH_BASE_ADDRESS + 0x02)
#define FLASH_NCR2_NOPT         7
#define FLASH_NCR2_NWPRG        6
#define FLASH_NCR2_NERASE       5
#define FLASH_NCR2_NFPRG        4
#define FLASH_NCR2_NPRG         0
#define FLASH_FPR               _SFR_(FLASH_BASE_ADDRESS + 0x03)
#define FLASH_NFPR              _SFR_(FLASH_BASE_ADDRESS + 0x04)
#define FLASH_IAPSR             _SFR_(FLASH_BASE_ADDRESS + 0x05)
#define FLASH_IAPSR_DUL         3
#define FLASH_IAPSR_EOP         2
#define FLASH_IAPSR_PUL         1
#define FLASH_PUKR              _SFR_(FLASH_BASE_ADDRESS + 0x08)
#define FLASH_PUKR_KEY1         0x56
#define FLASH_PUKR_KEY2         0xAE
#define FLASH_DUKR              _SFR_(FLASH_BASE_ADDRESS + 0x0A)
#define FLASH_DUKR_KEY1         FLASH_PUKR_KEY2
#define FLASH_DUKR_KEY2         FLASH_PUKR_KEY1

/* EXTI */
#define EXTI_BASE_ADDRESS       0x50A0
#define EXTI_CR1                _SFR_(EXTI_BASE_ADDRESS + 0x00)
#define EXTI_CR2                _SFR_(EXTI_BASE_ADDRESS + 0x01)

/* RST */
#define RST_BASE_ADDRESS        0x50B3
#define RST_SR                  _SFR_(RST_BASE_ADDRESS + 0x00)

/* Clock */
#define CLK_BASE_ADDRESS        0x50C0
#define CLK_ICKR                _SFR_(CLK_BASE_ADDRESS + 0x00)
#define CLK_ICKR_REGAH          5
#define CLK_ICKR_LSIRDY         4
#define CLK_ICKR_LSIEN          3
#define CLK_ICKR_FHWU           2
#define CLK_ICKR_HSIRDY         1
#define CLK_ICKR_HSIEN          0
#define CLK_ECKR                _SFR_(CLK_BASE_ADDRESS + 0x01)
#define CLK_ECKR_HSERDY         1
#define CLK_ECKR_HSEEN          0
#define CLK_CMSR                _SFR_(CLK_BASE_ADDRESS + 0x03)
#define CLK_SWR                 _SFR_(CLK_BASE_ADDRESS + 0x04)
#define CLK_SWCR                _SFR_(CLK_BASE_ADDRESS + 0x05)
#define CLK_SWCR_SWIF           3
#define CLK_SWCR_SWIEN          2
#define CLK_SWCR_SWEN           1
#define CLK_SWCR_SWBSY          0
#define CLK_CKDIVR              _SFR_(CLK_BASE_ADDRESS + 0x06)
#define CLK_PCKENR1             _SFR_(CLK_BASE_ADDRESS + 0x07)
#define CLK_CSSR                _SFR_(CLK_BASE_ADDRESS + 0x08)
#define CLK_CCOR                _SFR_(CLK_BASE_ADDRESS + 0x09)
#define CLK_CCOR_CCOEN          0
#define CLK_PCKENR2             _SFR_(CLK_BASE_ADDRESS + 0x0A)
#define CLK_HSITRIMR            _SFR_(CLK_BASE_ADDRESS + 0x0C)
#define CLK_SWIMCCR             _SFR_(CLK_BASE_ADDRESS + 0x0D)

/* Window Watchdog */
#define WWDG_BASE_ADDRESS       0x50D1
#define WWDG_CR                 _SFR_(WWDG_BASE_ADDRESS + 0x00)
#define WWDG_WR                 _SFR_(WWDG_BASE_ADDRESS + 0x01)

/* Independent Watchdog */
#define IWDG_BASE_ADDRESS       0x50E0
#define IWDG_KR                 _SFR_(IWDG_BASE_ADDRESS + 0x00)
#define IWDG_KEY_ENABLE         0xCC
#define IWDG_KEY_REFRESH        0xAA
#define IWDG_KEY_ACCESS         0x55
#define IWDG_PR                 _SFR_(IWDG_BASE_ADDRESS + 0x01)
#define IWDG_RLR                _SFR_(IWDG_BASE_ADDRESS + 0x02)

/* Auto-Wakeup */
#define AWU_BASE_ADDRESS        0x50F0
#define AWU_CSR                 _SFR_(AWU_BASE_ADDRESS + 0x00)
#define AWU_CSR_AWUF            5
#define AWU_CSR_AWUEN           4
#define AWU_CSR_MSR             0
#define AWU_APR                 _SFR_(AWU_BASE_ADDRESS + 0x01)
#define AWU_TBR                 _SFR_(AWU_BASE_ADDRESS + 0x02)

/* Beeper */
#define BEEP_BASE_ADDRESS       0x50F3
#define BEEP_CSR                _SFR_(BEEP_BASE_ADDRESS + 0x00)

/* SPI */
#define SPI_BASE_ADDRESS        0x5200
#define SPI_CR1                 _SFR_(SPI_BASE_ADDRESS + 0x00)
#define SPI_CR1_LSBFIRST        7
#define SPI_CR1_SPE             6
#define SPI_CR1_BR2             5
#define SPI_CR1_BR1             4
#define SPI_CR1_BR0             3
#define SPI_CR1_MSTR            2
#define SPI_CR1_CPOL            1
#define SPI_CR1_CPHA            0
#define SPI_CR2                 _SFR_(SPI_BASE_ADDRESS + 0x01)
#define SPI_CR2_BDM             7
#define SPI_CR2_BDOE            6
#define SPI_CR2_CRCEN           5
#define SPI_CR2_CRCNEXT         4
#define SPI_CR2_RXONLY          2
#define SPI_CR2_SSM             1
#define SPI_CR2_SSI             0
#define SPI_ICR                 _SFR_(SPI_BASE_ADDRESS + 0x02)
#define SPI_SR                  _SFR_(SPI_BASE_ADDRESS + 0x03)
#define SPI_SR_BSY              7
#define SPI_SR_OVR              6
#define SPI_SR_MODF             5
#define SPI_SR_CRCERR           4
#define SPI_SR_WKUP             3
#define SPI_SR_TXE              1
#define SPI_SR_RXNE             0
#define SPI_DR                  _SFR_(SPI_BASE_ADDRESS + 0x04)
#define SPI_CRCPR               _SFR_(SPI_BASE_ADDRESS + 0x05)
#define SPI_RXCRCR              _SFR_(SPI_BASE_ADDRESS + 0x06)
#define SPI_TXCRCR              _SFR_(SPI_BASE_ADDRESS + 0x07)

/* I2C */
#define I2C_BASE_ADDRESS        0x5210
#define I2C_CR1                 _SFR_(I2C_BASE_ADDRESS + 0x00)
#define I2C_CR1_PE              0
#define I2C_CR2                 _SFR_(I2C_BASE_ADDRESS + 0x01)
#define I2C_CR2_ACK             2
#define I2C_CR2_STOP            1
#define I2C_CR2_START           0
#define I2C_FREQR               _SFR_(I2C_BASE_ADDRESS + 0x02)
#define I2C_FREQR_FREQ2         2
#define I2C_FREQR_FREQ1         1
#define I2C_FREQR_FREQ0         0
#define I2C_OARL                _SFR_(I2C_BASE_ADDRESS + 0x03)
#define I2C_OARH                _SFR_(I2C_BASE_ADDRESS + 0x04)
#define I2C_OARH_ADDMODE        7
#define I2C_OARH_ADDCONF        6
#define I2C_DR                  _SFR_(I2C_BASE_ADDRESS + 0x06)
#define I2C_SR1                 _SFR_(I2C_BASE_ADDRESS + 0x07)
#define I2C_SR1_TXE             7
#define I2C_SR1_RXNE            6
#define I2C_SR1_BTF             2
#define I2C_SR1_ADDR            1
#define I2C_SR1_SB              0
#define I2C_SR2                 _SFR_(I2C_BASE_ADDRESS + 0x08)
#define I2C_SR3                 _SFR_(I2C_BASE_ADDRESS + 0x09)
#define I2C_SR3_BUSY            1
#define I2C_SR3_MSL             0
#define I2C_ITR                 _SFR_(I2C_BASE_ADDRESS + 0x0A)
#define I2C_CCRL                _SFR_(I2C_BASE_ADDRESS + 0x0B)
#define I2C_CCRH                _SFR_(I2C_BASE_ADDRESS + 0x0C)
#define I2C_TRISER              _SFR_(I2C_BASE_ADDRESS + 0x0D)
#define I2C_PECR                _SFR_(I2C_BASE_ADDRESS + 0x0E)

/* UART1 (mutually exclusive with UART4) */
#define UART1_BASE_ADDRESS      0x5230
#define UART1_SR                _SFR_(UART1_BASE_ADDRESS + 0x00)
#define UART1_SR_TXE            7
#define UART1_SR_TC             6
#define UART1_SR_RXNE           5
#define UART1_DR                _SFR_(UART1_BASE_ADDRESS + 0x01)
#define UART1_BRR1              _SFR_(UART1_BASE_ADDRESS + 0x02)
#define UART1_BRR2              _SFR_(UART1_BASE_ADDRESS + 0x03)
#define UART1_CR1               _SFR_(UART1_BASE_ADDRESS + 0x04)
#define UART1_CR2               _SFR_(UART1_BASE_ADDRESS + 0x05)
#define UART1_CR2_TEN           3
#define UART1_CR2_REN           2
#define UART1_CR3               _SFR_(UART1_BASE_ADDRESS + 0x06)
#define UART1_CR4               _SFR_(UART1_BASE_ADDRESS + 0x07)
#define UART1_CR5               _SFR_(UART1_BASE_ADDRESS + 0x08)
#define UART1_GTR               _SFR_(UART1_BASE_ADDRESS + 0x09)
#define UART1_PSCR              _SFR_(UART1_BASE_ADDRESS + 0x0A)

/* UART2 (mutually exclusive with UART3) */
#define UART2_BASE_ADDRESS      0x5240
#define UART2_SR                _SFR_(UART2_BASE_ADDRESS + 0x00)
#define UART2_SR_TXE            7
#define UART2_SR_TC             6
#define UART2_SR_RXNE           5
#define UART2_DR                _SFR_(UART2_BASE_ADDRESS + 0x01)
#define UART2_BRR1              _SFR_(UART2_BASE_ADDRESS + 0x02)
#define UART2_BRR2              _SFR_(UART2_BASE_ADDRESS + 0x03)
#define UART2_CR1               _SFR_(UART2_BASE_ADDRESS + 0x04)
#define UART2_CR2               _SFR_(UART2_BASE_ADDRESS + 0x05)
#define UART2_CR2_TEN           3
#define UART2_CR2_REN           2
#define UART2_CR3               _SFR_(UART2_BASE_ADDRESS + 0x06)
#define UART2_CR4               _SFR_(UART2_BASE_ADDRESS + 0x07)
#define UART2_CR5               _SFR_(UART2_BASE_ADDRESS + 0x08)
#define UART2_CR6               _SFR_(UART2_BASE_ADDRESS + 0x09)
#define UART2_GTR               _SFR_(UART2_BASE_ADDRESS + 0x0A)
#define UART2_PSCR              _SFR_(UART2_BASE_ADDRESS + 0x0B)

/* UART3 (mutually exclusive with UART2) */
#define UART3_BASE_ADDRESS      0x5240
#define UART3_SR                _SFR_(UART3_BASE_ADDRESS + 0x00)
#define UART3_SR_TXE            7
#define UART3_SR_TC             6
#define UART3_SR_RXNE           5
#define UART3_DR                _SFR_(UART3_BASE_ADDRESS + 0x01)
#define UART3_BRR1              _SFR_(UART3_BASE_ADDRESS + 0x02)
#define UART3_BRR2              _SFR_(UART3_BASE_ADDRESS + 0x03)
#define UART3_CR1               _SFR_(UART3_BASE_ADDRESS + 0x04)
#define UART3_CR2               _SFR_(UART3_BASE_ADDRESS + 0x05)
#define UART3_CR2_TEN           3
#define UART3_CR2_REN           2
#define UART3_CR3               _SFR_(UART3_BASE_ADDRESS + 0x06)
#define UART3_CR4               _SFR_(UART3_BASE_ADDRESS + 0x07)
#define UART3_CR6               _SFR_(UART3_BASE_ADDRESS + 0x09)

/* UART4 (mutually exclusive with UART1) */
#define UART4_BASE_ADDRESS      0x5230
#define UART4_SR                _SFR_(UART4_BASE_ADDRESS + 0x00)
#define UART4_SR_TXE            7
#define UART4_SR_TC             6
#define UART4_SR_RXNE           5
#define UART4_DR                _SFR_(UART4_BASE_ADDRESS + 0x01)
#define UART4_BRR1              _SFR_(UART4_BASE_ADDRESS + 0x02)
#define UART4_BRR2              _SFR_(UART4_BASE_ADDRESS + 0x03)
#define UART4_CR1               _SFR_(UART4_BASE_ADDRESS + 0x04)
#define UART4_CR2               _SFR_(UART4_BASE_ADDRESS + 0x05)
#define UART4_CR2_TEN           3
#define UART4_CR2_REN           2
#define UART4_CR3               _SFR_(UART4_BASE_ADDRESS + 0x06)
#define UART4_CR4               _SFR_(UART4_BASE_ADDRESS + 0x07)
#define UART4_CR6               _SFR_(UART4_BASE_ADDRESS + 0x09)
#define UART4_GTR               _SFR_(UART4_BASE_ADDRESS + 0x0A)
#define UART4_PSCR              _SFR_(UART4_BASE_ADDRESS + 0x0B)

/* TIM1 */
#define TIM1_BASE_ADDRESS       0x5250
#define TIM1_CR1                _SFR_(TIM1_BASE_ADDRESS + 0x00)
#define TIM1_CR2                _SFR_(TIM1_BASE_ADDRESS + 0x01)
#define TIM1_SMCR               _SFR_(TIM1_BASE_ADDRESS + 0x02)
#define TIM1_ETR                _SFR_(TIM1_BASE_ADDRESS + 0x03)
#define TIM1_IER                _SFR_(TIM1_BASE_ADDRESS + 0x04)
#define TIM1_SR1                _SFR_(TIM1_BASE_ADDRESS + 0x05)
#define TIM1_SR2                _SFR_(TIM1_BASE_ADDRESS + 0x06)
#define TIM1_EGR                _SFR_(TIM1_BASE_ADDRESS + 0x07)
#define TIM1_CCMR1              _SFR_(TIM1_BASE_ADDRESS + 0x08)
#define TIM1_CCMR2              _SFR_(TIM1_BASE_ADDRESS + 0x09)
#define TIM1_CCMR3              _SFR_(TIM1_BASE_ADDRESS + 0x0A)
#define TIM1_CCMR4              _SFR_(TIM1_BASE_ADDRESS + 0x0B)
#define TIM1_CCER1              _SFR_(TIM1_BASE_ADDRESS + 0x0C)
#define TIM1_CCER2              _SFR_(TIM1_BASE_ADDRESS + 0x0D)
#define TIM1_CNTR               _SFR16_(TIM1_BASE_ADDRESS + 0x0E)
#define TIM1_CNTRH              _SFR_(TIM1_BASE_ADDRESS + 0x0E)
#define TIM1_CNTRL              _SFR_(TIM1_BASE_ADDRESS + 0x0F)
#define TIM1_PSCR               _SFR16_(TIM1_BASE_ADDRESS + 0x10)
#define TIM1_PSCRH              _SFR_(TIM1_BASE_ADDRESS + 0x10)
#define TIM1_PSCRL              _SFR_(TIM1_BASE_ADDRESS + 0x11)
#define TIM1_ARR                _SFR16_(TIM1_BASE_ADDRESS + 0x12)
#define TIM1_ARRH               _SFR_(TIM1_BASE_ADDRESS + 0x12)
#define TIM1_ARRL               _SFR_(TIM1_BASE_ADDRESS + 0x13)
#define TIM1_RCR                _SFR_(TIM1_BASE_ADDRESS + 0x14)
#define TIM1_CCR1               _SFR16_(TIM1_BASE_ADDRESS + 0x15)
#define TIM1_CCR1H              _SFR_(TIM1_BASE_ADDRESS + 0x15)
#define TIM1_CCR1L              _SFR_(TIM1_BASE_ADDRESS + 0x16)
#define TIM1_CCR2               _SFR16_(TIM1_BASE_ADDRESS + 0x17)
#define TIM1_CCR2H              _SFR_(TIM1_BASE_ADDRESS + 0x17)
#define TIM1_CCR2L              _SFR_(TIM1_BASE_ADDRESS + 0x18)
#define TIM1_CCR3               _SFR16_(TIM1_BASE_ADDRESS + 0x19)
#define TIM1_CCR3H              _SFR_(TIM1_BASE_ADDRESS + 0x19)
#define TIM1_CCR3L              _SFR_(TIM1_BASE_ADDRESS + 0x1A)
#define TIM1_CCR4               _SFR16_(TIM1_BASE_ADDRESS + 0x1B)
#define TIM1_CCR4H              _SFR_(TIM1_BASE_ADDRESS + 0x1B)
#define TIM1_CCR4L              _SFR_(TIM1_BASE_ADDRESS + 0x1C)
#define TIM1_BKR                _SFR_(TIM1_BASE_ADDRESS + 0x1D)
#define TIM1_DTR                _SFR_(TIM1_BASE_ADDRESS + 0x1E)
#define TIM1_OISR               _SFR_(TIM1_BASE_ADDRESS + 0x1F)

/* TIM2 (mutually exclusive with TIM5) */
#define TIM2_BASE_ADDRESS       5300
#define TIM2_CR1                _SFR_(TIM2_BASE_ADDRESS + 0x00)
#define TIM2_CR1_ARPE           7
#define TIM2_CR1_OPM            3
#define TIM2_CR1_URS            2
#define TIM2_CR1_UDIS           1
#define TIM2_CR1_CEN            0
#define TIM2_IER                _SFR_(TIM2_BASE_ADDRESS + 0x03)
#define TIM2_SR1                _SFR_(TIM2_BASE_ADDRESS + 0x04)
#define TIM2_SR2                _SFR_(TIM2_BASE_ADDRESS + 0x05)
#define TIM2_EGR                _SFR_(TIM2_BASE_ADDRESS + 0x06)
#define TIM2_EGR_TG             6
#define TIM2_EGR_CC3G           3
#define TIM2_EGR_CC2G           2
#define TIM2_EGR_CC1G           1
#define TIM2_EGR_UG             0
#define TIM2_CCMR1              _SFR_(TIM2_BASE_ADDRESS + 0x07)
#define TIM2_CCMR2              _SFR_(TIM2_BASE_ADDRESS + 0x08)
#define TIM2_CCMR3              _SFR_(TIM2_BASE_ADDRESS + 0x09)
#define TIM2_CCER1              _SFR_(TIM2_BASE_ADDRESS + 0x0A)
#define TIM2_CCER2              _SFR_(TIM2_BASE_ADDRESS + 0x0B)
#define TIM2_CNTR               _SFR16_(TIM2_BASE_ADDRESS + 0x0C)
#define TIM2_CNTRH              _SFR_(TIM2_BASE_ADDRESS + 0x0C)
#define TIM2_CNTRL              _SFR_(TIM2_BASE_ADDRESS + 0x0D)
#define TIM2_PSCR               _SFR_(TIM2_BASE_ADDRESS + 0x0E)
#define TIM2_ARR                _SFR16_(TIM2_BASE_ADDRESS + 0x0F)
#define TIM2_ARRH               _SFR_(TIM2_BASE_ADDRESS + 0x0F)
#define TIM2_ARRL               _SFR_(TIM2_BASE_ADDRESS + 0x10)
#define TIM2_CCR1               _SFR16_(TIM2_BASE_ADDRESS + 0x11)
#define TIM2_CCR1H              _SFR_(TIM2_BASE_ADDRESS + 0x11)
#define TIM2_CCR1L              _SFR_(TIM2_BASE_ADDRESS + 0x12)
#define TIM2_CCR2               _SFR16_(TIM2_BASE_ADDRESS + 0x13)
#define TIM2_CCR2H              _SFR_(TIM2_BASE_ADDRESS + 0x13)
#define TIM2_CCR2L              _SFR_(TIM2_BASE_ADDRESS + 0x14)
#define TIM2_CCR3               _SFR16_(TIM2_BASE_ADDRESS + 0x15)
#define TIM2_CCR3H              _SFR_(TIM2_BASE_ADDRESS + 0x15)
#define TIM2_CCR3L              _SFR_(TIM2_BASE_ADDRESS + 0x16)

/* TIM3 */
#define TIM3_BASE_ADDRESS       0x5320
#define TIM3_CR1                _SFR_(TIM3_BASE_ADDRESS + 0x00)
#define TIM3_CR1_ARPE           7
#define TIM3_CR1_OPM            3
#define TIM3_CR1_URS            2
#define TIM3_CR1_UDIS           1
#define TIM3_CR1_CEN            0
#define TIM3_IER                _SFR_(TIM3_BASE_ADDRESS + 0x01)
#define TIM3_SR1                _SFR_(TIM3_BASE_ADDRESS + 0x02)
#define TIM3_SR2                _SFR_(TIM3_BASE_ADDRESS + 0x03)
#define TIM3_EGR                _SFR_(TIM3_BASE_ADDRESS + 0x04)
#define TIM3_EGR_CC2G           2
#define TIM3_EGR_CC1G           1
#define TIM3_EGR_UG             0
#define TIM3_CCMR1              _SFR_(TIM3_BASE_ADDRESS + 0x05)
#define TIM3_CCMR2              _SFR_(TIM3_BASE_ADDRESS + 0x06)
#define TIM3_CCER1              _SFR_(TIM3_BASE_ADDRESS + 0x07)
#define TIM3_CNTR               _SFR16_(TIM3_BASE_ADDRESS + 0x08)
#define TIM3_CNTRH              _SFR_(TIM3_BASE_ADDRESS + 0x08)
#define TIM3_CNTRL              _SFR_(TIM3_BASE_ADDRESS + 0x09)
#define TIM3_PSCR               _SFR_(TIM3_BASE_ADDRESS + 0x0A)
#define TIM3_ARR                _SFR16_(TIM3_BASE_ADDRESS + 0x0B)
#define TIM3_ARRH               _SFR_(TIM3_BASE_ADDRESS + 0x0B)
#define TIM3_ARRL               _SFR_(TIM3_BASE_ADDRESS + 0x0C)
#define TIM3_CCR1               _SFR16_(TIM3_BASE_ADDRESS + 0x0D)
#define TIM3_CCR1H              _SFR_(TIM3_BASE_ADDRESS + 0x0D)
#define TIM3_CCR1L              _SFR_(TIM3_BASE_ADDRESS + 0x0E)
#define TIM3_CCR2               _SFR16_(TIM3_BASE_ADDRESS + 0x0F)
#define TIM3_CCR2H              _SFR_(TIM3_BASE_ADDRESS + 0x0F)
#define TIM3_CCR2L              _SFR_(TIM3_BASE_ADDRESS + 0x10)

/* TIM4 (mutually exclusive with TIM6) */
#define TIM4_BASE_ADDRESS       0x5340
#define TIM4_CR1                _SFR_(TIM4_BASE_ADDRESS + 0x00)
#define TIM4_CR1_ARPE           7
#define TIM4_CR1_OPM            3
#define TIM4_CR1_URS            2
#define TIM4_CR1_UDIS           1
#define TIM4_CR1_CEN            0
#define TIM4_IER                _SFR_(TIM4_BASE_ADDRESS + 0x03)
#define TIM4_IER_UIE            0
#define TIM4_SR                 _SFR_(TIM4_BASE_ADDRESS + 0x04)
#define TIM4_SR_UIF             0
#define TIM4_EGR                _SFR_(TIM4_BASE_ADDRESS + 0x05)
#define TIM4_CNTR               _SFR_(TIM4_BASE_ADDRESS + 0x06)
#define TIM4_PSCR               _SFR_(TIM4_BASE_ADDRESS + 0x07)
#define TIM4_ARR                _SFR_(TIM4_BASE_ADDRESS + 0x08)

/* TIM5 (mutually exclusive with TIM2) */
#define TIM5_BASE_ADDRESS       5300
#define TIM5_CR1                _SFR_(TIM5_BASE_ADDRESS + 0x00)
#define TIM5_CR1_ARPE           7
#define TIM5_CR1_OPM            3
#define TIM5_CR1_URS            2
#define TIM5_CR1_UDIS           1
#define TIM5_CR1_CEN            0
#define TIM5_CR2                _SFR_(TIM5_BASE_ADDRESS + 0x01)
#define TIM5_SMCR               _SFR_(TIM5_BASE_ADDRESS + 0x02)
#define TIM5_IER                _SFR_(TIM5_BASE_ADDRESS + 0x03)
#define TIM5_SR1                _SFR_(TIM5_BASE_ADDRESS + 0x04)
#define TIM5_SR2                _SFR_(TIM5_BASE_ADDRESS + 0x05)
#define TIM5_EGR                _SFR_(TIM5_BASE_ADDRESS + 0x06)
#define TIM5_EGR_TG             6
#define TIM5_EGR_CC3G           3
#define TIM5_EGR_CC2G           2
#define TIM5_EGR_CC1G           1
#define TIM5_EGR_UG             0
#define TIM5_CCMR1              _SFR_(TIM5_BASE_ADDRESS + 0x07)
#define TIM5_CCMR2              _SFR_(TIM5_BASE_ADDRESS + 0x08)
#define TIM5_CCMR3              _SFR_(TIM5_BASE_ADDRESS + 0x09)
#define TIM5_CCER1              _SFR_(TIM5_BASE_ADDRESS + 0x0A)
#define TIM5_CCER2              _SFR_(TIM5_BASE_ADDRESS + 0x0B)
#define TIM5_CNTR               _SFR16_(TIM5_BASE_ADDRESS + 0x0C)
#define TIM5_CNTRH              _SFR_(TIM5_BASE_ADDRESS + 0x0C)
#define TIM5_CNTRL              _SFR_(TIM5_BASE_ADDRESS + 0x0D)
#define TIM5_PSCR               _SFR_(TIM5_BASE_ADDRESS + 0x0E)
#define TIM5_ARR                _SFR16_(TIM5_BASE_ADDRESS + 0x0F)
#define TIM5_ARRH               _SFR_(TIM5_BASE_ADDRESS + 0x0F)
#define TIM5_ARRL               _SFR_(TIM5_BASE_ADDRESS + 0x10)
#define TIM5_CCR1               _SFR16_(TIM5_BASE_ADDRESS + 0x11)
#define TIM5_CCR1H              _SFR_(TIM5_BASE_ADDRESS + 0x11)
#define TIM5_CCR1L              _SFR_(TIM5_BASE_ADDRESS + 0x12)
#define TIM5_CCR2               _SFR16_(TIM5_BASE_ADDRESS + 0x13)
#define TIM5_CCR2H              _SFR_(TIM5_BASE_ADDRESS + 0x13)
#define TIM5_CCR2L              _SFR_(TIM5_BASE_ADDRESS + 0x14)
#define TIM5_CCR3               _SFR16_(TIM5_BASE_ADDRESS + 0x15)
#define TIM5_CCR3H              _SFR_(TIM5_BASE_ADDRESS + 0x15)
#define TIM5_CCR3L              _SFR_(TIM5_BASE_ADDRESS + 0x16)

/* TIM6 (mutually exclusive with TIM4) */
#define TIM6_BASE_ADDRESS       0x5340
#define TIM6_CR1                _SFR_(TIM6_BASE_ADDRESS + 0x00)
#define TIM6_CR1_ARPE           7
#define TIM6_CR1_OPM            3
#define TIM6_CR1_URS            2
#define TIM6_CR1_UDIS           1
#define TIM6_CR1_CEN            0
#define TIM6_CR2                _SFR_(TIM6_BASE_ADDRESS + 0x01)
#define TIM6_SMCR               _SFR_(TIM6_BASE_ADDRESS + 0x02)
#define TIM6_IER                _SFR_(TIM6_BASE_ADDRESS + 0x03)
#define TIM6_IER_UIE            0
#define TIM6_SR                 _SFR_(TIM6_BASE_ADDRESS + 0x04)
#define TIM6_SR_UIF             0
#define TIM6_EGR                _SFR_(TIM6_BASE_ADDRESS + 0x05)
#define TIM6_CNTR               _SFR_(TIM6_BASE_ADDRESS + 0x06)
#define TIM6_PSCR               _SFR_(TIM6_BASE_ADDRESS + 0x07)
#define TIM6_ARR                _SFR_(TIM6_BASE_ADDRESS + 0x08)

/* ADC1 (mutually exclusive with ADC2) */
#define ADC1_BASE_ADDRESS       0x53E0
#define ADC1_DB0R               _SFR16_(ADC1_BASE_ADDRESS + 0x00)
#define ADC1_DB0RH              _SFR_(ADC1_BASE_ADDRESS + 0x00)
#define ADC1_DB0RL              _SFR_(ADC1_BASE_ADDRESS + 0x01)
#define ADC1_DB7R               _SFR16_(ADC1_BASE_ADDRESS + 0x0E)
#define ADC1_DB7RH              _SFR_(ADC1_BASE_ADDRESS + 0x0E)
#define ADC1_DB7RL              _SFR_(ADC1_BASE_ADDRESS + 0x0F)
#define ADC1_DB8R               _SFR16_(ADC1_BASE_ADDRESS + 0x10)
#define ADC1_DB8RH              _SFR_(ADC1_BASE_ADDRESS + 0x10)
#define ADC1_DB8RL              _SFR_(ADC1_BASE_ADDRESS + 0x11)
#define ADC1_DB9R               _SFR16_(ADC1_BASE_ADDRESS + 0x12)
#define ADC1_DB9RH              _SFR_(ADC1_BASE_ADDRESS + 0x12)
#define ADC1_DB9RL              _SFR_(ADC1_BASE_ADDRESS + 0x13)
#define ADC1_CSR                _SFR_(ADC1_BASE_ADDRESS + 0x20)
#define ADC1_CSR_EOC            7
#define ADC1_CSR_AWD            6
#define ADC1_CSR_EOCIE          5
#define ADC1_CSR_CH3            3
#define ADC1_CSR_CH2            2
#define ADC1_CSR_CH1            1
#define ADC1_CSR_CH0            0
#define ADC1_CR1                _SFR_(ADC1_BASE_ADDRESS + 0x21)
#define ADC1_CR1_SPSEL2         6
#define ADC1_CR1_SPSEL1         5
#define ADC1_CR1_SPSEL0         4
#define ADC1_CR1_CONT           1
#define ADC1_CR1_ADON           0
#define ADC1_CR2                _SFR_(ADC1_BASE_ADDRESS + 0x22)
#define ADC1_CR2_EXTTRIG        6
#define ADC1_CR2_EXTSEL1        5
#define ADC1_CR2_EXTSEL0        4
#define ADC1_CR2_ALIGN          3
#define ADC1_CR2_SCAN           1
#define ADC1_CR3                _SFR_(ADC1_BASE_ADDRESS + 0x23)
#define ADC1_CR3_DBUF           7
#define ADC1_CR3_OVR            6
#define ADC1_DR                 _SFR16_(ADC1_BASE_ADDRESS + 0x24)
#define ADC1_DRH                _SFR_(ADC1_BASE_ADDRESS + 0x24)
#define ADC1_DRL                _SFR_(ADC1_BASE_ADDRESS + 0x25)
#define ADC1_TDR                _SFR16_(ADC1_BASE_ADDRESS + 0x26)
#define ADC1_TDRH               _SFR_(ADC1_BASE_ADDRESS + 0x26)
#define ADC1_TDRL               _SFR_(ADC1_BASE_ADDRESS + 0x27)
#define ADC1_HTR                _SFR16_(ADC1_BASE_ADDRESS + 0x28)
#define ADC1_HTRH               _SFR_(ADC1_BASE_ADDRESS + 0x28)
#define ADC1_HTRL               _SFR_(ADC1_BASE_ADDRESS + 0x29)
#define ADC1_LTR                _SFR16_(ADC1_BASE_ADDRESS + 0x2A)
#define ADC1_LTRH               _SFR_(ADC1_BASE_ADDRESS + 0x2A)
#define ADC1_LTRL               _SFR_(ADC1_BASE_ADDRESS + 0x2B)
#define ADC1_AWSR               _SFR16_(ADC1_BASE_ADDRESS + 0x2C)
#define ADC1_AWSRH              _SFR_(ADC1_BASE_ADDRESS + 0x2C)
#define ADC1_AWSRL              _SFR_(ADC1_BASE_ADDRESS + 0x2D)
#define ADC1_AWCR               _SFR16_(ADC1_BASE_ADDRESS + 0x2E)
#define ADC1_AWCRH              _SFR_(ADC1_BASE_ADDRESS + 0x2E)
#define ADC1_AWCRL              _SFR_(ADC1_BASE_ADDRESS + 0x2F)

/* ADC2 (mutually exclusive with ADC1) */
#define ADC2_BASE_ADDRESS       0x5400
#define ADC2_CSR                _SFR_(ADC2_BASE_ADDRESS + 0x20)
#define ADC2_CSR_EOC            7
#define ADC2_CSR_AWD            6
#define ADC2_CSR_EOCIE          5
#define ADC2_CSR_CH3            3
#define ADC2_CSR_CH2            2
#define ADC2_CSR_CH1            1
#define ADC2_CSR_CH0            0
#define ADC2_CR1                _SFR_(ADC2_BASE_ADDRESS + 0x21)
#define ADC2_CR1_SPSEL2         6
#define ADC2_CR1_SPSEL1         5
#define ADC2_CR1_SPSEL0         4
#define ADC2_CR1_CONT           1
#define ADC2_CR1_ADON           0
#define ADC2_CR2                _SFR_(ADC2_BASE_ADDRESS + 0x22)
#define ADC2_CR2_EXTTRIG        6
#define ADC2_CR2_EXTSEL1        5
#define ADC2_CR2_EXTSEL0        4
#define ADC2_CR2_ALIGN          3
#define ADC2_CR3                _SFR_(ADC2_BASE_ADDRESS + 0x23)
#define ADC2_CR3_DBUF           7
#define ADC2_CR3_OVR            6
#define ADC2_DR                 _SFR16_(ADC2_BASE_ADDRESS + 0x24)
#define ADC2_DRH                _SFR_(ADC2_BASE_ADDRESS + 0x24)
#define ADC2_DRL                _SFR_(ADC2_BASE_ADDRESS + 0x25)
#define ADC2_TDR                _SFR16_(ADC2_BASE_ADDRESS + 0x26)
#define ADC2_TDRH               _SFR_(ADC2_BASE_ADDRESS + 0x26)
#define ADC2_TDRL               _SFR_(ADC2_BASE_ADDRESS + 0x27)

/* beCAN */
#define CAN_BASE_ADDRESS        0x5420
#define CAN_MCR                 _SFR_(CAN_BASE_ADDRESS + 0x00)
#define CAN_MSR                 _SFR_(CAN_BASE_ADDRESS + 0x01)
#define CAN_TSR                 _SFR_(CAN_BASE_ADDRESS + 0x02)
#define CAN_TPR                 _SFR_(CAN_BASE_ADDRESS + 0x03)
#define CAN_RFR                 _SFR_(CAN_BASE_ADDRESS + 0x04)
#define CAN_IER                 _SFR_(CAN_BASE_ADDRESS + 0x05)
#define CAN_DGR                 _SFR_(CAN_BASE_ADDRESS + 0x06)
#define CAN_PSR                 _SFR_(CAN_BASE_ADDRESS + 0x07)

/* Global Configuration */
#define CFG_BASE_ADDRESS        0x7F60
#define CFG_GCR                 _SFR_(CFG_BASE_ADDRESS + 0x00)

/* Interrupt Priority */
#define ITC_BASE_ADDRESS        0x7F60
#define ITC_ISPR1               _SFR_(CFG_BASE_ADDRESS + 0x00)
#define ITC_ISPR2               _SFR_(CFG_BASE_ADDRESS + 0x01)
#define ITC_ISPR3               _SFR_(CFG_BASE_ADDRESS + 0x02)
#define ITC_ISPR4               _SFR_(CFG_BASE_ADDRESS + 0x03)
#define ITC_ISPR5               _SFR_(CFG_BASE_ADDRESS + 0x04)
#define ITC_ISPR6               _SFR_(CFG_BASE_ADDRESS + 0x05)
#define ITC_ISPR7               _SFR_(CFG_BASE_ADDRESS + 0x06)
#define ITC_ISPR8               _SFR_(CFG_BASE_ADDRESS + 0x07)

/* Interrupts */
#define TLI_ISR                 0
#define AWU_ISR                 1
#define CLK_ISR                 2
#define EXTI0_ISR               3
#define EXTI1_ISR               4
#define EXTI2_ISR               5
#define EXTI3_ISR               6
#define EXTI4_ISR               7
#define CAN_RX_ISR              8   /* dual use, device dependent */
#define EXTI5_ISR               8   /* dual use, device dependent */
#define CAN_TX_ISR              9
#define SPI_ISR                 10
#define TIM1_OVF_ISR            11
#define TIM1_CC_ISR             12
#define TIM2_OVF_ISR            13   /* dual use, device dependent */
#define TIM5_OVF_ISR            13   /* dual use, device dependent */
#define TIM2_CC_ISR             14   /* dual use, device dependent */
#define TIM5_CC_ISR             14   /* dual use, device dependent */
#define TIM3_OVF_ISR            15
#define TIM3_CC_ISR             16
#define UART1_TXC_ISR           17
#define UART1_RXC_ISR           18
#define I2C_ISR                 19
#define UART2_3_4_TXC_ISR       20
#define UART2_3_4_RXC_ISR       21
#define ADC1_ISR                22   /* dual use, device dependent */
#define ADC2_ISR                22   /* dual use, device dependent */
#define TIM4_ISR                23   /* dual use, device dependent */
#define TIM6_ISR                23   /* dual use, device dependent */
#define FLASH_ISR               24

/* CPU */
#define CPU_CCR                 _MEM_(0x7F0A)

/* misc inline macros */
#define enable_interrupts()     __asm__("rim");
#define disable_interrupts()    __asm__("sim");
#define nop()                   __asm__("nop");
#define halt()                  __asm__("halt");

#endif /* STM8S_H */
