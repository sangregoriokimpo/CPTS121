#include "PA5R.h"

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    printf("Yahtzee\n");
    int choice = 0;
    do{
        printf("Enter Choice\n");
        printf("|1. Print game rules\n");
        printf("|2. Play game\n");
        printf("|3. Exit game\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            //PRINT GAME RULES
            print_game_rules();
            break;

            case 2:
            play_game();
            break;

            case 3:
            return 0;
            break;
        }
    }while(choice != 3);
    return 0;
}
