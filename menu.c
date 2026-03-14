/******************************************************************************
 *  Description     : Organizer for game mechanics.
 *  Author/s        : Dy, Jasmine Yzabelle
 *                    Reyes, Kaitlyn Raine
 *  Section         : S22A, S13A
 *  Last Modified   : 3 / 14 / 2026
 ******************************************************************************/
 
void lineBreak() {
    int i;
    for(i=0; i<BOARDER_SIZE_HORIZONTAL; i++)
        printf("=");
}

/*
    This function displays visuals for four choices.

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