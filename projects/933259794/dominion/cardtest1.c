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
#include <math.h>
#include "rngs.h"
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>

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
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		int i;

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("----------------- Unit Test 1 ----------------\n");

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		currentPlayer = whoseTurn(&testG);

		for (i = 0; i < testG.handCount[0]; i++)
		{
			if (testG.hand[0][i] == (copper || silver || gold))
				drawntreasure++;
		}

		result = drawntreasure;

		//then assert how many total treasure cards there are and output result
		printf("Result: %d  Expected: %d \n", result, expected);

   }