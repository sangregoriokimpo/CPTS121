#include "PA4functions.h"

char read_text(FILE *infile){//READ TEXT FILE 
    char read_text = '\0';
    fscanf(infile,"%c",&read_text);
    return read_text;
}

void print_game_rules(void)//PRINT GAME RULES
{
    printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. To win, you must continue rolling the dice until you make your point. The player loses by rolling a 7 before making the point.\n");
}

double get_bank_balance(void)//GET BANK BALANCE
{
    double bank_balance=0.0;
    printf("Enter Bank Balance: \n");
    scanf("%lf",&bank_balance);
    return bank_balance;

}

double get_wager_amount(void)//GET WAGER AMOUNT
{
    double wager_amount = 0.0;
    printf("Enter Wager Amount: \n");
    scanf("%lf",&wager_amount);
    return wager_amount;

}

int check_wager_amount(double wager, double balance)//CHECK IF WAGER AMOUNT IS WITHIN BUDGET OF BANK BALANCE
{
    int check_wager_amount = 1;
    if(balance - wager <= 0){
        check_wager_amount = 0;
        return check_wager_amount;
    }else{
        return check_wager_amount;
    }
}

int roll_die(void)//ROLL DICE
{
    int roll_die = 0;
    //srand((unsigned int)time(NULL));
    roll_die = rand() % 6 + 1;
    return roll_die;

}

int calculate_sum_dice(int die1_value, int die2_value)//CALCULATE SUM OF DICE
{
    int sum_dice = 0;
    sum_dice = die1_value + die2_value;
    return sum_dice;
}

int is_win_loss_or_point(int sum_dice)//CHECK IF SUM OF DICE IS WIN/LOSS/BECOMES THE POINT 
{
    if(sum_dice == 7 || sum_dice == 11){
        return 1; //player wins
    }else if(sum_dice == 2 || sum_dice == 3 || sum_dice == 12){
        return 0; //"craps", the player loses
    }else{
        return -1; //sum becomes the players point
    }
}

int is_point_loss_or_neither(int sum_dice, int point_value)//CHECK IF ROLL IS WIN/LOSS OR NEITHER
{
    if(sum_dice == point_value){
        return 1;//player wins
    }else if(sum_dice == 7){
        return 0;//player loses
    }else{
        return -1;
    }
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)//ADJUST BANK BALANCE, ADD OR SUBTRACT BASED ON WIN/LOSS
{
    if(add_or_subtract == 1){
        bank_balance = bank_balance + wager_amount;//WIN
    }else if(add_or_subtract == 0){
        bank_balance = bank_balance - wager_amount;//LOSS
    }
    return bank_balance;
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)//CHATTER MESSAGES
{
    //srand((unsigned int)time(NULL));

    //ROLLS A DICE FOR EACH CONDITION, EACH SIDE OF THE DICE IS A CHATTER MESSAGE
    int message_event_win = rand() % 6 + 1;
    int message_event_loss = rand() % 6 + 1;
    int message_event_rolls = rand() % 6 + 1;
    int message_event_initial_balance = rand() % 6 + 1;
    int message_event_bank_balance = rand() % 6 + 1;

    if(win_loss_neither == 1){
        switch(message_event_win){
            case 1:
            printf("You're up big, now's the time to cash in your chips!\n");
            break;
            case 2:
            printf("You've got this!\n");
            break;
            case 3:
            printf("You're on a roll!\n");
            break;
            case 4:
            printf("Good job!\n");
            break;
            case 5:
            printf("Craps champion?\n");
            break;
            case 6:
            printf("Craps millionare!\n");
            break;
        }
    }else if(win_loss_neither == 0){
        switch(message_event_loss){
            case 1:
            printf("Sorry, you busted!\n");
            break;
            case 2:
            printf("Just give up!\n");
            break;
            case 3:
            printf("The table is laughing at you!\n");
            break;
            case 4:
            printf("You think you can clutch this one?\n");
            break;
            case 5:
            printf("Not going well isn't it?\n");
            break;
            case 6:
            printf("You got this! I believe in you!\n");
            break;
        }
    }
    if (number_rolls >= 10) {
        switch (message_event_rolls) {
            case 1:
                printf("You've been rolling a lot! Feeling lucky?\n");
                break;
            case 2:
                printf("The dice are your best friends today!\n");
                break;
            case 3:
                printf("You must really love craps with all these rolls!\n");
                break;
            case 4:
                printf("Keep rolling, the excitement never ends!\n");
                break;
            case 5:
                printf("Roll after roll, the thrill continues!\n");
                break;
            case 6:
                printf("You're on a roll and can't stop!\n");
                break;
        }
    }
    if (initial_bank_balance >= 1000) {
        switch (message_event_initial_balance) {
            case 1:
                printf("Starting with a big bankroll! You're a high roller!\n");
                break;
            case 2:
                printf("You've got deep pockets today!\n");
                break;
            case 3:
                printf("Money isn't a problem for you, is it?\n");
                break;
            case 4:
                printf("You're ready to make some serious bets!\n");
                break;
            case 5:
                printf("A big bank balance means big wins, right?\n");
                break;
            case 6:
                printf("High stakes, high excitement!\n");
                break;
        }
    }
    if (current_bank_balance <= 100) {
        switch (message_event_bank_balance) {
            case 1:
                printf("Uh-oh, your bank balance is getting low. Be careful!\n");
                break;
            case 2:
                printf("Time to reconsider your bets, your balance is shrinking!\n");
                break;
            case 3:
                printf("Don't go broke, play smart!\n");
                break;
            case 4:
                printf("It's time to turn things around, your balance is hurting!\n");
                break;
            case 5:
                printf("You're living on the edge with that balance!\n");
                break;
            case 6:
                printf("A comeback story in the making? Let's find out!\n");
                break;
        }
    }

}

