#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ANSI_COLOR_PURPLE "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_SMALL "\x1b[2m"

typedef struct{
    int faceOfCard;
    int suitOfCard;
}Card;

typedef struct{
    Card hand[6];
}Hand;

typedef struct{
    char name[50];
    int frequencyTable[4][13];
    int FaceFrequencyTable[13];
    int SuitFrequencyTable[4];
    Hand playerHand;
}Player;

//i was too lazy to carry the face and suit arrays into these functions

//deck functions
void shuffle (int wDeck[][13]);
void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[]);
void draw(int wDeck[][13],Hand *hand,int *cardIndex);
void drawAmountOfCards(int wDeck[][13],Hand *hand,int amountOfCards, int *cardIndex);
void discardCards(int wDeck[][13],Hand *hand, int discardCards);

//player object functions
void setPlayerName(Player *player,const char *name);
void initializePlayerObject(Player *player);

//hand functions
void displayHand(Player player);
void showHand(Hand hand);
void renderCard(int cardFace,int cardSuit);
int checkPlayerHandCombo(Player player,int wDeck[][13],int *cardIndex);

//player frequency table functions
void setPlayerFaceFrequencyTable(Hand playerhand,int *FaceFrequencyTable);
void setPlayerSuitFrequencyTable(Hand playerhand,int *SuitFrequencyTable);
void displayPlayerFaceFrequencyTable(Player player);
void displayPlayerSuitFrequencyTable(Player player);

//score combo functions
int checkPair(Hand hand,int FaceFrequencyTable[13]);
int checkTwoPairs(Hand hand,int FaceFrequencyTable[13]);
int checkThreeOfAKind(Hand hand,int FaceFrequencyTable[13]);
int checkFourOfAkind(Hand hand,int FaceFrequencyTable[13]);
int checkFullHouse(Hand hand,int FaceFrequencyTable[13],int threeOfAkind,int twoOfAnother);
int checkFlush(Hand hand, int SuitFrequencyTable[4]);
int checkStraight(Hand hand,int FaceFrequencyTable[13]);

//dealer functions
int checkDealerHandCombo(Player dealer);
void dealerComputer(const int wDeck[][13],Hand *playerHand,int FaceFrequencyTable[13],int *cardIndex);

//compare hand functions
int compareHands(int playerHandRank, int dealerHandRank,Player player,Player dealer);

//display title functions
void printFileContentsInPurple(const char *filename);

//UI functions
void clearScreen();


/*
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
*/
