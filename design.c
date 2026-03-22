/******************************************************************************
 *  Description     : Handles the ASCII art display and UI helper functions
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defsDy.h"

/* ----- function implementation ----- */

/**
 * Displays the title "Mantis"
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
 * Asks user to press any key in order to continue
 */
void pressAnyKey()
{
    iHideCursor();
    printf("\nPress any key...\n");
    getchar();
    iShowCursor();
}

/**
 * Displays a header to be shows each turn
 */
void displayHeader()
{
    printf("         _\\|/_\n");
    printf("         (o o)\n");
    printf(" +----oOO-{_}-OOo---------------------+\n");
    printf(" |                                    |\n");
    printf(" |          M  A  N  T  I  S          |\n");
    printf(" |           Game Ongoing             |\n");
    printf(" |                                    |\n");
    printf(" +------------------------------------+\n\n");
}

/**
 * Displays the drawn card in an ASCII card
 * 
 * @param Card The drawn card
 */
void displayDrawnCard(Card card)
{
    printf(".-----.\n");
    printf("|  %c  |\n", card.front);
    printf("|     |\n");
    printf("|  %d  |\n", card.point);
    printf(".-----.\n");
}