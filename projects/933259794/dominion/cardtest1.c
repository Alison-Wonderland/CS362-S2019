/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 04/30/2019
 Description: This card test examines the discard aspect of the 
 * refactored adventurer function which is named new_adventurer. It also 
 * examines what happens with an invalid card parameter.
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

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Card Test 1: Adventurer ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		int prevCoinState = test.coins;
		int cardReturn = cardEffect(adventurer, choice1, choice2, choice3, &test, handpos, &bonus);

		//then check if discarded and output result
		expected = 1;
		result = test.discardCount[0];
		ASSERT(&result, &expected, "Testing discard");
		//verifying there is no effect on coins before update coins is called
		expected = prevCoinState;
		result = test.coins;
		ASSERT(&result, &expected, "Testing coin value before update coins is called");
		//coin value after updating coins 
		int player = whoseTurn(&test);
		updateCoins(player, &test, bonus);
		int total = 0;
		for (int i = 0; i < test.handCount[0]; i++)
		{
			if (test.hand[0][i] == (copper || silver || gold))
			{
				if(copper)
				{
					total += 1;
				}
				else if(silver)
				{
					total += 2;
				}
				else 
				{
					total +=3;
				}
			}
		}
		expected = total + prevCoinState;
		result = test.coins;
		ASSERT(&result, &expected, "Testing coin value after update coins is called");

		//check card effect return value with an invalid value in the card parameter
		cardReturn = cardEffect(-2, choice1, choice2, choice3, &test, handpos, &bonus);
		expected = -1;
		result = cardReturn;
		ASSERT(&result, &expected, "Testing card effect function return value when card parameter is invalid");

		


		/*if(result != expected)
		{
			printf("FAIL! Result: %d  Expected: %d \n", result, expected);
		}
		else
		{
			printf("SUCCESS! Result: %d  Expected: %d \n", result, expected);
		}*/

   }