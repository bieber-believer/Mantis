/******************************************************************************
 *  Description     : This function handles the menu
 *  Author/s        : <student1 full name (last name, first name)>
 *                    <student2 full name (last name, first name)>
 *  Section         : S22A
 *  Last Modified   : March 16, 2026
 ******************************************************************************/

 /* ----- preprocessor directives ----- */
#include <stdio.h>
#include<string.h>

#include "defs.h"


//===========================================
//          Function Implementation
//===========================================

/**
 * Display the title
 */
void displayTitle()
{
    iSetColor(I_COLOR_RED);
    printf(".___  ___.      ___      .__   __. .___________. __       _______.\n");
    iSetColor(I_COLOR_YELLOW);
    printf("|   \\/   |     /   \\     |  \\ |  | |           ||  |     /       |\n");
    iSetColor(I_COLOR_GREEN);
    printf("|  \\  /  |    /  ^  \\    |   \\|  | `---|  |----`|  |    |   (----`\n");
    iSetColor(I_COLOR_BLUE);
    printf("|  |\\/|  |   /  /_\\  \\   |  . `  |     |  |     |  |     \\   \\    \n");
    iSetColor(I_COLOR_CYAN);
    printf("|  |  |  |  /  _____  \\  |  |\\   |     |  |     |  | .----)   |  \n");
    iSetColor(I_COLOR_PURPLE);
    printf("|__|  |__| /__/     \\__\\ |__| \\__|     |__|     |__| |_______/    \n");
    iSetColor(I_COLOR_WHITE);
}

/**
 * Displays the tutorial of the game
 */
void displayHowToPlay()
{
    printf("The cards in Mantis are two sided. Each card has three different colors\n");
    printf("on the back and only one color on the front. One of the three colors on the back\n");
    printf("of the card is the color that in on the front of the card.\n\n");

    printf("To start the turn, you have to choose between one of the two actions:\n");
    printf("-Try to Score\n-Try to Steal\n\n");

    printf("When you decide to try and score, you will draw the top card from the Draw Pile.\n");
    printf("Flip the card over and put it in your Tank. If the new card matches any existing card(s)\n");
    printf("in your Tank, add the new card and all matching color cards to your Score Pile.\n");
    printf("If the card does not match any of the cards already in your Tank, add it.\n\n");

    printf("Your other option is to try to steal. First, decide which player you'll try to steal from.\n");
    printf("Then, flip over the top card from the Draw Pile. If the new card's color corresponds to one or\n");
    printf("more cards in the chosen player's Tank, place the new card and any matching cards in your own\n");
    printf("Tank. If the card does not match any of the cards in front of the chosen player, you will place the\n");
    printf("new card in the chosen player's Tank.\n\n");

    printf("The first player to get a score higer or equal to the winning points win.\n\n");

    printf("Source: https://www.geekyhobbies.com/mantis-rules/ \n");
}

/**
 * Displays the acknowledgements
 */
void displayAcknowledgements()
{
    displayHeader();
    printf("Artwork by: (unknown artist)\n");
    printf("View art in: https://boxes.thomasjensen.com/box-designs.html \n\n");

    displayTitle();
    printf("Font from: https://patorjk.com/software/taag/#p=display&f=Star+Wars&t=MANTIS&x=none&v=4&h=4&w=80&we=false \n");
}

/**
 * Compiles the functions needed for a new game
 */
void newGame(Player players[], int *numPlayers, GamePlayer gamePlayers[], int *numGamePlayers, Card deck[], Card gameDeck[], int *gameDeckSize, Settings currSettings)
{
    system("cls");
    //call getNumPlaying()
    getNumPlaying(numGamePlayers);
    //call playerSelection()
    playerSelection(players, numPlayers, gamePlayers, *numGamePlayers);
    //call gameStart()
    gameStart(players, *numPlayers, gamePlayers, *numGamePlayers, deck, gameDeck, gameDeckSize, currSettings);
}

