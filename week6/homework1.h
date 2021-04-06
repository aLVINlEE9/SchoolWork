#ifndef HOMEWORK1_H
#define HOMEWORK1_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int get_num(void);

typedef struct
{
	int deposit;
	int win;
	int game;
} user;

typedef struct
{
	int deposit;
	int win;
	int game = user.game;
} computer;
