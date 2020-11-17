#include <iostream>
#include "config.hpp"
#include "game.hpp"
#include "./components/transform_components.hpp"
#include "./components/sprite_component.hpp"
#include "./components/keyboard_component.hpp"
#include "../lib/glm/glm.hpp"

Entity_manager manager;
Asset_manager* Game::asset_manager = new Asset_manager(&manager);
SDL_Renderer* Game::renderer;
SDL_Event Game::event;


Game::Game() {
  running = false;
}


Game::~Game() {

}


bool Game::check_running() const {
  return running;
}


void Game::initialize(int width, int height) {
  //initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cerr << "Error Initializing SDL" << '\n';
    return;
  }

  //Create Wind
  window = SDL_CreateWindow(
    "2DGameEngine",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width, height,
    SDL_WINDOW_BORDERLESS
  );

  if (!window) {
    std::cerr << "Error creating Window" << '\n';
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    std::cerr << "Error creating renderer" << '\n';
    return;
  }

  load_level(0);

  running = true;
  return;
}

void Game::process_input() {
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT: {
      running = false;
      break;
    }
    case SDL_KEYDOWN: {
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
      }
    }
    default: {
      break;
    }
  }
}


void Game::update() {
  //Wait until 16ms has ellapsed
  unsigned int wait_time = FRAMERATE_TARGET_TIME - (SDL_GetTicks() - old_frameticks);

  // Only sleep if target time hasn't elapsed
  if (wait_time < 0 && wait_time <= old_frameticks) {
    SDL_Delay(wait_time);
  }
  //calculate delta time in seconds(i.e divide it by 1000)
  float delta_time = (SDL_GetTicks() - old_frameticks) / 1000.0f;

  old_frameticks = SDL_GetTicks(); //old frameticks in milliseconds

  //cap delta_time
  delta_time = (delta_time > 0.05f) ? 0.05f : delta_time;

  manager.update(delta_time);
}


void Game::load_level(int level_number) {
  asset_manager->add_texture("tank-image", std::string("./assets/images/tank-big-right.png").c_str());
  asset_manager->add_texture("chopper-image", std::string("./assets/images/chopper-spritesheet.png").c_str());
  asset_manager->add_texture("radar-image", std::string("./assets/images/radar.png").c_str());

  Entity& chopper_entity(manager.add_entity("chopper"));
  chopper_entity.add_component<Transform_component>(240, 106, 0, 0, 32, 32, 1);
  chopper_entity.add_component<Sprite_component>("chopper-image", 2, 90, true, false);
  chopper_entity.add_component<Keyboard_component>("up", "down", "left", "right", "space");


  Entity& tank_entity(manager.add_entity("tank"));
  tank_entity.add_component<Transform_component>(0, 0, 20, 20, 32, 32, 1);
  tank_entity.add_component<Sprite_component>("tank-image");
  // std::cout << tank.has_component<Sprite_component>() << '\n';


  Entity& radar_entity(manager.add_entity("radar"));
  radar_entity.add_component<Transform_component>(720, 15, 0, 0, 64, 64, 1);
  radar_entity.add_component<Sprite_component>("radar-image", 8, 150, false, true);

  manager.list_all_entities();
}


void Game::render() {
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);

  if (manager.check_no_entities()) {
    return;
  }

  manager.render();
  SDL_RenderPresent(renderer);
  //debug code for pausing at first frame, use ESC to quit
  // while (true) {
  //   SDL_Event event;
  //   SDL_PollEvent(&event);
  //   if (event.type == SDL_KEYDOWN) {
  //     if (event.key.keysym.sym == SDLK_ESCAPE) {
  //       running = false;
  //       return;
  //     }
  //   }
  // }
}


void Game::destruct() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
