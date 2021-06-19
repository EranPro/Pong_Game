#ifndef STRUCTS_H
#define STRUCTS_H
#include <string.h>

struct position {
	short x;
	short y;

};

enum WallType {
	horizental,
	vertical

};

enum direction {
	up,
	down,
	right,
	left
};

struct movement_direction {
	int x;
	int y;
};

#endif