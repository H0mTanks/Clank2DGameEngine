#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP value
#include <map>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "texture_manager.hpp"
#include "font_manager.hpp"
#include "entity_manager.hpp"

class Asset_manager {
private:
  Entity_manager* manager;
  std::map<std::string, SDL_Texture*> textures;
  std::map<std::string, TTF_Font*> fonts;
public:
  Asset_manager(Entity_manager* manager);
  ~Asset_manager();
  void clear_data();
  void add_texture(std::string texture_id, const char* filepath);
  void add_font(std::string font_id, const char* filepath, int font_size);
  SDL_Texture* get_texture(std::string texture_id);
  TTF_Font* get_font(std::string font_id);
};

#endif
