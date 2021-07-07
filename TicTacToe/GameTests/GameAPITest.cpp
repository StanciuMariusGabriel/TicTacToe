#include <gtest/gtest.h>
#include "GameAPI.h"
#include "Board.h"

#include <iostream>

using namespace tictactoe;

class TestSuite : public ::testing::Test
{
public:
	void SetUp()
	{
		emptyGame = IGame::Produce(5, 3);
		Game1 = IGame::Produce(5, 3);
		Game2 = IGame::Produce(5, 3);
		Game3 = IGame::Produce(5, 3);
		Game4 = IGame::Produce(5, 3);
		
	}

public:
	IGame::Game emptyGame;
	IGame::Game Game1;
	IGame::Game Game2;
	IGame::Game Game3;
	IGame::Game Game4;

};