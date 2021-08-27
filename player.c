#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include "globvars.h"
#include "./assets/turret.c"

typedef enum{true, false} bool;

int playerPosition[2];
bool canFire;
int8_t xVelocity;
int8_t yVelocity;
int timeSinceLastUpdate;

int playerUpdate();

int playerUpdate(){

    if (joypad() & J_LEFT){
      playerPosition[0]--;
      move_sprite(0, playerPosition[0], playerPosition[1]);
    }
    if(joypad() & J_RIGHT){
      playerPosition[0]++;
      move_sprite(0, playerPosition[0], playerPosition[1]);
    }
    return 0;
}

int *initializePlayer(){
    playerPosition[0] = PLAYER_X_START;
    playerPosition[1] = PLAYER_Y_START;
    set_sprite_data(0,1,Turret);
    set_sprite_tile(0,0);
    move_sprite(0, playerPosition[0], playerPosition[1]);

    return 0; 
}