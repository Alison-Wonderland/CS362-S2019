/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/02/2019
 Description: This unit test examines the number of buys a player recieves in the 
 * refactored councilroom function which is named new_councilroom. It also checks to see
 * if other players drew a card.
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

//test new_councilroom function which includes refactored code

//create custom assert to print out unit test results
int ASSERT(int *result, int *expected, char *s) {
  if(*result != *expected) 
  {
    printf("ASSERT FAIL! %s, Result: %d  Expected: %d\n", s, *result, *expected);
    return 1;
  }
  else
  {
    printf("ASSERT SUCCESS! %s,  Result: %d  Expected: %d\n", s, *result, *expected);
    return 0;
  }
}

int main(){
		int expected = 0;
		int result = 0;
		int buys = 0;
		int prevBuys = 0;
		int handCount = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Unit Test 4: Council Room ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		handCount = test.handCount[1];
		prevBuys = test.numBuys;
		cardEffect(council_room, choice1, choice2, choice3, &test, handpos, &bonus);
 
		buys = test.numBuys - prevBuys;

		//check how many buys there are and output result
		result = buys;
		expected = 1;
		ASSERT(&result, &expected, "Testing number of buys");
		//check if other players drew cards
		result = test.handCount[1];
		expected = handCount + 1;
		ASSERT(&result, &expected, "Testing number of cards opponent draws");

		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }