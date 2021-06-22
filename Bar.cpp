#include "Bar.h"
#include "Structs.h"
#include <tuple>
#include <windows.h>
#include <iostream>

Bar::Bar() {

}

 Bar::Bar(position bar_uppoer_point_position, size_t lenght_from_upper_point, char symbol_type) {
	m_position_of_upper_point = bar_uppoer_point_position;
	m_symbol_type = symbol_type;
	m_lenght_from_upper_point = lenght_from_upper_point;
}

char Bar::get_symbol_type() {
	return m_symbol_type;

}

struct position Bar::get_position() {

	return m_position_of_upper_point;
}


bool Bar::IsMoveAllowed(direction movement_direction) {
	switch (movement_direction){
	case up:
		if (m_position_of_upper_point.y > 0) {
			return true;
		}
		else {
			return false;
		}
		
	case down:
		if (m_position_of_upper_point.y + m_lenght_from_upper_point < m_SCREEN_HEIGHT) {
			return true;
		}
		else {
			return false;
		}

	default:
		return false;
	}
	

}


void Bar::move_down() {

	m_position_of_upper_point.y++;

	/*
	else {
		return std::make_tuple(false, m_position_of_upper_point);
	}
	*/
}



void Bar::move_up() {

	m_position_of_upper_point.y--;

	/*
	else {
		return std::make_tuple(false, m_position_of_upper_point);
	}
	*/
}

size_t Bar::GetBarLenght() {

	return m_lenght_from_upper_point;

}

void Bar::PrintOnScreen() {
	COORD cursor_position;

	for (int added_y_lenght = 0; added_y_lenght < m_lenght_from_upper_point; added_y_lenght++) {
		//SetCursorPos(m_position_of_upper_point.x, m_position_of_upper_point.y + added_y_lenght);

		cursor_position.X = m_position_of_upper_point.x;
		cursor_position.Y = m_position_of_upper_point.y + added_y_lenght;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);

		std::cout << m_symbol_type;
	}



}