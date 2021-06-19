#include "Ball.h"
#include <conio.h> 
#include <iostream>
#include "Structs.h"
#include<windows.h>


Ball::Ball(position ball_position_of_middle_point, char symbol_type) {
	m_position_of_middle_point = ball_position_of_middle_point;
	m_symbol_type = symbol_type;
	m_ball_direction.x = 1;
	m_ball_direction.y = 1;

}

char Ball::get_symbol_type(){
	return m_symbol_type;

}

struct position Ball::get_position() {
	return m_position_of_middle_point;

}

std::tuple<bool, position> Ball::move_ball() {
	bool can_it_move = true;
	
	//move x axis:
	if (m_ball_direction.x > 0) {
		m_position_of_middle_point.x++;
	}
	if (m_ball_direction.x < 0) {
		m_position_of_middle_point.x--;
	}
	

	//move y axis:
	if (m_ball_direction.y > 0) {
		m_position_of_middle_point.y++;
	}
	if (m_ball_direction.y < 0) {
		m_position_of_middle_point.y--;
	}

	
	return std::make_tuple(can_it_move , get_position()) ;

}


void Ball::ChangeBallDirection() {
	m_ball_direction.x *= -1;
	m_ball_direction.y *= -1;

}

void Ball::PrintOnScreen() {

	//SetCursorPos(m_position_of_middle_point.x, m_position_of_middle_point.y);
	COORD cursor_position;
	cursor_position.X = m_position_of_middle_point.x;
	cursor_position.Y = m_position_of_middle_point.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);
	std::cout << m_symbol_type;
}