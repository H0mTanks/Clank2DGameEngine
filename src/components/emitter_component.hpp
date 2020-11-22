#ifndef EMITTER_COMPONENT_HPP
#define EMITTER_COMPONENT_HPP

#include "../../lib/glm/glm.hpp"
#include "../entity_manager.hpp"
#include "transform_components.hpp"


class Emitter_component : public Component {
private:
  Transform_component* transform;
  glm::vec2 origin;
  int speed;
  int range;
  float angle_rad;
  bool loop;
public:
  Emitter_component(int speed, float angle_deg, int range, bool loop);
  void initialize() override;
  void update(float delta_time) override;
};


#endif
