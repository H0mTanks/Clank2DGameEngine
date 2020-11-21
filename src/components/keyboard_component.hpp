#ifndef KEYBOARD_COMPONENT_HPP
#define KEYBOARD_COMPONENT_HPP

#include "../game.hpp"
#include "../entity_manager.hpp"
#include "transform_components.hpp"
#include "sprite_component.hpp"

class Keyboard_component : public Component {
public:
  std::string up_key;
  std::string down_key;
  std::string left_key;
  std::string right_key;
  std::string shoot_key;
  int vel_change = 50;
  Transform_component* transform;
  Sprite_component* sprite;
  Keyboard_component();
  Keyboard_component(std::string up_key, std::string down_key, std::string right_key,
    std::string left_key, std::string shoot_key);
  std::string get_SDL_keycode(std::string key);
  void initialize() override;
  void update(float delta_time) override;

};


#endif
