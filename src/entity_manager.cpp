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
  for (unsigned int layer_number = 0; layer_number < NUM_LAYERS; layer_number++) {
    for (auto& entity: get_entities_by_layer(static_cast<Layer_type>(layer_number))) {
      entity->render();
    }
  }
}

Entity& Entity_manager::add_entity(std::string name, Layer_type layer) {
  Entity* entity = new Entity(*this, name, layer);
  entities.emplace_back(entity);
  return *entity;
}

std::vector<Entity*> Entity_manager::get_entities_by_layer(Layer_type layer) const {
  std::vector<Entity*> selected_entities;
  for (auto& entity: entities) {
    if (entity->layer == layer) {
      selected_entities.emplace_back(entity);
    }
  }
  return selected_entities;
}

std::vector<Entity*> Entity_manager::get_entities() const {
  return entities;
}

unsigned int Entity_manager::get_entity_count() const {
  return entities.size();
}
