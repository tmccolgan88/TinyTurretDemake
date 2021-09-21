#include "./assets/ground_top.c"

typedef struct GroundData{
  int tilePosition[2];
} GroundData;

int ix, jx;
//GroundData grounds [2];
int grounds [3][8];

int initializeGround(int8_t *);

int initializeGround(int8_t *mainsc){
  for(jx = 0; jx < sizeof(grounds) / sizeof (*grounds); jx++)
    for (ix = 0; ix < sizeof(grounds[jx]) / sizeof (*grounds[jx]); ix++){
      set_sprite_data(++*mainsc, 1, GroundTop);
      set_sprite_tile(*mainsc, 4);
      move_sprite(*mainsc, 40 + (ix * 10), 120 + (jx * 10));
    }

  return 0;
}