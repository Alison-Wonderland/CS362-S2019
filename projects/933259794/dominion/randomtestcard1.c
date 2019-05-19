/* -----------------------------------------------------------------------
Name: Kristin Ingellis
Date: 05/16/2019
Description: This card test examines the council room card using a random
* test generator.
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


int main() {
	struct gameState game;
	int numPlayers = 2;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int pass = 0, fail = 0, tests = 900;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	printf("----------------- Testing 2: Council Room ----------------\n");

	for (int i = 0; i < tests; i++) {
		//randomize initialize game parameters
	    int rand_seed = rand();
		int player = 0;
		initializeGame(numPlayers, k, rand_seed, &game);
		game.deckCount[player] = rand() % MAX_DECK;
		game.discardCount[player] = rand() % MAX_DECK;
		int pastHandCount = game.handCount[player] = rand() % MAX_HAND;
		int opponentHandCount = game.handCount[1] = rand() % MAX_HAND;
		int pastNumBuys = game.numBuys;

		//player council room card
		cardEffect(council_room, choice1, choice2, choice3, &game, handpos, &bonus);

        //check what happens after council room is played
		if (pastHandCount + 3 == game.handCount[player] && pastNumBuys + 1 == game.numBuys && opponentHandCount + 1 == game.handCount[1]) {
			pass++;
		}
		else
			fail++;
	}
	printf("\n\n----------------- Council Room Test Results ----------------\n");
	printf("\nTest Completed: %d \n  Success: %d \n Fails: %d \n\n", tests, pass, fail);

	return 0;
}