#include "PA6RFfunctions.h"

void initBoard(Cell grid[][gridSize])//initiate board cells
{
    for (int y = 0; y < gridSize; ++y)
    {
        for (int x = 0; x < gridSize; ++x)
        {
            grid[x][y] = (Cell){(Vector){x, y}, none, 0};
        }
    }
}

void copyBoard(Cell source[gridSize][gridSize], Cell destination[gridSize][gridSize]) {//copy board
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

Vector integerToDirection(int direction)//convert integer to direction (vector)
{
    Vector vector;
    //direction = direction -1;
    switch(direction){
        case 1://
        vector.x = 0;
        vector.y = -1;
        break;

        case 2:
        vector.x = 1;
        vector.y = 0;
        break;

        case 3:
        vector.x = 0;
        vector.y = 1;
        break;

        case 4:
        vector.x = -1;
        vector.y = 0;
        break;
    }
    return vector;
}

int checkShip(Cell grid[][gridSize], Cell *shipCells[], ShipPlace shipPlace){//check if ship is placeable
    Vector direction = integerToDirection(shipPlace.direction);
    int x = shipPlace.position.x, y = shipPlace.position.y;
    for (int i = 0; i < shipPlace.length; ++i)
    {
        int xIndex = x + (i * direction.x), yIndex = y + (i * direction.y);
        Cell* cell = &grid[xIndex][yIndex];
        if (cell->ship != none || xIndex < 0 || yIndex < 0 || xIndex > gridSize || yIndex > gridSize)
            return 0; // if occupied we can't fit or if out of bounds
        shipCells[i] = cell;
    }
    return 1;
}

void placeShip(Cell* shipCells[], int length, ShipType type){//place ship
    for (int i = 0; i < length; ++i)
    {
        shipCells[i]->ship = type;
    }
}

int tryPlaceShip(Cell grid[][gridSize], Cell* shipCells[], ShipPlace shipPlace, ShipType type)//attempt to place ship
{
    int result = checkShip(grid, shipCells, shipPlace);
    if (result)
        placeShip(shipCells, shipPlace.length, type);
    return result;
}

char renderCellToPlayerFleetBoard(Cell cell)//render cell for debugging
{
    if(cell.hit){
        return '*';
    }else{
        return cell.ship;
    }
}

char renderCellToPlayerEnemyBoard(Cell cell)//render cell for debugging
{
    if(cell.hit){
        return 'X';
    }else{
        return 'M';
    }
    if(cell.ship){
        return '-';
    }
}

char displayCell(Cell cell, int displayType)//display cell/hit system
{
    if(cell.hit){
        if(cell.ship !=none){
            return '*';
        }else{
            return 'm';
        }
    }if(displayType){//set to 1 to show FleetBoard
        return (char)cell.ship;
    }else{
        return none;
    }
}

void displayBoard(Cell grid[][gridSize], int displayType)//display board
{
    printf(" ");
    for (int x = 0; x < gridSize; ++x)
        printf(" %d", x);
    printf("\n");
    for (int y = 0; y < gridSize; ++y)
    {
        printf("%d|", y);
        for (int x = 0; x < gridSize; ++x)
        {
            Cell cell = grid[x][y];
            printf("%c|", displayCell(cell,displayType));
        }
        printf("\n");
    }
}

int checkPlayerBoardHits(Player player)//check hits
{
    int hits =0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            if(player.FleetBoard[i][j].ship != none && player.FleetBoard[i][j].hit == 1){
                hits++;
            }
        }
    }
    return hits;
}
int checkPlayerBoardMisses(Player player)//check hits
{
    int misses =0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            if(player.FleetBoard[i][j].ship == none && player.FleetBoard[i][j].hit == 1){
                misses++;
            }
        }
    }
    return misses;
}


/*void playGameAgainstPlayer(Player player1, Player player2)//pvp game (i misread the directions and didnt have to do this)
{
    int game = 0;int round = 0;
    char chooseTurn[50] = " ";
    printf("Who goes first? %s or %s?\n",player1.name,player2.name);
        do{
            printf(">");
            scanf("%s",chooseTurn);
        }while(strcmp(chooseTurn, player1.name) != 0 && strcmp(chooseTurn, player2.name) != 0);
    Player arrPlyr[3];
    initBoard(arrPlyr[1].FleetBoard);
    initBoard(arrPlyr[2].FleetBoard);
    if(strcmp(chooseTurn, player1.name)==0){
        arrPlyr[1] = player1;
        arrPlyr[2] = player2;
        
    }else if(strcmp(chooseTurn, player2.name)==0){
        arrPlyr[1] = player2;
        arrPlyr[2] = player1;
        
    }
    clearScreen();
    printf("PLACING %s's FLEET\n",arrPlyr[1].name);
    displayBoard(arrPlyr[1].FleetBoard,1);
    placeUserShips(arrPlyr[1].FleetBoard,player1.shipCells);
    clearScreen();
    printf("PLACING %s's FLEET\n",arrPlyr[2].name);
    displayBoard(arrPlyr[2].FleetBoard,1);
    placeUserShips(arrPlyr[2].FleetBoard,player2.shipCells);
    clearScreen();
    do{
        round++;
        if(arrPlyr[1].hits != 17 && arrPlyr[2].hits != 17){
            game = 1;
        }
        arrPlyr[1].hits = checkPlayerBoardHits(arrPlyr[2]);
        arrPlyr[2].hits = checkPlayerBoardHits(arrPlyr[1]);
        arrPlyr[1].misses = checkPlayerBoardMisses(arrPlyr[2]);
        arrPlyr[2].misses = checkPlayerBoardMisses(arrPlyr[1]);
        printf("Round: %d\n",round);
        printf("%s's TARGET BOARD\n",arrPlyr[1].name);
        printf("%s HITS: %d | MISSES: %d\n",arrPlyr[1].name,arrPlyr[1].hits,arrPlyr[1].misses);
        //printf("%s HITS: %d | MISSES: %d\n",name,player.hits,player.misses);
        displayBoard(arrPlyr[2].FleetBoard,0);
        fireSalvo(arrPlyr[2].FleetBoard,arrPlyr[1]);
        clearScreen();
        printf("%s's TARGET BOARD\n",arrPlyr[2].name);
        printf("%s HITS: %d | MISSES: %d\n",arrPlyr[2].name,arrPlyr[2].hits,arrPlyr[2].misses);
        //printf("%s HITS: %d\n",arrPlyr[2].name,arrPlyr[2].hits);
        displayBoard(arrPlyr[1].FleetBoard,0);
        fireSalvo(arrPlyr[1].FleetBoard,arrPlyr[2]);
        clearScreen();
    }while (game != 1 );

}*/

void playGameAgainstComputer(Player player, Player computer)//play game against computer (random number generator)
{
    initFleetHealth(player);initFleetHealth(computer);
    initBoard(player.FleetBoard);initBoard(computer.FleetBoard);
    int round = 0;
    int game1 = 0;int game2=0;
    char name[50];char playerName[50] = "Player";char computerName[50] = "Computer";
    player.name = "Player";computer.name = "Computer";
    //strcpy(player.name, playerName);strcpy(computer.name,computerName);
    clearScreen();
    printf("PLACING %s's FLEET\n",player.name);
    placeUserShips(player.FleetBoard,&player.shipCells);
    clearScreen();
    placeUserShipsAutomatically(computer.FleetBoard,&computer.shipCells);
    player.hits = 0;
    player.misses = 0;
    computer.hits = 0;
    computer.misses = 0;
    FILE *outputstream1 = fopen("battleshipPlayer.log","w");
    FILE *outputstream2 = fopen("battleshipComputer.log","w");
    do{
        round++;
        game1 = checkFleetHealth(player);
        game2 = checkFleetHealth(computer);
            printf("Round %d\n",round);

            player.hits = checkPlayerBoardHits(computer);
            computer.hits = checkPlayerBoardHits(player);
            player.misses = checkPlayerBoardMisses(computer);
            computer.misses = checkPlayerBoardMisses(player);
            
            printf("%s's TARGET BOARD\n",player.name);
            printf("%s HITS: %d | MISSES: %d\n",name,player.hits,player.misses);
            displayBoard(computer.FleetBoard,0);
            fireSalvo(computer.FleetBoard,player,computer);
            fileOutputBoard(computer.FleetBoard,computer.EnemyBoard,outputstream1,1,player,round);
            clearScreen();
            autoFireSalvo(player.FleetBoard,computer,player);
            fileOutputBoard(player.FleetBoard,player.EnemyBoard,outputstream2,1,computer,round);
    }while(game1 != 1 || game2 != 1);
    
}

