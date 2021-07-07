#include <gtest/gtest.h>
#include "API/GameAPI.h"
#include "Board.h"

#include <iostream>

using namespace tictactoe;

class GameStates : public ::testing::Test
{
public:
	void SetUp()
	{
		emptyGame = IGame::Produce(5, 3);

		Game1 = IGame::Produce(5, 3);
		moveResult1 = Game1->MakeMove(3, 3);
		moveResult2 = Game1->MakeMove(3, 3);
		moveResult3 = Game1->MakeMove(6, 5);

		Game2 = IGame::Produce(5, 3);
		Game2->MakeMove(3, 3);
		Game2->MakeMove(0, 1);
		Game2->MakeMove(3, 2);
		Game2->MakeMove(3, 1);
		Game2->MakeMove(3, 4);

		Game3 = IGame::Produce(5, 3);

		Game3->MakeMove(0, 3);
		Game3->MakeMove(3, 3);
		Game3->MakeMove(0, 1);
		Game3->MakeMove(3, 2);
		Game3->MakeMove(4, 1);
		Game3->MakeMove(3, 1);

		Game4 = IGame::Produce(5, 3);
	}

protected:

	IGame::Game emptyGame;
	IGame::Game Game1;
	IGame::Game Game2;
	IGame::Game Game3;
	IGame::Game Game4;
	EMoveResult moveResult1;
	EMoveResult moveResult2;
	EMoveResult moveResult3;

};

TEST_F(GameStates, InitializationBoardTest)
{
	int count = 0;
	for (int index1 = 0; index1 < emptyGame->GetBoardSize(); ++index1)
		for (int index2 = 0; index2 < emptyGame->GetBoardSize(); ++index2)
			if (emptyGame->GetElementAt(index1, index2) != '-')
				++count;
	ASSERT_EQ(count, 0);
}

TEST_F(GameStates, IntializationSizeTest)
{
	ASSERT_EQ(emptyGame->GetBoardSize(), 5);
}

TEST_F(GameStates, MoveTestSuccess)
{
	ASSERT_EQ(moveResult1, EMoveResult::Success);
}

TEST_F(GameStates, MoveTestOccupied)
{
	ASSERT_EQ(moveResult2, EMoveResult::PositionOccupied);
}

TEST_F(GameStates, MoveTestInvalid)
{
	ASSERT_EQ(moveResult3, EMoveResult::Invalid);
}

TEST_F(GameStates, GetElementTest)
{
	ASSERT_EQ(Game1->GetElementAt(3, 3), 'X');
}

TEST_F(GameStates, GetStateTest)
{
	ASSERT_EQ(Game1->GetState(), EGameState::Playing);
}

TEST_F(GameStates, Player1WinTest)
{
	ASSERT_EQ(Game2->GetState(), EGameState::Player1Win);
}

TEST_F(GameStates, Player2WinTest)
{
	ASSERT_EQ(Game3->GetState(), EGameState::Player2Win);
}