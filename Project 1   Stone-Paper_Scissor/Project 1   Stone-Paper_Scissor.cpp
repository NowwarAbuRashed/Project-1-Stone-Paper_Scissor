#include <iostream>
using namespace std;
int ReadChoice(string messige)
{
	int Number;
	do
	{
	cout << messige;
	cin >> Number;
	} while (Number < 1 || Number>3);

	return Number;
}
int ReadNumber(string messige)
{
	int Number;
	cout << messige;
	cin >> Number;
	return Number;
}
int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
string ChoiceStoneOrPaperOrScissor(short Choice)
{
	if (Choice == 1)
		return "Stone";
	else if (Choice == 2)
		return "Paper";
	else
		return "Scissor";

}
void ShowResultRound(short User, short Computer, short &counterUser,short &counterComputer,short & counterDraw)
{
	if (User == Computer)
	{
		system("color 5F");
		cout << "\n\aPlayer1  Choice: " << ChoiceStoneOrPaperOrScissor(User) << endl;
		cout << "Computer Choice: " << ChoiceStoneOrPaperOrScissor(Computer) << endl;
		cout << "Round Winner   : [No Winner]" << endl;
		++counterDraw;
	}
	else if (User - Computer == -1|| Computer - User == -2)
	{
		system("color 4F");
		cout << "\n\aPlayer1  Choice: " << ChoiceStoneOrPaperOrScissor(User) << endl;
		cout << "Computer Choice: " << ChoiceStoneOrPaperOrScissor(Computer) << endl;
		cout << "Round Winner   : [Computer Winner]" << endl;
		++counterComputer;
	}
	else
	{
		system("color 2F");
		cout << "\nPlayer1  Choice: " << ChoiceStoneOrPaperOrScissor(User) << endl;
		cout << "Computer Choice: " << ChoiceStoneOrPaperOrScissor(Computer) << endl;
		cout << "Round Winner   : [You Winner]" << endl;
		++counterUser;
	}
}
void ShowGameOver()
{
	cout << "                    ______________________________________________________________________________\n\n";

	cout << "                                            +++ G a m e  O v e r +++                              \n\n";

	cout << "                    ______________________________________________________________________________\n\n";

}
void ShowYouWiner()
{
	cout << "                    ______________________________________________________________________________\n\n";

	cout << "                                            +++ Y o u  W i n e r +++                              \n\n";

	cout << "                    ______________________________________________________________________________\n\n";

}
string  FinalWinner(short counterUser, short counterComputer)
{
	if (counterUser == counterComputer)
		return "NO Winner";
	else if (counterUser > counterComputer)
		return "You Winner";
	else
		return "Computer Winner";

}
void ShowGameResult(short Rounds, short counterUser, short counterComputer, short counterDraw)
{
	cout << "                    _____________________________[ Game Results ]_________________________________\n\n";
	cout << "                    Gamr Rounds        : " << Rounds << endl;
	cout << "                    Player1 won times  : " << counterUser << endl;
	cout << "                    Computer won times : " << counterComputer << endl;
	cout << "                    Draw Times times   : " << counterDraw << endl;
	cout << "                    Final Winner       : " << FinalWinner(counterUser, counterComputer) << endl;
	cout << "                    ______________________________________________________________________________\n\n";

}
void StartGame()
{
	char YesOrNo='y';
	do {
		short Rounds = ReadNumber("How Many Rounds  1 to 10 ?\n");
		short counterUser = 0, counterComputer = 0, counterSeem = 0;
		for (int i = 1; i <= Rounds; i++)
		{
			cout << "\nRound [" << i << "] begins:\n";
			short User = ReadChoice("\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ");
			short Computer = RandomNumber(1, 3);
			cout << "\n_________________Round [" << i << "] __________________\n";
			ShowResultRound(User, Computer, counterUser, counterComputer, counterSeem);
			cout << "\n\n___________________________________________________________\n\n";
		}
		if (counterComputer >= counterUser)
		{
			system("color 4F");
			ShowGameOver();
			ShowGameResult(Rounds, counterUser, counterComputer, counterSeem);
		}
		else
		{
			system("color 2F");
			ShowYouWiner();
			ShowGameResult(Rounds, counterUser, counterComputer, counterSeem);

		}
		cout << "Do you want to play again? Y/N? ";
		cin >> YesOrNo;
		if (YesOrNo == 'Y' || YesOrNo == 'y')
		{
			system("Clear");
		}
	} while (((YesOrNo == 'Y' || YesOrNo == 'y')));


	

}

int main()
{
  
	StartGame();



}

