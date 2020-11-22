#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SDL2/SDL.h>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const unsigned int FRAMERATE_TARGET = 60;
const unsigned int FRAMERATE_TARGET_TIME = 1000 / FRAMERATE_TARGET; //16ms target time for 60fps

enum Collide_type {
  NO_COLLIDE,
  PLAYER_ENEMY_COLLIDE,
  PLAYER_PROJECTILE_COLLIDE,
  ENEMY_PROJECTILE_COLLIDE,
  PLAYER_VEGETATION_COLLIDE,
  PLAYER_LEVEL_COMPLETE_COLLIDE
};

enum Layer_type {
  TILEMAP_LAYER = 0,
  VEGETATION_LAYER = 1,
  ENEMY_LAYER = 2,
  OBSTACLE_LAYER = 3,
  PLAYER_LAYER = 4,
  PROJECTILE_LAYER = 5,
  UI_LAYER = 6
};

const unsigned int NUM_LAYERS = 7;
const SDL_Color WHITE_COLOR = {255, 255, 255, 255};
const SDL_Color GREEN_COLOR = {0, 255, 0, 255};

#endif
