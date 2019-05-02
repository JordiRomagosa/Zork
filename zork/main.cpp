#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include "globals.h"

using namespace std;

int main()
{
	char key;
	string player_input = "";
	vector<string> args;

	cout << "Welcome to my Zork!" << endl;

	while (1)
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			if (key == '\b' && player_input.length() > 0) //back
			{
				player_input.pop_back();
				cout << '\b';
				cout << " ";
				cout << '\b';
			}
			
			else if (key == '\r') // return
			{
				Tokenize(player_input, args);
				cout << endl;
			}
			else
			{
				player_input.push_back(key);
				cout << key;
			}
		}

		if (args.size() > 0)
			if (Same(args[0], "quit"))
				break;

			else
			{
				args.clear();
				player_input = "";
				cout << "Action not implemented" << endl;
			}
	}

	cout << "Thanks for playing!";
	return 0;
}