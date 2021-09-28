#include "./assets/cannon_ball_1.c"

int8_t numCannonBalls = 3;

struct SpriteData * initialializeCannonBall(int8_t *mainsc);
void updateCannonBalls();


SpriteData balls[3];

struct SpriteData * initialializeCannonBall(int8_t *mainsc){
    set_sprite_data(CANNON_BALL_TILE, 1, CannonBall);
  for (ix = 0; ix < numCannonBalls; ix++){
      set_sprite_tile(++*mainsc, 3);
      move_sprite(*mainsc, 50 + (ix * 8), 50);

      balls[ix].spriteIndex = *mainsc;
      balls[ix].spritePosition[X_POSITION] = 50 + (ix * 8);
      balls[ix].spritePosition[Y_POSITION] = 50;

  }
  return balls;
}

void updateCannonBalls(){
  for (ix = 0; i < numCannonBalls; i++){
    ;
  }
}