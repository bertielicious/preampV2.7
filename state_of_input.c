#include "config.h"
#include <xc.h>
#include "write_character.h"
#include "clear_oled.h"
#include "update_PGA2311.h"
#include "bar_graph.h"
#include "split_digits.h"
#include "get_digit.h"

void state_of_input(int *c_state)
{
    switch (*c_state)
    {
        case STREAM:
       
              *c_state = STREAM;
              write_character(&s[0],0x0f,0xb0);  //write stream on oled
              write_character(&t[0],0x1f, 0xb0); 
              write_character(&r[0],0x2f, 0xb0);
              write_character(&e[0],0x3f,0xb0);  
              write_character(&a[0],0x4f,0xb0);
              write_character(&m[0],0x5f,0xb0);  
              *past_state = STREAM;
              break;
              
        case CD:
           
              *c_state = CD;
              write_character(&space[0],0x0f,0xb0);  //write cd on oled
              write_character(&space[0],0x1f,0xb0); 
              write_character(&c[0],0x2f, 0xb0);
              write_character(&d[0],0x3f,0xb0);  
              write_character(&space[0],0x4f,0xb0);
              write_character(&space[0],0x5f,0xb0);     
              *past_state = CD;
              break;
            
        case TUNER:
           *c_state = TUNER;
             write_character(&space[0],0x0f,0xb0);  //write tuner on oled
             write_character(&t[0],0x1f,0xb0); 
             write_character(&u[0],0x2f, 0xb0);
             write_character(&n[0],0x3f,0xb0);  
             write_character(&e[0],0x4f,0xb0);
             write_character(&r[0],0x5f,0xb0);
             *past_state = TUNER;
             break;
             
        case PHONO:
            *c_state = PHONO;
             write_character(&space[0],0x0f,0xb0);  //write phono on oled
             write_character(&p[0],0x1f, 0xb0); 
             write_character(&h[0],0x2f, 0xb0);
             write_character(&o[0],0x3f,0xb0);  
             write_character(&n[0],0x4f,0xb0);
             write_character(&o[0],0x5f,0xb0); 
             *past_state = PHONO;
             break;
             
        case DAC:
            *c_state = DAC;
             write_character(&space[0],0x0f,0xb0);  //write dac on oled
             write_character(&d[0],0x1f, 0xb0); 
             write_character(&a[0],0x2f, 0xb0);
             write_character(&c[0],0x3f,0xb0);  
             write_character(&space[0],0x4f,0xb0);
             write_character(&space[0],0x5f,0xb0); 
             *past_state = DAC;
             break;
             
      /*  case MUTE:
             *c_state = MUTE;
             
            old_count = count;

            write_character(&space[0],0x0f,0xb3);
            write_character(&m[0],0x1f,0xb3);  //do this
            write_character(&u[0],0x2f, 0xb3); 
            write_character(&t[0],0x3f, 0xb3);
            write_character(&e[0],0x4f,0xb3);
            while(count != 0)
                {
                    count--;
                    CW_Flag == LO;
                    bar_graph();
                    update_PGA2311(count);
                }
            *c_state = *past_state;
            break;
           
        case UNMUTE:
         *c_state = UNMUTE;    

            write_character(&space[0],0x0f,0xb3);
            write_character(&space[0],0x1f,0xb3);
            write_character(&space[0],0x2f,0xb3);
            write_character(&space[0],0x3f,0xb3);
            write_character(&space[0],0x4f,0xb3);
            split_digits();
            write_character(&minus[0], 0x0f,0xb3);
            get_digit(tens, 0x1f);
            get_digit(units, 0x2f);
            bar_graph();
            update_PGA2311(old_count);
           
            write_character(&d[0],0x3f,0xb3);   // write dB
            write_character(&B[0],0x4f,0xb3);
            *c_state = *past_state;
            break;*/
    }
}
           

