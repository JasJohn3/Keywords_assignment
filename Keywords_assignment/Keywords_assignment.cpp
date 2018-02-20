// Keywords_assignment.cpp : Defines the entry point for the console application.
//Publisher: Jason Johnson

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void Jumble();
int main()
{
	bool Play_Again = false;
	string User_Input;
	cout << "Welcome to Keyword\n\n";
	cout << "You will have three words to guess, good luck!\n\n";
	system("pause");
	do
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << "ROUND: " << i << "\n\n";
			Jumble();
		}
		cout << "Would you like to play again!\n\n";
		cout << "Please enter 'Y' or 'N'";
		cin >> User_Input;
		if (User_Input == "Y" || User_Input == "y")
		{
			Play_Again = true;
		}
		else if (User_Input == "N" || User_Input == "n")
		{
			Play_Again = false;
		}
		else
		{
			cout << "Invalid input";
		}


	} while (Play_Again);
	cout << "\nThanks for playing. ";
	system("pause");
    return 0;
}
void Jumble() {
	
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "Wall", "Do you feel you're banging your head against something?" },
		{ "Glasses", "These might help you see the answer" },
		{ "Labored", "Goind slowly is it?" },
		{ "Persistent", "You never give up do you.  You seem very ... MMM, what's the word?" },
		{ "Jumble", "It's what the game is all about." },
		{ "Home", "It's where the Heart is!" },
		{ "Help", "I need your ..." },
		{ "Rome", "It wasn't built in a day" },
		{ "Boat", "Row, row, row your ..." },
		{ "Simple", "Keep it ... Stupid" }


	};

	enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
	cout << "There Are " << NUM_DIFF_LEVELS << " difficulty levels.";
	
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; //hint for the word


	string jumble = theWord; //Jumbled version of word
	int length = jumble.size();

	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\tWelcome to Keywords!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game. \n\n";
	cout << "The Jumble is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour Guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{
		cout << "\nThats it! You guessed it !\n";

	}


	system("pause");
}
