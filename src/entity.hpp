#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <string>
#include "component.hpp"
#include "entity_manager.hpp"

class Entity_manager;
class Component;

class Entity {
private:
  Entity_manager& manager;
  bool active;
  std::vector<Component*> components;
public:
  std::string name;
  Entity(Entity_manager& manager);
  Entity(Entity_manager& manager, std::string name);
  void update(float delta_time);
  void render();
  void destroy();
  bool check_if_active() const;

  template <typename T, typename... TArgs>
  T& add_component(TArgs&&... args) {
    T* new_component(new T(std::forward<TArgs>(args)...));
    new_component->owner = this;
    components.emplace_back(new_component);
    new_component->initialize();
    return* new_component;
  }
};

#endif
