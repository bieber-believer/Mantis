/******************************************************************************
 *  Description     : Handles the functions for the main menu
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
 * Calls functions needed to start a new game
 * 
 * @param players The array of registered players
 * @param numPlayers Number of registered players
 * @param gamePlayers The array of players playing
 * @param numGamePlayers Number of players playing
 * @param deck The deck of cards
 * @param deckSize The number of cards in the deck
 * @param currSettings The current settings
 */
void newGame(Player players[], int *numPlayers, GamePlayer gamePlayers[], int *numGamePlayers, Card deck[], int *deckSize, Settings currSettings)
{
    system("cls");
    *deckSize = TOTAL_CARDS;
    mantisToStruct(deck);
    //call getNumPlaying()
    getNumPlaying(numGamePlayers);
    //call playerSelection()
    playerSelection(players, numPlayers, gamePlayers, *numGamePlayers);
    //call gameStart()
    gameStart(players, *numPlayers, gamePlayers, *numGamePlayers, deck, deckSize, currSettings);
}

/**
 * Display the tutorial of Mantis
 */
void displayHowToPlay()
{
    printf("The cards in Mantis are two sided. Each card has three different colors\n");
    printf("on the back and only one color on the front. One of the three colors on the back\n");
    printf("of the card is the color that in on the front of the card.\n\n");

    printf("To start the turn, you have to choose between one of the two actions:\n");
    iSetColor(I_COLOR_CYAN);
    printf("-Try to Score\n-Try to Steal\n\n");
    iSetColor(I_COLOR_WHITE);

    printf("When you decide to try and score, you will draw the top card from the Draw Pile.\n");
    printf("Flip the card over and put it in your Tank. If the new card matches any existing card(s)\n");
    printf("in your Tank, add the new card and all matching color cards to your Score Pile.\n");
    printf("If the card does not match any of the cards already in your Tank, add it.\n\n");

    printf("Your other option is to try to steal. First, decide which player you'll try to steal from.\n");
    printf("Then, flip over the top card from the Draw Pile. If the new card's color corresponds to one or\n");
    printf("more cards in the chosen player's Tank, place the new card and any matching cards in your own\n");
    printf("Tank. If the card does not match any of the cards in front of the chosen player, you will place the\n");
    printf("new card in the chosen player's Tank.\n\n");

    iSetColor(I_COLOR_GREEN);
    printf("The first player to get a score higer or equal to the winning points win.\n\n");
    iSetColor(I_COLOR_WHITE);

    printf("Source: https://www.geekyhobbies.com/mantis-rules/ \n");
}

/**
 * Sorts players by their wins in descending order
 * 
 * @param players The array with all the registered players
 * @param topWins The array where the sorted players will be stored
 * @param numPlayers Number of registered players
 */
void sortByWins(Player players[], Player topWins[], int numPlayers)
{
    int i, j, max;
    Player temp;

    //put all the registered players in topWins
    for(i = 0; i < numPlayers; i++)
        topWins[i] = players[i];

    //start sorting
    for(i = 0; i < numPlayers - 1; i++)
    {
        max = i;

        for(j= i + 1; j < numPlayers; j++)
        {
            if(topWins[j].wins > topWins[max].wins)
            max = j;
        }

        if(i != max)
        {
            temp = topWins[i];
            topWins[i] = topWins[max];
            topWins[max] = temp;
        }
    }
}

/**
 * Sorts players by their score in descending order
 * 
 * @param players The array with all the registered players
 * @param topScore The array where the sorted players will be stored
 * @param numPlayers Number of registered players
 */
void sortByScore(Player players[], Player topScore[], int numPlayers)
{
    int i, j, max;
    Player temp;

    //store the players in the top score
    for(i = 0; i < numPlayers; i++)
        topScore[i] = players[i];

    //start sorting
    for(i = 0; i < numPlayers - 1; i++)
    {
        max = i;

        for(j = i + 1; j < numPlayers; j++)
            if(topScore[j].highestScore > topScore[max].highestScore)
                max = j;
        
        if(i != max)
        {
            temp = topScore[i];
            topScore[i] = topScore[max];
            topScore[max] = temp;
        }
    }
}

