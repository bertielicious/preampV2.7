/* 
 * File:   config.h
 * Author: Phil
 *
 * Created on 07 June 2018, 21:48
 */

#ifndef CONFIG_H
#define	CONFIG_H

#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = DISABLED // PLL Enable Bit (3x or 4x PLL Disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)
#define _XTAL_FREQ 16000000
#include <xc.h>
#include <stdbool.h>
/********IR_CODE*******/
/********States**********/
#define STARTIR 0
#define MID1 1
#define START1 2
#define MID0 3
#define START0 4

/****OUTPUTS of state machine******/
#define HI 1
#define LO 0
/******pulse_types****/
#define SP 0
#define LP 1
#define SS 2
#define LS 3
#define ERR 4
#define IR  PORTBbits.RB5
/************global variables for IR code********/
volatile unsigned char has_run = 0;
volatile unsigned int space_width, pulse_width, temp1, temp2,temp3, countRC5 = 0;
volatile unsigned int pulse_type = SP;
unsigned int state = MID1;
volatile unsigned int RC5_code = 0x0000;
volatile unsigned int bits = 14;        // number of bits to be shifted left to form the RC5_code (14 bits)
volatile unsigned int magic_num = 1;
/********END_OF_IR_CODE********************/

/*******PREAMP_CODE************************/
#define SWIP PORTAbits.RA0      // SWIP pin 19 
#define CLK PORTAbits.RA1       // CLK input of rotary encoder pin 18
#define DT PORTAbits.RA4        // DT input of rotary encoder pin 3
//#define DT PORTAbits.RA3            // DT input of rotary encoder pin 4
#define IR  PORTBbits.RB5       // IOC input for IR RC5 data pin 12
#define SCK PORTBbits.RB6       // serial clock pin 11
#define SDO PORTCbits.RC7       // serial data out pin 9
#define RST PORTCbits.RC5       // RESET pin 5
#define DC  PORTCbits.RC6       // D/C data/ command pin 8
#define CS  PORTAbits.RA5       // chip select (active low) pin 2 for OLED
#define CS_PGA2311 PORTCbits.RC1// chip select (active low) pin 15 for PGA2311
#define HI 1
#define LO 0
/********fsm.c variables*************/
/************MACHINE STATES********************/
#define START 1
#define QCW 2
#define HCW 3
#define TQCW 4
#define FCW 5
#define QACW 6
#define HACW 7
#define TQACW 8
#define FACW 9

#define STREAM 0
#define CD 1
#define TUNER 2
#define PHONO 3
#define DAC 4
#define MUTE 5
#define UNMUTE 6

#define STREAM_RELAY PORTCbits.RC0  // pin 16
#define CD_RELAY PORTCbits.RC2      // pin 14
#define TUNER_RELAY PORTCbits.RC3   // pin 7
#define PHONO_RELAY PORTCbits.RC4   // pin 6
#define DAC_RELAY PORTBbits.RB7     // pin 10

volatile int current_state = STREAM;
volatile int previous_state = STREAM;
volatile int prev_state;
int *past_state = STREAM;
volatile unsigned char kurrent_state = START;
volatile bool CW_Flag = LO;      // CW_Flag is set when rotary encoder is turned clockwise
volatile bool ACW_Flag = LO;     // ACW_Flag is set when rotary encoder is turned anti-clockwise
//signed char count = 0;
int count = 0;
int old_count = 0;
volatile int prev_count = 0;
unsigned char tens = 0;
unsigned char units = 0;
bool fuck = 0;
bool shit = 0;
/*******************ADC variables*******************/
int adc_result = 0x0000;
int current_button_state = UNMUTE;
//int previous_button_state = VOLU;


/*OLED display parameters*/
#define SSD1306_128_64
#define SSD1306_LCDWIDTH  128
#define SSD1306_LCDHEIGHT  64

#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_SETSEGMENTREMAP 0xA0
#define SSD1306_SEGREMAP 0xA0

#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_DISPLAYALLON_RESUME 0xA4    // output follows RAM contents
#define SSD1306_NORMALDISPLAY 0xA6          // white on black or black on white
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_INVERTDISPLAY 0xA6
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A
#define SSD1306_SET_COM_OUTPUT_SCAN_DIRECTION 0xA0

const unsigned char V[32] = {0x06,0x0e,0x3c,0xf0,0xc0,0x80,0x00,0x00,
                   0x00,0x80,0xc0,0xf0,0x3c,0x0e,0x06,0x00,
                   0x00,0x00,0x00,0x00,0x01,0x07,0x1e,0x18,
                   0x1e,0x07,0x01,0x00,0x00,0x00,0x00,0x00};
const unsigned char o[32] = {0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,0x10,
                   0x10,0x10,0x30,0x60,0xe0,0xc0,0x80,0x00,
                   0x03,0x07,0x0f,0x0c,0x18,0x10,0x10,0x10,
                   0x10,0x18,0x0c,0x0f,0x07,0x03,0x00,0x00};
const unsigned char l[32] = {0x00,0x00,0x02,0x02,0x02,0x02,0xfe,0xfe,
                   0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,
                   0x1f,0x10,0x10,0x10,0x10,0x00,0x00,0x00};
const unsigned char u[32] = {0x00,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0xf0,0xf0,0xf0,0x00,0x00,
                   0x00,0x0f,0x0f,0x1f,0x18,0x10,0x10,0x10,
                   0x18,0x08,0x0c,0x1f,0x1f,0x1f,0x00,0x00};
const unsigned char m[32] = {0xf0,0xf0,0xf0,0x20,0x20,0x10,0xf0,0xf0,
                   0xe0,0x20,0x20,0x10,0xf0,0xf0,0xe0,0x00,
                   0x1F,0x1f,0x1f,0x00,0x00,0x00,0x1f,0x1f,
                   0x1f,0x00,0x00,0x00,0x1f,0x1f,0x1f,0x00};
const unsigned char e[32] = {0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,
                   0x10,0x10,0x10,0x30,0xe0,0xe0,0xc0,0x00,
                   0x00,0x03,0x07,0x0f,0x0d,0x19,0x11,0x11,
                   0x11,0x11,0x11,0x11,0x11,0x19,0x09,0x00};
/*****************Input********************************************/

const unsigned char I[32] = {0x00,0x02,0x02,0x02,0x02,0x02,0xfe,0xfe,
                   0xfe,0x02,0x02,0x02,0x02,0x02,0x00,0x00,
                   0x00,0x10,0x10,0x10,0x10,0x10,0x1f,0x1f,
                   0x1f,0x10,0x10,0x10,0x10,0x10,0x00,0x00};
const unsigned char n[32] = {0x00,0xf0,0xf0,0xf0,0x60,0x20,0x30,0x10,
                   0x10,0x10,0x30,0xf0,0xe0,0xe0,0x00,0x00,
                   0x00,0x1f,0x1f,0x1f,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x1f,0x1f,0x1f,0x00,0x00};
const unsigned char p[32] = {0x00,0xf0,0xf0,0xf0,0x60,0x20,0x30,0x10,
                   0x10,0x10,0x30,0xf0,0xe0,0xc0,0x00,0x00,
                   0x00,0xff,0xff,0xff,0x10,0x10,0x10,0x10,
                   0x10,0x18,0x0c,0x0f,0x07,0x03,0x00,0x00};
const unsigned char t[32] = {0x20,0x20,0x20,0x20,0xfc,0xfc,0xfc,0x20,
                   0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x07,0x0f,0x1f,0x18,
                   0x10,0x10,0x10,0x10,0x10,0x18,0x00,0x00};
const unsigned char space[32] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*****************rest of alphabet***************************************/

const unsigned char a[32] = {0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,
                   0x10,0x10,0x10,0xf0,0xf0,0xf0,0x00,0x00,
                   0x00,0x07,0x0f,0x1f,0x30,0x20,0x20,0x20,
                   0x18,0x08,0x0c,0x1f,0x1f,0x1f,0x00,0x00};

const unsigned char i[32] = {0x00,0x00,0x10,0x10,0x10,0x10,0xf2,0xf2,
                   0xf2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,
                   0x1f, 0x10,0x10,0x10,0x10,0x00,0x00,0x00};
