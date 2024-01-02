// Authors: Deitel & Deitel - C How to Program
#include "PA7R2functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//I REDID THIS ASSIGNMENT TWICE BECAUSE POINTERS ARE HARD TO WORK WITH (USING A PLAYER STRUCT BROKE SO MUCH STUFF)


int main (void)
{
    Player testPlayer;Player testEmpty;int handrankPlayer = 0;int handrankDealer=0;
    Player testDealer; 
    int testFaceFrequencyTable[13] = {0};int testSuitFrequencyTable[4] = {0};
    setPlayerName(&testPlayer,"Player");setPlayerName(&testEmpty,"test empty");setPlayerName(&testDealer,"Dealer");
    int testdebug = 1;
    initializePlayerObject(&testPlayer);
	/* initialize suit array */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	/* initialize face array */
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"};

	/* initalize deck array */
	int deck[4][13] = {0};
    int cardIndex = 52;//# of cards in deck

	srand ((unsigned) time (NULL)); /* seed random-number generator */


    printf("\n");

	shuffle (deck);
	deal (deck, face, suit);
    clearScreen();

    //printFileContentsInPurple("pokertitle.txt");//print title
    //draw(deck,&testPlayer.playerHand,&cardIndex);
    //draw(deck,&testDealer.playerHand,&cardIndex);
    //displayHand(testPlayer);
    //displayHand(testDealer);
    //handrankPlayer = checkPlayerHandCombo(testPlayer,deck,&cardIndex);
    //handrankDealer=checkDealerHandCombo(testDealer);
    //printf("hand rank: %d\n",handrankPlayer);
    //printf("hand rank: %d\n",handrankDealer);
    //compareHands(handrankPlayer,handrankDealer,testPlayer,testDealer);


    int choice =0; int chosen = 0;int game=0;char exitRules = 0;
    do{
        clearScreen();
        printFileContentsInPurple("pokertitle.txt");
        printf("\n");
        printf("MENU\n");
        printf("|1. Print Rules\n");
        printf("|2. Play Game\n");
        printf("|3. Exit Game\n");
        printf(">");
        scanf("%d",&choice);
        switch(choice){
            case 1://display rules
            //shuffle new deck
            //each draw cards
            //draw/discard based on what you decide
            //compare cards
            //repeat
            clearScreen();
            printFileContentsInPurple("pokerrulestitle.txt");
            printf("1) Each player draw cards\n");
            printf("2) Draw/discard based on what you decide\n");
            printf("3) Compare cards\n");
            printf("4) Highest ranking hand wins\n");
            sleep(5);
            clearScreen();
            break;

            case 2://play the game (i didnt make a game function because fuck pointers)
            clearScreen();
            draw(deck,&testPlayer.playerHand,&cardIndex);
            draw(deck,&testDealer.playerHand,&cardIndex);
            displayHand(testPlayer);
            int playerMenu =0;int playerMenuChosen = 0;int drawCardAmount = 0;int discardCardAmount=0;
            printf(">Player Menu\n");
            printf("|1. Redraw Hand\n");
            printf("|2. Discard cards\n");
            printf("|3. Keep Hand\n");
            do{
            printf(">Enter Input\n");
            scanf("%d",&playerMenu);
            switch(playerMenu){
                case 1:
                    printf("Redraw How many cards? [1-5]\n");
                    scanf("%d",&drawCardAmount);
                    drawAmountOfCards(deck,&testPlayer.playerHand,drawCardAmount,&cardIndex);

                    displayHand(testPlayer);
                    playerMenuChosen=1;
                break;

                case 2:
                    printf("Discard How many cards? [1-5]\n");
                    scanf("%d",&discardCardAmount);
                    discardCards(deck,&testPlayer.playerHand,discardCardAmount);

                    playerMenuChosen=1;
                break;

                case 3:
                    printf("Keeping hand\n");
                    playerMenuChosen=1;
                break;

                default:
                    printf("Enter Valid Input\n");
                break;
            }
            }while(playerMenuChosen != 1);
            //displayHand(testDealer);
            handrankPlayer = checkPlayerHandCombo(testPlayer,deck,&cardIndex);
            handrankDealer=checkDealerHandCombo(testDealer);
            //printf("hand rank: %d\n",handrankPlayer);
            //printf("hand rank: %d\n",handrankDealer);
            compareHands(handrankPlayer,handrankDealer,testPlayer,testDealer);
            sleep(2);
            break;

            case 3://exit game
            printf(">Exiting Game");
            game = 1;
            return 0;
            break;

            default:
            printf(">Enter Valid Input\n");
            break;
        }
    }while(game != 1);



	return 0;
}

