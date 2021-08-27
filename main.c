#include <gb/gb.h>
#include <stdio.h>
#include <gb/font.h>
#include "player.c"

void main(){
    
    SHOW_SPRITES;

    initializePlayer();
    
    while(1){
        delay(17);
        playerUpdate();
    }
}