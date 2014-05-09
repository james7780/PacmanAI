/// Random Pacman AI for compo

#include "stdafx.h"
#include "RandomAI.h"
#include <string.h>

/// @param buffer				Board state buffer to read/write to
CRandomAI::CRandomAI(char *buffer, char playerChar)
{
	// Copy board to local buffer
	memcpy(m_board, buffer, BOARD_WIDTH * BOARD_HEIGHT);

	// Make sure we have a terminator so we can use str functions
	m_board[BOARD_WIDTH * BOARD_HEIGHT] = 0;

	// Find player position
	m_playerChar = playerChar;

	char *pc = strchr(m_board, (int)m_playerChar);
	m_playerPosX = (pc - m_board) % BOARD_WIDTH;
	m_playerPosY = (pc - m_board) / BOARD_WIDTH;
}

CRandomAI::~CRandomAI(void)
{
}

// Calculate the next move (updates the board)
void CRandomAI::CalculateMove()
{
	// Rules:
	// 1. Calculate which directions are valid moves
	// 2. Choose a direction randomly
	
	// Erase old pacman
	m_board[m_playerPosX + BOARD_WIDTH * m_playerPosY] = ' ';

	// Write new pacman
	m_playerPosX--;
	m_board[m_playerPosX + BOARD_WIDTH * m_playerPosY] = m_playerChar;

}

// Get the results
/// @param buffer				Destination buffer for the results of AI processing
void CRandomAI::GetBoard(char *buffer)
{
	memcpy(buffer, m_board, BOARD_WIDTH * BOARD_HEIGHT);
}
