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

		Game1 = IGame::Produce(6, 3);
		moveResult1 = Game1->MakeMove(3, 3);
		moveResult2 = Game1->MakeMove(3, 3);
		moveResult3 = Game1->MakeMove(7, 5);

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

		Game4 = IGame::Produce(5, 4);
		Game4->MakeMove(3, 3);
		Game4->MakeMove(0, 1);
		Game4->MakeMove(3, 2);
		Game4->MakeMove(2, 1);
		Game4->MakeMove(3, 4);
		Game4->MakeMove(4, 0);
		Game4->MakeMove(3, 1);
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

class TestWinConditions : public::testing::Test
{
public:
	void SetUp()
	{
		Game = IGame::Produce(5, 3);
		GameDraw = IGame::Produce(3, 3);
	}

protected:
	IGame::Game Game;
	IGame::Game GameDraw;
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

TEST_F(GameStates, InitializationActivePlayer)
{
	ASSERT_EQ(emptyGame->GetActivePlayer(), 1);
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

TEST_F(GameStates, TestActivePlayerAfterMoves)
{
	ASSERT_EQ(Game1->GetActivePlayer(), 2);
}

TEST_F(GameStates, GetElementTest)
{
	ASSERT_EQ(Game1->GetElementAt(3, 3), 'X');
}

TEST_F(GameStates, GetStateTest)
{
	ASSERT_EQ(Game1->GetState(), EGameState::Playing);
}

TEST_F(GameStates, Player1WinTestCombo3)
{
	ASSERT_EQ(Game2->GetState(), EGameState::Player1Win);
}

TEST_F(GameStates, Player2WinTestCombo3)
{
	ASSERT_EQ(Game3->GetState(), EGameState::Player2Win);
}

TEST_F(GameStates, Player1WinTestCombo4)
{
	ASSERT_EQ(Game4->GetState(), EGameState::Player1Win);
}

TEST_F(GameStates, ResetGameTest)
{
	Game4->Reset();
	int count = 0;
	for (int index1 = 0; index1 < Game4->GetBoardSize(); ++index1)
		for (int index2 = 0; index2 < Game4->GetBoardSize(); ++index2)
			if (Game4->GetElementAt(index1, index2) != '-')
				++count;
	ASSERT_EQ(count, 0);
}

TEST_F(TestWinConditions, FirstDiagonalWinTest)
{
	Game->MakeMove(1, 1);
	Game->MakeMove(2, 1);
	Game->MakeMove(2, 2);
	Game->MakeMove(1, 0);
	Game->MakeMove(3, 3);
	ASSERT_EQ(EGameState::Player1Win, Game->GetState());
}

TEST_F(TestWinConditions, SecondDiagonalWinTest)
{
	Game->MakeMove(2, 3);
	Game->MakeMove(2, 1);
	Game->MakeMove(3, 2);
	Game->MakeMove(1, 0);
	Game->MakeMove(4, 1);
	ASSERT_EQ(EGameState::Player1Win, Game->GetState());
}

TEST_F(TestWinConditions, VerticalWinTest)
{
	Game->MakeMove(2, 0);
	Game->MakeMove(2, 3);
	Game->MakeMove(2, 1);
	Game->MakeMove(3, 3);
	Game->MakeMove(2, 4);
	Game->MakeMove(4, 3);
	ASSERT_EQ(EGameState::Player2Win, Game->GetState());
}

TEST_F(TestWinConditions, DrawTest)
{
	GameDraw->MakeMove(0, 0);
	ASSERT_EQ(GameDraw->GetElementAt(0, 0), 'X');
	GameDraw->MakeMove(0, 1);
	GameDraw->MakeMove(0, 2);
	GameDraw->MakeMove(1, 1);
	ASSERT_EQ(GameDraw->GetElementAt(1, 1), '0');
	GameDraw->MakeMove(1, 0);
	GameDraw->MakeMove(2, 0);
	GameDraw->MakeMove(1, 2);
	GameDraw->MakeMove(2, 2);
	GameDraw->MakeMove(2, 1);
	ASSERT_EQ(EGameState::Draw, GameDraw->GetState());
}