#include "entity.hpp"
#include <iostream>

Entity::Entity(Entity_manager& manager): manager(manager), active(true) {}

Entity::Entity(Entity_manager& manager, std::string name, Layer_type layer): manager(manager), active(true), name(name), layer(layer) {}

void Entity::list_all_components() {
  for (auto& component : components) {
    std::cout << component->name << '\n';
  }
}

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
