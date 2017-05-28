#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const			{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const		{ return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const				{ return bGameIsWon;}
int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLenghtToMaxTries{ {3,5},{4,7},{5,9},{6,11},{7,13} };
	return WordLenghtToMaxTries[MyHiddenWord.length()]; 
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	size_t WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
					BullCowCount.Bulls++;
				else
					BullCowCount.Cows++;
			}
				
		}
	}
	if (BullCowCount.Bulls == WordLength)
		bGameIsWon = true;
	else
		bGameIsWon = false;
	return BullCowCount;
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "balet";
	MyHiddenWord = HIDDEN_WORD;
	constexpr int32 MAX_TRIES = 10;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	bGameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (GetHiddenWordLength() != Guess.length())
		return EGuessStatus::Wrong_Lenght;
	else if (!IsLowercase(Guess))
		return EGuessStatus::Not_Lowecase;
	else if (!IsIsogram(Guess))
		return EGuessStatus::Not_Isogram;
	else
		return EGuessStatus::OK;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter strings as isograms
	if (Word.length() <= 1)
		return true;

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
			return false;
		else
			LetterSeen[Letter] = true;
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (Word.length() > 1)
		{
			if (!islower(Letter))
				return false;
		}
	}
	return true;
}
