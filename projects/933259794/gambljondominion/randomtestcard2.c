/* -----------------------------------------------------------------------
Name: Kristin Ingellis
Date: 05/16/2019
Description: This card test examines the smithy card using a random
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

	printf("----------------- Testing 3: Smithy ----------------\n");

	for (int i = 0; i < tests; i++) {
		//randomize initialize game parameters
		int player = 0, rand_seed = rand();
		initializeGame(numPlayers, k, rand_seed, &game);
		game.deckCount[player] = rand() % MAX_DECK;
		game.discardCount[player] = rand() % MAX_DECK;
		int prevHand = game.handCount[player] = rand() % MAX_HAND;
		int prevDeck = game.deckCount[0];

		//play smithy card
		cardEffect(smithy, choice1, choice2, choice3, &game, handpos, &bonus);

		//check variables after card is played
		int hand = game.handCount[0];
		int deck = game.deckCount[0];

		if (hand != (prevHand + 2) || prevDeck != (deck - 3))
			fail++;
		else
			pass++;
	}

	printf("----------------- Smithy Test Results ----------------\n");
	printf("\n\nTest Completed: %d \n  Success: %d \n Fails: %d \n\n", tests, pass, fail);
}