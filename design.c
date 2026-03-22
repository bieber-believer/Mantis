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