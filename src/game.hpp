#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "entity.hpp"
#include "component.hpp"
#include "entity_manager.hpp"

class Asset_manager;

class Game {
private:
  bool running; //holds true if game running
  SDL_Window* window;
public:
  static Asset_manager* asset_manager;
  static SDL_Renderer* renderer;
  static SDL_Event event;
  static SDL_Rect camera;
  Game();
  virtual ~Game();
  unsigned int old_frameticks{SDL_GetTicks()};
  bool check_running() const;
  void load_level (int level_number);
  void initialize(int width, int height); //does all the boilerplate SDL initialization
  void process_input();
  void update();
  void render();
  void camera_movement();
  void destruct();
  void check_collide();
  void next_level(int level_number);
  void game_over();
};

#endif
