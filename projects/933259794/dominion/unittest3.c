/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/02/2019
 Description: This unit test examines the extra actions aspect of the 
 * refactored village function which is named new_village. It also checks
 * to make sure the opponents hand and deck size didn't change.
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
the player gain four extra actions instead of two extra actions This unit test will include testing for 
the total actions added to the player's actions.'
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
		int actions = 0;
		int prevActions = 0;
		int playerTwoHand = 0;
		int playerTwoDeck = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Unit Test 3: Village ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		playerTwoHand = test.handCount[1];
		playerTwoDeck = test.deckCount[1];

		prevActions = test.numActions;
		int cardReturn = cardEffect(village, choice1, choice2, choice3, &test, handpos, &bonus);
 
		actions = test.numActions - prevActions;

		//check how many total actions there are and output result
		expected = 2;
		result = actions;
		ASSERT(&result, &expected, "Testing number of actions");

		//check player 2 hand count is unchanged
		expected = playerTwoHand;
		result = test.handCount[1];
		ASSERT(&result, &expected, "Testing player two, opponent, hand count");

		//check player 2 deck count is unchanged
		expected = playerTwoDeck;
		result = test.deckCount[1];
		ASSERT(&result, &expected, "Testing player two, opponent, deck count");
		
		//testing card effect function return value
		expected = 0;
		result = cardReturn;
		ASSERT(&result, &expected, "Testing card effect function return value");
		
   }