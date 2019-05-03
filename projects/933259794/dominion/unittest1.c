/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 04/30/2019
 Description: This unit test examines the draw treasure, opponent hand and deck sizes, and actions
 * in relation to the refactored adventurer function which is named new_adventurer.
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
the player draw three treasure cards instead of two, test the total drawn treasure cards will fail 
using the refactored code.
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
		int drawntreasure = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		int playerTwoHand = 0;
		int playerTwoDeck = 0;
		int actions = 0;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		int i;

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Unit Test 1: Adventurer ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		//save state of player 2 hand size and deck size to verify no changes occur after player 1
		//plays the adventurer card
		playerTwoHand = test.handCount[1];
		playerTwoDeck = test.deckCount[1];
		actions = test.numActions;
		int cardReturn = cardEffect(adventurer, choice1, choice2, choice3, &test, handpos, &bonus);

		for (i = 0; i < test.handCount[0]; i++)
		{
			if (test.hand[0][i] == (copper || silver || gold))
				drawntreasure++;
		}

		//then check how many total treasure cards there are and output result
		expected = 2;
		result = drawntreasure;
		ASSERT(&result, &expected, "Testing number of treasure cards in hand for current player");
		//check player 2 hand count is unchanged
		expected = playerTwoHand;
		result = test.handCount[1];
		ASSERT(&result, &expected, "Testing player two, opponent, hand count");
		//check player 2 deck count is unchanged
		expected = playerTwoDeck;
		result = test.deckCount[1];
		ASSERT(&result, &expected, "Testing player two, opponent, deck count");
		//check if actions changed which shouldn't for the adventurer card
		expected = actions;
		result = test.numActions;
		ASSERT(&result, &expected, "Testing number of actions for current player");
		//check card effect return value
		expected = 0;
		result = cardReturn;
		ASSERT(&result, &expected, "Testing card effect function return value");

		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }