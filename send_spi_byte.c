/*
 * File:   send_spi_byte.c
 * Author: philip
 *
 * Created on 04 February 2018, 18:06
 */


#include <xc.h>
#include "config.h"
#include "send_spi_byte.h"
void send_spi_byte(unsigned char byte)
{
    SSPBUF = byte;  // send byte MSB first
    while(SSPSTATbits.BF != 1)
    {
        ; // wait for all 8 bits to be transmitted
    }
}
