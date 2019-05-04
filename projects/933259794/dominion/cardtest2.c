/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/01/2019
 Description: This card test examines the deck count which should decrease by three cards
 *in the new_smithy function which has a bug that has the player draw two times per loop
 *and what happens with an incorrect card paramater entered in the cardEffect function
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
fail = deck count is any other number
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
		int deckCount = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Card Test 2: Smithy ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		int prevCoinState = test.coins;
		deckCount = test.deckCount[0];

		int cardReturn = cardEffect(smithy, choice1, choice2, choice3, &test, handpos, &bonus);

		//check how many total cards there are in the deck and output result
		expected = deckCount - 3;
		result = test.deckCount[0];
		ASSERT(&result, &expected, "Testing number of cards in deck");
		//verifying there is no effect on coins
		expected = prevCoinState;
		result = test.coins;
		ASSERT(&result, &expected, "Testing coin value");
		//verifying one card was played
		expected = 1;
		result = test.playedCardCount;
		ASSERT(&result, &expected, "Testing played cards count");
		//check card effect return value with an invalid value in the card parameter
		cardReturn = cardEffect(-2, choice1, choice2, choice3, &test, handpos, &bonus);
		expected = -1;
		result = cardReturn;
		ASSERT(&result, &expected, "Testing card effect function return value when card parameter is invalid");

		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d\n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }