#ifndef PA6RINPUT_H
#define PA6RINPUT_H

#include "PA6Rfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void playerTurn(Player player);
Vector getVector(char* question);
ShipPlace getShipPlace();
ShipPlace autoShipPlace();
void fireSalvo(Cell board[][gridSize],Player source);
void placeUserShip(Cell board[][gridSize], Cell* shipCells[], ShipType type, int length);
void placeUserShips(Cell board[][gridSize], Cell* shipsCells[][5]);
Vector autoVector();
void autoFireSalvo(Cell board[][gridSize],Player source);
void autoPlaceShip(Cell board[][gridSize],Cell *shipcells,ShipType type, int length);
void placeUserShipsAutomatically(Cell board[][gridSize],Cell *shipCells[][5]);

#endif

