#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(std::size_t grid_width, std::size_t grid_height)
    : engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {}

bool Obstacle::ObstacleCell(int x, int y)
{

    if (obstacles.empty())
    {
        //std::cout << "vector is empty" << std::endl;
        return false;
    } //checks if no obstacles have been placed

    else
    {
        //std::cout << "vector is not empty" << std::endl;

        for (auto &point : obstacles)
        {
            if (x == point.x && y == point.y)
                return true;

            else
                return false;
        }
    }
}
//checks when to insert new obstical
bool Obstacle::InsertNewobstacle(int score)
{
    if (score == 2)
        return true;
    else if (score == 8)
    {
        //std::cout << "score 8 achieved" << std::endl;
        return true;
        }

    else if (score == 10)
        return true;
    else
        return false;
}
void Obstacle::UpdateObstacle(SDL_Point &point)
{
    std::cout << "point inserted in obstacles" << std::endl;
    SDL_Point nextpoint;
    obstacles.push_back(point);

    //create rectangle add another block
    nextpoint.x = point.x + 1;
    nextpoint.y = point.y;
    obstacles.push_back(nextpoint);
}

//need an object of itself to check for not placing new obstalce on top a already existing one
void Obstacle::PlaceObstacle(Snake snake, int score, SDL_Point food)
{

    if (InsertNewobstacle(score))
    { // TODO add score DONE
        SDL_Point point;
        int x, y;
        //place it random
        while (true)
        {
            x = random_w(engine);
            y = random_h(engine);
            //check if location is free, not on food, snake element or obstacle
            if (!snake.SnakeCell(x, y) && x != food.x && y != food.y)
            {
                if (obstacles.empty())
                {
                    //std::cout<<"If empty statement"<< std::endl; //check
                    point.x = x;
                    point.y = y;
                    break;
                }
                else
                {
                    for (SDL_Point const &item : obstacles)
                    {
                        if (x != item.x && y != item.y)
                        { //check if not on obstacle
                            point.x = x;
                            point.y = y;
                        }
                        break;
                    }
                }

                UpdateObstacle(point);
            }
        }
    }
}