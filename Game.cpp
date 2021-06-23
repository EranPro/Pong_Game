#include "Game.h"
#include <conio.h>
#include "Structs.h"
#include "Ball.h"
#include<windows.h>
#include <iostream>

Game::Game() 

{
	
}

Game& Game::Instance() {

	static Game sinstance;

	//m_is_game_on = true;

	//ball :
	//Methos AddBallToList performs also adding of the ball to Drawer list.
	sinstance.AddBallToList();
	/*
	position ball_position_of_middle_point = { 60,  15 };
	char symbol_type = 'O';
	movement_direction ball_directuin = { 1,1 };
	sinstance.m_ball = Ball(ball_position_of_middle_point, symbol_type, ball_directuin);
	*/

	//left wall:
	position lw_wall_upper_point_position = { 0, 0 };
	size_t lw_lenght_from_upper_point = 25;
	char lw_symbol_type = '|';
	WallType wall_type = vertical;

	sinstance.m_left_wall = Wall(lw_wall_upper_point_position, lw_lenght_from_upper_point, lw_symbol_type, wall_type);

	//right wall:
	position rw_wall_upper_point_position = { 117, 0 };
	size_t rw_lenght_from_upper_point = 25;
	char rw_symbol_type = '|';
	wall_type = vertical;

	sinstance.m_right_wall = Wall(rw_wall_upper_point_position, rw_lenght_from_upper_point, rw_symbol_type, wall_type);

	//upper wall:
	position uw_wall_upper_point_position = { 0, 0 };
	size_t uw_lenght_from_upper_point = 117;
	char uw_symbol_type = '-';
	wall_type = horizental;

	sinstance.m_up_wall = Wall(uw_wall_upper_point_position, uw_lenght_from_upper_point, uw_symbol_type, wall_type);

	//down wall:
	position dw_wall_upper_point_position = { 0, 25 };
	size_t dw_lenght_from_upper_point = 117;
	char dw_symbol_type = '-';
	wall_type = horizental;

	sinstance.m_down_wall = Wall(dw_wall_upper_point_position, dw_lenght_from_upper_point, dw_symbol_type, wall_type);

	//left bar:
	position lb_bar_upper_point_position = { 10, 5 };
	size_t lb_lenght_from_upper_point = 10;
	char lb_symbol_type = '|';


	sinstance.m_left_bar = Bar(lb_bar_upper_point_position, lb_lenght_from_upper_point, lb_symbol_type);


	//right bar:
	position rb_bar_upper_point_position = { 107, 5 };
	size_t rb_lenght_from_upper_point = 10;
	char rb_symbol_type = '|';

	sinstance.m_right_bar = Bar(rb_bar_upper_point_position, rb_lenght_from_upper_point, rb_symbol_type);

	

	// init values for drawer_list :	
	//sinstance.m_drawers_list.push_back(&sinstance.m_ball);

	sinstance.m_drawers_list.push_back(&sinstance.m_right_wall);
	sinstance.m_drawers_list.push_back(&sinstance.m_right_wall);
	sinstance.m_drawers_list.push_back(&sinstance.m_up_wall);
	sinstance.m_drawers_list.push_back(&sinstance.m_down_wall);
	sinstance.m_drawers_list.push_back(&sinstance.m_left_bar);
	sinstance.m_drawers_list.push_back(&sinstance.m_right_bar);


	return sinstance; 
 }


Game::~Game() {
	//delete all balls from heap:
	for (auto& iter:m_list_of_balls_pointers) {
		delete(iter);
	}
	//delete all drawers objects from heap:
	for (auto& iter:m_drawers_list) {
		delete(iter);
	}

}

