/*
 *  point.h
 *  
 *
 *  Created by Shane Germann1 on 12/5/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;


class point{
private:
	
public:
	int x;
	int y;
	
	point(int a, int b) {x = a; y = b;}
	point() {x = 0, y = 0;}
	bool operator==(point& p) {return x == p.x && y == p.y;}
	void operator=(const point& p) {
		x = p.x;
		y = p.y;
	}

};

ostream& operator <<(ostream& out, point p);

#endif