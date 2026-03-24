/******************************************************************************
 *  Description     : Handles the game logic and mechanics of Mantis
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>
#include <string.h>

#include "defsDy.h"

/* ----- function implementation ----- */

/**
 * Ask the user how many players will be playing
 * 
 * @param numGamePlayers Where the users input will be stored
 */
void getNumPlaying(int *numGamePlayers)
{
    do{
        printf("How many players? ");
        scanf("%d", numGamePlayers);
        while(getchar() != '\n');

        if(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS)
        {
            iSetColor(I_COLOR_RED);
            printf("Invalid input. Minimum of %d players and maximum of %d players\n\n", MIN_GAME_PLAYERS, MAX_GAME_PLAYERS);
            iSetColor(I_COLOR_WHITE);
        }
            

    }while(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS);
}

/**
 * Check if a username exists
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players
 * @param name The username to check
 * 
 * @return 1 if username exits, 0 otherwise
 */
int usernameExists(Player players[], int numPlayers, User name)
{
    int i;
    int exists = 0;

    for(i = 0; i < numPlayers; i++)
        if(strcmp(name, players[i].name) == 0)
            exists =1;

    return exists;
}

/**
 *  Registeres a play and add them to players.txt
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players to be updated
 * @param success Updates the variable to if successfully registered
 */
void registerPlayer(Player players[], int *numPlayers, int *success)
{
    int loop = 1, exists = 0;
    FILE *fp;
    User newUsername;

    *success = 0;

    while(loop == 1)
    {   
        if(*numPlayers >= MAX_PLAYERS)
        {
            iSetColor(I_COLOR_RED);
            printf("\nCan't register. Max number of players reached.\n");
            iSetColor(I_COLOR_WHITE);
            pressAnyKey();
            loop = 0;
        }
        else
        {
            printf("\nEnter username (max 36 characters): ");
            scanf("%36s", newUsername);
            while(getchar() != '\n');

            //check if it exists
            exists = usernameExists(players, *numPlayers, newUsername);

            if(exists == 1)
            {
                iSetColor(I_COLOR_RED);
                printf("Username already exists. Try again.\n");
                iSetColor(I_COLOR_WHITE);
            }
                
            else
            {
                //add to array
                strcpy(players[*numPlayers].name, newUsername);
                players[*numPlayers].wins = 0;
                players[*numPlayers].highestScore = 0;

                //add to txt file
                fp = fopen(PLAYER_FILE, "a");
                fprintf(fp, "%s %d %d\n", newUsername, 0, 0);
                fclose(fp);

                //update the number of players
                *numPlayers += 1;
                iSetColor(I_COLOR_CYAN);
                printf("\n%s registered! Welcome!\n", newUsername);
                iSetColor(I_COLOR_WHITE);

                *success = 1;

                pressAnyKey();

                //exit loop
                loop = 0;
            }
        }
    }
}

/**
 * Let's user select the players who will be playing
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players
 * @param gamePlayes The array where the players playing will be stored
 * @param numGamePlayers Number of players playing
 */
