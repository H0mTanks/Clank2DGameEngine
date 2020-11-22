#include "label_component.hpp"

Label_component::Label_component(int x, int y, std::string text, std::string font_family, const SDL_Color color) {
  position.x = x;
  position.y = y;
  this->text = text;
  this->font_family = font_family;
  this->color = color;
  set_label_text(text, font_family);
}


void Label_component::set_label_text(std::string text, std::string font_family) {
  SDL_Surface* surface = TTF_RenderText_Blended(Game::asset_manager->get_font(font_family), text.c_str(), color);
  texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
  SDL_FreeSurface(surface);
  SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}


void Label_component::render() {
  Font_manager::draw(texture, position);
}
