#ifndef PINS_H
#define PINS_H


/*
The board assignment defines the capabilities of the motherboard and the used pins.
Each board definition follows the following scheme:

CPU_ARCH
  ARCH_AVR for AVR based boards
  ARCH_ARM for all arm based boards

STEPPER_CURRENT_CONTROL
  CURRENT_CONTROL_MANUAL  1  // mechanical poti, default if not defined
  CURRENT_CONTROL_DIGIPOT 2  // Use a digipot like RAMBO does
  CURRENT_CONTROL_LTC2600 3  // Use LTC2600 like Foltyn 3D Master
  CURRENT_CONTROL_ALLIGATOR 4  //Use External DAC like Alligator
*/

#define ARCH_AVR 1
#define ARCH_ARM 2
#define CPU_ARCH ARCH_ARM
#define CURRENT_CONTROL_MANUAL  1  // mechanical poti, default if not defined
#define CURRENT_CONTROL_DIGIPOT 2  // Use a digipot like RAMBO does
#define CURRENT_CONTROL_LTC2600 3  // Use LTC2600 like Foltyn 3D Master
#define CURRENT_CONTROL_ALLIGATOR 4  //Use External DAC like Alligator

/*
  arm does not have a eeprom build in. Therefore boards can add a
  eeprom. Board definition must set the right type of eeprom
*/

/****************************************************************************/
// RAMPS-FD Board
// 
#if MOTHERBOARD == 403 || MOTHERBOARD == 404 || MOTHERBOARD == 405
#ifndef __SAM3X8E__
#error Oops!  Make sure you have 'Arduino Due' selected from the 'Tools -> Boards' menu.
#endif

#define KNOWN_BOARD
#define CPU_ARCH ARCH_ARM

#if MOTHERBOARD == 403
#define HEATER_PINS_INVERTED 1  // only old boards had the output inverted
#else
#define HEATER_PINS_INVERTED 0
#endif


/*****************************************************************
* Arduino Due Pin Assignments
******************************************************************/

#define ORIG_X_STEP_PIN     63
#define ORIG_X_DIR_PIN      62
#define ORIG_X_MIN_PIN      22
#define ORIG_X_MAX_PIN      30
#define ORIG_X_ENABLE_PIN   48

#define ORIG_Y_STEP_PIN     65 
#define ORIG_Y_DIR_PIN      64
#define ORIG_Y_MIN_PIN      24
#define ORIG_Y_MAX_PIN      38
#define ORIG_Y_ENABLE_PIN   46

#define ORIG_Z_STEP_PIN     67
#define ORIG_Z_DIR_PIN      66
#define ORIG_Z_MIN_PIN      26
#define ORIG_Z_MAX_PIN      34
#define ORIG_Z_ENABLE_PIN   44

// Note that on the Due pin A0 on the board is channel 2 on the ARM chip
#define HEATER_0_PIN     8
// Due analog pin #54
#define TEMP_0_PIN       54 

#define HEATER_1_PIN     9 
// Due analog pin #55
#define TEMP_1_PIN       55

#define HEATER_2_PIN     10
// Due analog pin #56
#define TEMP_2_PIN       56 
#define HEATER_3_PIN     11
// Due analog pin #57
#define TEMP_3_PIN       57 

// Due analog pin #58
#define TEMP_4_PIN       -1 

#define ORIG_E0_STEP_PIN    36
#define ORIG_E0_DIR_PIN     28
#define ORIG_E0_ENABLE_PIN  42

#define ORIG_E1_STEP_PIN    43
#define ORIG_E1_DIR_PIN     41
#define ORIG_E1_ENABLE_PIN  39

#define ORIG_E2_STEP_PIN    32
#define ORIG_E2_DIR_PIN     47
#define ORIG_E2_ENABLE_PIN  45

//#define SDSUPPORT      false
#define SDPOWER 	   -1
// 4,10,52 if using HW SPI.
#define SDSS		   4 
//#define SDSS		   -1
//#define ORIG_SDCARDDETECT   -1
#define SDCARDDETECTINVERTED false
#define LED_PIN 	   13
#define ORIG_FAN_PIN 	   12 
#define ORIG_FAN2_PIN       2
#define ORIG_PS_ON_PIN      53
#define KILL_PIN	   -1
#define SUICIDE_PIN    -1  //PIN that has to be turned on right after start, to keep power flowing.

// 20 or 70
#define SDA_PIN 				20  	
// 21 or 71
#define SCL_PIN 				21  
	

#if MOTHERBOARD == 405
#define RESISTOR_0 0xF8  //x
#define RESISTOR_1 0xF9  //y
#define RESISTOR_2 0xFA  //z
#define RESISTOR_3 1xF8  //e0
#define RESISTOR_4 1xF9  //e1
#define RESISTOR_5 1xFA  //e2
#define STEPPER_CURRENT_CONTROL CURRENT_CONTROL_DIGIPOT
#endif


#define E0_PINS ORIG_E0_STEP_PIN,ORIG_E0_DIR_PIN,ORIG_E0_ENABLE_PIN,
#define E1_PINS ORIG_E1_STEP_PIN,ORIG_E1_DIR_PIN,ORIG_E1_ENABLE_PIN,
#define E2_PINS ORIG_E2_STEP_PIN,ORIG_E2_DIR_PIN,ORIG_E2_ENABLE_PIN,

#define TWI_CLOCK_FREQ          400000
// see eeprom device data sheet for the following values these are for 24xx256
#define EEPROM_SERIAL_ADDR      0x50   // 7 bit i2c address (without R/W bit)
#define EEPROM_PAGE_SIZE        64     // page write buffer size
#define EEPROM_PAGE_WRITE_TIME  7      // page write time in milliseconds (docs say 5ms but that is too short)
// specify size of eeprom address register
// TWI_MMR_IADRSZ_1_BYTE for 1 byte, or TWI_MMR_IADRSZ_2_BYTE for 2 byte
#define EEPROM_ADDRSZ_BYTES     TWI_MMR_IADRSZ_2_BYTE
#define EEPROM_AVAILABLE 1
#endif

#endif
