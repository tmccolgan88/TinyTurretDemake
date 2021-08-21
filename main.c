#include <gb/gb.h>
#include <stdio.h>
#include <gb/font.h>
#include "player.c"

void main(){
    
    SHOW_SPRITES;

    Player *p = initializePlayer();
    while(1){
        delay(500);
        p->playerUpdate();
    }

    //printf("hello world");
}