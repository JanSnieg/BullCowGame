#include "FBullCowGame.h"

int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
int FBullCowGame::GetMaxTries() { return MyMaxTries; }

void FBullCowGame::Reset(int WordLenght)
{
	return;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}