/**
 * Displays the top 10 Players with the most amount of wins
 * 
 * @param topWins The array with the sorted players based on the most amount of wins
 * @param numPlayers Number of registered players
 */
void displayTop10Wins(Player topWins[], int numPlayers)
{
    int i;

    printf("Top 10 Players with the highest wins:\n\n");
    printf("------------------------------------------------------------------\n");
    printf("%-10s %-36s %-10s %-10s\n", "Rank", "Username", "Wins", "Score");
    printf("------------------------------------------------------------------\n");

    if(numPlayers > 10)
    {
        for(i = 0; i < 10; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topWins[i].name, topWins[i].wins, topWins[i].highestScore);
        }
    }
    else
    {
        for(i = 0; i < numPlayers; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topWins[i].name, topWins[i].wins, topWins[i].highestScore);
        }
    }
}

/**
 * Displays the top 10 players with the highest score
 * 
 * @param topScore The array with the sorted players by highest score
 * @param numPlayers Number of registered players
 */
void displayTop10Score(Player topScore[], int numPlayers)
{
    int i;

    printf("Top 10 Players with the highest score:\n\n");
    printf("------------------------------------------------------------------\n");
    printf("%-10s %-36s %-10s %-10s\n", "Rank", "Username", "Wins", "Score");
    printf("------------------------------------------------------------------\n");

    if(numPlayers > 10)
    {
        for(i = 0; i < 10; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topScore[i].name, topScore[i].wins, topScore[i].highestScore);
        }
    }
    else
    {
        for(i = 0; i < numPlayers; i++)
        {
            printf("%-10d %-36s %-10d %-10d\n", i+1, topScore[i].name, topScore[i].wins, topScore[i].highestScore);
        }
    }
}

/**
 * Asks user how they want to view the top 10 players then displays the top 10 of their chosen choice
 * 
 * @param players The array of registered players
 * @param topWins The array of players sorted by most to least wins
 * @param topScore The array of players sorted by highest to lowest score
 * @param numPlayers Number of registered players
 */
void displayTop10(Player players[], Player topWins[], Player topScore[], int numPlayers)
{
    int loop = 1;
    int choice = -1;

    while(loop == 1)
    {
        if(numPlayers == 0)
        {
            system("cls");
            printf("No player has played :(\n");
            pressAnyKey();
            loop = 0;
        }
        else
        {
            system("cls");
            printf("View top players by:\n");
            printf("[1] Wins\n");
            printf("[2] Highest Score\n");
            printf("[0] Back to Main Menu\n\n");
            printf(">> ");
            scanf("%d", &choice);
            while(getchar() != '\n');

            switch(choice)
            {
                case 1:
                    system("cls");
                    sortByWins(players, topWins, numPlayers);
                    displayTop10Wins(topWins, numPlayers);
                    pressAnyKey();
                    loop = 0; // user goes back to main menu
                    break;
                case 2:
                    system("cls");
                    sortByScore(players, topScore, numPlayers);
                    displayTop10Score(topScore, numPlayers);
                    pressAnyKey();
                    loop = 0; // user goes back to main menu
                    break;
                case 0:
                    loop = 0;
                    break;
                default:
                    iSetColor(I_COLOR_RED);
                    printf("Invalid input. Try again.\n");
                    iSetColor(I_COLOR_WHITE);
                    pressAnyKey();
            }
        }
    }
}

/**
 * Allows the user to change the settings of the game
 * 
 * @param currSettings The settings they wish to change
 * 
 * @pre initRandom() has been called already
 */
