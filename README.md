# CPPND: Capstone Snake Game 

As my final project I added a feature to the given Snake game. This feature creates obstacles depending on how many scores you reached. So with increasing score more obstacles are placed. The obstacles are rendred in red. 

Since I wanted to really understand object oriented programming I added a new class Obstacle. I really had some issues at the beginning, because my architecture doesn't made sense. So with this Capstone project I have hone my skills regarding OOP and how to integrate new .cpp files in a bigger project, regarding the CMakeLists.txt file and how to add new executables.

<img src="snake_game.gif"/>


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg


## Met Project Specification

*Loops, Functions, I/O
	-loops and functions look at the obstacle.cpp file

*Object Oriented Programming
	-New Class obstacle is added (look at obstacle.cpp/obstalce.h)
	-All class data members are explicitly specified as public, protected, or private
	-All class members are set to argument calues are initialized through member initialization lists. (obstacle.cpp construtor)
	-All class member functions document their effects, implementation either through function names,comments, or details from formal documentation. Member functions do nottheir interfaces. change program 		state in undocumented ways.

## What is new
The class Obstacle has to check whether a new obstacle should be placed or not. So I added a member variable of type Obstacle to the class Snake. So in the class Game we only need a member variable of typ Snake to acces the obstacle. When placing an obstacle we have to check that it is not placed on top on the snake's body nor on the food, so when we make add a member of type obstacle to the class snake we can easy passover the snake's body. After the score hits 10, 20 and 30 one new obstacle is added is red.


