#include "homework1.h"

int main()
{
	int rand_val;
	int bet_amout;
	int bet;
	int truth;
	int winner;
	USER_ST user;
	COM_ST computer;

	set(&user, &computer);
	while(!(user.deposit <= 0 || computer.deposit <= 0))
	{
		rand_val = 0;
		bet_amout = 0;
		bet = -1;
		truth = -1;
		winner = -1;

		rand_val = randnum_gen();

		do
		{
			printf("Even Or Odd Pick one! (Even : 0, Odd : 1)");
			scanf("%d", &bet);
		} while (!(bet == 0 || bet == 1));
		
		do
		{
			printf("How much you want to bet? (1~20)");
			scanf("%d", &bet_amout);
		} while(bet_amout <= 0 && bet_amout >= 21);
		even_odd_checker(rand_val) ? (truth = ODD) : (truth = EVEN);
		betting_calc(truth, bet, bet_amout, &user, &computer) ? (winner = USER) : (winner = COM);
		print_game_status(&user, &computer, bet_amout, truth, winner, rand_val);
	}
	printf("===============All GAME ENDED===============");
}

int randnum_gen()
{
	return rand() % 10 + 1;
}

void set(USER_ST* user, COM_ST *computer)
{
	user->deposit = 100;
	user->win = 0;
	user->game = 0;
	computer->deposit = 100;
	computer->win = 0;
	computer->game = 0;
}

int even_odd_checker(int rand_val)
{
	if(rand_val % 2 == 1)
		return ODD;
	else if(rand_val % 2 == 0)
		return EVEN;
}

int betting_calc(int truth, int bet, int bet_amout, USER_ST *user, COM_ST *computer)
{
	if(truth == bet)
	{
		user->deposit += bet_amout;
		user->win += 1;
		user->game += 1;
		computer->deposit -= bet_amout;
		computer->game += 1;
		return 0;
	}
	else if(truth != bet)
	{
		user->deposit -= bet_amout;
		user->game += 1;
		computer->deposit += bet_amout;
		computer->win += 1;
		computer->game += 1;
		return 1;
	}
	return -1;
}

void print_game_status(USER_ST *user, COM_ST *computer, int bet_amout, int truth, int winner, int rand_val)
{
	printf(" [%d tried] Bet is over\n\n", user->game);
	printf(" The Number is %d\n\n", rand_val);
	printf(" The Winner is %s\n\n", winner ? "User" : "Computer");
	printf(" USER : COMPUTER \n");
	printf("  %d       %d\n\n", user->win, computer->win);
	printf(" User Deposit : %d\n", user->deposit);
	printf(" Computer Deposit : %d\n", computer->deposit);
}
