#include "emitter_component.hpp"

Emitter_component::Emitter_component(int speed, float angle_deg, int range, bool loop) : speed(speed), range(range), loop(loop) {
  angle_rad = glm::radians(angle_deg);
}

void Emitter_component::initialize() {
  transform = owner->get_component<Transform_component>();
  origin = glm::vec2(transform->position.x, transform->position.y);
  transform->velocity = glm::vec2(glm::cos(angle_rad) * speed, glm::sin(angle_rad) * speed);
}

void Emitter_component::update(float delta_time) {
  if (glm::distance(transform->position, origin) > range) {
    if (loop) {
      transform->position.x = origin.x;
      transform->position.y = origin.y;
    }
    else {
      owner->destroy();
    }
  }
}
