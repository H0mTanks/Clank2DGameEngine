#include "Asset_manager.hpp"

Asset_manager::Asset_manager(Entity_manager* manager) : manager(manager) {}

void Asset_manager::clear_data() {
  textures.clear();
  fonts.clear();
}

void Asset_manager::add_texture(std::string texture_id, const char* filepath) {
  textures.emplace(texture_id, Texture_manager::load_texture(filepath));
}


void Asset_manager::add_font(std::string font_id, const char* filepath, int fontsize) {
  fonts.emplace(font_id, Font_manager::load_font(filepath, fontsize));
}


SDL_Texture* Asset_manager::get_texture(std::string texture_id) {
  return textures[texture_id];
}


TTF_Font* Asset_manager::get_font(std::string font_id) {
  return fonts[font_id];
}
