#include "./assets/ground_top.c"

typedef struct GroundData{
  int tilePosition[2];
} GroundData;

int ix, jx;
//GroundData grounds [2];
int grounds [8];

int initializeGround();

int initializeGround(){
  set_sprite_data(spriteCount, 1, GroundTop);
  set_sprite_tile(spriteCount, 2);
  /*for (ix = 0; ix < sizeof(grounds) / sizeof (*grounds); ix++){
    set_sprite_tile(spriteCount + ix, 2);
    move_sprite(2 + ix, 40 + (ix * 10), 120);
  }*/

  return 0;
}