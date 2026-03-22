/******************************************************************************
 *  Description     : Handles the functions for file processing
 *  Author/s        : Dy, Jasmine Yzabelle
 *  Section         : S22A
 *  Last Modified   : March 22, 2026
 ******************************************************************************/

/* ----- preprocessor directives ----- */
#include <stdio.h>

#include "defsDy.h"

/* ----- function implementation ----- */

/**
 * Reads the mantis.txt file and stores it in a struct array
 * 
 * @param deck The array where the cards will be stored
 */
void mantisToStruct(Card deck[])
{
    int i;
    FILE *fp;
    fp = fopen("mantis.txt", "r");

    for(i = 0; i < TOTAL_CARDS; i++){
        fscanf(fp," %c | %3s %d", &deck[i].front, deck[i].back, &deck[i].point);
    }

    fclose(fp);
}