double playgame(void)//PLAYS THE GAME
{
    int die1 = 0; int die2 = 0;int sum_dice = 0; double wager = 0.0; extern double bank_balance; int number_rolls = 0;double initial_bank_balance = 0.0;
    int win_or_loss = '\0'; int points = 0; int check_wager = 0;
    int game = 1;
    //bank_balance = get_bank_balance();
    if(bank_balance == 0){
        bank_balance = get_bank_balance();
    }
    initial_bank_balance = bank_balance;
    //wager = get_wager_amount();
    //check_wager = check_wager_amount(wager,bank_balance);

    do{//CHECK IF WAGER IS WITHIN BANK BALANCE BUDGET
        wager = get_wager_amount();
        check_wager = check_wager_amount(wager,bank_balance);
    }while(check_wager == 0 );


    print_line();
    printf("Bank Balance: $%.2lf\n",bank_balance);
    printf("Wager Amount: $%.2lf\n",wager);
    print_line();
   
    //die1 = roll_die();
    //die2 =roll_die();
    //printf("Dice 1: [%d]\n",die1);
    //printf("Dice 2: [%d]\n",die2);
    do{
        
        rollingdice_loadingbar();
        die1 = roll_die();
        die2 =roll_die();
        number_rolls++;
        printf("Number of rolls: [%d]\n",number_rolls);
        printf("Point Value: [%d]\n",points);
        printf("Dice 1: [%d]\n",die1);
        printf("Dice 2: [%d]\n",die2);
        sum_dice = calculate_sum_dice(die1,die2);
        //win_or_loss = is_win_loss_or_point(sum_dice);
        //chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);

        if(number_rolls <= 1){
            win_or_loss = is_win_loss_or_point(sum_dice);
            switch(win_or_loss){
            case 1:
            print_line();
            display_winner();
            printf("\n");
            printf("Player wins! Wager added onto bank balance.\n");
            bank_balance = adjust_bank_balance(bank_balance,wager,1);
            chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);
            print_line();
            game = 0;

            break;
            
            case 0:
            print_line();
            display_loser();
            printf("\n");
            printf("Craps! Player loses. Wager subtracted from bank balance\n");
            bank_balance = adjust_bank_balance(bank_balance,wager,0);
            
            chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);
            print_line();
            game = 0;
            break;

            case -1:
            printf("Sum of dice becomes player's point\n");
            points = sum_dice;
            chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);
            print_line();
            
            break;
        }
        }else if(number_rolls > 1){
            win_or_loss = is_point_loss_or_neither(sum_dice,points);
            switch(win_or_loss){
                case 1:
                print_line();
                display_winner();
                printf("\n");
                printf("Player wins! Wager added onto bank balance.\n");
                bank_balance = adjust_bank_balance(bank_balance,wager,1);
                chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);
                print_line();
                game = 0;
                break;

                case 0:
                print_line();
                display_loser();
                printf("\n");
                printf("Craps! Player loses. Wager subtracted from bank balance\n");
                bank_balance = adjust_bank_balance(bank_balance,wager,0);
            
                chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);
                print_line();
                game = 0;
                break;

            }
        }



        /*switch(win_or_loss){
            case 1:
            printf("Player wins! Wager added onto bank balance.\n");
            bank_balance = bank_balance + wager;
            chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);

            break;
            
            case 0:
            printf("Craps! Player loses. Wager subtracted from bank balance\n");
            bank_balance = bank_balance - wager;
            
            chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);

            break;

            case -1:
            printf("Sum of dice becomes player's point\n");
            points = points + sum_dice;
            chatter_messages(number_rolls,win_or_loss,initial_bank_balance,bank_balance);
            
            break;
        }*/
        
        //wager = get_wager_amount();
    }while(game != 0);

    return bank_balance;

}



void display_title(void) {
    FILE* input_stream = fopen("title.txt", "r");
    char title = '\0';
    if (input_stream != NULL) {
        while (!feof(input_stream)) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 35; j++) {
                    title = read_text(input_stream);
                    printf("\x1b[31m%c\x1b[0m", title);  
                }
                //printf("\n");
            }
        }
        fclose(input_stream);  
    }
}

