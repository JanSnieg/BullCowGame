#pragma once
#include <string>

class FBullCowGame
{

	int MyCurrentTry = 1;
	int MyMaxTries = 5;

public:
	void Reset(int WordLenght);
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
	int GetCurrentTry();
	int GetMaxTries();
};