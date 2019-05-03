/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 04/30/2019
 Description: This card test examines the discard aspect of the 
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


/*test new_adventurer function to verify the player discards a card 
pass = card discarded
fail = any other action
*/

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
		int expected = 1;
		int result = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Card Test 1 ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &test, handpos, &bonus);

		result = test.discardCount[0];

		//then check if discarded and output result
		ASSERT(&result, &expected, "Testing discard");
		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }