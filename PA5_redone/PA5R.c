#include "PA5R.h"

/*struct player_scorecard{
    char *name;
    int scorecard[14];
    int frequencytable[7];
};*/

void print_game_rules(void){
      printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations. See the score table.\n");
}

void roll_dice(int *arr)
{
  for(int i = 0; i < 5; i++){
        arr[i] = rand() % 6 + 1;
    }
}

void reroll_dice(int *arr)
{
  int reroll = 0;
  printf("How many dice do you want to reroll? [1-5]\n");
  do{
    scanf("%d",&reroll);
  }while(reroll > 5 || reroll < 0);
  //scanf("%d",&reroll);
  /*if(reroll > 5 || reroll < 0){
    printf("Enter valid input\n");
    scanf("%d",&reroll);
  }*/
  for(int i = 1; i < reroll+1; i++){
    arr[i] = rand() % 6 + 1;
  }

}

void display_dice(int *arr)
{
  printf("\n");
  for(int i = 0; i < 5; i++){
    printf("Dice [%d]: %d ",i,arr[i]);
  }
  printf("\n");
}

int check_scorecard(int scorecard[])
{
  for(int i = 1; i < 14; i++){
    if(scorecard[i] == -1){
      return 1;
    }
  }
}

void sort_die(int arr[], int freq[])
{
    int index = 0;
	  for (; index < 5; index++)
	  {
		  if (arr[index] > 0) 
		  {
			  freq[arr[index]]++; 
		  }
	}
}

int prompt(void)
{
    char choice = '\0';
    printf("Are you sure? [Y/N]\n");
    //scanf("%c",&choice);
    /*switch(choice){
      case 'Y':
      case 'y':
      return 1;
      break;

      case 'N':
      case 'n':
      return 0;
      break;

      default:
      printf("Enter valid input\n");
      scanf("%c",&choice);
    }*/
    do{
      scanf("%c",&choice);
      switch(choice){
      case 'Y':
      case 'y':
      return 1;
      break;

      case 'N':
      case 'n':
      return 0;
      break;

      default:
      printf("Enter valid input\n");
      //scanf("%c",&choice);
    }
    }while(choice != 'Y' || choice != "y" || choice != 'N' || choice != 'n');
    
}
void display_scorecard(struct player_scorecard player)
{
  char *name = player.name;

  printf("%s's Scorecard:\n",name);
  for(int i = 1; i < 14; i++){
    printf("[%d]: %d\n",i,player.scorecard[i]);
  }
}

void initialize_scorecard(int *arr)
{
  for(int i = 1; i < 14; i++){
    arr[i] = -1;
  }
}

void initialize_frequencytable(int *arr)
{
  for(int i = 1; i < 7; i++){
    arr[i] = 0;
  }
}

void sum_scorecard(struct player_scorecard player)
{
  int sum = 0;
  for(int i = 1; i < 14; i++){
    sum = sum + player.scorecard[i];
  }
  player.score = sum;
  printf("%s's Score: %d\n",player.name,player.score);
}

