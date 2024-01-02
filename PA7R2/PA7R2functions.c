#include "PA7R2functions.h"
/* shuffle cards in deck */

void shuffle (int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
 
	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

void draw(int wDeck[][13],Hand *hand,int *cardIndex){
    int currentCardIndex = *cardIndex;//set current card index to # of cards left in deck
    for(int handIndex = 0; handIndex < 5; handIndex++){
        for(int row = 0; row < 4; row++){
            for(int column = 0; column < 13; column++){
                if(wDeck[row][column] == currentCardIndex){//set the card at the top of the deck
                    hand->hand[handIndex].suitOfCard=row;//set the suit of card to the card in deck
                    hand->hand[handIndex].faceOfCard=column;//set the face of the card to the card in deck
                    //printf("hand: %d, %d,%d %d\n",handIndex,row,column,wDeck[row][column]);//for testing
                }
            }
        }
        currentCardIndex--;//decrement current card index for each card drawn
    }
    *cardIndex = currentCardIndex;//set cardindex to # of cards left in the deck
}

void drawAmountOfCards(int wDeck[][13],Hand *hand,int amountOfCards,int *cardIndex){
    int currentCardIndex = *cardIndex;//set current card index to # of cards left in deck
    for(int indexHand = 0; indexHand < amountOfCards;indexHand++){
        for(int indexRow = 0; indexRow < 4; indexRow++){
            for(int indexColumn = 0; indexColumn < 13; indexColumn++){
                if(wDeck[indexRow][indexColumn] == currentCardIndex){//set the card at the top of the deck
                    hand->hand[indexHand].suitOfCard=indexRow;//set the suit of card to the card in deck
                    hand->hand[indexHand].faceOfCard=indexColumn;//set the face of the card to the card in deck
                    //printf("hand: %d, %d,%d %d\n",indexHand,indexRow,indexColumn,wDeck[indexRow][indexColumn]);
                }
            }
            
        }
        currentCardIndex--;//decrement current card index for each card drawn
    }
    *cardIndex = currentCardIndex;//set cardindex to # of cards left in deck
}

void discardCards(int wDeck[][13],Hand *hand, int discardCards){
    for(int indexDiscard = 0; indexDiscard < discardCards; indexDiscard++){
        hand->hand[indexDiscard].faceOfCard=-1;//set face to empty
        hand->hand[indexDiscard].suitOfCard=-1;//set suit to empty
    }
}

void setPlayerName(Player *player, const char *name)
{
     strcpy(player->name,name);//set player name to input name
}

void initializePlayerObject(Player *player)
{
    for(int i = 0; i < 5; i++){//initialize player hand to empty
        player->playerHand.hand[i] = (Card){-1,-1};
    }
    for(int j = 0; j < 13; j++){//initialize face frequency table to zero
        player->FaceFrequencyTable[j] = 0;
    }
    for(int k = 0; k < 4; k++){//initialize suit frequency table to zero
        player->SuitFrequencyTable[k] = 0;
    }
}

void displayHand(Player player)
{
    printf("%s's Hand:\n",player.name);//print player name
    showHand(player.playerHand);//display cards in hand
}

void showHand(Hand hand)
{
    for(int i = 0; i < 5; i++){//increment through hand
        printf("[Card %d]:",i+1);
        renderCard(hand.hand[i].faceOfCard,hand.hand[i].suitOfCard);//display card
    }
}

int checkPlayerHandCombo(Player player,int wDeck[][13],int *cardIndex)
{
    int playerChoice = 0;int chosen = 0;
    const char *scoreComboAvailability[] = {"Unavailable","Available"};
    const char *scoreCombo[]={"Pair", "Two Pairs", "Three of a kind", "Four of a kind", "Full house", "Flush", "Straight"};
    
    setPlayerFaceFrequencyTable(player.playerHand,player.FaceFrequencyTable);
    setPlayerSuitFrequencyTable(player.playerHand,player.SuitFrequencyTable);
    //displayPlayerFaceFrequencyTable(player);
    //displayPlayerSuitFrequencyTable(player);

    //showHand(player.playerHand);
    int pairCheck =0; int twoPairCheck = 0; int threeOfAKindCheck = 0; int fourofAkindCheck = 0;
    int fullHouseCheck = 0; int flushCheck = 0; int straightCheck = 0;
    


    pairCheck = checkPair(player.playerHand,player.FaceFrequencyTable);
    twoPairCheck = checkTwoPairs(player.playerHand,player.FaceFrequencyTable);
    threeOfAKindCheck = checkThreeOfAKind(player.playerHand,player.FaceFrequencyTable);
    fourofAkindCheck=checkFourOfAkind(player.playerHand,player.FaceFrequencyTable);
    fullHouseCheck = checkFullHouse(player.playerHand,player.FaceFrequencyTable,threeOfAKindCheck,pairCheck);
    flushCheck = checkFlush(player.playerHand,player.SuitFrequencyTable);
    straightCheck = checkStraight(player.playerHand,player.FaceFrequencyTable);
    int optionArr[] = {pairCheck,twoPairCheck,threeOfAKindCheck,fourofAkindCheck,fullHouseCheck,flushCheck,straightCheck};

    

    setPlayerFaceFrequencyTable(player.playerHand,player.FaceFrequencyTable);
    setPlayerSuitFrequencyTable(player.playerHand,player.SuitFrequencyTable);


    printf("[I] Combos Available\n");
    for(int i = 0; i < 7;i++){
        printf("[%d] %s : %s\n",i+1,scoreCombo[i],scoreComboAvailability[optionArr[i]]);
    }
    printf("[8] High Card : \n");
    do{
        printf(">Enter Combo:\n");
        scanf("%d",&playerChoice);
        switch(playerChoice){
        case 1://pair
        if(!pairCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 1;
        }
        break;

        case 2://two pair
        if(!twoPairCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 2;
        }
        break;

        case 3://three of a kind
        if(!threeOfAKindCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 3;
        }
        break;

        case 4://four of a kind
        if(!fourofAkindCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 4;
        }
        break;

        case 5://fullhouse
        if(!fullHouseCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 5;
        }
        break;

        case 6://flush
        if(!flushCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 6;
        }
        break;

        case 7: //straight 
        if(!straightCheck){
            printf("Unavailable\n");
        }else{
            chosen = 1;
            return 7;
        }
        break;

        case 8://high card
        return 0;

        break;

        default:
        printf(">Enter Valid input\n");
        break;
    }
    }while(chosen !=1);





    
    
}

void setPlayerFaceFrequencyTable(Hand playerhand,int *FaceFrequencyTable)//set player face frequency table
{
    for(int handIndex = 0; handIndex < 5; handIndex++){
        if(playerhand.hand[handIndex].faceOfCard !=-1 || playerhand.hand[handIndex].suitOfCard != -1){
            FaceFrequencyTable[playerhand.hand[handIndex].faceOfCard]++;
        }
    }

}
/*if(player->playerHand.hand[handIndex].faceOfCard != -1 || player->playerHand.hand[handIndex].suitOfCard != -1){
            player->FaceFrequencyTable[player->playerHand.hand[handIndex].faceOfCard]++;
        }*/

void setPlayerSuitFrequencyTable(Hand playerhand,int *SuitFrequencyTable)//set player suit frequency table
{
    for(int handIndex = 0; handIndex < 5; handIndex++){
        if(playerhand.hand[handIndex].faceOfCard !=-1 || playerhand.hand[handIndex].suitOfCard != -1){
            SuitFrequencyTable[playerhand.hand[handIndex].suitOfCard]++;
        }
    }
}
/*for(int handIndex = 0; handIndex < 5; handIndex++){
        player->FaceFrequencyTable[player->playerHand.hand[handIndex].faceOfCard]++;
    }*/
        //player->SuitFrequencyTable[player->playerHand.hand[handIndex].suitOfCard]++;


void displayPlayerFaceFrequencyTable(Player player)//display player face frequency table
{
    const char *faceValues[] = {//face values
        "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"
    };
    
    printf("%s's Face Frequency Table\n",player.name);
    for(int i = 0; i < 13; i++){
        printf("%s:  %d\n",faceValues[i],player.FaceFrequencyTable[i]);
    }
}

void displayPlayerSuitFrequencyTable(Player player)//display player suit frequency table
{
    const char *cardSuits[] = {//card suits
        "Hearts", "Diamonds", "Clubs", "Spades"
    };

    printf("%s's Suit Frequency Table\n",player.name);
    for(int i = 0; i < 4; i++){
        printf("%s: %d\n",cardSuits[i],player.SuitFrequencyTable[i]);
    }
}

void renderCard(int cardFace,int cardSuit)//render card
{
    const char *faceValues[] = {//face values
        "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"
    };
    const char *cardSuits[] = {//card suits
        "Hearts", "Diamonds", "Clubs", "Spades"
    };
    
    if(cardFace != -1 || cardSuit != -1){//if face or suit is not -1 (empty) print the face and suit 
        printf("%s of %s \n",faceValues[cardFace],cardSuits[cardSuit]);
    }else{//if face or suit is -1, print empty instead
        printf("Empty\n");
    }
}

int checkPair(Hand hand, int FaceFrequencyTable[13])//Write a function to determine if the hand contains a pair
{
    for(int i = 0; i < 13; i++){
        if(FaceFrequencyTable[i] ==2){//return 1 if pair is found
            return 1;
        }
    }
    return 0;
}

int checkTwoPairs(Hand hand, int FaceFrequencyTable[13])//Write a function to determine if the hand contains two pairs
{
    int paircount=0;//count amount of pairs
    for(int i = 0; i < 13; i++){
        if(FaceFrequencyTable[i] == 2){
            paircount++;//increment paircount if pair is found
        }
    }
    if(paircount == 2){//return 1 if two pairs are found
        //printf("%d\n",paircount);
        return 1;
    }
    //printf("%d\n",paircount);
    return 0;
    
}

int checkThreeOfAKind(Hand hand, int FaceFrequencyTable[13])//Write a function to determine if the hand contains three of a kind (i.e.three jacks)
{
    for(int i = 0; i < 13; i++){
        if(FaceFrequencyTable[i] ==3){//return 1 if three of a kind is found
            return 1;
        }
    }
    return 0;
}

int checkFourOfAkind(Hand hand, int FaceFrequencyTable[13])//Write a function to determine if the hand contains four of a kind (i.e.four aces)
{
    for(int i = 0; i < 13; i++){
        if(FaceFrequencyTable[i] == 4){//return 1 if four of a kind is found
            return 1;
        }
    }
    return 0;
}

int checkFullHouse(Hand hand, int FaceFrequencyTable[13],int threeOfAkind,int twoOfAnother)//Write a function to determine if the hand contains a full house (i.e three of a kind and two of another).
{
    if(threeOfAkind == 1 && twoOfAnother == 1){//check if there is three of a kind, and a pair
        return 1;
    }
    return 0;
}

int checkFlush(Hand hand, int SuitFrequencyTable[4])//Write a function to determine if the hand contains a flush (i.e. all five cards of the same suit).
{
    for(int i = 0; i < 4; i++){
        if(SuitFrequencyTable[i] == 5){//check if all the cards have the same face
            return 1;
        }
    }
    return 0;
}

int checkStraight(Hand hand, int FaceFrequencyTable[13])//Write a function to determine if the hand contains a straight (i.e. five cards of consecutive face values).
{
    int consecutiveCount = 0;
    for(int i = 0; i < 13; i ++){//index through whole face frequency table
        if(FaceFrequencyTable[i] == 1){//if face frequency == 1, increment consecutive count
            consecutiveCount++;
        }else if(FaceFrequencyTable[i] == 0 && consecutiveCount == 5){//if there are 5 consecutive counts and the current face frequency table index is zero, return 1
            return 1;
        }else{//set consecutive count to zero after conecutiveness is broken
            consecutiveCount = 0;
        }
    }
    if(consecutiveCount == 5){//if consecutive count is 5, return 1
        //printf("%d\n",consecutiveCount);
        return 1;
    }
    //printf("%d\n",consecutiveCount);
    return 0;
    
}

int checkDealerHandCombo(Player dealer)
{
    /*int pairCheck =0; int twoPairCheck = 0; int threeOfAKindCheck = 0; int fourofAkindCheck = 0;
    int fullHouseCheck = 0; int flushCheck = 0; int straightCheck = 0;
    
    setPlayerFaceFrequencyTable(player.playerHand,&player.FaceFrequencyTable);
    setPlayerSuitFrequencyTable(player.playerHand,&player.SuitFrequencyTable);
    displayPlayerFaceFrequencyTable(player);
    displayPlayerSuitFrequencyTable(player);


    pairCheck = checkPair(player.playerHand,player.FaceFrequencyTable);
    twoPairCheck = checkTwoPairs(player.playerHand,player.FaceFrequencyTable);
    threeOfAKindCheck = checkThreeOfAKind(player.playerHand,player.FaceFrequencyTable);
    fourofAkindCheck=checkFourOfAkind(player.playerHand,player.FaceFrequencyTable);
    fullHouseCheck = checkFullHouse(player.playerHand,player.FaceFrequencyTable,threeOfAKindCheck,pairCheck);
    flushCheck = checkFlush(player.playerHand,player.SuitFrequencyTable);
    straightCheck = checkStraight(player.playerHand,player.FaceFrequencyTable);*/

    int highestCombo = 0;


    int dealerPairCheck=0;int dealerTwoPairCheck=0;int dealerThreeOfAKindCheck = 0; int dealerFourOfAKindCheck =0;
    int dealerFullHouseCheck=0;int dealerFlushCheck = 0; int dealerStraightCheck=0;

    /*
    set the AI's frequency tables to their hand
    */
    setPlayerFaceFrequencyTable(dealer.playerHand,dealer.FaceFrequencyTable);
    setPlayerSuitFrequencyTable(dealer.playerHand,dealer.SuitFrequencyTable);
    //displayPlayerFaceFrequencyTable(dealer);
    //displayPlayerSuitFrequencyTable(dealer);


    dealerPairCheck=checkPair(dealer.playerHand,dealer.FaceFrequencyTable);
    dealerTwoPairCheck=checkTwoPairs(dealer.playerHand,dealer.FaceFrequencyTable);
    dealerThreeOfAKindCheck = checkThreeOfAKind(dealer.playerHand,dealer.FaceFrequencyTable);
    dealerFourOfAKindCheck=checkFourOfAkind(dealer.playerHand,dealer.FaceFrequencyTable);
    dealerFullHouseCheck=checkFullHouse(dealer.playerHand,dealer.FaceFrequencyTable,dealerPairCheck,dealerThreeOfAKindCheck);
    dealerFlushCheck=checkFlush(dealer.playerHand,dealer.SuitFrequencyTable);
    dealerStraightCheck =checkStraight(dealer.playerHand,dealer.FaceFrequencyTable);
    
    /*printf(": %d\n",dealerPairCheck);
    printf(": %d\n",dealerTwoPairCheck);
    printf(": %d\n",dealerThreeOfAKindCheck);
    printf(": %d\n",dealerFourOfAKindCheck);
    printf(": %d\n",dealerFullHouseCheck);
    printf(": %d\n",dealerFlushCheck);
    printf(": %d\n",dealerStraightCheck);*/

    /*
    array for the combo options for the AI to choose from
    */
    int dealerOptionArr[] = {dealerPairCheck,dealerTwoPairCheck,dealerThreeOfAKindCheck,dealerFourOfAKindCheck,
    dealerFullHouseCheck,dealerFlushCheck,dealerStraightCheck};

    int i =0;int highestcomboindex=0;//index and index of the highest combo from the dealer option array
    do{
        if(dealerOptionArr[i] == 1){
            highestCombo = dealerOptionArr[i];
            //printf("%d\n",highestCombo);
            //printf("%d\n",i);
            highestcomboindex=i+1;
        }
        i++;
    }while(i != 7);
    //printf("higest combo %d\n",highestCombo);
    //printf("higest combo index %d\n",highestcomboindex);
    return highestcomboindex;//returns the highest rank (index) able to score 
}

void dealerComputer(const int wDeck[][13],Hand *playerHand,int FaceFrequencyTable[13],int *cardIndex)//this is useless i just threw this away
{
    int mostOccurent = 0;int most =0;int drawAmount=5;
    for(int i = 0; i < 13; i++){
        if(FaceFrequencyTable[i] > most){
            most = FaceFrequencyTable[i];
            mostOccurent=i;
        }
    }
    drawAmount=drawAmount-most;
    drawAmountOfCards(&wDeck,playerHand,drawAmount,cardIndex);
}

int compareHands(int playerHandRank, int dealerHandRank,Player player,Player dealer)//compare hand ranking to decide who is winner
{
    if(playerHandRank > dealerHandRank){
        printf("%s wins!\n",player.name);
        return 1;
    }else if(playerHandRank < dealerHandRank){
        printf("%s wins!\n",dealer.name);
        return 0;
    }else{
        printf("Tie!\n");
    }
}

void printFileContentsInPurple(const char *filename)//i literally stole this from stack overflow
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char buffer[1000];
    printf(ANSI_COLOR_PURPLE);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    printf(ANSI_COLOR_RESET);
    fclose(file);
}

void clearScreen(){//i stole this from stack overflow lol
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



/*  printf("%d\n",pairCheck);
    printf("%d\n",twoPairCheck);
    printf("%d\n",threeOfAKindCheck);
    printf("%d\n",fourofAkindCheck);
    printf("%d\n",fullHouseCheck);
    printf("%d\n",flushCheck);
    printf("%d\n",straightCheck);
    
    */

//shuffle new deck
//each draw cards
//draw/discard based on what you decide
//compare cards
//repeat

//count what card occuring the most
//draw amount of cards that are not the amount of common cards