#include <stdlib.h>
#include "./assets/turret.c"
#include "./assets/bullet.c"

typedef struct BulletStruct{
  int8_t bulletPosition[2];
  int8_t velocity;
  int8_t active;
}BulletStruct;

int playerPosition[2];
bool canFire;
int timeSinceLastUpdate;

BulletStruct * bullets = 0;

int playerUpdate();
int * initializePlayer();
BulletStruct * addBullet();
int * getPlayerPosition();

int playerUpdate(){
    
    //player movement logic
    if (joypad() & J_LEFT){
      playerPosition[X_POSITION]--;
      move_sprite(0, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
    }
    if(joypad() & J_RIGHT){
      playerPosition[0]++;
      move_sprite(0, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
    }

    //shooting logic
    if(joypad() & J_A){
      bullets = addBullet();
    }

    if (bullets != 0){
      bullets->bulletPosition[Y_POSITION]--;
      move_sprite(1, bullets->bulletPosition[X_POSITION], bullets->bulletPosition[Y_POSITION]);

    }
      
    return 0;
}

int *initializePlayer(){
    playerPosition[0] = PLAYER_X_START;
    playerPosition[1] = PLAYER_Y_START;
    set_sprite_data(0,1,Turret);
    set_sprite_tile(0,0);
    move_sprite(0, playerPosition[X_POSITION], playerPosition[Y_POSITION]);

    return 0; 
}

BulletStruct * addBullet(){
  BulletStruct *b  = malloc(sizeof(BulletStruct));
  b->bulletPosition[X_POSITION] = playerPosition[X_POSITION];
  b->bulletPosition[Y_POSITION] = playerPosition[Y_POSITION];
  set_sprite_data(1, 1, Bullet);
  set_sprite_tile(1, 1);
  move_sprite(1, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
  return b;
}

int * getPlayerPosition(){
  return playerPosition;
}