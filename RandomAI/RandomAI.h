#pragma once

#define BOARD_WIDTH			21			// includes 0D 0A newline chars
#define BOARD_HEIGHT		22
#define TIMEOUT					3700

class CRandomAI
{
public:
	CRandomAI(char *buffer, char playerChar = 'A');
	~CRandomAI();

	// Calculate the next move
	void CalculateMove();

	// Get the results
	void GetBoard(char *buffer);

private:
	char m_board[BOARD_WIDTH * BOARD_HEIGHT];
	char m_playerChar;
	int m_playerPosX;
	int m_playerPosY;
};
