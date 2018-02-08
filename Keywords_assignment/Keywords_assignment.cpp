// Keywords_assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"Glasses", "These might help you see the answer"},
		{"labored", "Goind slowly is it?"},
		{"persistent", "You never give up do you.  You seem very ... MMM, what's the word?"},
		{"jumble", "It's what the game is all about."}

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
		cout << "\nThaats it! You guessed it !\n";

	}


	cout << "\nThanks for playing.\n";
	
	system("pause");
	
    return 0;
}

