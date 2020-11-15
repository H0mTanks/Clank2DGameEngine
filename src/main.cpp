#include <iostream>
#include "config.hpp"
#include "game.hpp"

int main(int argc, char *argv[]) {
  Game *game = new Game();

  game->initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

  while(game->check_running()) {
    game->process_input();
    game->update();
    game->render();
  }

  game->destruct();

  return 0;
}
