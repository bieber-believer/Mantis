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