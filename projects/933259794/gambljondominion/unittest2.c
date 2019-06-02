/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/01/2019
 Description: This unit test examines the draw card and discard aspects of the 
 * refactored smithy function which is named new_smithy. It also verifies that 
 * actions do not change for current player.
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
new_smithy function which is the same as the original smithy function.  This unit test will include testing that
bug
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
		int expected = 0;
		int result = 0;
		int drawnCards = 0;
		int originalHandCount = 0;
		int actionsCurrentPlayer = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Unit Test 2: Smithy ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		originalHandCount = test.handCount[0];
		actionsCurrentPlayer = test.numActions;
		int cardReturn = cardEffect(smithy, choice1, choice2, choice3, &test, handpos, &bonus);
 
		drawnCards = test.handCount[0] - originalHandCount;

		//check how many total drawn cards there are and output result
		expected = 1;
		result = drawnCards;
		ASSERT(&result, &expected, "Testing number of drawn cards in hand for current player");
		//check discard aspect of smithy card
		expected = 1;
		result = test.discardCount[0];
		ASSERT(&result, &expected, "Testing number of cards discarded in hand for current player");
		
		//check if actions changed which shouldn't for the smithy card
		expected = actionsCurrentPlayer;
		result = test.numActions;
		ASSERT(&result, &expected, "Testing number of actions for current player");

		//testing card effect function return value
		expected = 0;
		result = cardReturn;
		ASSERT(&result, &expected, "Testing card effect function return value");

}