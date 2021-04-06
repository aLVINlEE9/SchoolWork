#include "homework1.h"

int main()
{
	int rand_num;
	set_deposit(); // set 100 won to each player 
	while(computer.deposit >= 0 && user.deposit >= 0)
	{
		int user_pick; // 0 is even, 1 is odd 
		int com_pick; // 0 is even, 1 is odd
		int bet;

		printf("Put Betting money here!! (1 ~ 20won) :");
		scnaf("%d", &bet);

		printf("ODD OR EVEN CHOOSE ONE!! (0 is even, 1 is odd) :");
		scanf("%d", &user_pick);
		com_pick = get_computer_statement();

		get_num() = rand_num;
		if(check_if_odd(rand_num) == com_pick || check_if_odd(rand_num) == user_pick)
		{
			
		}
		else
		{
			continue;
		}
	
	}
}

void set_deposit()
{
	computer.deposit = 100;
	human.deposit = 100;
}

int get_num()
{
	return(rand() % 10 + 1);
}

int get_computer_statement()
{
	return(rand() % 2);
}

bool check_if_odd(int rand_num)
{
	if(rand_num % 2 == 1)
		return true;
	else if(rand_num % 2 == 0)
		return false;
}
