/*
 * t.c
 *
 * Created: 5/2/2018 8:22:05 PM
 * Author: MSS
 */

#include <io.h>
#include <stdio.h>
#include <delay.h>

// set dht11 sensor port and pin
#define SPIN C.0
#include <DHT11/DHT11.h>




void main(void)
{
//DHT_setup();
UCSRB=0x08;
UCSRC=0x86;
UBRRL=0xCF;
while (1)
    {
    // Please write your application code here     
       //#asm("cli")
       // DHT_read(&temp,&hum);              
       // #asm("sei")  
       
                     
        
        unsigned char hum=0;
        char temp=0;
	
	unsigned char crc=readDHT11(&temp,&hum);
	
        printf("T=%dC  H=%dR CRC=%i\r\n",temp,hum,crc);
        
        delay_ms(2000);
    }
}
