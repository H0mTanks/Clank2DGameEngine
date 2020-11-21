#ifndef TILE_COMPONENT_HPP
#define TILE_COMPONENT_HPP

#include <SDL2/SDL.h>
#include "../../lib/glm/glm.hpp"
#include "../entity_manager.hpp"

class Tile_component : public Component {
public:
  SDL_Texture *texture;
  SDL_Rect source_rect;
  SDL_Rect dest_rect;
  glm::vec2 position;

  Tile_component(int source_x, int source_y, int x, int y, int tile_size, int tile_scale, std::string asset_texture_id);
  ~Tile_component();
  void update(float delta_time) override;
  void render() override;
};

#endif
