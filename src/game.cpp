#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
//,obstacle(new Obstacle(grid_width, grid_height))
{
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // for (auto const &point : snake.obstacle->obstacles)
    // {                                                    //TEST
    //   std::cout << "point.x = " << point.x << std::endl; //TEST
    //   std::cout << "point.y = " << point.y << std::endl; //TEST
    // }

    // std::cout << "food.x = " << food.x << std::endl; //TEST
    // std::cout << "food.y = " << food.y << std::endl; //TEST

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item or obstacle before placing
    // food.
    if (!snake.SnakeCell(x, y) && !snake.obstacle->ObstacleCell(x, y))
    {
      food.x = x;
      food.y = y;
    }

    return;
  }
}

void Game::PlaceObstacle()
{
  int x, y;
  //std::cout << "obstacle should be placed" << std::endl;
  SDL_Point point; //have privat member now (wall)

  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);

    // Check that the location is not occupied by a snake item or obstacle before placing
    // food.
    if (!snake.SnakeCell(x, y) && x != food.x && y != food.y)
    {
      if (snake.obstacle->obstacles.empty())
      {
        point.x = x;
        point.y = y;
      }
      else
      {
        for (auto const &item : snake.obstacle->obstacles)
        {
          //check if not on obstacle
          if (x != item.x && y != item.y)
          {
            point.x = x;
            point.y = y;
          }
        }
      }
    }
    break;
  }
  snake.obstacle->UpdateObstacle(point);
}

void Game::Update()
{
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    score++;
    PlaceFood();
    //check if obstacle should be placed
    if (snake.obstacle->InsertNewobstacle(score))
    {
      PlaceObstacle();
      //std::cout << "Placeobstacle()" << std::endl; //test
    }

    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
