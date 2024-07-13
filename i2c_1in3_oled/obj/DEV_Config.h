#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_
/***********************************************************************************************************************
			------------------------------------------------------------------------
			|\\\																///|
			|\\\					Hardware interface							///|
			------------------------------------------------------------------------
***********************************************************************************************************************/
#ifdef USE_BCM2835_LIB
	#include <bcm2835.h>
#elif USE_WIRINGPI_LIB
	#include <wiringPi.h>
	#include <wiringPiSPI.h>
	#include <wiringPiI2C.h>
#elif USE_DEV_LIB
	#include <lgpio.h>
	#define LFLAGS 0
	#define NUM_MAXBUF  4
	
#endif

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "Debug.h"


#define USE_SPI 0
#define USE_IIC 1
#define IIC_CMD        0X00
#define IIC_RAM        0X40


/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

 // +------+-----+----------+--------+---+  ZERO2W  +---+--------+----------+-----+------+
 // | GPIO | wPi |   Name   |  Mode  | V | Physical | V |  Mode  | Name     | wPi | GPIO |
 // +------+-----+----------+--------+---+----++----+---+--------+----------+-----+------+
 // |      |     |     3.3V |        |   |  1 || 2  |   |        | 5V       |     |      |
 // |  264 |   0 |    SDA.1 |   ALT5 | 0 |  3 || 4  |   |        | 5V       |     |      |
 // |  263 |   1 |    SCL.1 |   ALT5 | 0 |  5 || 6  |   |        | GND      |     |      |
 // |  269 |   2 |     PWM3 |    OFF | 0 |  7 || 8  | 0 | ALT2   | TXD.0    | 3   | 224  |
 // |      |     |      GND |        |   |  9 || 10 | 0 | ALT2   | RXD.0    | 4   | 225  |
 // |  226 |   5 |    TXD.5 |     IN | 1 | 11 || 12 | 1 | IN     | PI01     | 6   | 257  |
 // |  227 |   7 |    RXD.5 |    OFF | 0 | 13 || 14 |   |        | GND      |     |      |
 // |  261 |   8 |    TXD.2 |    OUT | 0 | 15 || 16 | 0 | OFF    | PWM4     | 9   | 270  |
 // |      |     |     3.3V |        |   | 17 || 18 | 0 | OFF    | PH04     | 10  | 228  |
 // |  231 |  11 |   MOSI.1 |    OFF | 0 | 19 || 20 |   |        | GND      |     |      |
 // |  232 |  12 |   MISO.1 |    OFF | 0 | 21 || 22 | 1 | IN     | RXD.2    | 13  | 262  |
 // |  230 |  14 |   SCLK.1 |    OFF | 0 | 23 || 24 | 0 | OFF    | CE.0     | 15  | 229  |
 // |      |     |      GND |        |   | 25 || 26 | 1 | IN     | CE.1     | 16  | 233  |
 // |  266 |  17 |    SDA.2 |   ALT5 | 0 | 27 || 28 | 0 | ALT5   | SCL.2    | 18  | 265  |
 // |  256 |  19 |     PI00 |     IN | 1 | 29 || 30 |   |        | GND      |     |      |
 // |  271 |  20 |     PI15 |     IN | 1 | 31 || 32 | 1 | IN     | PWM1     | 21  | 267  |
 // |  268 |  22 |     PI12 |    OFF | 0 | 33 || 34 |   |        | GND      |     |      |
 // |  258 |  23 |     PI02 |    OFF | 0 | 35 || 36 | 0 | OUT    | PC12     | 24  | 76   |
 // |  272 |  25 |     PI16 |    OUT | 1 | 37 || 38 | 1 | IN     | PI04     | 26  | 260  |
 // |      |     |      GND |        |   | 39 || 40 | 0 | OFF    | PI03     | 27  | 259  |
 // +------+-----+----------+--------+---+----++----+---+--------+----------+-----+------+
 // | GPIO | wPi |   Name   |  Mode  | V | Physical | V |  Mode  | Name     | wPi | GPIO |
 // +------+-----+----------+--------+---+  ZERO2W  +---+--------+----------+-----+------+

// //OLED
// #define SPI_MOSI		10
// #define SPI_SCK			11
// #define I2C_SCL			3
// #define I2C_SDA			2
// #define OLED_CS			8
// #define OLED_RST		25
// #define OLED_DC			24

// //KEY
// #define KEY_UP_PIN		6
// #define KEY_DOWN_PIN	19
// #define KEY_LEFT_PIN	5
// #define KEY_RIGHT_PIN	26
// #define KEY_PRESS_PIN	13
// #define KEY1_PIN		21
// #define KEY2_PIN		20
// #define KEY3_PIN		16


// OPI WiringOP Pin Num
#define SPI_MOSI		11
#define SPI_SCK			14
#define I2C_SCL			1
#define I2C_SDA			0
#define OLED_CS			15
#define OLED_RST		13
#define OLED_DC			10

#define KEY_UP_PIN		20
#define KEY_DOWN_PIN	23
#define KEY_LEFT_PIN	19
#define KEY_RIGHT_PIN	25
#define KEY_PRESS_PIN	22
#define KEY1_PIN		27
#define KEY2_PIN		26
#define KEY3_PIN		24


#define OLED_CS_0		DEV_Digital_Write(OLED_CS,0)
#define OLED_CS_1		DEV_Digital_Write(OLED_CS,1)

#define OLED_RST_0		DEV_Digital_Write(OLED_RST,0)
#define OLED_RST_1		DEV_Digital_Write(OLED_RST,1)
#define OLED_RST_RD		DEV_Digital_Read(OLED_RST)

#define OLED_DC_0		DEV_Digital_Write(OLED_DC,0)
#define OLED_DC_1		DEV_Digital_Write(OLED_DC,1)


#define KEY_UP_RD		DEV_Digital_Read(KEY_UP_PIN)
#define KEY_DOWN_RD		DEV_Digital_Read(KEY_DOWN_PIN)
#define KEY_LEFT_RD		DEV_Digital_Read(KEY_LEFT_PIN)
#define KEY_RIGHT_RD	DEV_Digital_Read(KEY_RIGHT_PIN)
#define KEY_PRESS_RD	DEV_Digital_Read(KEY_PRESS_PIN)
#define KEY1_RD			DEV_Digital_Read(KEY1_PIN)
#define KEY2_RD			DEV_Digital_Read(KEY2_PIN)
#define KEY3_RD			DEV_Digital_Read(KEY3_PIN)
/*------------------------------------------------------------------------------------------------------*/


uint8_t DEV_ModuleInit(void);
void    DEV_ModuleExit(void);

void I2C_Write_Byte(uint8_t value, uint8_t Cmd);

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode);
void DEV_Digital_Write(UWORD Pin, UBYTE Value);
UBYTE DEV_Digital_Read(UWORD Pin);
void DEV_Delay_ms(UDOUBLE xms);

void DEV_SPI_WriteByte(UBYTE Value);
void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len);



#endif
