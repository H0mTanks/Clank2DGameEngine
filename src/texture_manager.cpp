#include "texture_manager.hpp"


//textures are the GPU rendering equivalent of surfaces. Hence, textures are
//almost always created from surfaces, using the function SDL_CreateTextureFromSurface().
//This function more or less does what you'd expect—the parameters are the
//rendering context and a surface to create the texture from. As with other
//creation functions, it will return NULL on failure.
//SDL surface stores in RAM and is used for software rendering
SDL_Texture* Texture_manager::load_texture(const char* filepath) {
  SDL_Surface* surface = IMG_Load(filepath);
  //convert surface to texture for rendering (textures are more optimized)
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

void Texture_manager::draw(SDL_Texture* texture, SDL_Rect source_rect, SDL_Rect dest_rect, SDL_RendererFlip flip) {
  SDL_RenderCopyEx(Game::renderer, texture, &source_rect, &dest_rect, 0, nullptr, flip);
}
