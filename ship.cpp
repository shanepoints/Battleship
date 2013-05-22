/*
 *  ship.cpp
 *  
 *
 *  Created by Shane Germann1 on 12/5/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <string>
#include <iostream>
#include "point.h"
#include "ship.h"

using namespace std;

void ship::randomlyPlaceShip() {
	//bool hasConflict = true;
	//while (hasConflict) {
	
	srand(time(NULL));
	bool b = rand() % 2;
	setVertical(b);
	if(isVertical) {
		srand(time(NULL));
		int rx = rand() % 10 + 1;
		int ry = rand() % (10 - (getLength() - 1)) + 1;
		point r(rx, ry);
		setOrigin(r);
	}else {
		srand(time(NULL));
		int rx = rand() % (10 - (getLength() - 1)) + 1;
		int ry = rand() % 10 + 1;
		point r(rx, ry);
		setOrigin(r);
	}
	//}
	
}

bool ship::containsPoint(point p) {
	if(isVertical && origin.x == p.x) {
		for(int i = origin.y; i < (origin.y + length); i++) {
			if(i == p.y) return true;
		}
	}else if(!isVertical && origin.y == p.y) {
		for(int i = origin.x; i < (origin.x + length); i++) {
			if(i == p.x) return true;
		}
	}
	return false;
}

bool ship::hasConflictWith(ship s) {
	point p;
	if(isVertical) {
		for(int i = origin.y; i < (origin.y + length); i++) {
			p.x = origin.x;
			p.y = i;
			if(s.containsPoint(p)) {
				return true;
			}
		}
	}else if(!isVertical) {
		for(int i = origin.x; i < (origin.x + length); i++) {
			p.x = i;
			p.y = origin.y;
			if(s.containsPoint(p)) {
				return true;
			}
		}
	}
	return false;
}










