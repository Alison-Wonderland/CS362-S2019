/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/01/2019
 Description: This unit test examines the deck count which should decrease by three cards
 *in the new_smithy function which has a bug that has the player draw two times per loop.
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

/*test new_smithy function and that it does decrease the deck count correctly
pass = deck count - 3
fail = deck count - any other number
*/

int main(){
		int expected = 0;
		int result = 0;
		int deckCount = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		int i;

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Card Test 2 ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));

		deckCount = test.deckCount[0];

		cardEffect(smithy, choice1, choice2, choice3, &test, handpos, &bonus);
		
		 expected = deckCount - 3;

		 result = test.deckCount[0];

		//check how many total cards there are in the deck and output result
		if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d\n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}

   }