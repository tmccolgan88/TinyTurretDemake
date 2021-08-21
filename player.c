#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include "./assets/turret.c"

typedef enum{true, false} bool;

typedef struct Player {
  int playerPosition[2];
  bool canFire;
  int xVelocity;
  int yVelocity;
  int timeSinceLastUpdate;

  int (* playerUpdate)();
} Player;

int playerUpdate(){
    scroll_sprite(0, 1, 1);
    return 0;
}

Player *initializePlayer(){
    Player * p = malloc(sizeof(Player));
    p->canFire = true;
    p->timeSinceLastUpdate = 100;
    p->xVelocity = 1;
    p->yVelocity = 0;
    p->playerUpdate = playerUpdate;
    set_sprite_data(0,1,Turret);
    set_sprite_tile(0,0);
    move_sprite(0, 50, 50);

    return p; 
}