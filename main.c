#include <gb/gb.h>
#include <stdio.h>
#include <gb/font.h>
#include "globvars.h"
#include "player.c"
#include "ground.c"

void main(){
    
    SHOW_SPRITES;
    SHOW_BKG;

    initializePlayer();
    initializeGround();
    
    while(1){
        delay(17);
        playerUpdate();
    }
}