#include "./assets/cannon_ball_1.c"

int8_t numCannonBalls = 3;

int8_t initialializeCannonBall(int8_t *mainsc);

int8_t initialializeCannonBall(int8_t *mainsc){
    set_sprite_data(CANNON_BALL_TILE, 1, CannonBall);
  for (ix = 0; ix < numCannonBalls; ix++){
      set_sprite_tile(++*mainsc, 3);
      move_sprite(*mainsc, 50 + (ix * 8), 50);
  }
  return 0;
}