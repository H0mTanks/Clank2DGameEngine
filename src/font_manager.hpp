#ifndef FONT_MANAGER
#define FONT_MANAGER

#include "game.hpp"

class Font_manager {
public:
  static TTF_Font* load_font(const char* filename, int fontsize);
  static void draw(SDL_Texture* texture, SDL_Rect position);
};


#endif
