#ifndef BAR_H
#define BAR_H

#include <tuple>
#include "Structs.h"
#include "Drawer.h"



class Bar: public Drawer {
	//Represents a vertical Bar

private:
	size_t m_SCREEN_HEIGHT = 30;
	position m_position_of_upper_point;
	size_t m_lenght_from_upper_point;
	char m_symbol_type;
	bool IsMoveAllowed(direction);
public:
	Bar();
	Bar(position bar_upper_point_position, size_t lenght_from_upper_point, char symbol_type);

	std::tuple<bool, struct position> move_up();
	std::tuple<bool, struct position> move_down();
	void PrintOnScreen();

	char get_symbol_type();
	struct position get_position();
	size_t GetBarLenght();
};





#endif
