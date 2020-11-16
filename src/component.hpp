#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <string>

class Entity;

class Component {
public:
  Entity* owner;
  std::string name = "Component";
  virtual ~Component() {}
  virtual void initialize() {}
  virtual void update(float delta_time) {}
  virtual void render() {}

};


#endif
