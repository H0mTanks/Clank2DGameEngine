#include "font_manager.hpp"

TTF_Font* Font_manager::load_font(const char* filename, int fontsize) {
  return TTF_OpenFont(filename, fontsize);
}

void Font_manager::draw(SDL_Texture* texture, SDL_Rect position) {
  SDL_RenderCopy(Game::renderer, texture, NULL, &position);
}
