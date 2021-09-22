#include <stdlib.h>
#include "./assets/turret.c"
#include "./assets/bullet.c"

typedef struct BulletStruct{
  int8_t bulletPosition[2];
  int8_t velocity;
  int8_t active;
}BulletStruct;

int8_t i;
int playerPosition[2];
int8_t canFire;
int8_t timeSinceLastFire;
int timeSinceLastUpdate;
int8_t bulletIndex = 0;

BulletStruct * bullets = 0;
BulletStruct *bullets2[3];

int8_t bulletsUpdate();
int playerUpdate();
int * initializePlayer(int8_t *mainsc);
int initializeBullets();
BulletStruct * addBullet();
int * getPlayerPosition();

int8_t bulletsUpdate(){
  for (i = 0; i < 3; i++){
    if (bullets2[i]->active == 1){
      bullets2[i]->bulletPosition[Y_POSITION] = bullets2[i]->bulletPosition[Y_POSITION] - 2;
      move_sprite(i + 1, 
                  bullets2[i]->bulletPosition[X_POSITION], 
                  bullets2[i]->bulletPosition[Y_POSITION]);

      if (bullets2[i]->bulletPosition[Y_POSITION] < -10){
        bullets2[i]->active = 0;
      }
    }
  }

  return 0;
}

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
      if (canFire)
        fireBullet();
    }
      
    bulletsUpdate();

    return 0;
}

int initializeBullets(){
  for (i = 0; i < 3; i++){
    bullets2[i] = malloc(sizeof(BulletStruct));
    bullets2[i]->bulletPosition[X_POSITION] = SPRITE_LOAD_POSITION_X + i;
    bullets2[i]->bulletPosition[Y_POSITION] = SPRITE_LOAD_POSITION_Y + i;
    bullets2[i]->active = 0;
    set_sprite_tile(i + 1, 1);
    move_sprite(i + 1, bullets2[i]->bulletPosition[X_POSITION] = SPRITE_LOAD_POSITION_X, 
                       bullets2[i]->bulletPosition[Y_POSITION] = SPRITE_LOAD_POSITION_Y);
  }

  return 0;
}

int *initializePlayer(int8_t *mainsc){
    playerPosition[0] = PLAYER_X_START;
    playerPosition[1] = PLAYER_Y_START;
    set_sprite_data(++*mainsc,1,Turret);
    set_sprite_data(++*mainsc,1,Bullet);
    set_sprite_data(++*mainsc,1,Bullet);
    set_sprite_data(++*mainsc,1,Bullet);
    set_sprite_tile(0,0);
    move_sprite(0, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
    
    canFire = 0;

    initializeBullets();

    return 0; 
}

BulletStruct * addBullet(){
  BulletStruct *b  = malloc(sizeof(BulletStruct));
  b->bulletPosition[X_POSITION] = playerPosition[X_POSITION];
  b->bulletPosition[Y_POSITION] = playerPosition[Y_POSITION];
  //set_sprite_data(1, 1, Bullet);
  set_sprite_tile(1, 1);
  move_sprite(1, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
  return b;
}

int8_t fireBullet(){
  if (bullets2[bulletIndex]->active == 1)
    return -1;

  bullets2[bulletIndex]->bulletPosition[X_POSITION] = playerPosition[X_POSITION];
  bullets2[bulletIndex]->bulletPosition[Y_POSITION] = playerPosition[Y_POSITION];
  bullets2[bulletIndex]->active = 1;

  canFire = 0;

  ++bulletIndex;
  if (bulletIndex > 2)
    bulletIndex = 0;

  return 0;
}

int * getPlayerPosition(){
  return playerPosition;
}

void setCanFire(){
  canFire = 1;
}