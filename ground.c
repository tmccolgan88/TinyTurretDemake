#include "./assets/ground_top.c"

typedef struct GroundData{
  int tilePosition[2];
} GroundData;

int8_t ix, jx;
int8_t groundRows = 3;
int8_t groundCols = 8;

int initializeGround(int8_t *);

int initializeGround(int8_t *mainsc){
  
  set_sprite_data(GROUND_TOP_TILE, 1, GroundTop);
  
  for(jx = 0; jx < groundRows; jx++)
    for (ix = 0; ix < groundCols; ix++){
      set_sprite_tile(++*mainsc, 2);
      move_sprite(*mainsc, 40 + (ix * 10), 120 + (jx * 10));
    }

  return 0;
}