#include "PA6Rfunctions.h"
#include "PA6RInput.h"
//IGNORE THIS
//i wasted 3 hours doing this 

/*  
Cell *shipCells1;Cell *shipCells2;Player arrPlyr[3];
    int game = 0;
    int choosePlyr = rand() % 2;
    //initBoard(player.FleetBoard);initBoard(computer.FleetBoard);
    /*placeUserShipsAutomatically(computer.FleetBoard,computer.shipCells);
    //displayBoard(computer.FleetBoard,1);
    printf("PLACING %s's FLEET\n",player.name);
    displayBoard(player.FleetBoard,1);
    placeUserShips(player.FleetBoard,player.shipCells);
    clearScreen();*/

    
    
    
    /*if(choosePlyr == 1){//player goes first
        arrPlyr[1] = player;//arrPlyr[1].name = player.name;
        arrPlyr[1].name = strdup(player.name);
        arrPlyr[2] = computer;//arrPlyr[2].name = computer.name;
        arrPlyr[2].name = strdup(computer.name);
        //copyBoard(player.FleetBoard,arrPlyr[1].FleetBoard);
        //copyBoard(computer.FleetBoard,arrPlyr[2].FleetBoard);
        
        printf("PLACING %s's FLEETA\n",arrPlyr[1].name);
        placeUserShips(arrPlyr[1].FleetBoard,arrPlyr[1].shipCells);
        placeUserShipsAutomatically(arrPlyr[2].FleetBoard,arrPlyr[2].shipCells);
    }
    if(choosePlyr == 0){//computer goes first
        arrPlyr[1] = computer;//arrPlyr[1].name = computer.name;
        arrPlyr[1].name = strdup(computer.name);
        arrPlyr[2] = player;//arrPlyr[2].name = player.name;
        arrPlyr[2].name = strdup(player.name);
        //copyBoard(computer.FleetBoard,arrPlyr[1].FleetBoard);
        //copyBoard(player.FleetBoard,arrPlyr[2].FleetBoard);
        
        placeUserShipsAutomatically(arrPlyr[1].FleetBoard,arrPlyr[1].shipCells);
        printf("PLACING %s's FLEETB\n",arrPlyr[2].name);
        placeUserShips(arrPlyr[2].FleetBoard,arrPlyr[2].shipCells);
    }

    /*placeUserShipsAutomatically(computer.FleetBoard,computer.shipCells);
    //displayBoard(computer.FleetBoard,1);
    printf("PLACING %s's FLEET\n",player.name);
    displayBoard(player.FleetBoard,1);
    placeUserShips(player.FleetBoard,player.shipCells);
    clearScreen();
    initBoard(arrPlyr[1].FleetBoard);initBoard(arrPlyr[2].FleetBoard);*/
    
    /*do{
        do{
            arrPlyr[1].hits = checkPlayerBoard(arrPlyr[2]);
            arrPlyr[2].hits = checkPlayerBoard(arrPlyr[1]);
            if(choosePlyr == 0){
                arrPlyr[1].hits = checkPlayerBoard(player);
                arrPlyr[2].hits = checkPlayerBoard(computer);

                printf("%s's TARGET BOARD\n",arrPlyr[1].name);
                printf("%s HITS: %d\n",arrPlyr[1].name,arrPlyr[1].hits);
                autoFireSalvo(arrPlyr[1].FleetBoard);
                displayBoard(arrPlyr[1].FleetBoard,1);
                clearScreen();

                printf("%s's TARGET BOARD\n",arrPlyr[2].name);
                printf("%s HITS: %d\n",arrPlyr[2].name,arrPlyr[2].hits);
                displayBoard(arrPlyr[2].FleetBoard,1);
                fireSalvo(arrPlyr[2].FleetBoard);
                clearScreen();
            }else{
                arrPlyr[1].hits = checkPlayerBoard(computer);
                arrPlyr[2].hits = checkPlayerBoard(player);

                printf("%s's TARGET BOARD\n",arrPlyr[2].name);
                printf("%s HITS: %d\n",arrPlyr[2].name,arrPlyr[2].hits);
                displayBoard(arrPlyr[2].FleetBoard,1);
                fireSalvo(arrPlyr[2].FleetBoard);
                clearScreen();

                printf("%s's TARGET BOARD\n",arrPlyr[1].name);
                printf("%s HITS: %d\n",arrPlyr[1].name,arrPlyr[1].hits);
                autoFireSalvo(arrPlyr[1].FleetBoard);
                displayBoard(arrPlyr[1].FleetBoard,1);
                clearScreen();
            }
        }while(arrPlyr[1].hits != 17 && arrPlyr[2].hits != 17);
    }while (game != 1 );*/

    






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


void playGameAgainstPlayer(Player player1, Player player2)//pvp game (i misread the directions and didnt have to do this)
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

}

void playGameAgainstComputer(Player player, Player computer)//play game against computer (random number generator)
{
    int round = 0;
    int game = 0;
    char name[50];
    //char *name= "computer";
    //strcpy(computer.name,computer);
    strcpy(name, player.name);
    clearScreen();
    printf("PLACING %s's FLEET\n",player.name);
    //displayBoard(player.FleetBoard,1);
    placeUserShips(player.FleetBoard,player.shipCells);
    clearScreen();
    placeUserShipsAutomatically(computer.FleetBoard,computer.shipCells);
    player.hits = 0;
    player.misses = 0;
    computer.hits = 0;
    computer.misses = 0;
    FILE *outputstream1 = fopen("battleshipPlayer.log","w");
    FILE *outputstream2 = fopen("battleshipComputer.log","w");
    do{
        round++;
        if(player.hits == 17 || computer.hits == 17){
                game = 1;
        }
            printf("Round %d\n",round);
            //printf("HITS test: %d",player.hits);
            player.hits = checkPlayerBoardHits(computer);
            computer.hits = checkPlayerBoardHits(player);
            player.misses = checkPlayerBoardMisses(computer);
            computer.misses = checkPlayerBoardMisses(player);
            
            printf("%s's TARGET BOARD\n",name);
            printf("%s HITS: %d | MISSES: %d\n",name,player.hits,player.misses);
            displayBoard(computer.FleetBoard,0);
            fireSalvo(computer.FleetBoard,player);
            fileOutputBoard(computer.FleetBoard,computer.EnemyBoard,outputstream1,1,player,round);
            //logPlayer(player,round,1,outputstream);
            clearScreen();
            autoFireSalvo(player.FleetBoard,computer);
            //fileOutputBoard(player.FleetBoard,player.EnemyBoard,outputstream2,1,computer,round);
    }while(game != 1);
    
}

char getPlayerName()//get player name
{
    char *enterName = " ";
    printf("Enter Player Name: \n");
    scanf("%c",enterName);
    return enterName;
}

int promptPlayAgainstComputer()//prompt play against computer (didnt use this)
{
    int promptPlayAgainstComputer;
    printf("Play against AI? [1: Yes | 2: No]\n");
    do{
        printf(">");
        scanf("%d",&promptPlayAgainstComputer);
    }while(promptPlayAgainstComputer != 1 || promptPlayAgainstComputer != 0);
    return promptPlayAgainstComputer;
}

void fileOutputBoard(Cell grid[][gridSize], Cell targetGrid[][gridSize],FILE *input,int displayType,Player player,int round)//output board to file 
{
    double hitOrMissRatio = 0.0;
    //char name[50];
    //strcpy(name,player.name);
    hitOrMissRatio = (double)player.hits / player.misses;
    //fprintf(input,"%s's TARGET BOARD\n",player.name);
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
    printFileContents("rules.txt");
    
}
