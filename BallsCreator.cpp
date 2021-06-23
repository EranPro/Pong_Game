#include "BallsCreator.h"
#include <windows.h>

void BallsCreator::CreateBalls(Game& my_game, int period_of_creating_a_new_ball)
{
	//receive as input a period in seconds in which a new ball need to be created.

	const int TIME_TO_SLEEP = 1000; //sleep 1 sec in each iteration
	int total_elapsed_time = 0; //elapsed time to create a ne ball
	while (my_game.check_if_game_is_on())
	{
		Sleep(TIME_TO_SLEEP);
		total_elapsed_time++; //add 1 sec that has passed during sleep
		if (total_elapsed_time == period_of_creating_a_new_ball) //if time of creating a ball has arrived: create a new ball + reset counter
		{
			my_game.AddBallToList();
			total_elapsed_time = 0;
		}
		

	}
}
