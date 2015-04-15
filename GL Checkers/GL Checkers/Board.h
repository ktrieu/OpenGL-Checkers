#pragma once

#include <vector>
#include <SDL.h>
#include <glm/glm.hpp>
#include <GL\glew.h>
#include <iostream>

#include "SpriteBatch.h"
#include "PieceColor.h"
#include "SavedSquare.h"

class Piece;


class Board {

public:
	Board(App& app);
	~Board();

	void handleInput(SDL_Event& event);
	void update();
	void render(SpriteBatch& batch);

	void load(const std::string& name);
	void save(const std::string& name);

	void getPieceAt(int row, int col);

	glm::vec2 mouseToBoard(glm::vec2 coords);
	glm::vec2 boardToScreen(glm::vec2 coords);
private:
	const int SQUARE_SIZE = 64;
	const int BOARD_SIZE = 8; //This really should only be used with no save files

	float boardX;
	float boardY;

	GLuint darkSquareTex;
	GLuint lightSquareTex;

	App& appRef;

	std::vector< std::vector <Piece *> > boardData; //Stores all pointers to all the pieces in the board, and nullptr for empty spaces;

	SavedSquare pieceToSquare(Piece * piece);
	void addPiece(glm::vec2 coords, PieceColor color, bool king);

	void renderBackground(SpriteBatch& batch);
	void renderPieces(SpriteBatch& batch);

};



