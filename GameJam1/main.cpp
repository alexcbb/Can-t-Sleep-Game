#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "PerlinNoise.h"
#include <iostream>
#include <ctime>
#include "Game.h"


int main()
{
    Game game; 
    srand(time(NULL));

    game.update();

    return 0;
}