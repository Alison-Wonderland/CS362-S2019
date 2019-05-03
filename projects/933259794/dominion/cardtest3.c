/* -----------------------------------------------------------------------
 Name: Kristin Ingellis
 Date: 05/02/2019
 Description: This card test examines the choice aspect of the steward card
 *relating to the coin choice and what happens with an incorrect card paramater 
 *entered in the cardEffect function. It also examines an invalid choice paramater
 *for choice1 and it's affect on the coin state.
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

//test the choice and it's affect on the results, this one uses the coin option 

//create custom assert to print out unit test results
int ASSERT(int *result, int *expected, char *s) {
  if(*result != *expected) 
  {
    printf("ASSERT FAIL! %s, Result: %d  Expected: %d\n", s, *result, *expected);
    return 0;
  }
  else
  {
    printf("ASSERT SUCCESS! %s,  Result: %d  Expected: %d\n", s, *result, *expected);
    return 1;
  }
}

int main(){
		int expected = 2;
		int result = 0;
		int prevCoinState = 0;

		int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
		int seed = 1000;
		int numPlayers = 2;
		struct gameState game, test;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &game);

		printf("----------------- Card Test 3: Steward ----------------\n");

		// copy the game state to a test case
		memcpy(&test, &game, sizeof(struct gameState));
		
		prevCoinState = test.coins;
		//draw coins choice
		choice1 = 2;
		int cardReturn = cardEffect(steward, choice1, choice2, choice3, &test, handpos, &bonus);

		//check how many total coins were added and output result
		expected = prevCoinState + 2;
		result = test.coins;
		ASSERT(&result, &expected, "Testing number of coins");

		//check coin state with an invalid value in the choice 1 parameter
		choice1 = -1;
		cardEffect(steward, choice1, choice2, choice3, &test, handpos, &bonus);
		expected = prevCoinState;
		result = test.coins;
		ASSERT(&result, &expected, "Testing coin value when choice1 parameter is -1");

		//check coin state with an invalid value in the choice 1 parameter
		choice1 = 0;
		cardEffect(steward, choice1, choice2, choice3, &test, handpos, &bonus);
		expected = prevCoinState;
		result = test.coins;
		ASSERT(&result, &expected, "Testing coin value when choice1 parameter is a 0");

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