void display_winner(void)//DISPLAY WINNER TITLE
{
    FILE* input_stream = fopen("winner.txt", "r");
    char title = '\0';
    if (input_stream != NULL) {
        while (!feof(input_stream)) {
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 43; j++) {
                    title = read_text(input_stream);
                    printf("\x1b[31m%c\x1b[0m", title);  
                }
                //printf("\n");
            }
        }
        fclose(input_stream);  
    }
}

void display_loser(void)//DISPLAY LOSER TITLE
{
    FILE* input_stream = fopen("loser.txt", "r");
    char title = '\0';
    if (input_stream != NULL) {
        while (!feof(input_stream)) {
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 34; j++) {
                    title = read_text(input_stream);
                    printf("\x1b[31m%c\x1b[0m", title);  
                }
                //printf("\n");
            }
        }
        fclose(input_stream);  
    }
}

void rollingdice_loadingbar(void)//I STOLE THIS FROM STACK OVERFLOW
{
    int numberOfDots = 3;  // Number of dots in the loading animation
    int animationDuration = 500;  // Duration of the animation in milliseconds
    int delayBetweenFrames = 250;  // Delay between frames in milliseconds

    int numFrames = animationDuration / delayBetweenFrames;
    printf("\nRolling Dice!\n");
    for (int i = 0; i < numFrames; i++) {
        for (int j = 0; j < numberOfDots; j++) {
            putchar('.');
            fflush(stdout);
            usleep(delayBetweenFrames * 1000);  // Sleep for the specified milliseconds
        }
        printf("\r");  // Move the cursor back to the beginning of the line
        usleep(delayBetweenFrames * 1000);  // Sleep for the specified milliseconds
        for (int j = 0; j < numberOfDots; j++) {
            putchar(' ');  // Clear the dots
        }
        printf("\r");  // Move the cursor back to the beginning of the line
        usleep(delayBetweenFrames * 1000);  // Sleep for the specified milliseconds
    }


}



int get_term_width() {//GET TERMINAL WIDTH
  int cols;  
#ifdef _WIN32
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
  cols = ws.ws_col;
 #endif
  return cols;
}

void printupper_line(void)//PRINT UPPER BOX LINE
{
    int col = 0;
    col = get_term_width();
    for(int i = 0; i < col; i++){
        if(i == 0){
            printf("┏");
        }else if(i == col-1){
            printf("┓");
        }else{
            printf("━");
        }
    }
    printf("\n");
    
}

void printlower_line(void){//PRINT LOWER BOX LINE
    int col = 0;
    col = get_term_width();
    for(int i = 0; i < col; i++){
        if(i == 0){
            printf("┗");
        }else if(i == col-1){
            printf("┛");
        }else{
            printf("━");
        }
    }
    printf("\n");
}

void printmid_line(void){//PRINT MID BOX LINE
    int col = 0;
    col = get_term_width();
    for(int i = 0; i < col; i++){
        if(i == 0){
            printf("┣");
        }else if(i == col-1){
            printf("┫");
        }else{
            printf("━");
        }
    }
    printf("\n");
}

void print_text(void){//PRINT TEXT EXAMPLE
    int console_width = get_term_width();
    printf("┃");
    int output_width = printf("Whatever message you want");
    for (int i = 0; i < (console_width - output_width - 2); ++i){
    putchar(' '); // or printf(" ");
    }
    printf("┃");
}

void print_menu1(void)//PRINT MENU1 - DISPLAY RULES
{
    int console_width = get_term_width();
    printf("┃");
    int output_width = printf("1. Display Rules.");
    for (int i = 0; i < (console_width - output_width - 2); ++i){
    putchar(' '); // or printf(" ");
    }
    printf("┃");
}

void print_menu2(void){//PRINT MENU2 - PLAY GAME
    int console_width = get_term_width();
    printf("┃");
    int output_width = printf("2. Play Game.");
    for (int i = 0; i < (console_width - output_width - 2); ++i){
    putchar(' '); // or printf(" ");
    }
    printf("┃");
}
void print_menu3(void){//PRINT MENU3 - EXIT
    int console_width = get_term_width();
    printf("┃");
    int output_width = printf("3. Exit.");
    for (int i = 0; i < (console_width - output_width - 2); ++i){
    putchar(' '); // or printf(" ");
    }
    printf("┃");
}
void print_bank_balance(void){//PRINT BANK BALANCE
    int console_width = get_term_width();
    printf("┃");
    int output_width = printf("Bank Balance: $%.2lf",bank_balance);
    for (int i = 0; i < (console_width - output_width - 2); ++i){
    putchar(' '); // or printf(" ");
    }
    printf("┃");
}

void print_line(void){//PRINT DIVIDER LINE
    int col = 0;
    col = get_term_width();
    for(int i = 0; i < col; i++){
        if(i == 0){
            printf("━");
        }else if(i == col-1){
            printf("━");
        }else{
            printf("━");
        }
    }
    printf("\n");
}