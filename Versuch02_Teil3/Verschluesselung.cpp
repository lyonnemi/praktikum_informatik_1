///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code

	for (int i = 0; i < wort.length(); i++)
	{
		char c = wort[i];
		if (c >= 'a' && c <= 'z')
		{
			int index = c - 'a';
			wort[i] = schluessel[0][index];
		}
		else if (c >= 'A' && c <= 'Z')
		{
			int index = c - 'A';
			wort[i] = schluessel[1][index];
		}
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code

	for (int i = 0; i < wort.length(); i++)
	{
		char c = wort[i];
		if (c >= 'a' && c <= 'z')
		{
			for (int j = 0; j < 26; j++)
			{
				if (schluessel[0][j] == c)
				{
					wort[i] = 'a' + j;
					break;
				}
			}
		}
		else if (c >= 'A' && c <= 'Z')
		{
			for (int j = 0; j < 26; j++)
			{
				if (schluessel[1][j] == c)
				{
					wort[i] = 'A' + j;
					break;
				}
			}
		}
	}
	return wort;
}

int main()
{
	// Hier folgt Ihr Code
	char schluessel[2][26] = {
		{'q', 'w', 'e', 'r', 't', 'z', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'y', 'x', 'c', 'v', 'b', 'n', 'm'},
		{'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Y', 'X', 'C', 'V', 'B', 'N', 'M'}
	};

	string eingabe;
	cout << "Bitte geben Sie ein Wort ein: ";
	cin >> eingabe;

	string verschluesselt = verschluesseln(schluessel, eingabe);
	cout << "Verschluesseltes Wort: " << verschluesselt << endl;

	string entschluesselt = entschluesseln(schluessel, verschluesselt);
	cout << "Entschluesseltes Wort: " << entschluesselt << endl;

	return 0;
}
