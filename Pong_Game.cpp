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

#define BALL_DELAY 30
#define TIME_TO_ADD_BALL 15000

using namespace std;

//pthread_create(thread, attr, start_routine, arg);

void CreateBalls(Game& my_game) {
	while (my_game.check_if_game_is_on()) {
		Sleep(TIME_TO_ADD_BALL);
		my_game.AddBallToList();

	}

}

int main()
{


	Game& my_game = Game::Instance();
	
	std::thread create_balls_thread(CreateBalls, std::ref(my_game));
	//thread* p_create_balls_thread = &create_balls_thread;


	while (my_game.check_if_game_is_on()) {

		//check if ball & right/left walls collide :
		if (my_game.IsBallAndRightAndLeftWallsCollide()) {
			break;
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
	
	create_balls_thread.join();
	my_game.EndGame();
	
	return 0;
}
