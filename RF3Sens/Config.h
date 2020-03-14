//###########################################################################################
// RF3Sens (RoboForum triangulation range sensor)
// http://roboforum.ru/forum107/topic15929.html (official language for this forum - russian)
// MIT License
// 2015-2016
// Дмитрий Лилик (aka Dmitry__ @ RoboForum.ru)
// Андрей Пожогин (aka dccharacter  @ RoboForum.ru)
// Сергей Тараненко (aka setar @ RoboForum.ru)
//###########################################################################################

/* Config.h */
//###########################################################################################
//        Manual settings
//###########################################################################################
/*
In the absence of a flag DEBUG_TYPE, the program quickly processes resp. register and provides data on led (regular printer operation).
When the DEBUG_TYPE flag is set, data is transmitted via the serial port:
DEBUG_TYPE = 1 Transmission of the image for focusing the lens, number of. byte = ARRAY_WIDTH * ARRAY_HEIGHT
DEBUG_TYPE = 2 For a test of positioning accuracy (dccharacter idea).
                The search for the threshold as in normal mode (speed is important), as soon as the threshold is triggered - issue a picture in the serial port
DEBUG_TYPE = 3 Transmission in text form to the data terminal: Max_Pix, Min_Pix, Pix_Sum, Shutter
DEBUG_TYPE = 4 As the 3rd mode, but by the resolution of the pin_TRIG signal (the log is precisely limited by the z_probe signal)
DEBUG_TYPE = 5 Mouse movement data.
DEBUG_TYPE = 6 Testing the dual laser mode
*/
#define DEBUG_TYPE 1 
#define NUM_SAMPLES_PER_MEASURE 5 //amount of data for 4th mode

/*
Only relevant if there is a DEBUG_TYPE flag
If defined, the software Serial port is used (only one leg for data transfer)
For the Digispark, this is the only option and automatically turns on 1 foot
If not defined, Hardware Serial is used for debugging.
*/
//#define SOFTWARE_SERIAL 1 // at the same time, a sign of software serial and a leg number for data transfer (TX PIN)
#define SERIAL_SPEED 230400

/*
Type of sensor, select one you need
*/
//#define SENS_TYPE_ADNS_5020
//#define SENS_TYPE_ADNS_2610
#define SENS_TYPE_ADNS_2620

/*
Do we use power from the controller
*/
//#define laser_power_via_mcu // laser power mode from the feet of the microcontroller (apply power to the desired legs)
//#define sens_power_via_mcu // sensor power mode from the feet of the microcontroller (we supply power to the desired legs)

/*
Type of controller, select one you need
*/
//#define DIGI_SPARK
//#define ARDUINO_NANO // arduino nano base wiring
//#define ARDUINO_NANO_wPOWER  // wiring the sensor on the arduino nano to power the feet of the microcontroller
#define ARDUINO_NANO_DOUBLE_LASER

/*
Detection algorithm, select the one you need
*/
//#define Algo_MaxPix         // the simplest mode is when the edge of the laser spot begins to appear in the field of view.
                            // the most stable, but the response distance is different for different surface colors
//#define Algo_MaxSqualMA   // Squal maximum detection mode, as the parameter is not stable; smoothing and analysis are introduced through the sliding average
                            // experimental

//###########################################################################################
//        End of manual settings
//###########################################################################################


#if (defined(DIGI_SPARK) && !defined(SOFTWARE_SERIAL)) 
  #error "This board can be used only with SOFTWARE_SERIAL"
#endif

#if DEBUG_TYPE == 5
  #if defined(SENS_TYPE_ADNS_2610) || defined(SENS_TYPE_ADNS_2620)
    #error "This sensor doesn't have a motion register; DEBUG_TYPE 5 is unavailable"
  #endif
#endif


//###########################################################################################
//        Connecting libraries
//###########################################################################################
#if defined(SENS_TYPE_ADNS_5020)
  #include "sens/ADNS_5020.h"
#endif
#if defined(SENS_TYPE_ADNS_2610)
  #include "sens/ADNS_2610.h"
#endif
#if defined(SENS_TYPE_ADNS_2620)
  #include "sens/ADNS_2620.h"
#endif

#if defined(DIGI_SPARK)
#include "boards/Digispark.h"
#endif
#if defined(ARDUINO_NANO)
#include "boards/ArduinoNano.h"
#endif
#if defined(ARDUINON_NANO_wPOWER)
#include "boards/ArduinoNano.h"
#endif
#if defined(ARDUINO_NANO_DOUBLE_LASER)
#include "board_ArduinoNano_doubleLaser.h"
#endif

#if defined(DEBUG_TYPE) && defined(SOFTWARE_SERIAL)
  #include <SendOnlySoftwareSerial.h>
  SendOnlySoftwareSerial MyDbgSerial(SOFTWARE_SERIAL, false); //true allows to connect to a regular RS232 without RS232 line driver
  #define SERIAL_OUT MyDbgSerial
#else
  #define SERIAL_OUT Serial
#endif

//###########################################################################################
//        Definitions
// for an example of a beautiful definition, thanks to Denis Konstantinov aka linvinus  roboforum.ru
//###########################################################################################
#define GET_PIN(x) x ## _PIN
#define GET_DDR(x) x ## _DDR
#define GET_PORT(x) x ## _PORT
#define GET_IN(x) x ## _IN
  
#define PIN_OUTPUT(PIN)   GET_DDR(PIN) |= (1<<GET_PIN(PIN))
#define PIN_INPUT(PIN)   GET_DDR(PIN) &=~(1<<GET_PIN(PIN))
#define PIN_LOW(PIN)   GET_PORT(PIN) &=~(1<<GET_PIN(PIN))
#define PIN_HIGH(PIN)   GET_PORT(PIN) |= (1<<GET_PIN(PIN))
#define PIN_TOGGLE(PIN)   GET_PORT(PIN) ^= (1<<GET_PIN(PIN))
#define PIN_READ(PIN)   GET_IN(PIN) & (1<<GET_PIN(PIN))
#define NUM_PIXS (ARRAY_WIDTH * ARRAY_HEIGHT)
