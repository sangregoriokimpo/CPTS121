#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct player_scorecard{
    char name[100];
    int scorecard[14];
    int frequencytable[7];
    int score;
};

void print_game_rules(void);

void roll_dice(int *arr);

void reroll_dice(int *arr);

void display_dice(int *arr);

int check_scorecard(int scorecard[]);

void sort_die(int arr[], int freq[]);

int check_filled(int scorecard[]);

void play_game(void);

int prompt(void);

void display_scorecard(struct player_scorecard player);

void initialize_scorecard(int *arr);

void initialize_frequencytable(int *arr);

void sum_scorecard(struct player_scorecard player);

void determine_score(int frequencytable[],int scorecard[]);

int Aces(int frequenctytable[]);

int Twos(int frequenctytable[]);

int Threes(int frequenctytable[]);

int Fours(int frequenctytable[]);

int Fives(int frequenctytable[]);

int Sixes(int frequenctytable[]);

int Three_of_akind(int frequencytable[]);

int Four_of_akind(int frequencytable[]);

int Full_house(int frequencytable[]);

int Small_straight(int frequencytable[]);

int Large_straight(int frequencytable[]);

int Yahtzee(int frequencytable[]);

int Chance(int frequencytable[]);




