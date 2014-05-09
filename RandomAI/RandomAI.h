#pragma once

#define BOARD_WIDTH			30
#define BOARD_HEIGHT		30
#define TIMEOUT					3700

class CRandomAI
{
public:
	CRandomAI(char *buffer);
	~CRandomAI();

	// Get the results
	void GetBoard(char *buffer);

private:
	char m_board[1000];
};
