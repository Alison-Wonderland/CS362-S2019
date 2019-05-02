/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/02/2019
 Description: This unit test examines the number of buys a player recieves in the 
 * refactored councilroom function which is named new_councilroom.
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

/*test new_councilroom function which includes refactored code. It is not testing the introduced
bug, but rather the number of buys a player recieves
pass = 1 buy added
fail = any other number
*/

int main(){
		int expected = 1;
		int result = 1;
		int buys = 0;
		int prevBuys = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		int i;

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("----------------- Unit Test 4 ----------------\n");

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));

		prevBuys = testG.numBuys;
		cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);
 
		buys = testG.numBuys - prevBuys;
		result = buys;

		//check how many total actions there are and output result
		if(result != 1)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}

   }