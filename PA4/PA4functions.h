
#include <math.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#endif


char read_text(FILE *infile);

void printupper_line(void);

void printlower_line(void);

void printmid_line(void);

void print_line(void);

void print_text(void);

void print_game_rules (void);

double get_bank_balance (void);

double get_wager_amount (void);

int check_wager_amount (double wager, double balance);

int roll_die (void);

int calculate_sum_dice (int die1_value, int die2_value);

int is_win_loss_or_point (int sum_dice);

int is_point_loss_or_neither (int sum_dice, int point_value);

double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract);

void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

double playgame(void);

void display_title(void);

void display_winner(void);

void display_loser(void);

void rollingdice_loadingbar(void);

int get_term_width();

void print_menu1(void);

void print_menu2(void);

void print_menu3(void);

void print_bank_balance(void);

double bank_balance;






