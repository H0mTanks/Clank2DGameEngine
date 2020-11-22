#include <iostream>
#include "entity_manager.hpp"
#include "collider.hpp"
#include "components/collider_component.hpp"

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


Collide_type Entity_manager::check_entity_collide() const {
  for (auto& entityA : entities) {
    if (entityA->has_component<Collider_component>()) {
      Collider_component* colliderA = entityA->get_component<Collider_component>();
      for (auto& entityB : entities) {
        if (entityA->name.compare(entityB->name) != 0 && entityB->has_component<Collider_component>()) {
          Collider_component* colliderB = entityB->get_component<Collider_component>();
          if (Collider::check_aabb_collision(colliderA->collider, colliderB->collider)) {
            if (colliderA->collider_tag.compare("PLAYER") == 0 &&
                colliderB->collider_tag.compare("ENEMY") == 0) {
                  return PLAYER_ENEMY_COLLIDE;
            }
            if (colliderA->collider_tag.compare("PLAYER") == 0 &&
                colliderB->collider_tag.compare("PROJECTILE") == 0) {
                  return PLAYER_PROJECTILE_COLLIDE;
            }
            if (colliderA->collider_tag.compare("ENEMY") == 0 &&
                colliderB->collider_tag.compare("FRIENDLY_PROJECTILE") == 0) {
                  return ENEMY_PROJECTILE_COLLIDE;
            }
            if (colliderA->collider_tag.compare("PLAYER") == 0 &&
                colliderB->collider_tag.compare("VEGETATION") == 0) {
                  return PLAYER_VEGETATION_COLLIDE;
            }
            if (colliderA->collider_tag.compare("PLAYER") == 0 &&
                colliderB->collider_tag.compare("LEVEL_COMPLETE") == 0) {
                  return PLAYER_LEVEL_COMPLETE_COLLIDE;
            }
          }
        }
      }
    }
  }
  return NO_COLLIDE;
}


void Entity_manager::update(float delta_time) {
  int sz = entities.size();
  int k = sz;
  // While updating entities move the inactive ones to the end of the vector
  //by swapping with whatever is last
  for (int i=0; i<k; i++) {
    Entity* entity = entities[i];
    entity->update(delta_time);

    if (!entity->check_if_active()) {
      Entity* another = entities[k - 1];
      entities[i] = another;
      entities[k-1] = entity;
      i--;
      k--;
    }
  }

  // Destroy inactive entities
  if (k < sz) {
    entities.erase(entities.begin() + k - 1, entities.end());
  }
}


void Entity_manager::destroy_inactive_entities() {
  for (unsigned int i = 0; i < entities.size(); i++) {
    if (!entities[i]->check_if_active()) {
      entities.erase(entities.begin() + i);
    }
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
