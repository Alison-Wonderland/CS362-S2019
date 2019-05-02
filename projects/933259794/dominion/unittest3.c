/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/02/2019
 Description: This unit test examines the extra actions aspect of the 
 * refactored village function which is named new_village.
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

/*test new_village function which includes refactored code and an introduced bug which lets 
the player gain four extra actions instead of two extra actions This unit test will test 
the total actions added to the player's actions.'
pass = 2 actions added
fail = any other number
*/

int main(){
		int expected = 2;
		int result = 0;
		int actions = 0;
		int prevActions = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		int i;

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Unit Test 3 ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));

		prevActions = test.numActions;
		cardEffect(village, choice1, choice2, choice3, &test, handpos, &bonus);
 
		actions = test.numActions - prevActions;
		result = actions;

		//check how many total actions there are and output result
		if(result != 2)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}

   }