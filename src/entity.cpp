#include "entity.hpp"

Entity::Entity(Entity_manager& manager): manager(manager), active(true) {}

Entity::Entity(Entity_manager& manager, std::string name): manager(manager), active(true), name(name) {}

void Entity::update(float delta_time) {
  for (auto& component: components) {
    component->update(delta_time);
  }
}

void Entity::render() {
  for (auto& component: components) {
    component->render();
  }
}

void Entity::destroy() {
  active = false;
}

bool Entity::check_if_active() const {
  return active;
}
