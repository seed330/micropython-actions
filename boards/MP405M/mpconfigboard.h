#define MICROPY_HW_BOARD_NAME       "F411MIO"
#define MICROPY_HW_MCU_NAME         "STM32F411CE"

#define MICROPY_HW_HAS_SWITCH       (0)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_HAS_SDCARD       (0)
#define MICROPY_HW_HAS_MMA7660      (0)
#define MICROPY_HW_HAS_LCD          (0)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_RTC       (0)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_DAC       (0)
#define MICROPY_HW_ENABLE_USB       (1)

#define MICROPY_HW_FLASH_FS_LABEL "W25Q128"

// HSE is 12MHz
#define MICROPY_HW_CLK_PLLM (6)
#define MICROPY_HW_CLK_PLLN (96)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV2)
#define MICROPY_HW_CLK_PLLQ (4)
#define MICROPY_HW_CLK_LAST_FREQ (1)

// The pyboard has a 32kHz crystal for the RTC
#define MICROPY_HW_RTC_USE_LSE      (0)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// UART config

#define MICROPY_HW_UART1_TX     (pin_A9)
#define MICROPY_HW_UART1_RX     (pin_A10)

#define MICROPY_HW_UART2_TX     (pin_A2)
#define MICROPY_HW_UART2_RX     (pin_A3)

#define MICROPY_HW_UART6_TX     (pin_A11)
#define MICROPY_HW_UART6_RX     (pin_A12)

// I2C busses

#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)

#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B11)

#define MICROPY_HW_I2C3_SCL (pin_A8)
#define MICROPY_HW_I2C3_SDA (pin_B8)
// SPI busses

#define MICROPY_HW_SPI1_NSS  (pin_A4) 
#define MICROPY_HW_SPI1_SCK  (pin_A5) 
#define MICROPY_HW_SPI1_MISO (pin_A6) 
#define MICROPY_HW_SPI1_MOSI (pin_A7) 

#define MICROPY_HW_SPI2_NSS  (pin_B12) 
#define MICROPY_HW_SPI2_SCK  (pin_B13) 
#define MICROPY_HW_SPI2_MISO (pin_B14) 
#define MICROPY_HW_SPI2_MOSI (pin_B15) 


// USRSW has no pullup or pulldown, and pressing the switch makes the input go low
#define MICROPY_HW_USRSW_PIN        (pin_B3)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// The board led 
#define MICROPY_HW_LED1             (pin_B5) // green


// USB config
#define MICROPY_HW_USB_FS              (1)

#define MICROPY_PY_THREAD           (1)
// #define MICROPY_PY_THREAD_GIL       (1)

// #define MICROPY_PY_LWIP (1)
// #define MICROPY_PY_USOCKET    (1)
// #define MICROPY_PY_UWEBSOCKET (1)
// #define MICROPY_PY_WEBREPL (1)
// #define MICROPY_PY_USOCKET_EVENTS (MICROPY_PY_WEBREPL)
// #define MICROPY_PY_UHASHLIB_SHA1            (1)
// #define MICROPY_ME_SHA1                     (1)

// Bootloader configuration (only needed if Mboot is used)
// #define MBOOT_FSLOAD (1)
// #define MBOOT_SPIFLASH_ADDR (0x80000000) 
// #define MBOOT_SPIFLASH_BYTE_SIZE (16 * 1024 * 1024) 
// #define MBOOT_SPIFLASH_LAYOUT "/0x80000000/016*04Kg" 
// #define MBOOT_SPIFLASH_ERASE_BLOCKS_PER_PAGE (16 / 4) 
// #define MBOOT_SPIFLASH_SPIFLASH (&spi_bdev.spiflash) 
// #define MBOOT_SPIFLASH_CONFIG (&spiflash_config)

// use external SPI flash for storage
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_SPIFLASH_SIZE_BITS (128 * 1024 * 1024)
#define MICROPY_HW_SPIFLASH_CS      (pin_A4)
#define MICROPY_HW_SPIFLASH_SCK     (pin_A5)
#define MICROPY_HW_SPIFLASH_MOSI    (pin_A7)
#define MICROPY_HW_SPIFLASH_MISO    (pin_A6)

// block device config for SPI flash
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? (MICROPY_HW_SPIFLASH_SIZE_BITS / 8 / FLASH_BLOCK_SIZE) : \
    (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
    spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
)
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
