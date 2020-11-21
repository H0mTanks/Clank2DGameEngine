#include "tile_component.hpp"
#include "../asset_manager.hpp"

Tile_component::Tile_component(int source_x, int source_y, int x, int y,
  int tile_size, int tile_scale, std::string asset_texture_id) {
    texture = Game::asset_manager->get_texture(asset_texture_id);

    source_rect.x = source_x;
    source_rect.y = source_y;
    source_rect.w = tile_size;
    source_rect.h = tile_size;

    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.w = tile_size * tile_scale;
    dest_rect.h = tile_size * tile_scale;

    position.x = x;
    position.y = y;
  }

Tile_component::~Tile_component() {
  SDL_DestroyTexture(texture);
}

void Tile_component::update(float delta_time) {
  dest_rect.x = position.x - Game::camera.x;
  dest_rect.y = position.y - Game::camera.y;
}

void Tile_component::render() {
  Texture_manager::draw(texture, source_rect, dest_rect, SDL_FLIP_NONE);
}
