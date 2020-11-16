#include "Asset_manager.hpp"

Asset_manager::Asset_manager(Entity_manager* manager) : manager(manager) {}

void Asset_manager::clear_data() {
  textures.clear();
}

void Asset_manager::add_texture(std::string texture_id, const char* filepath) {
  textures.emplace(texture_id, Texture_manager::load_texture(filepath));
}

SDL_Texture* Asset_manager::get_texture(std::string texture_id) {
  return textures[texture_id];
}
