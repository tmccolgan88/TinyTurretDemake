#include <gb/gb.h>
#include <gb/console.h>
#include <stdio.h>
#include <gb/font.h>
#include "globvars.h"
#include "player.c"
#include "ground.c"

int initializeGlbalVariables();

int8_t spriteCount = 0;
int8_t mainsc = -1;
int vbl_count = 0;
int counter;

void vbl_increment(){
  ++vbl_count;
}
void main(){
    
    SHOW_SPRITES;
    SHOW_BKG;
    
    
    add_VBL(vbl_increment);
    set_interrupts(VBL_IFLAG);

    initializePlayer(&mainsc);
    initializeGround(&mainsc);
    while(1){
        delay(17);
        playerUpdate();

        if (vbl_count % 30 == 0){
          setCanFire();
          vbl_count = 0;
        }
          
    }
}

int initializeGlobalVariables(){
  return 0;
}