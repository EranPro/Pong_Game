#include "Game.h"
#include <conio.h>
#include "Structs.h"
#include "Ball.h"
#include<windows.h>
#include <iostream>

Game::Game() 

{
	m_is_game_on = true;


	position ball_position_of_middle_point = { 60,  15 };
	char symbol_type = 'O';
	Ball m_ball = Ball(ball_position_of_middle_point, symbol_type);

	//left wall:
	position lw_wall_upper_point_position = { 0, 0 };
	size_t lw_lenght_from_upper_point = 20;
	char lw_symbol_type = '|';
	WallType wall_type = vertical ;
	
	Wall m_left_wall = Wall(lw_wall_upper_point_position, lw_lenght_from_upper_point, lw_symbol_type, wall_type);

	//right wall:
	position rw_wall_upper_point_position = { 30, 0 };
	size_t rw_lenght_from_upper_point = 20;
	char rw_symbol_type = '|';
	wall_type = vertical;

	Wall m_right_wall = Wall(rw_wall_upper_point_position, rw_lenght_from_upper_point, rw_symbol_type, wall_type);

	//upper wall:
	position uw_wall_upper_point_position = { 0, 0 };
	size_t uw_lenght_from_upper_point = 30;
	char uw_symbol_type = '-';
	wall_type = horizental;

	Wall m_up_wall = Wall(uw_wall_upper_point_position, uw_lenght_from_upper_point, uw_symbol_type, wall_type);

	//down wall:
	position dw_wall_upper_point_position = { 0, 20 };
	size_t dw_lenght_from_upper_point = 30;
	char dw_symbol_type = '-';
	wall_type = horizental;

	Wall m_down_wall = Wall(dw_wall_upper_point_position, dw_lenght_from_upper_point, dw_symbol_type, wall_type);

	//left bar:
	position lb_bar_upper_point_position = { 10, 0 };
	size_t lb_lenght_from_upper_point = 20;
	char lb_symbol_type = '|';
	

	Bar m_left_bar = Bar(lb_bar_upper_point_position, lb_lenght_from_upper_point, lb_symbol_type);


	//right bar:
	position rb_bar_upper_point_position = { 30, 0 };
	size_t rb_lenght_from_upper_point = 20;
	char rb_symbol_type = '|';

	Bar m_right_bar = Bar(rb_bar_upper_point_position, rb_lenght_from_upper_point, rb_symbol_type);
}

Game& Game::Instance() {
	
	static Game sinstance; 
	return sinstance; 
 }


char Game::Read_key_from_user() {

	char key = 0;

	if (_kbhit())
	{
		key = _getch();
		
	}

	// TODO: read the user input (cin) every cycle

	return key;

}



void Game::input_key_handler(char key) {
	direction direction;
	switch (key)
	{
	case 'w':
		if (is_movement_allowed(m_left_bar, direction = up)) {
			m_left_bar.move_up();
		}		
		break;

	case 's':
		if (is_movement_allowed(m_left_bar, direction = down)) {
			m_left_bar.move_down();
		}
		break;

	case 'i':
		if (is_movement_allowed(m_right_bar, direction = up)) {
			m_right_bar.move_up();
		}
		break;

	case 'm':
		if (is_movement_allowed(m_right_bar, direction = down)) {
			m_right_bar.move_down();
		}
		break;

	case 'q':
		m_is_game_on = false;
		break;

	}
	
}

void Game::GetAndHandleKeyPressed() {

	char input_char_from_user = Read_key_from_user();
	input_key_handler(input_char_from_user);

}


/*
void Game::quit_game() {
	m_is_game_on = false;

}

*/

bool Game::check_if_game_is_on() {

	return m_is_game_on;

}


bool Game::is_movement_allowed(Bar& bar, direction direction) {


	return true;
}


void Game::EndGame() {

	SetCursorPos(20, 20);
	std::cout << "**** Game Over *****";


}

bool Game::IsBallAndRightAndLeftWallsCollide() {
	if ( (m_ball.get_position().x <= m_left_wall.get_position().x)   ||
		 (m_ball.get_position().x >= m_right_wall.get_position().x)  //||
		 //(m_ball.get_position().y <= m_up_wall.get_position().y)     ||
		 //(m_ball.get_position().y >= m_down_wall.get_position().y)  
		
		)
	{
		return true;
	}

	return false;
	 
}


void Game::UpdateScreen() {
	system("cls");
	
	m_ball.PrintOnScreen();

	m_left_wall.PrintOnScreen();
	m_right_wall.PrintOnScreen();
	m_up_wall.PrintOnScreen();
	m_down_wall.PrintOnScreen();

	m_left_bar.PrintOnScreen();
	m_right_bar.PrintOnScreen();


}


void Game::MoveBall() {

	m_ball.move_ball();

}

void Game::ChangeBallDirection() {

	m_ball.ChangeBallDirection();
}

bool Game::DoesBallHitUpOrDownWalls()
{
	if ((m_ball.get_position().y == m_up_wall.get_position().y) ||
		(m_ball.get_position().y == m_down_wall.get_position().y)  //||
		//(m_ball.get_position().y <= m_up_wall.get_position().y)     ||
		//(m_ball.get_position().y >= m_down_wall.get_position().y)  

		)
	{
		return true;
	}

	return false;
}

bool Game::DoesBallHitLeftOrRightBars()
{
	if ((m_ball.get_position().x == m_left_bar.get_position().x) ||
		(m_ball.get_position().x == m_right_bar.get_position().x)  //||
		//(m_ball.get_position().y <= m_up_wall.get_position().y)     ||
		//(m_ball.get_position().y >= m_down_wall.get_position().y)  

		)
	{
		return true;
	}

	return false;
}
