/*
    This function validates or invalidates user input when asked to pick an option. Prints an
    error message when given an input out of the n range.

    @param      n       Number of choices.

    @return     User input, given that the input is valid.
*/

int options(int n) {
    int choice, validChoice;
    do {
        printf("--> ");
        scanf("%d", &choice);

        // BUFFER: Clears the scanf
        while (getchar() != '\n');

        if(choice >= 1 && choice <= n)
            validChoice = choice;
        else {
            // ERROR MESSAGE
        printf("Invalid Input.\n"); }

    } while (choice < 1 || choice > n);
    return validChoice;
}