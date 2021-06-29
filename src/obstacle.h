#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL.h"
#include <vector>
#include "snake.h"
#include <random>
#include <iostream>
//#include "game.h"

class Snake;

class Obstacle {

public:
    //constrcutor default
    Obstacle(std::size_t grid_width, std::size_t grid_height);


    std::vector<SDL_Point> obstacles;
    bool ObstacleCell(int x, int y);
    bool InsertNewobstacle(int score);
    void PlaceObstacle(Snake snake, int score, SDL_Point food);

    void UpdateObstacle(SDL_Point &obst);
    

private:

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
        



};

#endif