/**
 * Sorts the players by their wins in descending order
 * 
 * @param players The array with all the players
 * @param topWins The array where the top 10 players will be stored
 * @param numPlayers The number of players that are registered
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
 * Sorts the players by their score in descending order
 * 
 * @param players The array with all the players
 * @param topScore The array where the top 10 players will be stored
 * @param numPlayers The number of players that are registered
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
 * Display the top 10 Players with the highest win
 * 
 * @param players Array of all registered players
 * @param topWins Array where the sorted players get stored
 * @param numPlayers Number of registered players
 */
void displayTop10ByWins(Player players[], Player topWins[], int numPlayers)
{
    int i;

    sortByWins(players, topWins, numPlayers);

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
 * Display the top 10 Players with the highest score  
 * 
 * @param players Array of registered players
 * @param topScore Array where the sorted players gets stored
 * @param numPlayers Number of registered players
 */
void displayTop10ByScore(Player players[], Player topScore[], int numPlayers)
{
    int i;

    sortByScore(players, topScore, numPlayers);

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
 * Asks user how they wanna view the top 10 players then displays the top 10 of their chosen choice
 * 
 * @param players Array of registered players
 * @param topWins Array where the players with the highest wins are stored in descending order
 * @param topScore Array where the players with the highest scores are stored in descending order
 * @param numPlayers Number of registered players
 */
void displayTop10(Player players[], Player topWins[], Player topScore[], int numPlayers)
{
    int loop = 1;
    int choice;

    while(loop == 1)
    {
        if(numPlayers == 0)
        {
            system("cls");
            printf("No player has played :(\n\n");
            printf("Press any key...\n");
            getchar();
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
                    displayTop10ByWins(players, topWins, numPlayers);
                    printf("\nPress any key to go back...\n");
                    getchar();
                    loop = 0; // user goes back to main menu
                    break;
                case 2:
                    system("cls");
                    displayTop10ByScore(players, topScore, numPlayers);
                    printf("\nPress any key to go back...\n");
                    getchar();
                    loop = 0; // user goes back to main menu
                    break;
                case 0:
                    loop = 0;
                    break;
                default:
                    printf("Invalid input. Try again.\n");
                    printf("\nPress any key to go back...\n");
                    getchar();
            }
        }
    }
}

/**
 * Allows the user to change the wining points and shuffle seed
 * 
 * @param currSettings The current game settings to be changed
 * 
 * @pre initRandom has been called already
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

        printf("Change Settings?\n");
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
                printf("\nNew Winning Points?\n");
                printf(">> ");
                scanf("%d", &currSettings->winningPoints);
                while(getchar() != '\n');
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
                printf("Press any key...\n");
                getchar();
                break;
            case 0:
                loop = 0;
                break;
            default:
                printf("Invalid input. Try again.\n");
                printf("Press any key...\n");
                getchar();
        }
    }
}

/**
 * The main menu of the game
 * 
 * @param players The array of registered players
 * @param topWins The array where the players are sorted by their wins
 * @param topScore The array where the players are sorted by their highest scores
 * @param numPlayers The number of registered players
 * @param currSetting The current game settings
 * @param numGamePlayers
 */
void mainMenu(Player players[], Player topWins[], Player topScore[], int *numPlayers, GamePlayer gamePlayers[], Settings *currSettings, int *numGamePlayers, Card deck[], Card gameDeck[], int *gameDeckSize)
{
    int loop = 1; // variable to keep the loop going
    int choice;  // where users choice will be stored
    while(loop == 1)
    {
        system("cls");
        displayTitle();
        printf("\nMain Menu\n");
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
                printf("Enjoy the game!\n\n");
                printf("Press any key...\n");
                getchar();
                newGame(players, numPlayers, gamePlayers, numGamePlayers, deck, gameDeck, gameDeckSize, *currSettings);
                break;
            case 2:
                system("cls");
                displayHowToPlay();
                printf("\nPress any key...\n");
                getchar();
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
                printf("\nPress any key...\n");
                getchar();
                break;  
            case 0:
                printf("\nMay the force be with you. Bye!");
                loop = 0; // set loop to 0 to break out the loop
                break;
            default:
                printf("Invalid input. Try again.");
                printf("Press any key...\n");
                getchar();
        }
    }
}