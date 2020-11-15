#ifndef TRANSFORM_COMPONENT_HPP
#define TRANSFORM_COMPONENT_HPP

#include "../entity_manager.hpp"
#include "../../lib/glm/glm.hpp"
#include "../game.hpp"
#include <SDL2/SDL.h>


class Transform_component: public Component {
public:
  glm::vec2 position;
  glm::vec2 velocity;
  int width;
  int height;
  int scale;

  Transform_component(int pos_x, int pos_y, int vel_x, int vel_y, int w, int h, int s);
  void initialize() override;
  void update(float delta_time) override;
  void render() override;
};

#endif