void changeSettings(Settings *currSettings)
{
    int loop = 1;
    int choice;

    while(loop == 1)
    {
        system("cls");
        printf("Settings:\n");
        printf("Winning Points: %d points ", currSettings->winningPoints);
        printf("(Default: 20 points)\n");
        printf("Shuffle Seed: %d ", currSettings->seed);
        printf("(Default: Random)\n\n"); 

        iSetColor(I_COLOR_CYAN);
        printf("Change Settings?\n");
        iSetColor(I_COLOR_WHITE);
        printf("[1] Winning Points\n");
        printf("[2] Shuffle Seed\n");
        printf("[3] Reset to Default\n");
        printf("[0] Back to Main Menu\n\n");
        printf(">> ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        
        switch (choice)
        {
            case 1:
                do
                {
                    printf("\nNew Winning Points? (minimum 5)\n");
                    printf(">> ");
                    scanf("%d", &currSettings->winningPoints);
                    while(getchar() != '\n');

                    if(currSettings->winningPoints < 5)
                    {
                        iSetColor(I_COLOR_RED);
                        printf("Winning points must be at least 5.\n");
                        iSetColor(I_COLOR_WHITE);
                    }
                }while(currSettings->winningPoints < 5);
                break;
            case 2:
                printf("\nNew Shuffle Seed?\n");
                printf(">> ");
                scanf("%d", &currSettings->seed);
                while(getchar() != '\n');
                break;
            case 3:
                currSettings->winningPoints = 20;
                currSettings->seed = randomInt();
                pressAnyKey();
                break;
            case 0:
                loop = 0;
                break;
            default:
                iSetColor(I_COLOR_RED);
                printf("Invalid input. Try again.\n");
                iSetColor(I_COLOR_WHITE);
                pressAnyKey();
        }
    }
}

/**
 * Display the acknowledgements
 */
void displayAcknowledgements()
{
    displayHeader();
    printf("Artwork by: (unknown artist)\n");
    printf("View art in: https://boxes.thomasjensen.com/box-designs.html \n\n");

    displayTrophy();
    printf("Artwork by: Joan Stark (Spunk)\n");
    printf("View art in: https://asciiart.website/art/5899 \n\n");

    displayTitle();
    printf("Font from: https://patorjk.com/software/taag/#p=display&f=Star+Wars&t=MANTIS&x=none&v=4&h=4&w=80&we=false \n");
}

/**
 * The main menu of the game
 * 
 * @param players The array of registered players
 * @param topWins The array of players sorted by most to least wins
 * @param topScore The array of players sorted by highest to lowest score
 * @param numPlayers Number of registered players
 * @param currSettings The game settings
 * @param gamePlayers The players who will be playing the game
 * @param numGamePlayers Number of players who will be playing
 * @param deck The deck of cards
 * @param deckSize Number of cards in the deck
 */
void mainMenu(Player players[], Player topWins[], Player topScore[], int *numPlayers, Settings *currSettings, GamePlayer gamePlayers[], int *numGamePlayers, Card deck[], int *deckSize)
{
    int loop = 1; // variable to keep the loop going
    int choice = -1;  // where users choice will be stored
    while(loop == 1)
    {
        system("cls");
        displayTitle();
        printf("Main Menu\n");
        printf("[1] New Game\n");
        printf("[2] How To Play\n");
        printf("[3] View Statistics\n");
        printf("[4] Settings\n");
        printf("[5] Acknowledgements\n");
        printf("[0] Exit\n\n");

        printf(">> ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice)
        {
            case 1:
                system("cls");
                printf("Enjoy the game!\n");
                pressAnyKey();
                newGame(players, numPlayers, gamePlayers, numGamePlayers, deck, deckSize, *currSettings);
                break;
            case 2:
                system("cls");
                displayHowToPlay();
                pressAnyKey();
                break;
            case 3:
                displayTop10(players, topWins, topScore, *numPlayers);
                break;
            case 4:
                changeSettings(currSettings);
                break;
            case 5:
                system("cls");
                displayAcknowledgements();  
                pressAnyKey();
                break;  
            case 0:
                iSetColor(I_COLOR_CYAN);
                printf("\nMay the force be with you. Bye!");
                loop = 0; // set loop to 0 to break out the loop
                break;
            default:
                iSetColor(I_COLOR_RED);
                printf("Invalid input. Try again.");
                iSetColor(I_COLOR_WHITE);
                pressAnyKey();
        }
    }
}