char getPlayerName()//get player name
{
    char *enterName = " ";
    printf("Enter Player Name: \n");
    scanf("%c",enterName);
    return enterName;
}

/*int promptPlayAgainstComputer()//prompt play against computer (didnt use this)
{
    int promptPlayAgainstComputer;
    printf("Play against AI? [1: Yes | 2: No]\n");
    do{
        printf(">");
        scanf("%d",&promptPlayAgainstComputer);
    }while(promptPlayAgainstComputer != 1 || promptPlayAgainstComputer != 0);
    return promptPlayAgainstComputer;
}*/

void fileOutputBoard(Cell grid[][gridSize], Cell targetGrid[][gridSize],FILE *input,int displayType,Player player,int round)//output board to file 
{
    double hitOrMissRatio = 0.0;
    hitOrMissRatio = (double)player.hits / player.misses;
    fprintf(input,"ROUND %d\n",round);
    fprintf(input,"%s HITS: %d | MISSES: %d\n",player.name,player.hits,player.misses);
    fprintf(input," ");
    for (int x = 0; x < gridSize; ++x)
        fprintf(input," %d", x);
    fprintf(input,"\n");
    for (int y = 0; y < gridSize; ++y)
    {
        fprintf(input,"%d|", y);
        for (int x = 0; x < gridSize; ++x)
        {
            Cell cell = grid[x][y];
            fprintf(input,"%c|", displayCell(cell,displayType));
        }
        fprintf(input,"\n");
    }
    //fclose(input);
    fprintf(input,"HIT/MISS RATIO: %f\n",hitOrMissRatio);
}

void logPlayer(Player player, int round,int displayType,FILE *input)
{
    //player.FleetBoard;
    printf("ROUND %d\n",round);
    printf("%s HITS: %d | MISSES: %d\n",player.name,player.hits,player.misses);
    fprintf(input," ");
    for (int x = 0; x < gridSize; ++x)
        fprintf(input," %d", x);
    fprintf(input,"\n");
    for (int y = 0; y < gridSize; ++y)
    {
        fprintf(input,"%d|", y);
        for (int x = 0; x < gridSize; ++x)
        {
            //Cell cell = grid[x][y];
            Cell cell = player.FleetBoard[x][y];
            fprintf(input,"%c|", displayCell(cell,displayType));
        }
        fprintf(input,"\n");
    }
}

void clearScreen() {//clear screen
#ifdef _WIN32
    // For Windows
    system("cls");
#elif __APPLE__
    // For macOS
    system("clear");
#else
    // ANSI escape codes to clear the screen
    printf("\033[H\033[J");
#endif
}

void printFileContents(const char *filename) {//print file contents
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1000]; // Adjust the buffer size as needed

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

void printFileContentsInBlue(const char *filename) {//print file contents in blue (used this for the title)
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1000]; // Adjust the buffer size as needed

    printf(ANSI_COLOR_BLUE); // Set text color to blue

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    printf(ANSI_COLOR_RESET); // Reset text color

    fclose(file);
}

