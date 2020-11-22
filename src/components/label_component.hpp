#ifndef LABEL_COMPONENT_HPP
#define LABEL_COMPONENT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../entity_manager.hpp"
#include "../asset_manager.hpp"
#include "../game.hpp"

class Label_component: public Component {
private:
  SDL_Rect position;
  std::string text;
  std::string font_family;
  SDL_Color color;
  SDL_Texture* texture;
public:
  Label_component(int x, int y, std::string text, std::string font_family, const SDL_Color color);
  void set_label_text(std::string text, std::string font_family);
  void render() override;

};


#endif
