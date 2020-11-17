#include "./game.hpp"
#include "./map.hpp"
#include "./entity_manager.hpp"

Map::Map(std::string texture_id, int scale, int tile_size) : texture_id(texture_id), scale(scale), tile_size(tile_size) {}

void Map::load_map(std::string filepath, int map_size_x, int map_size_y) {

}

void Map::add_tile(int source_x, int source_y, int x, int y) {
  
}
