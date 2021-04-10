#include "homework2.h"

int main()
{
	INFO_ST st[5];
	while(1)
	{
		int input = -1;
		printf("[save{0} / search{1} / quit{2}] :");
		scanf("%d", &input);
		printf("\n");
		if(input == 0)
		{
			for(int i = 0; i < 5; i++)
			{
				printf("\t\t\tpage%d\n", i + 1);
				printf("---Student Information---\n\n");
				save(&st[i]);
			}
			printf("\n\n---input finished---\n\n");
		}
		else if(input == 1)
		{
			int s_num;
			printf("---Student Search---\n\n");
			printf("search (put student number):");
			scanf("%d", &s_num);
			for(int i = 0; i < 5; i++)
			{
				if(s_num == st[i].number)
				{
					printf("\n\n**match found**\n\n");
					print_info(&st[i]);
					break;
				}
				if(i == 4)
				{
					printf("Your search - %d - did not match any documents.\n---Try Again---\n", s_num);
					i = 0;
				}
			}
		}
		else if(input == 2)
			break;
	}
}

void save(INFO_ST *st)
{
	char name[20];
	char gender[20];
	char major[20];
	printf("student name :");
	scanf("%s", name);
	strcpy(st->name, name);

	printf("student age :");
	scanf("%d", &(st->age));
	
	printf("student gender :");
	scanf("%s", gender);
	strcpy(st->gender, gender);
	
	printf("student number :");
	scanf("%d", &(st->number));

	printf("student major :");
	scanf("%s", major);
	strcpy(st->major, major);
}

void print_info(INFO_ST *st)
{
	printf("student name : %s\n", st->name);
	printf("student age : %d\n", st->age);
	printf("student gender : %s\n", st->gender);
	printf("student number : %d\n", st->number);
	printf("student major : %s\n", st->major);
}
