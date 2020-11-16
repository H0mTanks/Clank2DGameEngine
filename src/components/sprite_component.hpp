#ifndef SPRITE_COMPONENT_HPP
#define SPRITE_COMPONENT_HPP

#include <SDL2/SDL.h>
#include "transform_components.hpp"
#include "../texture_manager.hpp"
#include "../asset_manager.hpp"
#include "../animation.hpp"

class Sprite_component: public Component {
private:
  Transform_component* transform;
  SDL_Texture* texture;
  SDL_Rect source_rect;
  SDL_Rect dest_rect;
  bool animated;
  int num_frames;
  int animation_speed;
  bool fixed;
  std::map<std::string, Animation> animations;
  std::string current_animation_name;
  unsigned int animation_index = 0;

public:
  SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;
  Sprite_component(const char* filename);
  Sprite_component(std::string animation_id, int num_frames, int animation_speed,
    bool direction, bool fixed);
  void play(std::string animation_name);
  void set_texture(std::string asset_texture_id);
  void initialize() override;
  void update(float delta_time) override;
  void render() override;

};

#endif
