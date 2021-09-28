//Sprite/Screen locations
#define PLAYER_INDEX 0
#define PLAYER_Y_START 110
#define PLAYER_X_START 50
#define X_POSITION 0
#define Y_POSITION 1
#define SPRITE_LOAD_POSITION_X -10 //used to load sprites offscreen
#define SPRITE_LOAD_POSITION_Y -10 //.. .. .. .. ..
#define LEFT_BOUNDARY 42
#define RIGHT_BOUNDARY 106

//Tile indexes
#define TURRET_TILE 0
#define BULLET_TILE 1
#define GROUND_TOP_TILE 2
#define CANNON_BALL_TILE 3

//enum definitions
typedef enum {true, false} bool;

//typedef struct definitions 
typedef struct SpriteData{
  int8_t spritePosition[2];
  int8_t spriteIndex;
} SpriteData;

typedef struct BulletStruct{
  int8_t bulletPosition[2];
  int8_t velocity;
  int8_t active;
}BulletStruct;