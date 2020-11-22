#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SDL2/SDL.h>

class Collider {
public:
  static bool check_aabb_collision(const SDL_Rect& rectA, const SDL_Rect& rectB);
};


#endif
