#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "game.hpp"

class Texture_manager {
public:
  static SDL_Texture* load_texture(const char* filepath);
  static void draw(SDL_Texture* texture, SDL_Rect source_rect,
    SDL_Rect destination_rect, SDL_RendererFlip flip);
};

#endif
