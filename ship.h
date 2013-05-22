/*
 *  ship.h
 *  
 *
 *  Created by Shane Germann1 on 12/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SHIP_H
#define SHIP_H

#include <string>
#include "point.h"

using namespace std;


class ship {

private:
	point origin;
	int length, hitCount;
	string name;
	
public:
	bool isVertical;

	
	ship(int l, string n) {length = l; name = n; hitCount = 0;}
	
	void randomlyPlaceShip();

	void setOrigin(point p) {origin = p;}
	void setVertical(bool b) {isVertical = b;}
	int getLength() {return length;}
	point getOrigin() {return origin;}
	string getName() {return name;}
	bool containsPoint(point);
	bool hasConflictWith(ship);
	void bumpHitCount() {hitCount++;}
	bool isAfloat() {return hitCount != length;}
	
	

};

#endif

