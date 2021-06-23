// Pong_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Pong_Game.h"
#include "Game.h"
#include <conio.h>
#include<windows.h> 
#include <time.h>
//#include <unistd.h>
//#include <pthread.h>
#include <thread>
#include "BallsCreator.h"

#define BALL_DELAY 30
#define TIME_TO_ADD_BALL 15 //in non-fructional seconds

using namespace std;




int main()
{
	Game& my_game = Game::Instance();
	
	std::thread create_balls_thread(BallsCreator::CreateBalls, std::ref(my_game), TIME_TO_ADD_BALL);
	//thread* p_create_balls_thread = &create_balls_thread;


	while (my_game.check_if_game_is_on()) {

		//check if ball & right/left walls collide. If yes- end the game.
		if (my_game.IsBallAndRightAndLeftWallsCollide()) {
			my_game.EndGame();
		}


		//check if ball hits bars or up/down walls . If yes- change its direction
		my_game.DoesBallHitUpOrDownWalls();
		my_game.DoesBallHitLeftOrRightBars();
	


		//Read input from user
		my_game.GetAndHandleKeyPressed();

		//Move ball
		my_game.MoveBall();

		//Draw screen & wait a delay
		my_game.UpdateScreen();

		Sleep(BALL_DELAY);
	}
	
	my_game.PrintGameOver();
	create_balls_thread.join();
	//my_game.DeleteHeap();
	//void* p_my_game = &my_game;
	//delete(p_my_game);

	return 0;
}
