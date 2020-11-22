#ifndef COLLIDER_COMPONENT_HPP
#define COLLIDER_COMPONENT_HPP

#include "../game.hpp"
#include "../entity_manager.hpp"
#include "transform_components.hpp"


class Collider_component: public Component {
public:
  std::string collider_tag;
  SDL_Rect collider;
  SDL_Rect source_rect;
  SDL_Rect dest_rect;
  SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;
  Transform_component* transform;
  SDL_Texture* texture;
  static bool debug;

  Collider_component(std::string collider_tag, int x, int y, int width, int height);
  Collider_component(std::string collider_tag, int x, int y, int width, int height, std::string asset_texture_id);
  void initialize() override;
  void update(float delta_time) override;
  void set_texture(std::string asset_texture_id);
  void render() override;
};


#endif
