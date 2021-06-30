#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "obstacle.h"

class Obstacle;

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(std::size_t grid_width, std::size_t grid_height); //error Unterschied zu game, std::size_t und hier int
         

  void Update(); 

  void GrowBody();
  bool SnakeCell(int x, int y);


  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
  Obstacle* obstacle;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell); //, Obstacle* obstacle new, Game game

  bool growing{false};
  int grid_width;
  int grid_height;
  
};

#endif