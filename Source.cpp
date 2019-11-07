#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string pattern;
	cout << "Enter substring: ";
	cin >> pattern;
	cout << "Enter hole string: ";
	cin >> str;
	int* pi = new int[pattern.length()];
	pi[0] = 0;
	int i = 1, j = 0;
	while (pattern[i] != 0)
	{
		if(pattern[i] == pattern[j])
		{
			pi[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j == 0)
			{
				pi[i] = 0;
				i++;
			}
			else
			{
				j = pi[j - 1];
			}
		}
	}
	i = 0; j = 0;
	bool choiñe = false;
	while (pattern[i] != 0)
	{
		if (str[i] == pattern[j])
		{
			i++;
			j++;
			if (j == pattern.length())
			{
				cout << "Pattern found in string";
				choiñe = true;
				break;
			}
		}
		else
		{
			if (j == 0)
			{
				i++;
				if (i == str.length())
				{
					cout << "Pattern do not found in string";
					choiñe = true;
					break;
				}
			}
			else
			{
				j = pi[j - 1];
			}
		}
	}
	if (!choiñe)
	{
		cout << "Pattern found in string";
	}
	

	_getch();
	return 0;
}