const unsigned char f[32] = {0x40,0x40,0x40,0xf8,0xfc,0xfc,0x06,0x06,
                   0x42,0x42,0x42,0x42,0x42,0x02,0x02,0x00,
                   0x00,0x00,0x00,0x1f,0x1f,0x1f,0x00,0x00,
                   0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const unsigned char h[32] = {0x00,0xfe,0xfe,0xfe,0x60,0x20,0x30,0x10,
                   0x10,0x10,0x30,0xf0,0xe0,0xe0,0x00,0x00,
                   0x00,0x1f,0x1f,0x1f,0x00,0x00,0x00,0x00,
                   0x00, 0x00,0x00,0x1f,0x1f,0x1f,0x00,0x00};
const unsigned char g[32] = {0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,
                   0x10,0x10,0x10,0xf0,0xf0,0xf0,0x00,0x00,
                   0x00,0x47,0xcf,0x9f,0x98,0x90,0x90,0x90,
                   0x98, 0x88,0xcc,0x7f,0x7f,0x3f,0x00,0x00};
const unsigned char r[32] = {0x00,0x00,0xf0,0xf0,0xf0,0x60,0x20,0x30,
                   0x10,0x10,0x70,0x70,0x70,0x00,0x00,0x00,
                   0x00,0x00,0x1f,0x1f,0x18,0x00,0x00,0x00,
                   0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const unsigned char M[32] = {0xfe,0xfe,0x1e,0x38,0xf0,0xc0,0x00,0x00,
                   0x00,0xc0,0xf0,0x38,0x0e,0xfe,0xfe,0x00,
                   0x01f,0x1f,0x00,0x00,0x00,0x01,0x07,0x06,
                   0x07,0x01,0x00,0x00,0x00,0x1f,0x1f,0x00};
const unsigned char N[32] = {0x00,0xfe,0xfe,0xfe,0x1c,0x38,0x70,0xc0,
                   0x80,0x00,0x00,0xfe,0xfe,0xfe,0x00,0x00,
                   0x00,0x1f,0x1f,0x1f,0x00,0x00,0x00,0x00,
                   0x03,0x07,0x0e,0x1f,0x1f,0x1f,0x00,0x00};
const unsigned char b[32] = {0x00,0x00,0xfe,0xfe,0xfe,0x40,0x20,0x30,
                   0x10,0x10,0x10,0x20,0xf0,0xe0,0xc0,0x00,
                   0x00,0x00,0x1f,0x1f,0x1f,0x10,0x10,0x10,
                   0x10,0x10,0x18,0x0c,0x0f,0x07,0x03,0x00};
const unsigned char x[32] = {0x00,0x10,0x30,0x30,0x60,0xc0,0x80,0x80,
                   0x80,0xc0,0x60,0x30,0x10,0x10,0x00,0x00,
                   0x10,0x10,0x18,0x0c,0x06,0x06,0x03,0x01,
                   0x03,0x06,0x06,0x0c,0x18,0x10,0x10,0x00};
const unsigned char d[32] = {0x00,0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,
                   0x10,0x10,0x10,0x10,0xfe,0xfe,0xfe,0x00,
                   0x00,0x00,0x07,0x0f,0x1f,0x18,0x10,0x10,
                   0x10,0x18,0x08,0x0c,0x1f,0x1f,0x1f,0x00};
const unsigned char B[32] = {0x00,0xfe,0xfe,0xfe,0x42,0x42,0x42,0x42,
                   0x42,0x62,0xe6,0x20,0x1c,0x1c,0x00,0x00,
                   0x00,0x3f,0x3f,0x3f,0x20,0x20,0x20,0x20,
                   0x20,0x20,0x30,0x31,0x0f,0x0f,0x07,0x00};
const unsigned char minus[32] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
                   0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00};
const unsigned char s[32] = {0x00,0x60,0xe0,0xf0,0xb0,0x90,0x10,0x10,
                    0x10,0x10,0x10,0x30,0x20,0x00,0x00,0x00,
                    0x00,0x08,0x08,0x10,0x10,0x10,0x10,0x10,
                    0x11,0x13,0x1b,0x1f,0x0e,0x0e,0x00,0x00};
const unsigned char c[32] = {0x00,0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,
                    0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x00,
                    0x00,0x00,0x03,0x07,0x0f,0x0c,0x18,0x10,
                    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00};
                    
/* *************************numbers from 0 to 9**************************/

const unsigned char cero[32] = {0xf0,0xf8,0xfc,0x0c,0x06,0x02,0x02,0x02,
                      0x62,0x32,0x1c,0x1c,0xf8,0xf0,0xe0,0x00,
                      0x01,0x03,0x07,0x0e,0x0e,0x13,0x11,0x10,
                      0x10,0x10,0x18,0x0e,0x0f,0x07,0x03,0x00};
const unsigned char uno[32] =  {0x00,0x08,0x04,0x04,0x04,0x02,0xfe,0xfe,
                      0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                      0x00,0x10,0x10,0x10,0x10,0x10,0x1f,0x1f,
                      0x1f,0x10,0x10,0x10,0x10,0x10,0x00,0x00};
const unsigned char dos[32] =  {0x00,0x04,0x06,0x02,0x02,0x02,0x82,0x82,
                      0xc2,0x62,0x66,0x3e,0x1c,0x1c,0x00,0x00,
                      0x18,0x1c,0x1e,0x12,0x12,0x13,0x11,0x10,
                      0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00};
const unsigned char tres[32] = {0x00,0x04,0x04,0x42,0x42,0x42,0x42,0x42,
                      0x62, 0xe6,0xbe,0xbc,0x98,0x00,0x00,0x00,
                      0x00,0x08,0x18,0x10,0x10,0x10,0x10,0x10,
                      0x10,0x18,0x08,0x0f,0x0f,0x07,0x00,0x00};
const unsigned char cuatro[32] = {0x00,0x80,0xc0,0xe0,0x70,0x78,0x3c,0x1e,
                      0xfe,0xfe,0xfe,0x00,0x00,0x00,0x00,0x00,
                      0x03,0x03,0x03,0x02,0x02,0x02,0x02,0x02,
                      0x1f,0x1f,0x1f,0x02,0x02,0x02,0x02,0x02};
const unsigned char cinco[32] = {0x00,0x3e,0x3e,0x3e,0x22,0x22,0x22,0x22,
                      0x62,0x62,0xc2,0xc2,0x82,0x80,0x00,0x00,
                      0x00,0x08,0x10,0x10,0x10,0x10,0x10,0x10,
                      0x10,0x18,0x0c,0x0f, 0x07,0x03,0x00,0x00};
const unsigned char seis[32] =  {0x00,0xe0,0xf8,0xfc,0x8c,0x44,0x46,0x22,
                       0x22,0x22,0x22,0x62,0xc2,0xc0,0x80,0x00,
                       0x00,0x03,0x07,0x0f,0x0f,0x18,0x10,0x10,
                       0x10,0x10,0x18,0x1c,0x0f,0x07,0x03,0x00};
const unsigned char siete[32] = {0x00,0x02,0x02,0x02,0x02,0x02,0x82,0xc2,
                       0xe2,0x72,0x32,0x1a,0x0e,0x0e,0x06,0x00,
                       0x00,0x00,0x00,0x1c,0x1e,0x1f,0x03,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const unsigned char ocho[32] =  {0x00,0x00,0x18,0xbc,0xbe,0xe2,0x62,0x42,
                       0x42,0xe2,0xbe,0xbc,0x1c,0x00,0x00,0x00,
                       0x00,0x06,0x0f,0x1f,0x19,0x10,0x10,0x10,
                       0x10,0x10,0x19,0x0f,0x0f,0x06,0x00,0x00};
const unsigned char nueve[32] = {0x70,0xf8,0xfc,0x8c,0x06,0x02,0x02,0x02,
                       0x02,0x82,0x86,0x7c,0xfc,0xf8,0xf0,0x00,
                       0x00,0x00,0x10,0x11,0x11,0x11,0x11,0x11,
                       0x11,0x18,0x08,0x0c,0x07,0x07,0x01,0x00};
/*******END_OF_PREAMP_CODE*****************/
#endif	/* CONFIG_H */
