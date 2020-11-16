#include <iostream>
#include "entity_manager.hpp"

void Entity_manager::clear() {
  for (auto& entity : entities) {
    entity->destroy();
  }
}

bool Entity_manager::check_no_entities() {
  return entities.size() == 0;
}

void Entity_manager::list_all_entities() {
  for (auto& entity : entities) {
    std::cout << entity->name << '\n';
    entity->list_all_components();
  }
}

void Entity_manager::update(float delta_time) {
  for (auto& entity : entities) {
    entity->update(delta_time);
  }
}

void Entity_manager::render() {
  for (auto& entity : entities) {
    entity->render();
  }
}

Entity& Entity_manager::add_entity(std::string name) {
  Entity* entity = new Entity(*this, name);
  entities.emplace_back(entity);
  return *entity;
}

std::vector<Entity*> Entity_manager::get_entities() const {
  return entities;
}

unsigned int Entity_manager::get_entity_count() const {
  return entities.size();
}
