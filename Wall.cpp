#include "Wall.h"
#include <iostream>
#include<windows.h>


Wall::Wall() {


}

Wall::Wall(position wall_upper_point_position, size_t lenght_from_upper_point, char symbol_type, WallType wall_type) {

	m_position_of_upper_point = wall_upper_point_position;
	m_lenght_from_upper_point = lenght_from_upper_point;
	m_symbol_type = symbol_type;
	m_wall_type = wall_type;
}


char Wall::get_symbol_type() {
	return m_symbol_type;

}


struct position Wall::get_position() {
	return m_position_of_upper_point;

}

void Wall::PrintOnScreen() {
	COORD cursor_position;
	
	
	if (m_wall_type == horizental) {
		cursor_position.Y = m_position_of_upper_point.y;

		for (int added_lenght = 0; added_lenght < m_lenght_from_upper_point; added_lenght++) {
			
			cursor_position.X = m_position_of_upper_point.x + added_lenght; 
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);
			std::cout << m_symbol_type;
		}

	}
	
	else if (m_wall_type == vertical) {
		cursor_position.X = m_position_of_upper_point.x;

		for (int added_lenght = 0; added_lenght < m_lenght_from_upper_point; added_lenght++) {
			
			cursor_position.Y = m_position_of_upper_point.y + added_lenght;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);
			std::cout << m_symbol_type;
		}
	}



	
	


}