//TEST FUNCTIONS TRIAL 1 - TEST DISPLAY HAND AND CARD RENDER 
/*  
    draw(deck,&testPlayer.playerHand,&cardIndex);
    displayHand(testPlayer);
    initializePlayerObject(&testEmpty);
    printf("test empty hand\n");
    displayHand(testEmpty);
    draw(deck,&testEmpty.playerHand,&cardIndex);
    printf("test empty hand draw\n");
    displayHand(testEmpty);
*/

//TEST FUNCTIONS TRIAL 2 - TEST DRAW AMOUNT OF CARDS AND DISCARD CARDS, 
//ALSO CHECK IF HAND IS PASSED INTO CHECK HAND FUNCTION CORRECTLY
/*
    draw(deck,&testPlayer.playerHand,&cardIndex);
    displayHand(testPlayer);
    printf("test drawing 3 cards\n");
    drawAmountOfCards(deck,&testPlayer.playerHand,3,&cardIndex);
    displayHand(testPlayer);
    printf("test discarding 3 cards\n");
    discardCards(deck,&testPlayer.playerHand,3);
    displayHand(testPlayer);
    checkPlayerHandCombo(testPlayer);
*/

//TEST FUNCTIONS TRIAL 3 - TEST HAND AND FREQUENCY TABLE PASSING
//it took me like 3 hours to realise if you wanna pass an array from a struct into a function you dont specify array length
/*
    draw(deck,&testPlayer.playerHand,&cardIndex);
    displayHand(testPlayer);
    checkPlayerHandCombo(testPlayer);
    //displayPlayerFaceFrequencyTable(testPlayer);
    //displayPlayerSuitFrequencyTable(testPlayer);
    setPlayerFaceFrequencyTable(testPlayer.playerHand,&testPlayer.FaceFrequencyTable);
    displayPlayerFaceFrequencyTable(testPlayer);
*/

//TEST FUNCTIONS TRIAL 4 - TEST POKER FUNCTION IMPLEMENTATION
//ALL THE GAME FUNCTIONS WORK
/*
    draw(deck,&testPlayer.playerHand,&cardIndex);
    draw(deck,&testDealer.playerHand,&cardIndex);
    displayHand(testPlayer);
    displayHand(testDealer);
    handrankPlayer = checkPlayerHandCombo(testPlayer,deck,&cardIndex);
    handrankDealer=checkDealerHandCombo(testDealer);
    printf("hand rank: %d\n",handrankPlayer);
    printf("hand rank: %d\n",handrankDealer);
    compareHands(handrankPlayer,handrankDealer,testPlayer,testDealer);
*/






//MENU WHILE LOOP

/*
do{
        printf("MENU\n");
        printf("|1. Print Rules\n");
        printf("|2. Play Game\n");
        printf("|3. Exit Game\n");
        
        do{
            printf("> ");
            scanf("%d",&choice);
            if(choice != 3 && choice != 2 && choice != 1){
                printf(">Invalid Input\n");
            }
        }while(choice != 3 && choice != 2 && choice != 1);

        switch(choice){
            case 1:

            break;

            case 2:

            break;

            case 3:
            return 0;
            break;
        }
    }while(choice != 3);
*/