/******************************************************************************
 *  Description     : This file handle the functions when the game starts
 *  Author/s        : <student1 full name (Dy, Jasmine Yzabelle)>
 *                    <student2 full name (last name, first name)>
 *  Section         : S22A
 *  Last Modified   : March 16, 2026
 ******************************************************************************/

 /* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defs.h"
#include "helpers_1.c"
#include "helpers_2.c"
#include "interface.c"

//===========================================
//          Function Implementation
//===========================================

/**
 * Ask the user how many players will be playing
 * 
 * @param numGamePlayers Pointer where the users input will be stored
 */
void getNumPlaying(int *numGamePlayers)
{
    do{
        printf("How many players? ");
        scanf("%d", numGamePlayers);
        while(getchar() != '\n');

        if(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS)
            printf("Invalid input. Minimum of %d players and maximum of %d players\n\n", MIN_GAME_PLAYERS, MAX_GAME_PLAYERS);

    }while(*numGamePlayers < MIN_GAME_PLAYERS || *numGamePlayers > MAX_GAME_PLAYERS);
}

/**
 * Checks if a username already exists
 * 
 * @param players The list of players
 * @param numPlayer The number of registered players
 * @param name The username to check
 * 
 * @return 1 if username exists, 0 otherwise
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
 * Registers a new player to a Players array and add them to players.txt
 * 
 * @param players The array of registered players
 * @param numPlayers The number of reigstered players that will be updated
 * @param success Updates the variable to 1 if the user is successfully registered
 */
void registerPlayer(Player players[], int *numPlayers, int *success)
{
    int i;
    int loop = 1, exists = 0;
    FILE *fp;
    User newUsername;

    *success = 0;

    while(loop == 1)
    {   
        if(*numPlayers >= MAX_PLAYERS)
        {
            printf("Can't register. Max number of players reached.\n");
            printf("Press any key...\n");
            getchar();
            loop = 0;
        }
        else
        {
            printf("Enter username (max 36 characters): ");
            scanf("%36s", newUsername);
            while(getchar() != '\n');

            //check if it exists
            exists = usernameExists(players, *numPlayers, newUsername);

            if(exists == 1)
                printf("Username already exists. Try again.\n");
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
                printf("%s registered! Welcome!\n", newUsername);

                *success = 1;

                printf("Press any key...\n");
                getchar();

                //exit loop
                loop = 0;
            }
        }
    }
}

/**
 * Let's the user select which players will be playing
 * 
 * @param players The array of reigstered players
 * @param numPlayers The number of registered players
 * @param gamePlayers The array where players who will be playing will be stored
 * @param numGamePlayers The number of players playing
 * @param selection The array that will store the players and see if they have been selected
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
                printf("\nThat player is already selected. Try again.\n");
                printf("Press any key...\n");
                getchar();
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
            printf("Invalid input. Try again.\n");
            printf("Press any key...\n");
            getchar();
        }
   }

   //initialize gamePlayer tank
   for(i = 0; i < numGamePlayers; i++)
    for(j = 0; j < 7; j++)
    {
        gamePlayers[i].tank[j] = 0;
        gamePlayers[i].tankPoints[j] = 0;
    }
}

/**
 * Check if a player has at least one card of the given card's front color
 * in their tank
 * 
 * @param card The card whose front color is being checked
 * @param player The player whose tank is being checked
 * @return 1 if the players has at least one card of that color, 0 otherwise
 */
int hasColor(Card card, GamePlayer player)
{
    return player.tank[getColorIndex(card.front)] > 0;
}

/**
 * Returns the index corresponding to a color character
 * Used for accessing tank[] and tankPoints[] arrays
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
 * Draws the top card from the deck. If the player already has that color in
 * their tank, all cards of that color is moved to their sccore pile.
 * Otherwise the card is added to their tank.
 * 
 * @param gameDeck The game deck to draw from
 * @param gameDeckSize Number of cards reamining in the deck
 * @param player Current player whose turn is being resolved
 */
void tryToScore(Card gameDeck[], int *gameDeckSize, GamePlayer *player)
{
    Card drawnCard = drawCard(gameDeck, gameDeckSize);
    int exist = hasColor(drawnCard, *player);
    int colorIndex = getColorIndex(drawnCard.front);

    printf("Resolving turn for %s...\n", player->player->name);
    printf("Drawn Card: %c (%d pt/s)\n", drawnCard.front, drawnCard.point);

    if(exist == 1)
    {
        printf("%s has (%d) %c card/s worth a total of (%d) pt/s\n", player->player->name, player->tank[colorIndex], drawnCard.front, player->tankPoints[colorIndex]);
        //update the score
        player->score += player->tankPoints[colorIndex] + drawnCard.point;
        printf("+%d point/s to player's score pile\n", player->score);

        //reset the tank
        player->tank[colorIndex] = 0;
        player->tankPoints[colorIndex] = 0;
    }
    else
    {
        printf("%s has no %c cards...\n", player->player->name, drawnCard.front);
        printf("Adding drawn card to player's tank\n");
        addToTank(player, drawnCard);
    }

    printf("Press any key...\n");
    getchar();
}

/**
 *
 */
void tryToSteal()
{

}

/**
 * 
 */
void displayGameState()
{

}

/**
 * Shuffle the deck and deal 4 cards to each player
 * 
 * @param deck The original deck of cards
 * @param gameDeck The copy of deck that will be shuffled and used int the game
 * @param gameDeckSize The number of cards in the deck
 * @param gamePlayers The players currently playing
 * @param numGamePlayers The number of players playing
 * @param seed The seed value used for shuffling
 * 
 * @pre playerSelection has been called and gamePlayers tanks are initialized to 0
 */
void shuffleAndDeal(Card deck[], Card gameDeck[], int *gameDeckSize, GamePlayer gamePlayers[], int numGamePlayers, int seed)
{
    int i, j;

    //put deck in gamedeck
    for(i = 0; i < TOTAL_CARDS; i++)
        gameDeck[i] = deck[i];

    *gameDeckSize = TOTAL_CARDS;

    //shuffle the gamedeck
    shuffle(gameDeck, *gameDeckSize, sizeof(Card), seed);

    //deal 4 cards (draw a card and add it to the tank)
    for(i = 0; i < numGamePlayers; i++)
        for(j = 0; j < 4; j++)
            addToTank(&gamePlayers[i], drawCard(gameDeck, gameDeckSize));
}

/**
 * Draws the top card from the deck and move the remaining cards forward
 * 
 * @param gameDeck The game deck to draw from
 * @param gameDeckSize number of cards in the deck
 * 
 * @return The drawn card
 * @pre gameDeckSize is greater than 0
 */
Card drawCard(Card gameDeck[], int *gameDeckSize)
{
    int i;
    Card drawn = gameDeck[0];

    for(i = 0; i < *gameDeckSize - 1; i++)
        gameDeck[i] = gameDeck[i + 1];

    *gameDeckSize -= 1;

    return drawn;
}

/**
 * Adds a card to a color slot in a player's tank based on the front color
 * 
 * @param gamePlayer The player whose tank will be updated
 * @param card The card added to the tank
 */
void addToTank(GamePlayer *gamePlayer, Card card)
{
    int index = getColorIndex(card.front);
    gamePlayer->tank[index]++;
    gamePlayer->tankPoints[index] += card.point;
}

/**
 * 
 */
int checkWinner()
{

}

void gameStart()
{

}

void showResults()
{

}