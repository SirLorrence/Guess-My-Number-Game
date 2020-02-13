#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

static bool gameOver;
static int score;
static int tries = 3;
static int attempts = 0;
static int seedNum = 5;
static int randNum;


int start()
{
	srand(static_cast<unsigned int>(time(0)));
	randNum = rand() % seedNum + 1;
	return 0;
}
int Newlvl()
{
	attempts = 0;
	seedNum += 5;
	srand(static_cast<unsigned int>(time(0)));
	randNum = rand() % seedNum + 1;
	tries++;
	cout << "Okay lets go again, now my number is between 1 and " << seedNum << endl;
	return 0;
}
int Reset()
{
	tries = 3;
	seedNum = 5;
	attempts = 0;
	return  0;
}
int Game()
{
	start();
	int Guess;
	score = 0;
	cout << "My number is between 1 and " << seedNum << endl;
	cout << "\t\t\t\tscore: " << score << endl;

	//----------------------------GAME LOOP
	while (attempts < tries)
	{
		cout << "You have " << tries - attempts << " of attempts" << endl;
		cin >> Guess;
		if (Guess == randNum)
		{
			score += 100;
			cout << "\t\t\t\tscore: " << score << endl;
			cout << "Correct that's my number" << endl;
			Newlvl();
			continue;
		}
		attempts++;
		cout << "Wrong number (-.-;) " << endl;
		if (Guess > randNum)
		{
			cout << "Your Number is too high" << endl;
		}
		else if (Guess < randNum)
		{
			cout << "Your number is too low" << endl;
		}
	}
	//-------------------------------------------

	cout << "\n My number was " << randNum << endl;
	gameOver = true;
	return 0;
}

int main()
{
	cout << "Welcome to.... \n \tGuess \n\t\t My \n\t\t\t NUMBER!!!!\n\n" << endl;

	while (!gameOver)
	{
		Game();
	}	
	cout << "\t ********[ GAME OVER ]*********" << endl;
	cout << "\t ********[ Your Score: " << score << "]*********" << endl;

	cout << "\n Play Again?? (y/n)";
	char Restart;
	cin >> Restart;
	if (Restart == 'y' || Restart =='Y')
	{
		system("cls"); //clears console
		gameOver = false;
		Reset();
		main();
	}
	else
	{
		return 0;
	}
}

