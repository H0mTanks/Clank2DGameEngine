#include "keyboard_component.hpp"
#include "../config.hpp"

Keyboard_component::Keyboard_component() {}

Keyboard_component::Keyboard_component(std::string up_key, std::string down_key, std::string left_key,
  std::string right_key, std::string shoot_key) {
  this->up_key = get_SDL_keycode(up_key);
  this->down_key = get_SDL_keycode(down_key);
  this->left_key = get_SDL_keycode(left_key);
  this->right_key = get_SDL_keycode(right_key);
  this->shoot_key = get_SDL_keycode(shoot_key);
}

std::string Keyboard_component::get_SDL_keycode(std::string key) {
  if (key.compare("up") == 0) return "1073741906";
  if (key.compare("down") == 0) return "1073741905";
  if (key.compare("left") == 0) return "1073741904";
  if (key.compare("right") == 0) return "1073741903";
  if (key.compare("space") == 0) return "32";
  return std::to_string(static_cast<int>(key[0]));
}

void Keyboard_component::initialize() {
  transform = owner->get_component<Transform_component>();
  sprite = owner->get_component<Sprite_component>();
}

void Keyboard_component::update(float delta_time) {
  if (Game::event.type == SDL_KEYDOWN) {
    std::string key_code = std::to_string(Game::event.key.keysym.sym);

    if (key_code.compare(up_key) == 0) {
      if (transform->position.y > 0) {
        transform->velocity.y = -vel_change;
        transform->velocity.x = 0;
      }
      else {
        transform->position.y = 0;
      }
      sprite->play("up_animation");
    }
    if (key_code.compare(down_key) == 0) {
      if (transform->position.y < WINDOW_HEIGHT - transform->height) {
        transform->velocity.y = vel_change;
        transform->velocity.x = 0;
      }
      else {
        transform->position.y = WINDOW_HEIGHT - transform->height;
      }
      sprite->play("down_animation");
    }
    if (key_code.compare(left_key) == 0) {
      if (transform->position.x > 0) {
        transform->velocity.y = 0;
        transform->velocity.x = -vel_change;
      }
      else {
        transform->position.x = 0;
      }
      sprite->play("left_animation");
    }
    if (key_code.compare(right_key) == 0) {
      if (transform->position.x < WINDOW_WIDTH - transform->width) {
        transform->velocity.y = 0;
        transform->velocity.x = vel_change;
      }
      else {
        transform->position.x = WINDOW_WIDTH - transform->width;
      }
      sprite->play("right_animation");
    }
    if (key_code.compare(shoot_key) == 0) {

    }
  }

  if (Game::event.type == SDL_KEYUP) {
    std::string key_code = std::to_string(Game::event.key.keysym.sym);

    if (key_code.compare(up_key) == 0) {
      transform->velocity.y = 0;
    }
    if (key_code.compare(down_key) == 0) {
      transform->velocity.y = 0;
    }
    if (key_code.compare(left_key) == 0) {
      transform->velocity.x = 0;
    }
    if (key_code.compare(right_key) == 0) {
      transform->velocity.x = 0;
    }
    // if (key_code.compare(shoot_key) == 0) {
    //
    // }
  }
}
