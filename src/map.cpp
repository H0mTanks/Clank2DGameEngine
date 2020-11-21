#include <fstream>
#include "./game.hpp"
#include "./map.hpp"
#include "./entity_manager.hpp"
#include "./components/tile_component.hpp"

extern Entity_manager manager;
Map::Map(std::string texture_id, int scale, int tile_size) : texture_id(texture_id), scale(scale), tile_size(tile_size) {}

void Map::load_map(std::string filepath, int map_size_x, int map_size_y) {
  std::fstream map_file;
  map_file.open(filepath);

  for (int y = 0; y < map_size_y; y++) {
    for (int x = 0; x < map_size_x; x++) {
      char ch;
      map_file.get(ch);
      int source_y = atoi(&ch) * tile_size;
      map_file.get(ch);
      int source_x = atoi(&ch) * tile_size;
      add_tile(source_x, source_y, x * (scale * tile_size), y * (scale * tile_size));
      map_file.ignore();
    }
  }
  map_file.close();
}

void Map::add_tile(int source_x, int source_y, int x, int y) {
  Entity& new_tile(manager.add_entity("Tile", TILEMAP_LAYER));
  new_tile.add_component<Tile_component>(source_x, source_y, x, y, tile_size, scale, texture_id);
}
