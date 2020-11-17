#ifndef MAP_HPP
#define MAP_HPP

#include <string>

class Map {
private:
  std::string texture_id;
  int scale;
  int tile_size;
public:
  Map(std::string texture_id, int scale, int tile_size);
  ~Map();
  void load_map(std::string filepath, int map_size_x, int map_size_y);
  void add_tile(int source_x, int source_y, int x, int y);
};


#endif
