/*
 *  point.cpp
 *  
 *
 *  Created by Shane Germann1 on 12/10/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "point.h"

using namespace std;

ostream& operator <<(ostream& out, point p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}