void Game::DeleteHeap()
{
//delete all balls from heap:
	for (auto& iter:m_list_of_balls_pointers) 
	{
		delete(iter);
	}
	//delete all drawers objects from heap:
	for (auto& iter:m_drawers_list) 
	{
		delete(iter);
	}

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

	case 'z':
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
	if (
		(  (direction == up) && (bar.get_position().y > m_up_wall.get_position().y) ) || //if bar below upper wall AND requested for 'up'
		 (  (direction == down) && (bar.get_position().y + bar.GetBarLenght() < m_down_wall.get_position().y))
		)
	{return true;}

	else { return false; }

}


void Game::EndGame() {

	m_is_game_on = false;
	


}

void Game::PrintGameOver()
{
	SetCursorPos(60, 15);

	COORD cursor_position;
	cursor_position.X = 60;
	cursor_position.Y = 15;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);


	std::cout << "**** Game Over *****";

}

bool Game::IsBallAndRightAndLeftWallsCollide() { //TO DO: change ball check to list of balls checks
	for (auto&iter:m_list_of_balls_pointers) {
		//check for each ball from list of it collides with right and left walls:
		if ((iter->get_position().x <= m_left_wall.get_position().x) ||
			(iter->get_position().x >= m_right_wall.get_position().x) 
			)
		{
			return true;
		}

		
	}

	return false;
	 
}


void Game::UpdateScreen() {
	system("cls");
	
	std::list<Drawer*>::iterator it;
	//std::advance(it, 2);

	Drawer* current_object_to_draw;
	
	for ( it = m_drawers_list.begin(); it != m_drawers_list.end(); ++it) {
		current_object_to_draw = *it;
		current_object_to_draw->PrintOnScreen();
	}
	

	/*
	m_ball.PrintOnScreen();

	m_left_wall.PrintOnScreen();
	m_right_wall.PrintOnScreen();
	m_up_wall.PrintOnScreen();
	m_down_wall.PrintOnScreen();

	m_left_bar.PrintOnScreen();
	m_right_bar.PrintOnScreen();
	*/

}


void Game::MoveBall() {

	for (auto &it:m_list_of_balls_pointers) {
		it->move_ball();

	}
	//m_ball.move_ball();

}

void Game::ChangeBallXDirection() {

	m_ball.ChangeBallXDirection();
}



void Game::ChangeBallYDirection() {
	m_ball.ChangeBallYDirection();
}


void Game::DoesBallHitUpOrDownWalls()
{
	
	for (auto& iter:m_list_of_balls_pointers) {
		if ((iter->get_position().y == m_up_wall.get_position().y) ||
			(iter->get_position().y == m_down_wall.get_position().y)  

			)
		{
			iter->ChangeBallYDirection();
		}
	}

}


bool Game::IsBallInBarRange(Bar bar, Ball& ball) {
	if (	(ball.get_position().x == bar.get_position().x) &&
			( (ball.get_position().y >= bar.get_position().y) && (ball.get_position().y <= bar.get_position().y + bar.GetBarLenght() ) )
		)
	{
		return true;
	}
	else {
		return false;
	}

}


void Game::DoesBallHitLeftOrRightBars()
{
	for (auto& iter: m_list_of_balls_pointers) {

		if ((IsBallInBarRange(m_left_bar, *iter)) || (IsBallInBarRange(m_right_bar, *iter)))
		{
			iter->ChangeBallXDirection();
		}

	}

}

void Game::AddBallToList() {
	
	// Params for a new ball:
	position ball_position_of_middle_point = { 60,  15 };
	char symbol_type = 'O';
	movement_direction ball_directuin = { 1,1 };
	

	Ball* ball_p_ball = new Ball(ball_position_of_middle_point, symbol_type, ball_directuin); //create ball at heap
	m_list_of_balls_pointers.push_back(ball_p_ball); //add pointer to the heap in the game class
	
	Drawer* drawer_p_ball = &(*ball_p_ball); //create drawer pointer to the ball which is in the heap
	m_drawers_list.push_back(drawer_p_ball); //add the pointer to the dr=rawer pointers list for later printing


}
