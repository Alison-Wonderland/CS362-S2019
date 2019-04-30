/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 04/30/2019
 Description: This unit test examines the draw treasure aspect of the 
 * refactored adventurer function which is named new_adventurer.
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//test new_adventurer function which includes refactored code
//test the total drawn treasure
//pass = 2 total treasure drawn
//fail = any other value of treasure cards drawn 

int main(){
	int newCards = 0;
		int discarded = 1;
		int shuffledCards = 0;
		int expected = 2;
		int result = 0;
		int drawntreasure = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		int currentPlayer = 0;
		struct gameState G, testG;
		int card = 1 //adventurer

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("----------------- Unit Test 1 ----------------\n");

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		while(state->handCount[currentPlayer])
		{
			cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			 drawntreasure++;
		}

		result = drawntreasure;

		//then assert how many total treasure cards there are and output result

		printf("Test Draw Cards")

   }