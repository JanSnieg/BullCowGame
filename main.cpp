// Created by Jon Snow
// All rights reserved

#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
// The entry point of our application
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());
	return 0;
}

void PrintIntro()
// Introduce the game
{
	constexpr int WORLD_LENGTH = 10;
	std::cout << "Welcome to Cows and Bulls game! a fun word game" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking on?" << std::endl << std::endl;
	return;
}


void PlayGame()
// Loop for the number of turns asking for guesses
{
	int MyMaxTries = BCGame.GetMaxTries();
	for (int i = 0; i < MyMaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
// Get guess from the player
{
	std::cout << "Try " << BCGame.GetCurrentTry();
	std::cout << ". Type you guess: ";
	std::string Guess;
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n): ";
	std::string Response;
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}