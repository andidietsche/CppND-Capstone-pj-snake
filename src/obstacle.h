#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL.h"
#include <vector>
#include "snake.h"
#include <random>
//#include "game.h"


class Obstacle {

public:
    //constrcutor
    Obstacle(){};
    bool ObstacleCell(int x, int y);
    bool InsertNewobstacle(int score);
    void PlaceObstacle(Snake snake, int score, SDL_Point food);
        


private:
    std::vector<SDL_Point> obstacles;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
        



};

#endif