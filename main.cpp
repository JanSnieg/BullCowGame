/*
Created by Jon Snow
All rights reserved

This is a console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//Using Unreal friendly syntax
using FText = std::string;
using int32 = int;

// Declarations of functions
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();
bool bIsFirstTurn();

//Initialization of game class
FBullCowGame BCGame;

// The entry point of our application
int main()
{
	bool IsFirstTurn = true;
	do
	{
		PrintIntro();
		if (IsFirstTurn)
			IsFirstTurn = bIsFirstTurn();
		PlayGame();
	}
	while (AskToPlayAgain());
	return 0;
}

// Introduce the game
void PrintIntro()
{
	std::cout << "\t\tWelcome to: \n\n";
	std::cout << "__________      .__  .__                                .___   _________                      " << std::endl;
	std::cout << "\\______   \\__ __|  | |  |   ______   _____    ____    __| _/   \\_   ___ \\  ______  _  ________" << std::endl;
	std::cout << " |    |  _/  |  \\  | |  |  /  ___/   \\__  \\  /    \\  / __ |    /    \\  \\/ /  _ \\ \\/ \\/ /  ___/" << std::endl;
	std::cout << " |    |   \\  |  /  |_|  |__\\___ \\     / __ \\|   |  \\/ /_/ |    \\     \\___(  <_> )     /\\___ \\ " << std::endl;
	std::cout << " |______  /____/|____/____/____  >   (____  /___|  /\\____ |     \\______  /\\____/ \\/\\_//____  >" << std::endl;
	std::cout << "        \\/                     \\/         \\/     \\/      \\/            \\/                  \\/ " << std::endl;
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl << std::endl;
	return;
}

//Loop for the number of turns asking for guesses
void PlayGame()
{
	BCGame.Reset();
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
	}
	PrintGameSummary();
}

// loop continually until user gives valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_status;
	do
	{
		std::cout << "\nTry " << BCGame.GetCurrentTry() << "/" << BCGame.GetMaxTries();
		std::cout << ". Type you guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an Isogram." << std::endl;
			break;
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Lowecase:
			std::cout << "Please enter word in lowercase." << std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
		std::cout << "\nCongratulations You WON THE GAME!!\n" << std::endl;
	else
		std::cout << "\nBetter luck next time!\n" << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word? (y/n): ";
	FText Response;
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

bool bIsFirstTurn()
{
	std::cout << "This is game about trying to guess the word im hiding from you." << std::endl;
	std::cout << "Bulls means you got right letter in right place." << std::endl;
	std::cout << "Cows means you got right letter but in wrong place.\nGood luck" << std::endl;
	return false;
}