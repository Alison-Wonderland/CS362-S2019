/* -----------------------------------------------------------------------
Name: Kristin Ingellis
Date: 05/16/2019
Description: This card test examines the adventurer card using a random
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


	printf("----------------- Testing 1: Adventurer ----------------\n");

	for (int i = 0; i < tests; i++) {
		int treasureCardsAdded = 0;
		int prevTreasureCardsAdded = 0;
		//randomize initialize game parameters
		int player = 0, rand_seed = rand();
		initializeGame(numPlayers, k, rand_seed, &game);
		//randomize deck size, discard size, and hand size
		game.deckCount[player] = rand() % MAX_DECK;
		game.discardCount[player] = rand() % MAX_DECK;
		game.handCount[player] = rand() % MAX_HAND;

		for (int j = 0; j < game.handCount[player]; j++) {
			if ((game.hand[player][j] == gold) || (game.hand[player][j] == silver) || (game.hand[player][j] == copper)) {
				prevTreasureCardsAdded++;
			}
		}

		//play adventurer card
		cardEffect(adventurer, choice1, choice2, choice3, &game, handpos, &bonus);

		//results after the card is played
		for (int k = 0; k < game.handCount[player]; k++) {
			if ((game.hand[player][k] == gold) || (game.hand[player][k] == silver) || (game.hand[player][k] == copper)) {
				treasureCardsAdded++;
			}
		}

		if (treasureCardsAdded < (treasureCardsAdded + 2))
			fail++;
		else
			pass++;

	}
	printf("\n\n----------------- Adventurer Test Results ----------------\n");
	printf("\nTest Completed: %d \n  Success: %d \n Fails: %d \n\n", tests, pass, fail);


	return 0;
}