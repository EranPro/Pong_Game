#ifndef BALL_H
#define BALL_H

#include <tuple>
#include "Structs.h"
#include "Drawer.h"

class Ball:public Drawer {
private:
	position m_position_of_middle_point;
	movement_direction m_ball_direction;
	// TO ADD VOLUME TO THE BALL
	char m_symbol_type;
public:
	Ball();
	Ball(position ball_position_of_middle_point, char symbol_type, movement_direction ball_direction);
	
	char get_symbol_type();
	struct position get_position();

	void ChangeBallXDirection();
	void ChangeBallYDirection();

	std::tuple<bool, position> move_ball();

	virtual void PrintOnScreen();

};



#endif