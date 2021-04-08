#ifndef HOMEWORK1_H
#define HOMEWORK1_H

#include<stdio.h>
#include<stdlib.h>

#define EVEN 0
#define ODD 1
#define USER 0
#define COM 1

typedef struct user_st{
	int deposit;
	int win;
	int game;
} USER_ST;

typedef struct computer_st{
	int deposit;
	int win;
	int game;
} COM_ST;

int randnum_gen(void);
void set(USER_ST*, COM_ST*);
int even_odd_checker(int rand_val);
int betting_calc(int truth, int bet, int bet_amout, USER_ST*, COM_ST*);
void print_game_status(USER_ST*, COM_ST*, int bet_amout, int truth, int winner, int rand_val);

#endif
