/*
 *  main.cpp
 *  
 *
 *  Created by Shane Germann1 on 12/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <cstring>
#include "model.h"
#include "point.h"
#include "ship.h"


using namespace std;


int main() {
	ship acCarrier(5, "Aircraft Carrier");
	ship battleShip(4, "Battleship");
	ship submarine(3, "Submarine");
	ship destroyer(3, "Destroyer");
	ship patrol(2, "Patrol Boat");
	ship shipFleet[5] = {acCarrier, battleShip, submarine, destroyer, patrol};
	

	
	model board(10, 10);
	shipFleet[0].randomlyPlaceShip();
	for (int i = 1; i < 5; i++) {   // this loop initialazes the board model
		bool conflict = true;
		while (conflict) {
			conflict = false;
			shipFleet[i].randomlyPlaceShip();
			for (int j = 0; j < i; j++) {
				if (shipFleet[j].hasConflictWith(shipFleet[i])) {
					conflict = true;
					break;
				}
			}
		}
	}
	cout << "\n\n   Welcome to Battleship!\n\n";
	cout << "Here is a grid of the enemy sea:\n\n";
	
	board.display(shipFleet, 5);
	
	cout << "\n    Fire away, Captain!\n";
	bool gameOver = false;
	while (!gameOver) {
		cout << endl << endl;
		point p = board.getFiringCoordinates();
		if (!board.hitsShip(p, shipFleet, 5)) cout << "\n\nmiss...\n\n";
		board.display(shipFleet, 5);
		if (!shipFleet[1].isAfloat()) gameOver = true;
		else cout << "\nHave another Shot!";
	}
	cout << "\n\n  Battleship Destroyed!! You Won!!\n\n\n";
	
	cout << "     Game Over.\n\n\n";
	
	
	
	return 0;
}








