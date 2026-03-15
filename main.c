/**
* Description : This is an iteration of the colorful card game, "Mantis" in C Programming Language. This is in fulfillment of our major requirement for CCPROG2 to
*               showcase the programming concepts learned throughout the course. // Unfinished description
* Author/s : Dy, Jasmine Yzabelle Young
*           Reyes, Kaitlyn Raine Panergo
* Section : S22A, S13A
* Last Modified : 2/22/2026
* Acknowledgments : <list of references used in the making of this project> // uwu
*/

//--------------------------------------------------
// Preprocessor Directives
//--------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//--------------------------------------------------
// Definitions
//--------------------------------------------------

#include "defs.c" // Organizer file for user-defined functions such as macros and dialogue.
#include "game.c" // Structure for the entire logic of the game.
#include "mechanics.c" // Structure for the mechanics of the game.
#include "menu.c" // Separate file to help control the functions of the game.



int main () {
    int gameState = 1;

    printf("Mantis: imagine a really cool ASCII title was here. But we're gonna prioritize that once we're done\nwith the entire logic.\n");
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');

    display4Choices(NEW_GAME, TOP_PLAYERS, SETTINGS, EXIT);
    
    while(gameState) {
    switch (options(4)) {
        case 1: // Starts a new game
            system("cls");
            // gameLoop()
            break;
        case 2: // Displays Leaderboard
            system("cls");
            // topPlayers();
            break;
        case 3: // Displays Settings
            system("cls");    
            // settings();
            break;
        case 4: // Ends Program
            gameState = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}

/**
* This is to certify that this project is my/our own work, based on my/our personal
* efforts in studying and applying the concepts learned. I/We have constructed the
* functions and their respective algorithms and corresponding code by myself/ourselves.
* The program was run, tested, and debugged by my/our own efforts. I/We further certify
* that I/we have not copied in part or whole or otherwise plagiarized the work of other
* students and/or persons, nor did I employ the use of AI in any part of the deliverable.
*
* Dy, Jasmine Yzabelle Young (DLSU ID# 12504254)
* Reyes, Kaitlyn Raine Panergo (DLSU ID# 12525006)
*/