#include "PA6Rfunctions.h"
#include "PA6RInput.h"

Vector getVector(char* question){//get vector to place ship (row,column)
    printf("%s",question);
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);
    while (!(x >= 0 && y >= 0 && x < gridSize && y < gridSize))
    {
        printf("Out of range, please enter a new value [0-%d]", gridSize - 1);
        scanf("%d %d", &x, &y);
    }
    return (Vector){x, y};
}
ShipPlace getShipPlace(){//get ship placement
    Vector position = getVector("Enter position x y where to place ship: ");
    int direction = 0;
    printf("Enter a value 1-4 for which direction to place your ship:\n"
           "1: Up\n2: Right\n3: Down\n4: Left");
    scanf("%d", &direction);
    while (direction < 1 || direction > 5)
    {
        printf("Out of range");
        scanf("%d", &direction);
    }
    return (ShipPlace){position, direction};
}
void playerTurn(Player player)//ignore this
{
    //printf("")
}
ShipPlace autoShipPlace()//automatically place ships using random number generator
{
    Vector position = autoVector();
    int direction = rand() % 4 + 1;
    return (ShipPlace){position,direction};
}
void fireSalvo(Cell board[][gridSize],Player source)//manually fire salvo
{
    int xSalvo;int ySalvo;
    Vector salvoPosition = getVector("Enter position x y where to fire salvo:");
    xSalvo = salvoPosition.x;ySalvo = salvoPosition.y;
    board[xSalvo][ySalvo].hit = 1;
    if(board[xSalvo][ySalvo].ship != none){
        ++source.hits;
    }else{
        ++source.misses;
    }
    
    
}
Vector autoVector()//automatically generate vector
{
    int x = 0; int y = 0;
    x= rand() % gridSize + 1;y=rand() % gridSize + 1;
    return (Vector){x,y};
}
void autoFireSalvo(Cell board[][gridSize],Player source)//automatically fire salvo
{
    int xAutoSalvo;int yAutoSalvo;
    Vector autoSalvo = autoVector();
    xAutoSalvo = autoSalvo.x;yAutoSalvo = autoSalvo.y;
    board[xAutoSalvo][yAutoSalvo].hit = 1;
    if (board[xAutoSalvo][yAutoSalvo].ship != none) {
        ++source.hits;
    } else {
        ++source.misses;
    }
}
void autoPlaceShip(Cell board[][gridSize], Cell *shipcells, ShipType type, int length)//automatically place ship
{
    int result = 0;
    while(!result){
        ShipPlace place = autoShipPlace();
        place.length = length;
        result = tryPlaceShip(board, shipcells, place, type);
    }
}
void placeUserShipsAutomatically(Cell board[][gridSize], Cell *shipCells[][5])//automatically place ships
{
    //rand() % 6 + 1
    autoPlaceShip(board,shipCells[0],carrier,5);
    autoPlaceShip(board,shipCells[1],battleship,4);
    autoPlaceShip(board,shipCells[2],cruiser,3);
    autoPlaceShip(board,shipCells[3],submarine,3);
    autoPlaceShip(board,shipCells[4],destroyer,2);
    //displayBoard(board,1);
}
void placeUserShip(Cell board[][gridSize], Cell *shipCells[], ShipType type, int length)//manually place ships
{
    int result = 0;
    while (!result)
    {
        ShipPlace place = getShipPlace();
        place.length = length;
        result = tryPlaceShip(board, shipCells, place, type);
        if (!result)
            printf("Invalid placement, try again.");
    }
}
void placeUserShips(Cell board[][gridSize], Cell* shipsCells[][5]){//manually place fleet
    displayBoard(board,1);
    printf("Placing carrier with length 5\n");
    placeUserShip(board, shipsCells[0], carrier, 5);
    clearScreen();
    displayBoard(board,1);
    printf("Placing battleship with length 4\n");
    placeUserShip(board, shipsCells[1], battleship, 4);
    clearScreen();
    displayBoard(board,1);
    printf("Placing cruiser with length 3\n");
    placeUserShip(board, shipsCells[2], cruiser, 3);
    clearScreen();
    displayBoard(board,1);
    printf("Placing submarine with length 3\n");
    placeUserShip(board, shipsCells[3], submarine, 3);
    clearScreen();
    displayBoard(board,1);
    printf("Placing destroyer with length 2\n");
    placeUserShip(board, shipsCells[4], destroyer, 2);
    displayBoard(board,1);
}