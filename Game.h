#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Bar.h"
#include "Wall.h"
#include "Structs.h"
#include "Drawer.h"
#include <list>



class Game {
	// class to conatin and manage all screen objects.
private:
	Game();
	
	bool m_is_game_on = true;

	Ball m_ball; 

	Wall m_left_wall;
	Wall m_right_wall;
	Wall m_up_wall;
	Wall m_down_wall;

	Bar m_left_bar;
	Bar m_right_bar;

	std::list<Drawer*> m_drawers_list; //list of drawer object to print
	std::list<Ball*> m_list_of_balls_pointers;

public:
	
	static Game& Instance();

	bool check_if_game_is_on();
	//void quit_game();

	char Read_key_from_user();
	void input_key_handler(char key);
	void GetAndHandleKeyPressed();
	
	bool is_movement_allowed(Bar& bar, direction direction);
	void EndGame();

	bool IsBallAndRightAndLeftWallsCollide();

	void MoveBall();

	bool DoesBallHitUpOrDownWalls();

	bool IsBallInBarRange(Bar bar);
	bool DoesBallHitLeftOrRightBars();

	void ChangeBallXDirection();
	void ChangeBallYDirection();

	void UpdateScreen();

	void AddBallToList();

};
#endif // !GAME_H
