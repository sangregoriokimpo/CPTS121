#include "PA4functions.h"
#include <ncurses.h>

int main(int argc, char const *argv[])
{
    /*int col = 0;
    col = get_term_width();
    for(int i = 0; i < col;i++ ){
        printf("━");
    }*/
    print_line();
    printf("\n");
    //printupper_line();
    //printmid_line();
    //printlower_line();

    //print_text();


    int count = 0; double bank_balance; double wager = 0.0;
    srand((unsigned int)time(NULL));
    display_title();//DISPLAY TITLE
    printf("By Gregory Jabido\n");
     do
    {
        /*printf("\n");
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");//MENU
        printf("┃Bank Balance: $%15.2lf                                               ┃\n",bank_balance);
        printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
        printf("┃1. Display Rules.                                                            ┃\n");
        printf("┃2. Play Game.                                                                ┃\n");    
        printf("┃3. Exit.                                                                     ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        scanf("%d",&count);*/

        //PRINT MENU
        printf("\n");
        printupper_line();
        print_bank_balance();
        printmid_line();
        print_menu1();//OPTION 1
        print_menu2();//OPTION 2
        print_menu3();//OPTION 3
        printlower_line();
        scanf("%d",&count);//PLAYER CHOICE

        switch(count){
            case 1:
            //PRINT RULES
            print_line();
            print_game_rules();
            print_line();
            break;

            case 2:
            //PLAY GAME
            print_line();
            bank_balance = playgame();
            print_line();
            break;
            
            case 3:
            //EXIT GAME
            print_line();
            printf("Exiting game...\n");
            print_line();
            return 0;

        }




    } while (count != 3); // !(count >= 1 && count <= 3) input validation loop pattern 
    return 0; 
}
