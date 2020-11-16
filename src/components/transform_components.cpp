#include "transform_components.hpp"
#include "../game.hpp"
#include <SDL2/SDL.h>
#include "iostream"

Transform_component::Transform_component(int pos_x, int pos_y, int vel_x, int vel_y, int w, int h, int s) {
  position = glm::vec2(pos_x, pos_y);
  velocity = glm::vec2(vel_x, vel_y);
  width = w;
  height = h;
  scale = s;
  name = "Transform_component";
}

void Transform_component::initialize() {

}

void Transform_component::update(float delta_time) {
  position.x += velocity.x * delta_time;
  position.y += velocity.y * delta_time;
}

void Transform_component::render() {
}
