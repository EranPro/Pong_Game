#ifndef WALL_H
#define WALL_H

#include "Drawer.h"
#include "Structs.h"

class Wall:public Drawer {

private:
	position m_position_of_upper_point;
	size_t m_lenght_from_upper_point;
	WallType m_wall_type;
	char m_symbol_type;
public:
	Wall();
	Wall(position wall_upper_point_position, size_t lenght_from_upper_point, char symbol_type, WallType wall_type);
	char get_symbol_type();
	struct position get_position();
	virtual void PrintOnScreen();
};

#endif