void determine_score(int frequencytable[], int scorecard[])
{
    // ##UPPER SECTION##

    // Aces/Sum of dice with number one

    // Twos/Sum of dice with number two

    // Threes/Sum of dice with number three

    // Fours/Sum of dice with number four

    // Fives/Sum of dice with number five

    // Sixes/Sum of dice with number six

    // ##LOWER SECTION##

    // Three-of-akind/Three dice with the same face/Sum of all face values on the 5 dice

    // Four-of-akind/Four dice with the same face/Sum of all face values on the 5 dice

    // Full house/One pair and a three-of-a-kind/25

    // Small straight/A sequence of four dice/30

    // Large straight/A sequence of five dice/40

    // Yahtzee(think fiveof-a-kind)/Five dice with the same face /50

    // Chance May be used for any sequence of dice; this is the catch all combination/Sum of all face values on the 5 dice

    int scorechoice = 0;int playerpromt = 0;int chosen = 0;
    int aces = 0;int twos = 0;int threes = 0;int fours = 0;int fives = 0;int sixes = 0;int threeofakind = 0;int fourofakind = 0;
    int fullhouse = 0;int smallstraight = 0;int largestraight = 0;int yahtzee = 0;int chance = 0;
    aces = Aces(frequencytable);
    twos = Twos(frequencytable);
    threes = Threes(frequencytable);
    fours = Fours(frequencytable);
    fives = Fives(frequencytable);
    sixes = Sixes(frequencytable);
    threeofakind = Four_of_akind(frequencytable);
    fourofakind = Three_of_akind(frequencytable);
    fullhouse = Full_house(frequencytable);
    smallstraight = Small_straight(frequencytable);
    largestraight = Large_straight(frequencytable);
    yahtzee = Yahtzee(frequencytable);
    chance = Chance(frequencytable); 
    
    //printf("What combo do you want to score?\n");
    //scanf("%d",scorechoice);
    do{
      printf("What combination do you want to score?\n");
      scanf("%d",&scorechoice);
      switch (scorechoice)
    {
    case 1:
    //scorecard[1] = aces;
    if(scorecard[1] == -1){
      scorecard[1] = aces;
      printf("%d\n",aces);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 2:
    //scorecard[2] = twos;
    if(scorecard[2] == -1){
      scorecard[2] = twos;
      printf("%d\n",twos);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 3:
    //scorecard[3] = threes;
    if(scorecard[3] == -1){
      scorecard[3] = threes;
      printf("%d\n",threes);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 4:
    //scorecard[4] = fours;
    if(scorecard[4] == -1){
      scorecard[4] = fours;
      printf("%d\n",fours);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 5:
    //scorecard[5] = fives;
    if(scorecard[5] == -1){
      scorecard[5] = fives;
      printf("%d\n",fives);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 6:
    //scorecard[6] = sixes;
    if(scorecard[6] == -1){
      scorecard[6] = sixes;
      printf("%d\n",sixes);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 7:
    //scorecard[7] = Three_of_akind;
    if(scorecard[7] == -1){
      //scorecard[7] = threeofakind;
      scorecard[7] = threeofakind;
      printf("%d\n",threeofakind);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 8:
    //scorecard[8] = Four_of_akind;
    if(scorecard[8] == -1){
      scorecard[8] = fourofakind;
      printf("%d\n",fourofakind);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 9:
    //scorecard[9] = fullhouse;
    if(scorecard[9] == -1){
      scorecard[9] = fullhouse;
      printf("%d\n",fullhouse);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 10:
    //scorecard[10] = smallstraight;
    if(scorecard[10] == -1){
      scorecard[10] = smallstraight;
      printf("%d\n",smallstraight);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 11:
    //scorecard[11] = largestraight;
    if(scorecard[11] == -1){
      scorecard[11] = largestraight;
      printf("%d\n",largestraight);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 12:
    //scorecard[12] = yahtzee;
    if(scorecard[12] == -1){
      scorecard[12] = yahtzee;
      printf("%d\n",yahtzee);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    case 13:
    //scorecard[13] = chance;
    if(scorecard[13] == -1){
      scorecard[13] = chance;
      printf("%d\n",chance);
      chosen = 1;
    }else{
      printf("Invalid input\n");
    }
    break;

    default:
    printf("Invalid input\n");
    break;
  }
    }while(chosen != 1);

    
}

int Aces(int frequenctytable[])
{
    int sum = 0;
    sum = 1 * frequenctytable[1];
    return sum;
}

int Twos(int frequenctytable[])
{
    int sum = 0;
    sum = 2 * frequenctytable[2];
    return sum;
}

int Threes(int frequenctytable[])
{
    int sum = 0;
    sum = 3 * frequenctytable[3];
    return sum;
}

int Fours(int frequenctytable[])
{
    int sum = 0;
    sum = 4 * frequenctytable[4];
    return sum;
}

int Fives(int frequenctytable[])
{
    int sum = 0;
    sum = 5 * frequenctytable[5];
    return sum;
}

int Sixes(int frequenctytable[])
{
    int sum = 0;
    sum = 6 * frequenctytable[6];
    return sum;
}

int Three_of_akind(int frequencytable[])
{
    int sum = 0;
    for(int i = 1; i < 7;i++){
      if(frequencytable[i] == 3){
        sum = frequencytable[i] * 3;
        
      }else{
        sum = 0;
    }
    return sum;

}
}

int Four_of_akind(int frequencytable[])
{
    int sum = 0;
    for(int i = 1; i < 7; i++){
      if(frequencytable[i] == 4){
        sum = frequencytable[i] * 4;
      }else{
        sum = 0;
      }
    }
    return sum;
}

int Full_house(int frequencytable[])
{
    int sum = 0;
    int threeofakind=0;int pair = 0;
    for(int i = 1; i < 7; i++){
      if(frequencytable[i] == 3){
        threeofakind =  1; 
      }
      if(frequencytable[i] == 2){
        pair = 1;
      }
    }
    if(threeofakind == 1 && pair == 1){
      sum = 25;
    }else{
      sum = 0;
    }
    return sum;
}

int Small_straight(int frequencytable[])
{
    int sum = 0;
    for(int i = 1; i < 7; i++){
      if(frequencytable[i] == 4){
        sum = 30;
      }else{
        sum = 0;;
      }
    }
    return sum;
}

int Large_straight(int frequencytable[])
{
    int sum = 0;
    for(int i = 1; i < 7; i++){
      if(frequencytable[i] == 5){
        sum = 40;
      }else{
        sum = 0;
      }
    }
    return sum;
}

int Yahtzee(int frequencytable[])
{
    int sum = 0;
    for(int i = 1; i < 7; i++){
      if(frequencytable[i] == 5){
        sum = 50;
      }else{
        sum = 0;
      }
    }
    return sum;
}

int Chance(int frequencytable[])
{
    int sum = 0;
    for(int i = 1; i < 7; i++){
      sum = sum + (i* frequencytable[i]);
    }
    return sum;
}

void play_game(void)
{
  int game = 1;
  int plyr = 0; char *temp = " ";
  int dice[5];
  char prompt_reroll;
  int count_rerolls = 0;
  int user_reroll = 0;
  //printf("How many players? [2-10]\n");
  do{
    printf("How many players? [2-10]\n");
    scanf("%d",&plyr);
    while (getchar() != '\n');
  }while(plyr > 10 || plyr < 2);

  struct player_scorecard players[plyr];
  for(int i = 0; i < plyr; i++){
    printf("Enter player name: \n");
    fgets(players[i].name, sizeof(players[i].name), stdin);
    //name[strcspn(name, "\n")] = '\0';
    players[i].name[strcspn(players[i].name,"\n")] = '\0';
    initialize_scorecard(players[i].scorecard);
    initialize_frequencytable(players[i].frequencytable);
  }
  for(int i = 0; i < plyr; i++){
    display_scorecard(players[i]);
  }

  do{
    
    for(int i = 0; i < 13; ++i){
      if(i <= 13){
        game = 0;
      }
      for(int j = 0; j < plyr; ++j){
        user_reroll = 0;
        count_rerolls = 1;
        printf("Round %d:\n",i+1);
        printf("%s's Turn!\n",players[j].name);
        initialize_frequencytable(players[j].frequencytable);
        roll_dice(dice);
        display_dice(dice);
        //printf("Do you want to reroll? [Y/N]\n");
        
        do{
          if(count_rerolls == 2){
              user_reroll = 1;
            }
          printf("Do you want to reroll? [Y/N]\n");
          scanf(" %c",&prompt_reroll);
          switch(prompt_reroll){
            case 'Y':
            case 'y':
            count_rerolls++;
            initialize_frequencytable(players[j].frequencytable);
            reroll_dice(dice);
            display_dice(dice);
            //user_reroll = 1;
            break;

            case 'N':
            case 'n':
            user_reroll = 1;
            break;

            default:
            printf("Invalid input\n");
          }
        }while(user_reroll != 1);
        //reroll_dice(dice);
        sort_die(dice,players[j].frequencytable);
        display_scorecard(players[j]);
        determine_score(players[j].frequencytable,players[j].scorecard);
        }
    }
  }while(game != 0);
  int max = players[0].score;
  int winner_index = 0;
  char *winner= players[0].name;
  for(int i = 0; i < plyr; i++){
    if(max < players[i].score){
      max = players[i].score;
      winner_index = i;
    }
    sum_scorecard(players[i]);
    display_scorecard(players[i]);
  }
  printf("%s WINS!\n",players[winner_index].name);
}


/*printf("Round %d:\n",i+1);
      printf("%s's Turn!\n",players[i].name);
      roll_dice(dice);
      display_dice(dice);
      //printf("Do you want to reroll? [Y/N]\n");
      do{
        printf("Do you want to reroll? [Y/N]\n");
        scanf(" %c",&prompt_reroll);
        switch(prompt_reroll){
          case 'Y':
          case 'y':
          reroll_dice(dice);
          display_dice(dice);
          count_rerolls++;
          //user_reroll = 1;
          if(count_rerolls >= 2){
            user_reroll = 1;
          }
          break;

          case 'N':
          case 'n':
          user_reroll = 1;
          break;

          default:
          printf("Invalid input\n");
        }
      }while(user_reroll != 1);
      //reroll_dice(dice);
      sort_die(dice,players[i].frequencytable);
      display_scorecard(players[i]);
      determine_score(players[i].frequencytable,players[i].scorecard);*/