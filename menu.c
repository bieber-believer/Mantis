/******************************************************************************
 *  Description     : Container for UI (user interface) formatting and display.
 *  Author/s        : Dy, Jasmine Yzabelle
 *                    Reyes, Kaitlyn Raine
 *  Section         : S22A, S13A
 *  Last Modified   : 3 / 14 / 2026
 ******************************************************************************/
 
void lineBreak(int n) {
    int i;
    for(i=0; i<n; i++)
        printf("=");
}

/*
    This function displays two choices.

    @param      *n1     Define string for 1st choice.
    @param      *n2     Define string for 2nd choice.
    @param      *n3     Define string for 3rd choice.
    @param      *n4     Define string for 4th choice.

*/
void display4Choices(const char *n1, const char *n2, const char *n3, const char *n4) {
    printf("[1] %s\n", n1);
    printf("[2] %s\n", n2);
    printf("[3] %s\n", n3);
    printf("[4] %s\n", n4);
}

/*
    This function displays two choices.

    @param      *n1     Define string for 1st choice.
    @param      *n2     Define string for 2nd choice.

*/
void display2Choices(const char *n1, const char *n2) {
    printf("[1] %s\n", n1);
    printf("[2] %s\n", n2);
}

/**
 * Asks the user to press the "Enter" key, then clears the terminal interface.
 *
 */

 void enter() {
    printf("Press enter to continue...\n");
    while (getchar() != '\n');
    system("cls");
 }


/**
 * Displays the array of coordinates
 * @param points The array of coordinates to be displayed
 * @param arrSize The size of the array
 */
 void displayCoodinates(Coordinate points[], int arrSize)
 {
   // NOTE: This file includes defs.h, which provides access to the
   //       Coordinate structure definition.
 
   for (int i = 0; i < arrSize; i++)
     printf("(%d, %d)  ", points[i].x, points[i].y);
 
   printf("\n\n");
 }
