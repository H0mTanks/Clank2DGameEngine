#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP value
#include <map>
#include <string>
#include "Texture_manager.hpp"
#include "Entity_manager.hpp"

class Asset_manager {
private:
  Entity_manager* manager;
  std::map<std::string, SDL_Texture*> textures;
public:
  Asset_manager(Entity_manager* manager);
  ~Asset_manager();
  void clear_data();
  void add_texture(std::string texture_id, const char* filepath);
  SDL_Texture* get_texture(std::string texture_id);
};

#endif
