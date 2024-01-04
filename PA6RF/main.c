#include "PA6RFfunctions.h"
//PA6 REVAMPED
int main(int argc, char const *argv[])
{
    int choice=0;
    Player player; Player computer;
    initPlayer(player);initPlayer(computer);

    do{
        clearScreen();
        printFileContentsInBlue("title2.txt");
        printf("|1. Display Rules\n");
        printf("|2. Play against computer\n");
        printf("|3. Exit game\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            displayRules();
            clearScreen();
            break;
        case 2:
            playGameAgainstComputer(player,computer);
            break;
        case 3:
            return 0;
            break;
        default:
            printf(">Enter valid input\n");
            break;

        }

    }while(choice != 3);
    
    return 0;
}

//TRIAL 1 - test firing and ship hit system

/*
    fireSalvo(computer.FleetBoard,player,computer);
    displayBoard(computer.FleetBoard,1);
    fireSalvo(computer.FleetBoard,player,computer);
    displayBoard(computer.FleetBoard,1);
    fireSalvo(computer.FleetBoard,player,computer);
    displayBoard(computer.FleetBoard,1);
    fireSalvo(computer.FleetBoard,player,computer);
    displayBoard(computer.FleetBoard,1);
    fireSalvo(computer.FleetBoard,player,computer);
    displayBoard(computer.FleetBoard,1);
    fireSalvo(computer.FleetBoard,player,computer);
    displayBoard(computer.FleetBoard,1);
*/

//TRIAL 2 - test ship placement 

/*
    initBoard(player.FleetBoard);initBoard(computer.FleetBoard);
    placeUserShips(player.FleetBoard,&player.shipCells);
    placeUserShipsAutomatically(computer.FleetBoard,&computer.shipCells);
*/



//important

/* 
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
*/
