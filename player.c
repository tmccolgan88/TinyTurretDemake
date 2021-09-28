#include <stdlib.h>
#include "./assets/turret.c"
#include "./assets/bullet.c"

typedef struct BulletStruct{
  int8_t bulletPosition[2];
  int8_t velocity;
  int8_t active;
}BulletStruct;

int8_t i;
int8_t playerPosition[2];
int8_t canFire;
int8_t timeSinceLastFire;
int timeSinceLastUpdate;
int8_t bulletIndex = 0;

BulletStruct *bullets[3];

//function prototypes
int8_t bulletsUpdate();
int8_t fireBullet();
int8_t playerUpdate();
int8_t * initializePlayer(int8_t *mainsc);
int8_t initializeBullets(int8_t *mainsc);
BulletStruct * addBullet();
int * getPlayerPosition();

int8_t bulletsUpdate(){
  for (i = 0; i < 3; i++){
    if (bullets[i]->active == 1){
      bullets[i]->bulletPosition[Y_POSITION] = bullets[i]->bulletPosition[Y_POSITION] - 2;
      move_sprite(i + 1, 
                  bullets[i]->bulletPosition[X_POSITION], 
                  bullets[i]->bulletPosition[Y_POSITION]);

      if (bullets[i]->bulletPosition[Y_POSITION] < -10){
        bullets[i]->active = 0;
      }
    }
  }

  return 0;
}

int8_t playerUpdate(){
    
    //player movement logic
    if ((joypad() & J_LEFT) && playerPosition[0] > LEFT_BOUNDARY){
      playerPosition[X_POSITION]--;
      move_sprite(0, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
    }
    if((joypad() & J_RIGHT) && playerPosition[0] < RIGHT_BOUNDARY){
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

int8_t initializeBullets(int8_t *mainsc){
  for (i = 0; i < 3; i++){
    bullets[i] = malloc(sizeof(BulletStruct));
    bullets[i]->bulletPosition[X_POSITION] = SPRITE_LOAD_POSITION_X + i;
    bullets[i]->bulletPosition[Y_POSITION] = SPRITE_LOAD_POSITION_Y + i;
    bullets[i]->active = 0;
    set_sprite_tile(++*mainsc, 1);
    move_sprite(i + 1, bullets[i]->bulletPosition[X_POSITION] = SPRITE_LOAD_POSITION_X, 
                       bullets[i]->bulletPosition[Y_POSITION] = SPRITE_LOAD_POSITION_Y);
  }

  return 0;
}

int8_t *initializePlayer(int8_t *mainsc){
    playerPosition[0] = PLAYER_X_START;
    playerPosition[1] = PLAYER_Y_START;

    set_sprite_data(TURRET_TILE,1,Turret);
    set_sprite_data(BULLET_TILE,1,Bullet);

    set_sprite_tile(++*mainsc,0);
    move_sprite(0, playerPosition[X_POSITION], playerPosition[Y_POSITION]);
    
    canFire = 0;

    initializeBullets(mainsc);

    return 0; 
}

int8_t fireBullet(){
  if (bullets[bulletIndex]->active == 1)
    return -1;

  bullets[bulletIndex]->bulletPosition[X_POSITION] = playerPosition[X_POSITION];
  bullets[bulletIndex]->bulletPosition[Y_POSITION] = playerPosition[Y_POSITION];
  bullets[bulletIndex]->active = 1;

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