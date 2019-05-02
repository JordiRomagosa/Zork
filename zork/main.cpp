#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	char key;
	string player_input = "";

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
				player_input += "\n";
				cout << "\n" + player_input;
				player_input = "";
			}
			else
			{
				player_input.push_back(key);
				cout << key;
			}
		}
	}

	return 0;
}