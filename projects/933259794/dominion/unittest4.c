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

//create custom assert to print out unit test results
int ASSERT(int *result, int *expected, char *s) {
  if(result != expected) 
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
		int expected = 1;
		int result = 0;
		int buys = 0;
		int prevBuys = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Unit Test 4 ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));

		prevBuys = test.numBuys;
		cardEffect(council_room, choice1, choice2, choice3, &test, handpos, &bonus);
 
		buys = test.numBuys - prevBuys;
		result = buys;

		//check how many buys there are and output result
		ASSERT(&result, &expected, "Testing number of buys");
		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }