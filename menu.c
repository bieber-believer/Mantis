void lineBreak() {
    int i;
    for(i=0; i<BOARDER_SIZE_HORIZONTAL; i++)
        printf("=");
}

void display4Choices(const char *n1, const char *n2, const char *n3, const char *n4) {
    printf("[1] %s\n", n1);
    printf("[2] %s\n", n2);
    printf("[3] %s\n", n3);
    printf("[4] %s\n", n4);
}

void gameMenu(int* startGame) {
    printf("Mantis: imagine a really cool ASCII title was here. But we're gonna prioritize that once we're done\nwith the entire logic.\n");
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');

    display4Choices(NEW_GAME, TOP_PLAYERS, SETTINGS, EXIT);
    
    switch (options(4)) {
        case 1:
            *startGame = 1;
            break;
        case 2:
            *startGame = 2;
            break;
        case 3:
            *startGame = 3;
            break;
        case 4:
            *startGame = 4;
            break;
        default:
            break;
    }
}