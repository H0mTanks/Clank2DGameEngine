#include "collider_component.hpp"
#include "../asset_manager.hpp"
#include <iostream>

bool Collider_component::debug = 0;

Collider_component::Collider_component(std::string collider_tag, int x, int y, int width, int height) {
  this->collider_tag = collider_tag;
  this->collider = {x, y, width, height};
}

Collider_component::Collider_component(std::string collider_tag, int x, int y, int width, int height, std::string asset_texture_id) {
  this->collider_tag = collider_tag;
  this->collider = {x, y, width, height};
  set_texture(asset_texture_id);
}

void Collider_component::initialize() {
  if (owner->has_component<Transform_component>()) {
    transform = owner->get_component<Transform_component>();
    source_rect = {0, 0, transform->width, transform->height};
    dest_rect = {collider.x, collider.y, collider.w, collider.h};
  }
}

void Collider_component::update(float delta_time) {
  collider.x = static_cast<int>(transform->position.x);
  collider.y = static_cast<int>(transform->position.y);
  collider.w = transform->width * transform->scale;
  collider.h = transform->height * transform->scale;
  dest_rect.x = collider.x - Game::camera.x;
  dest_rect.y = collider.y - Game::camera.y;
}


void Collider_component::set_texture(std::string asset_texture_id) {
  texture = Game::asset_manager->get_texture(asset_texture_id);
}


void Collider_component::render() {
  SDL_PollEvent(&Game::event);
  if(Game::event.type == SDL_KEYDOWN) {
    if (Game::event.key.keysym.sym == SDLK_F11) {
      debug = true;
    }
    if (Game::event.key.keysym.sym == SDLK_F10) {
      debug = false;
    }
  }
  if (debug) {
    Texture_manager::draw(texture, source_rect, dest_rect, sprite_flip);
  }
}
