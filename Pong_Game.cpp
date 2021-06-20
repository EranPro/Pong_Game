// Pong_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Pong_Game.h"
#include "Game.h"
#include <conio.h>
#include<windows.h>
#include <time.h>

#define BALL_DELAY 30
#define TIME_TO_ADD_BALL 15000;

using namespace std;

int main()
{
	Game& my_game = Game::Instance();


	while (my_game.check_if_game_is_on()) {

		//check if ball & right/left walls collide :
		if (my_game.IsBallAndRightAndLeftWallsCollide()) {
			break;
		}


		//check if ball hits bars or up/down walls . If yes- change its direction
		if (my_game.DoesBallHitUpOrDownWalls()) {

			my_game.ChangeBallYDirection();

		}
		
		if (my_game.DoesBallHitLeftOrRightBars()) {

			my_game.ChangeBallXDirection();
		}



		//Read input from user
		my_game.GetAndHandleKeyPressed();

		//Move ball
		my_game.MoveBall();

		//Draw screen & wait a delay
		my_game.UpdateScreen();

		Sleep(BALL_DELAY);
	}

	my_game.EndGame();


	return 0;
}
