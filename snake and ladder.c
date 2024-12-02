#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
// Function to roll a dice 
int rollDie() { return rand() % 6 + 1; } 
int playerA = 0, playerB = 0; 

// Function to print the board 
void printBoard() 
{ 
	int board[101]; 
	for (int i = 1; i <= 100; i++) { 
		board[i] = i; 
	} 

	int alt = 0; // to switch between the alternate nature of the board 
	int iterLR = 101; // iterator to print from left to right 
	int iterRL = 80; // iterator to print from right to left 
	int val = 100;	 
	while (val--) { 
		if (alt == 0) { 
			iterLR--; 
			if (iterLR == playerA) { 
				printf("#A "); 
			} 
			else if (iterLR == playerB) { 
				printf("#B "); 
			} 
			else
				printf("%d ", board[iterLR]); 

			if (iterLR % 10 == 1) { 
				printf("\n\n"); 
				alt = 1; 
				iterLR -= 10; 
			} 
		} 
else { 
			iterRL++; 
			if (iterRL == playerA) { 
				printf("#A "); 
			} 
			else if (iterRL == playerB) { 
				printf("#B "); 
			} 
			else
				printf("%d ", board[iterRL]); 

			if (iterRL % 10 == 0) { 
				printf("\n\n"); 
				alt = 0; 
				iterRL -= 30; 
			} 
		} 
		if (iterRL == 10) 
			break; 
	} 
	printf("\n"); 
} 

// Function to move the player 
int movePlayer(int currentPlayer, int roll) 
{ 
	int newPosition = currentPlayer + roll; 
	// Define the positions of snakes and ladders on the 
	// board 
	int snakesAndLadders[101]; 

	for (int i = 0; i <= 100; i++) { 
		snakesAndLadders[i] = 0; 
	} 
	snakesAndLadders[6] = 50; 
        snakesAndLadders[23] = -10; 
	snakesAndLadders[45] = -7; 
	snakesAndLadders[61] = -18; 
	snakesAndLadders[65] = 8; 
	snakesAndLadders[77] = 4; 
	snakesAndLadders[98] = -10; 

	int newSquare 
		= newPosition + snakesAndLadders[newPosition]; 

	if (newSquare > 100) { 
		return currentPlayer; // Player cannot move beyond 
							// square 100 
	} 

	return newSquare; 
} 

int main() 
{ 
	srand(time(0)); // Initialize random seed 
	int currentPlayer = 1; 
	int won = 0; 

	printf("Snake and Ladder Game\n"); 

	while (!won) { 

		printf( 
			"\nPlayer %d, To roll the dice,press enter: ", 
			currentPlayer); 
		getchar(); // Wait for the player to press Enter 
		int roll = rollDie(); 
		printf("You rolled a %d.\n", roll); 
if (currentPlayer == 1) { 
			playerA = movePlayer(playerA, roll); 
			printf("Player A is now at square %d.\n\n", 
				playerA); 
			printBoard(); 
			if (playerA == 100) { 
				printf("Player A wins!\n"); 
				won = 1; 
			} 
		} 
		else { 
			playerB = movePlayer(playerB, roll); 
			printf("Player B is now at square %d.\n\n", 
				playerB); 
			printBoard(); 
			if (playerB == 100) { 
				printf("Player B wins!\n"); 
				won = 1; 
			} 
		} 

		// Switch to the other player 
		currentPlayer = (currentPlayer == 1) ? 2 : 1; 
	} 

	return 0; 
}