void printFileContentsInBlueSmall(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[5]; // Adjust the buffer size as needed

    printf(ANSI_COLOR_BLUE); // Set text color to blue
    printf(ANSI_COLOR_SMALL); // Set text size to small

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    printf(ANSI_COLOR_RESET); // Reset text color and size

    fclose(file);
}


void displayRules()//display rules
{
    clearScreen();
    printFileContentsInBlue("rules.txt");
    sleep(2);
    clearScreen();
    
}

//input

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
void fireSalvo(Cell board[][gridSize],Player source,Player target)//manually fire salvo
{
    int xSalvo;int ySalvo;int checkshipIfHit;
    Vector salvoPosition = getVector("Enter position x y where to fire salvo:");
    xSalvo = salvoPosition.x;ySalvo = salvoPosition.y;
    board[xSalvo][ySalvo].hit = 1;
    checkshipIfHit = checkShipHit(board,target,salvoPosition);
    checkShipHitShip(board,target,salvoPosition,checkshipIfHit);
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
void autoFireSalvo(Cell board[][gridSize],Player source,Player target)//automatically fire salvo
{
    int xAutoSalvo;int yAutoSalvo;int checkshipIfHit;
    Vector autoSalvo = autoVector();
    xAutoSalvo = autoSalvo.x;yAutoSalvo = autoSalvo.y;
    board[xAutoSalvo][yAutoSalvo].hit = 1;
    checkshipIfHit = checkShipHit(board,target,autoSalvo);
    checkShipHitShip(board,target,autoSalvo,checkshipIfHit);
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

void initFleetHealth(Player player)
{
    player.carrierHealth=5;
    player.battleshipHealth=4;
    player.cruiserHealth=3;
    player.submarineHealth=3;
    player.destroyerHealth=2;
}

int checkShipHit(Cell board[][gridSize], Player check, Vector vector)
{
    int xPos=0;int yPos=0;
    xPos=vector.x;yPos=vector.y;
    if(board[xPos][yPos].ship == carrier){//return 1 if carrier
        return 1;
    }
    if(board[xPos][yPos].ship == battleship){//return 2 if battleship
        return 2;
    }
    if(board[xPos][yPos].ship == cruiser){//return 3 if cruiser
        return 3;
    }
    if(board[xPos][yPos].ship ==submarine){//return 4 if submarine
        return 4;
    }
    if(board[xPos][yPos].ship == destroyer){//return 5 if destroyer
        return 5;
    }
    return -1;
}

void checkShipHitShip(Cell board[][gridSize],Player check, Vector vector,int checkShipHit)
{
    switch(checkShipHit){
        case 1:
        check.carrierHealth--;
        if(check.carrierHealth==0){
            printf("Carrier sunk!\n");
        }
        break;

        case 2:
        check.battleshipHealth--;
        if(check.battleshipHealth==0){
            printf("Battleship sunk!\n");
        }
        break;

        case 3:
        check.cruiserHealth--;
        if(check.cruiserHealth==0){
            printf("Cruiser sunk!\n");
        }
        break;

        case 4:
        check.submarineHealth--;
        if(check.submarineHealth==0){
            printf("Submarine sunk!\n");
        }
        break;

        case 5:
        check.destroyerHealth--;
        if(check.destroyerHealth==0){
            printf("Destroyer sunk!\n");
        }
        break;

        default:

        break;
    }
}

int checkFleetHealth(Player check)
{
    if(check.carrierHealth == 0 && check.battleshipHealth == 0 && 
    check.cruiserHealth == 0 && check.destroyerHealth == 0 && check.submarineHealth == 0){
        return 1;
    }
    return 0;
}

void initPlayer(Player player)
{
    initBoard(player.FleetBoard);
    initBoard(player.EnemyBoard);
    initFleetHealth(player);
}
