#ifndef PA6R_H
#define PA6R_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


#define gridSize 10
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_SMALL "\x1b[2m"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_ORANGE "\x1b[38;5;208m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_INDIGO "\x1b[38;5;129m"
#define ANSI_COLOR_VIOLET "\x1b[35m"




typedef struct
{
    int x, y;
} Vector;

typedef enum {
    none = '-',
    carrier = 'c',
    battleship = 'b',
    cruiser = 'r',
    submarine = 's',
    destroyer = 'd'
} ShipType;

typedef struct
{
    Vector position;
    int ship, hit;
} Cell;

typedef struct
{
    Vector position;
    int direction, length;
} ShipPlace;

typedef struct{
    char *name;
    int points;
    Cell FleetBoard[gridSize][gridSize];
    Cell EnemyBoard[gridSize][gridSize];
    Cell *shipCells[5];
    int carrierHealth;int battleshipHealth;int cruiserHealth;int submarineHealth;int destroyerHealth;
    int hits,misses;
}Player;
Vector integerToDirection(int direction);
int checkShip(Cell grid[][gridSize], Cell *shipCells[], ShipPlace shipPlace);
void placeShip(Cell* shipCells[], int length, ShipType type);
int tryPlaceShip(Cell grid[][gridSize], Cell* shipCells[], ShipPlace shipPlace, ShipType type);
char renderCellToPlayerFleetBoard(Cell cell);
char renderCellToPlayerEnemyBoard(Cell cell);
char displayCell(Cell cell, int displayType);
void displayBoard(Cell grid[][gridSize],int displayType);

void initBoard(Cell grid[][gridSize]);
void copyBoard(Cell source[gridSize][gridSize], Cell destination[gridSize][gridSize]);
void placeShip(Cell* shipCells[], int length, ShipType type);
int tryPlaceShip(Cell grid[][gridSize], Cell* shipCells[], ShipPlace shipPlace, ShipType type);

int checkPlayerBoardHits(Player player);
int checkPlayerBoardMisses(Player player);

void playGameAgainstPlayer(Player player1,Player player2);
void playGameAgainstComputer(Player player,Player computer);
void initializeBattleship(void);
char getPlayerName();
int promptPlayAgainstComputer();


void fileOutputBoard(Cell grid[][gridSize], Cell targetGrid[][gridSize],FILE *input,int displayType,Player player, int round);
void logPlayer(Player player,int round,int displayType,FILE *input);
void clearScreen();
void printFileContents(const char *filename);
void printFileContentsInBlue(const char *filename);
void printFileContentsInBlueSmall(const char *filename);
void displayRules();

//input

void playerTurn(Player player);
Vector getVector(char* question);
ShipPlace getShipPlace();
ShipPlace autoShipPlace();
void fireSalvo(Cell board[][gridSize],Player source,Player target);
void placeUserShip(Cell board[][gridSize], Cell* shipCells[], ShipType type, int length);
void placeUserShips(Cell board[][gridSize], Cell* shipsCells[][5]);
Vector autoVector();
void autoFireSalvo(Cell board[][gridSize],Player source,Player target);
void autoPlaceShip(Cell board[][gridSize],Cell *shipcells,ShipType type, int length);
void placeUserShipsAutomatically(Cell board[][gridSize],Cell *shipCells[][5]);

void initFleetHealth(Player player);
int checkShipHit(Cell board[][gridSize],Player check,Vector vector);
void checkShipHitShip(Cell board[][gridSize],Player check,Vector vector,int checkShipHit);
int checkFleetHealth(Player check);

//player

void initPlayer(Player player);

//customization

void changeSkin();

#endif




