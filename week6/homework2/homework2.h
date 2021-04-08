#ifdef HOMEWORK2_H
#define HOMEWORK2_H

#include<stdio.h>
#include<string.h>

typedef struct student_info_st{
	char name[20];
	int age;
	char gender[20];
	int number;
	char major[20];
} INFO_ST;

void save(INFO_ST*);
void search(INFO_ST*);

#endif
