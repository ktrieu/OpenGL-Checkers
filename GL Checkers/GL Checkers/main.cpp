#include <SDL.h>
#include <iostream>

#include "Game.h"

//Entry point
int main(int argc, char** argv) {
	Game game = Game();
	game.runLoop();
	return 0;
}