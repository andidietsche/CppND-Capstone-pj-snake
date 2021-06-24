#include "obstacle.h"

bool Obstacle::ObstacleCell(int x, int y){
    for (SDL_Point &point : obstacles){
        if(point.x == x && point.y == y) return true;
        else return false;
    }
}
//checks when to insert new obstical
bool Obstacle::InsertNewobstacle(int score){
    if(score == 15) return true;
    else if (score == 25) return true;
    else if (score == 40) return true;
    else return false;

}

void Obstacle::PlaceObstacle(Snake snake, int score, SDL_Point food){
    SDL_Point point;

    if(InsertNewobstacle(score)){ // TODO add score
        int x,y;
        //place it random
        while(true){
        x = random_w(engine);
        y = random_h(engine);
        //check if location is free
        if(!snake.SnakeCell(x,y) && x != food.x && y != food.y) 
            
            point.x = x;
            point.y = y;
        }

    obstacles.push_back(point);
    }

}