#include "PA6Rfunctions.h"
#include "PA6RInput.h"
//Daniel Bereza helped me with this assignment
//he told me how to do the placing system 
int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    FILE *outputstream = fopen("logfile.txt","w");
    int menu = 0;int choice = 0;
    char temp[50];
    Player player1;Player player2;Player computer;
    initBoard(player1.FleetBoard);initBoard(player2.FleetBoard);initBoard(computer.FleetBoard);
    //initBoard(player1.EnemyBoard);initBoard(player2.EnemyBoard);
    //player1.name = "test1";player2.name = "test2";computer.name = "computer";
    //printf("×\n");
    /*Cell board[gridSize][gridSize];
    Cell *shipCells[5][5];
    initBoard(board);
    placeUserShipsAutomatically(board,shipCells);
    autoFireSalvo(board);
    autoFireSalvo(board);
    displayBoard(board,0);
    displayBoard(board,1);
    fileOutputBoard(board,board,outputstream,1);
    fileOutputBoard(board,board,outputstream,0);*/
    /*displayBoard(board,1);
    placeUserShips(board,shipCells);
    fireSalvo(board);
    printf("TARGET BOARD\n");
    displayBoard(board,0);
    displayBoard(board,1);*/
    //playGameAgainstPlayer(player1,player2);
    clearScreen();
    //printFileContents("title2.txt");
    printFileContentsInBlue("title2.txt");
    //printFileContentsInBlueSmall("Battleship.txt");
    do{
        printf("\n");
        //MENU
        printf("|1. Display Rules\n");
        printf("|2. Play pvp (i misread the assigmment and thought you needed to make pvp. kinda broken but pvp isnt a grading requirement)\n");
        printf("|3. Play against computer\n");
        printf("|4. Exit game\n");
        scanf("%d",&choice);
        switch(choice){
            case 1://display rules
            displayRules();
            break;

            case 2://player vs player battleship
            printf("Enter Player name: \n");
            scanf("%s",temp);
            strcpy(player1.name,temp);
            printf("Enter Player name: \n");
            scanf("%s",temp);
            strcpy(player2.name,temp);
            playGameAgainstPlayer(player1,player2);
            break;

            case 3://play against computer
            printf("Enter Player name: \n");
            scanf("%s",temp);
            strcpy(player1.name,temp);
            playGameAgainstComputer(player1,computer);
            break;

            case 4://exit game
            return 0;
            break;
        }
    }while(choice != 4);
    //playGameAgainstComputer(player1,computer);
    

    
    return 0;
}
