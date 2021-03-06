//###########################################################################################
// RF3Sens (RoboForum triangulation range sensor)
// http://roboforum.ru/forum107/topic15929.html (official language for this forum - russian)
// MIT License
// 2015-2016
// Дмитрий Лилик (aka Dmitry__ @ RoboForum.ru)
// Андрей Пожогин (aka dccharacter  @ RoboForum.ru)
// Сергей Тараненко (aka setar @ RoboForum.ru)
//###########################################################################################

/* board_ArduinoNano.h */

#if defined(use_nCS)
  //pin_nCS  PB2 SS D10
  #define NCS_PIN        2
  #define NCS_DDR        DDRB
  #define NCS_PORT       PORTB
#endif 

//pin_led
//PB5 D13
#define LED_PIN         5
#define LED_DDR         DDRB
#define LED_PORT        PORTB

//pin_nClock (SCK)
//PB4 D12
#define NCLOCK_PIN      4
#define NCLOCK_DDR      DDRB
#define NCLOCK_PORT     PORTB

//MOSI
//PB3  D11
#define SDIO_PIN        3
#define SDIO_DDR        DDRB
#define SDIO_PORT       PORTB
#define SDIO_IN    PINB

//PD4 TRIGGER_PIN
//PD4 D4
#define TRIG_PIN        4
#define TRIG_DDR        DDRD
#define TRIG_IN    PIND

//Laser 1 VCC
//PD5 D5
#define laser1_vcc_PIN   5
#define laser1_vcc_DDR   DDRD
#define laser1_vcc_PORT  PORTD

//Laser 2 VCC
//PD6 D6
#define laser2_vcc_PIN   6
#define laser2_vcc_DDR   DDRD
#define laser2_vcc_PORT  PORTD

//Laser PWM control
//PB1 D9
#define laser_pwm_PIN	1
#define laser_pwm_DDR	DDRB
#define laser_pwm_PORT	PORTB

// GPIO for signalling to external board
// PRD7 D7
#define gpio1_PIN	7
#define gpio1_DDR	DDRD
#define gpio1_PORT	PORTD
