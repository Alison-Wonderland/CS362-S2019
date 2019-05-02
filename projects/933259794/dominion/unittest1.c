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


/*test new_adventurer function which includes refactored code and an introduced bug which lets 
the player draw three treasure cards instead of two, test the total drawn treasure cards
pass = 2 total treasure drawn
fail = any other number
*/

int main(){
		int expected = 2;
		int result = 0;
		int drawntreasure = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
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

		for (i = 0; i < testG.handCount[0]; i++)
		{
			if (testG.hand[0][i] == (copper || silver || gold))
				drawntreasure++;
		}

		result = drawntreasure;

		//then check how many total treasure cards there are and output result
		if(result != 2)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}

   }