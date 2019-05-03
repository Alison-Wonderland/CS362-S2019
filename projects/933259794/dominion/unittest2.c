/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/01/2019
 Description: This unit test examines the draw card aspect of the 
 * refactored smithy function which is named new_smithy.
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

/*test new_smithy function which includes refactored code and an introduced bug which lets 
the player draw  a card twice instead of once for each loop for a total of 4 draw cards,
The total drawn cards with the introduced bug should be 3 since there is one discard function in the
new_smithy function which is the same as the original smithy function.  This unit test will test the total drawn cards
pass = 1 card drawn
fail = any other number
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
		int drawnCards = 0;
		int originalHandCount = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		printf("----------------- Unit Test 2 ----------------\n");

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		originalHandCount = testG.handCount[0];

		cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
 
		drawnCards = testG.handCount[0] - originalHandCount;
		result = drawnCards;

		//check how many total drawn cards there are and output result
		ASSERT(&result, &expected, "Testing number of drawn cards in hand");
		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }