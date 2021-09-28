/***************************************
 *  Program main.c
 *  Author : Tim McColgan
 * 
 * 
 * 
 * 
 * 
 * *************************************/
#include <gb/gb.h>
#include <gb/console.h>
#include <stdio.h>
#include <gb/font.h>
#include "globvars.h"
#include "player.c"
#include "ground.c"
#include "cannon_ball.c"

int8_t mainsc = -1; //main sprite count
int vbl_count = 0;  //vertical blank counter
int counter;

SpriteData *cannonBalls;

int initializeGlobalVariables();

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
    cannonBalls = initialializeCannonBall(&mainsc);

    while(1){
        delay(17);
        playerUpdate();
        
        //this still isn't right
        if (vbl_count % 30 == 0){
          setCanFire();
          vbl_count = 0;
        }
          
    }
}

int initializeGlobalVariables(){
  return 0;
}