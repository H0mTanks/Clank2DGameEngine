#include "tile_component.hpp"
#include "../asset_manager.hpp"

Tile_component::Tile_component(int source_x, int source_y, int x, int y,
  int tile_size, int tile_scale, int asset_texture_id) {

  }

Tile_component::~Tile_component() {
  SDL_DestroyTexture(texture);
}

void Tile_component::update(float delta_time) {

}

void Tile_component::render() {
  Texture_manager::draw(texture, source_rect, dest_rect, SDL_FLIP_NONE);
}
