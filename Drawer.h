//#include <WinBase.h>
//#include <processenv.h>
//#include <WinBase.h>
#ifndef DRAWER_H
#define DRAWER_H

//#include "Ball.h"
//#include "Bar.h"
//#include "Wall.h"

class Drawer {
private:
	//HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


public:
	//Drawer();
	virtual void PrintOnScreen() = 0;
	/*
	void clear_screen();
	void print_on_screen(Bar&);
	void print_on_screen(Ball&);
	void print_on_screen(Wall&);
	*/
};




#endif