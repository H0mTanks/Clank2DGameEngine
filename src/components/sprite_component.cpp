#include "sprite_component.hpp"

Sprite_component::Sprite_component(std::string asset_texture_id) {
  name = "Sprite_component";
  animated = false;
  fixed = false;
  set_texture(asset_texture_id);
}

Sprite_component::Sprite_component(std::string animation_id, int num_frames, int animation_speed,
   bool direction, bool fixed) {
  animated = true;
  this->num_frames = num_frames;
  this->animation_speed = animation_speed;
  this->fixed = fixed;

  if (direction) {
    Animation down_animation = Animation(0, num_frames, animation_speed);
    Animation right_animation = Animation(1, num_frames, animation_speed);
    Animation left_animation = Animation(2, num_frames, animation_speed);
    Animation up_animation = Animation(3, num_frames, animation_speed);

    animations.emplace("down_animation", down_animation);
    animations.emplace("right_animation", right_animation);
    animations.emplace("left_animation", left_animation);
    animations.emplace("up_animation", up_animation);

    this->animation_index = 0;
    this->current_animation_name = "down_animation";
  }
  else {
    Animation single_animation = Animation(0, num_frames, animation_speed);
    animations.emplace("single_animation", single_animation);
    this->animation_index = 0;
    this->current_animation_name = "single_animation";
  }
  play(this->current_animation_name);
  set_texture(animation_id);
}


void Sprite_component::play(std::string animation_name) {
  num_frames = animations[animation_name].num_frames;
  animation_index = animations[animation_name].index;
  animation_speed = animations[animation_name].animation_speed;
  current_animation_name = animation_name;
}


void Sprite_component::set_texture(std::string asset_texture_id) {
  texture = Game::asset_manager->get_texture(asset_texture_id);
}


void Sprite_component::initialize() {
  transform = owner->get_component<Transform_component>();
  source_rect.x = 0;
  source_rect.y = 0;
  source_rect.w = transform->width;
  source_rect.h = transform->height;
}


void Sprite_component::update(float delta_time) {
  if (animated) {
    source_rect.x = source_rect.w * static_cast<int>((SDL_GetTicks() / animation_speed) % num_frames);
  }
  source_rect.y = animation_index * transform->height;

  dest_rect.x = static_cast<int>(transform->position.x) - (fixed ? 0 : Game::camera.x);
  dest_rect.y = static_cast<int>(transform->position.y) - (fixed ? 0 : Game::camera.y);
  dest_rect.w = transform->width * transform->scale;
  dest_rect.h = transform->height * transform->scale;
}

void Sprite_component::render() {
  Texture_manager::draw(texture, source_rect, dest_rect, sprite_flip);
}
