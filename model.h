/*
 *  model.h
 *  
 *
 *  Created by Shane Germann1 on 12/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include "ship.h"
#include "point.h"


class model {
private:
	ship* shipFleet[5];
	int rows, columns;
	
public:
	int hitCount, missCount, shotCount;
	
	point hits[17], misses[83], shots[100];
	
	model(int, int);
	void display(ship[], int);
	bool shoot(point);
	bool conflictsWith(ship);
	point getFiringCoordinates();
	bool hitsShip(point, ship[], int);

};