void playerSelection(Player players[], int *numPlayers, GamePlayer gamePlayers[], int numGamePlayers)
{
    int registered; // 1 if player has been successfully registered
    int numSelected = 0; // the number of players that has been selected
    int choice;
    int i, j;

    //set picked variable in players to 0
    for(i = 0; i < *numPlayers; i++)
        players[i].picked = 0;

    while(numSelected < numGamePlayers) 
    {
        system("cls");

        //show which player is Player n and which slots are empty
        for(i = 0; i < numGamePlayers; i++)
        {
            if(i < numSelected)
                printf("P%d: %s\n", i+1, gamePlayers[i].player->name);
            else 
                printf("P%d: ?\n", i+1);
        }

        printf("\nSelect Player %d:\n", numSelected + 1);
        printf("\t[0] Add new player\n");

        //show the players they can select
        for(i = 0; i < *numPlayers; i++)
        {
            if(players[i].picked == 1)
            {
                printf("\t[%d] %s ", i+1, players[i].name);
                iSetColor(I_COLOR_GREEN);
                printf("(Already selected)\n");
                iSetColor(I_COLOR_WHITE);
            }
            else
                printf("\t[%d] %s\n", i+1, players[i].name);
        }

        //ask user
        printf("\n>> ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice == 0)
        {
            registerPlayer(players, numPlayers, &registered);

            if(registered == 1)
            {
                players[*numPlayers - 1].picked = 1;
                gamePlayers[numSelected].player = &players[*numPlayers - 1];
                numSelected++;
            }
        }
        else if(choice >= 1 && choice <= *numPlayers)
        {
            if(players[choice-1].picked == 1)
            {
                iSetColor(I_COLOR_RED);
                printf("\nThat player is already selected. Try again.\n");
                iSetColor(I_COLOR_WHITE);
                pressAnyKey();
            }
            else
            {
                players[choice-1].picked = 1;
                gamePlayers[numSelected].player = &players[choice-1];
                numSelected++;
            }
        }
        else
        {
            iSetColor(I_COLOR_RED);
            printf("Invalid input. Try again.\n");
            iSetColor(I_COLOR_WHITE);
            pressAnyKey();
        }
    }

   //initialize gamePlayer tank
    for(i = 0; i < numGamePlayers; i++)
        for(j = 0; j < 7; j++)
        {
            gamePlayers[i].tank[j] = 0;
            gamePlayers[i].tankPoints[j] = 0;
            gamePlayers[i].score = 0;
        }
}

/**
 * Check if the player has at least one card of card's front color in their tank
 * 
 * @param card The card thats being checked
 * @param player The player whose tank is being checked
 * 
 * @return 1 if the players has at least 1 card of that color, 0 otherwise
 */
int hasColor(Card card, GamePlayer player)
{
    int index = getColorIndex(card.front);
    return player.tank[index] > 0;
}

/**
 * Get the index corresponding to the color 
 * Used for accessing tank[] and tankPoints[]
 * 
 * @param color The color character (R,O,Y,G,B,I,V)
 * @return The index number of the color (0=R, 1=O, 2=Y, 3=G, 4=B, 5=I, 6=V)
 */
int getColorIndex(char color)
{
    int index;

    if(color == 'R') 
        index = 0;
    else if(color == 'O')
        index = 1;
    else if(color == 'Y')
        index = 2;
    else if(color == 'G')
        index = 3;
    else if(color == 'B')
        index = 4;
    else if(color == 'I')
        index = 5;
    else
        index = 6;

    return index;
}

/**
 * Draws the top card from the deck and move the remaining cards forward
 * 
 * @param deck The card deck to draw from
 * @param deckSize Number of cards in the deck
 * 
 * @return drawn card
 * @pre deckSize must be greater than 0
 */
Card drawCard(Card deck[], int *deckSize)
{
    int i;
    Card drawn = deck[0];

    for(i = 0; i < *deckSize - 1; i++)
        deck[i] = deck[i + 1];

    *deckSize -= 1;

    return drawn;
}

/**
 * Adds a card to a players tank based on the front color
 * 
 * @param gamePlayer The player whose tank will be updated
 * @param card  The drawn card
 */
void addToTank(GamePlayer *gamePlayer, Card card)
{
    int index = getColorIndex(card.front);
    gamePlayer->tank[index]++;
    gamePlayer->tankPoints[index] += card.point;
}

/**
 * Shuffles the deck and deals 4 cards to each player
 * 
 * @param deck The deck of cards
 * @param deckSize The number of cards in the deck
 * @param gamePlayers The array of players playing
 * @param numGamePlayers The numbers of players playing
 * @param seed The seed value used for shuffling
 * 
 * @pre game player's tank must be initialized with 0
 */
void shuffleAndDeal(Card deck[], int *deckSize, GamePlayer gamePlayers[], int numGamePlayers, int seed)
{
    int i, j;

    //shuffle the gamedeck
    shuffle(deck, *deckSize, sizeof(Card), seed);

    //deal 4 cards (draw a card and add it to the tank)
    for(i = 0; i < numGamePlayers; i++)
        for(j = 0; j < 4; j++)
            addToTank(&gamePlayers[i], drawCard(deck, deckSize));
}

/**
 * Draws the top card from the deck. If the player already has that color in their tank, all cards of that 
 * color is moved to their sccore pile. Otherwise the card is added to their tank.
 * 
 * @param deck The game deck to draw from
 * @param deckSize Number of cards reamining in the deck
 * @param player Current player whose turn is being resolved
 */
void tryToScore(Card deck[], int *deckSize, GamePlayer *player)
{
    Card drawnCard = drawCard(deck, deckSize);
    int colorIndex = getColorIndex(drawnCard.front);

    printf("\nResolving turn for %s...\n\n", player->player->name);
    displayDrawnCard(drawnCard);
    printf("\nDrawn Card: %c (%d pt/s)\n", drawnCard.front, drawnCard.point);

    if(hasColor(drawnCard, *player) == 1)
    {
        printf("- %s has (%d) %c card/s worth a total of (%d) pt/s!\n", player->player->name, 
                player->tank[colorIndex], drawnCard.front, player->tankPoints[colorIndex]);
        //update the score
        player->score += player->tankPoints[colorIndex] + drawnCard.point;
        printf("- +%d point/s to player's score pile!\n", player->tankPoints[colorIndex] + drawnCard.point);

        //reset the tank
        player->tank[colorIndex] = 0;
        player->tankPoints[colorIndex] = 0;
    }
    else
    {
        printf("- %s has no %c cards...\n", player->player->name, drawnCard.front);
        printf("- Adding drawn card to %s's tank.\n", player->player->name);
        addToTank(player, drawnCard);
    }

    pressAnyKey();
}

/**
 * The current player selects a target player, then draw the top card from the deck. If the target has 
 * that color in their tank, all cards of that color and the drawn card are put in the current player's 
 * tank. Otherwise, the drawn card is added to the target player's tank
 * 
 * @param deck The game deck to draw from
 * @param deckSize Number of cards remaining in the deck
 * @param gamePlayers The array of all the players playing the game
 * @param numGamePlayers The number of players playing the game
 * @param currentPlayerIndex The index of the current player in gamePlayers
 */
void tryToSteal(Card deck[], int *deckSize, GamePlayer gamePlayers[], int numGamePlayers, int currentPlayerIndex)
{
    Card drawnCard;
    int colorIndex;
    int i, choice, valid;
    int targetIndex; // the index of the player to be stolen from

    //ask who to steal from
    do
    {
        valid = 1;

        printf("Who would you like to steal from?\n");
        for(i = 0; i < numGamePlayers; i++)
            if(i != currentPlayerIndex)
                printf("\t[%d] %s\n", i + 1, gamePlayers[i].player->name);
        
        printf("\n>> ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice < 1 || choice > numGamePlayers)
        {
            iSetColor(I_COLOR_RED);
            printf("Invalid input. Try again.\n");
            iSetColor(I_COLOR_WHITE);
            valid = 0;
        }
        else if(choice - 1 == currentPlayerIndex)
        {
            iSetColor(I_COLOR_RED);
            printf("You cannot steal from yourself. Try again.\n");
            iSetColor(I_COLOR_WHITE);
            valid = 0;
        }

    } while (valid == 0);

    targetIndex = choice - 1;
    
    //draw card and get the color index
    drawnCard = drawCard(deck, deckSize);
    colorIndex = getColorIndex(drawnCard.front);

    printf("Resolving turn for %s...\n\n", gamePlayers[currentPlayerIndex].player->name);
    displayDrawnCard(drawnCard);
    printf("\nDrawn card: %c (%d pt/s)\n", drawnCard.front, drawnCard.point);

    if(hasColor(drawnCard, gamePlayers[targetIndex]) == 1)
    {
        printf("- %s has (%d) %c card/s!\n", gamePlayers[targetIndex].player->name, gamePlayers[targetIndex].tank[colorIndex], 
                drawnCard.front);

        //add to the players tank
        gamePlayers[currentPlayerIndex].tank[colorIndex] += gamePlayers[targetIndex].tank[colorIndex] + 1;
        gamePlayers[currentPlayerIndex].tankPoints[colorIndex] += gamePlayers[targetIndex].tankPoints[colorIndex] + drawnCard.point;

        //remove from target's tank
        gamePlayers[targetIndex].tank[colorIndex] = 0;
        gamePlayers[targetIndex].tankPoints[colorIndex] = 0;

        printf("- +%d (%c) cards to %s's tank!\n", gamePlayers[currentPlayerIndex].tank[colorIndex], drawnCard.front, 
                gamePlayers[currentPlayerIndex].player->name);
    }
    else
    {
        printf("- %s has no %c cards...\n", gamePlayers[targetIndex].player->name, drawnCard.front);
        printf("- Adding drawn card to %s's tank\n", gamePlayers[targetIndex].player->name);
        addToTank(&gamePlayers[targetIndex], drawnCard);
    }

    pressAnyKey();
}

/**
 * Displays the current state of the game like the player's tank, score, and the top card of the deck
 * 
 * @param gamePlayers The players playing the game
 * @param numGamePlayers Number of players playing
 * @param deck The game deck
 * @param deckSize Number of cards remaining in the deck
 */
void displayGameState(GamePlayer gamePlayers[], int numGamePlayers, Card deck[], int deckSize)
{
    int i;

    for(i = 0; i < numGamePlayers; i++)
    {
        printf(" ================================================\n");
        printf("   %-36s Score: %d\n", gamePlayers[i].player->name, gamePlayers[i].score);
        printf("\tR:%d  O:%d  Y:%d  G:%d  B:%d  I:%d  V:%d\n", gamePlayers[i].tank[0], 
                gamePlayers[i].tank[1], gamePlayers[i].tank[2], gamePlayers[i].tank[3], 
                gamePlayers[i].tank[4], gamePlayers[i].tank[5], gamePlayers[i].tank[6]);
    }

    printf(" ================================================\n");
    printf("\n Top Deck: %s | Cards Remaining: %d\n\n", deck[0].back, deckSize);
}

/**
 * Checks if there is a winner
 * 
 * @param gamePlayers The players playing the game
 * @param numGamePlayers Number of players playing the game
 * @param deckSize Number of cards remaining in the deck
 * @param winningPoints The points the players must have in order to win
 * @return The index number of the winner, -1 if no winner yet
 */
int checkWinner(GamePlayer gamePlayers[], int numGamePlayers, int deckSize, int winnningPoints)
{
    int winnerIndex = -1;
    int i, j;
    int tie = 0; //1 if there is a tie
    int highestScore=0, mostTankCards=0;
    int totalTank = 0; // the total number of cards in a tank

    //check if there is a player who has already reached the winning points
    for(i = 0; i < numGamePlayers; i++)
        if(gamePlayers[i].score >= winnningPoints)
            winnerIndex = i;

    //if draw pile runs out and no player got score >= winningPoints
    if(deckSize == 0 && winnerIndex == -1)
    {
        for(i = 0; i < numGamePlayers; i++)
        {
            if(gamePlayers[i].score > highestScore)
            {
                highestScore = gamePlayers[i].score;
                winnerIndex = i;
            }
        }

        //check is there is anyone with the same score
        for(i = 0; i <numGamePlayers && tie == 0; i++)
        {
            if(gamePlayers[i].score == highestScore && i != winnerIndex)
            {
                tie = 1;
            }
        }

        //if there is a tie, look for the players with the most tank cards
        if(tie == 1)
        {
            for(i = 0; i < numGamePlayers; i++)
            {
                totalTank = 0;

                for(j = 0; j < 7; j++)
                {
                    totalTank += gamePlayers[i].tank[j];
                }

                if(totalTank > mostTankCards)
                {
                    mostTankCards = totalTank;
                    winnerIndex = i;
                }
            }
        }
    }
    return winnerIndex;
}

/**
 * Display the results of the game and updates the wins and highest score of a player
 * 
 * @param gamePlayers The players playing the game
 * @param numGamePlayers Number of players playing
 * @param winnerIndex The index of the winner in gamePlayers
 */
void showResults(GamePlayer gamePlayers[], int numGamePlayers, int winnderIndex)
{
    int i;
    int firstWinner = 1; // 1 if only 1 winner

    displayTrophy();

    for(i = 0; i < numGamePlayers; i++)
    {
        iSetColor(I_COLOR_WHITE);
        printf(" ================================================\n");
        if(gamePlayers[i].score == gamePlayers[winnderIndex].score)
            iSetColor(I_COLOR_GREEN);
        printf("   %-36s Score: %d", gamePlayers[i].player->name, gamePlayers[i].score);

        if(gamePlayers[i].score > gamePlayers[i].player->highestScore)
        {
            iSetColor(I_COLOR_CYAN);
            printf("  *** NEW BEST! ***");
        }

        iSetColor(I_COLOR_WHITE);
        printf("\n\tR:%d  O:%d  Y:%d  G:%d  B:%d  I:%d  V:%d\n", gamePlayers[i].tank[0], 
                gamePlayers[i].tank[1], gamePlayers[i].tank[2], gamePlayers[i].tank[3], 
                gamePlayers[i].tank[4], gamePlayers[i].tank[5], gamePlayers[i].tank[6]);
    }

    printf(" ================================================\n\n");

    printf("  >> ");
    for(i = 0; i < numGamePlayers; i++)
    {
        if(gamePlayers[i].score == gamePlayers[winnderIndex].score)
        {
            if(!firstWinner) printf(" & ");
            iSetColor(I_COLOR_GREEN);
            printf("%s", gamePlayers[i].player->name);
            iSetColor(I_COLOR_WHITE);
            firstWinner = 0;
        }
    }
    printf(" WIN! <<\n\n  [Record Updated]\n");

    for(i = 0; i < numGamePlayers; i++)
    {
        if(gamePlayers[i].score == gamePlayers[winnderIndex].score)
        {
            gamePlayers[i].player->wins++;
            printf("  %s: +1 win (Total wins: %d)\n",
                gamePlayers[i].player->name, gamePlayers[i].player->wins);
        }

        if(gamePlayers[i].score > gamePlayers[i].player->highestScore)
        {
            iSetColor(I_COLOR_CYAN);
            printf("  %s: *** NEW BEST! Old: %d | New: %d ***\n",
                gamePlayers[i].player->name,
                gamePlayers[i].player->highestScore,
                gamePlayers[i].score);
            iSetColor(I_COLOR_WHITE);
            gamePlayers[i].player->highestScore = gamePlayers[i].score;
        }
    }

    pressAnyKey();
}

/**
 * Handles the turn order and checks for a winner after each turn then displays the results when the game ends
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players
 * @param gamePlayers The array of players playing the game
 * @param numGamePlayers Number of players playing
 * @param deck The deck of cards
 * @param deckSize Number of cards remaining in the deck
 * @param currSettings The current game settings
 */
void gameStart(Player players[], int numPlayers, GamePlayer gamePlayers[], int numGamePlayers, Card deck[], int *deckSize, Settings currSettings)
{
    int choice;
    int winnderIndex = -1;
    int currentPlayerIndex = 0;

    //shuffle and deal cards
    system("cls");
    printf("         _\\|/_\n");
    printf("         (o o)\n");
    printf(" +----oOO-{_}-OOo---------------------+\n");
    printf(" |                                    |\n");
    printf(" |          M  A  N  T  I  S          |\n");
    printf(" |           Game Starting            |\n");
    printf(" |                                    |\n");
    printf(" +------------------------------------+\n\n");
    shuffleAndDeal(deck, deckSize, gamePlayers, numGamePlayers, currSettings.seed);
    printf("Deck shuffled! Dealing Tank cards...\n\n");
    displayGameState(gamePlayers, numGamePlayers, deck, *deckSize);
    pressAnyKey();

    //loop
    while(winnderIndex == -1)
    {
        system("cls");

        //display game state
        displayHeader();
        displayGameState(gamePlayers, numGamePlayers, deck, *deckSize);

        //ask player want they wanna do
        printRainbow(gamePlayers[currentPlayerIndex].player->name);
        printf(", what would you like to do?\n");
        printf("  [1] Try to Score\n");
        printf("  [2] Try to Steal\n\n");
        printf(">> ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if(choice == 1)
            tryToScore(deck, deckSize, &gamePlayers[currentPlayerIndex]);
        else if(choice == 2)
            tryToSteal(deck, deckSize, gamePlayers, numGamePlayers, currentPlayerIndex);
        else
        {
            iSetColor(I_COLOR_RED);
            printf("Invalid input. Try again.\n");
            iSetColor(I_COLOR_WHITE);
            pressAnyKey();
        }

        //go to next play only if a valid choice was made
        if(choice == 1 || choice == 2)
        {
            winnderIndex = checkWinner(gamePlayers, numGamePlayers, *deckSize, currSettings.winningPoints);
            
            if(currentPlayerIndex == numGamePlayers - 1)
                currentPlayerIndex = 0;
            else
                currentPlayerIndex++;
        }
    }

    system("cls");
    showResults(gamePlayers, numGamePlayers, winnderIndex);
    savePlayers(players, numPlayers);
}