#include "homework2.h"

int main()
{
	INFO_ST st[5];
	while(1)
	{
		int input = -1;
		printf("[save{0} / search{1} / quit{2}]");
		scanf("%d", &input);
		if(input == 0)
		{
			for(int i = 0; i < 5; i++)
				save(&st[i]);
		}
		else if(input == 1)
		{
			search(&st);
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
	pritnf("---Student Information---\n\n");
	printf("student name :");
	scanf("%s", &name);
	strcpy(st->name, &name);

	printf("student age :");
	scanf("%d", &(st->age));
	
	printf("student gender :");
	scanf("%s", &gender);
	strcpy(st->gender, &gender);
	
	printf("student number :");
	scanf("%d", &(st->number));

	printf("student major :");
	scanf("%s", &major);
	strcpy(st->major, &major);
	pritnf("\n\n---input finished---\n\n");
}

void search(INFO_ST *st)
{
	int s_num;
	int i = 0;
	printf("---Student Search---\n\n");
	printf("search :");
	scanf("%d", &s_num);
	for(i = 0; i < 5; i++)
	{
		if(s_num == st[i]->number)
			break;
	}
	printf("student name : %s\n", st[i]->name);
	printf("student age : %d\n", st[i]->age);
	printf("student gender : %s\n", st[i]->gender);
	printf("student number : %d\n", st[i]->number);
	printf("student major : %s\n", st[i]->major);
}
