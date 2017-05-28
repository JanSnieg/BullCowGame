/*
Header file that expails how the game work, without looking into .cpp file
Here we have all declarations, and proper comments.*/
#pragma once
#include <string>

//Using Unreal friendly syntax
using FString = std::string;
using int32 = int;

//Structure that keeps bulls and cows (results of shots)
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

//Enum class that keeps few things that we use in CheckGuessValidity
enum class EGuessStatus
{
	Invalid_status,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowecase
};

// Main game class
class FBullCowGame
{
//Private variables
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

//Private methods
	bool IsIsogram(FString) const;						//Chacking if the guess word is isogram
	bool IsLowercase(FString) const;					//Chackking if the guess word is lowercase

public:
	FBullCowGame();										//Constructor

	void Reset();										//Resets the game, used in constructor
	bool IsGameWon() const;								//Chacking if the game is won
	EGuessStatus CheckGuessValidity(FString) const;		//Using Enum class to check if guess is valid
	FBullCowCount SubmitValidGuess(FString);			//Recives a valid guess, increments turn and returns count
	
//Getters
	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;
	
};