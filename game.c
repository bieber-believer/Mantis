/******************************************************************************
 *  Description     : Container for utility functions such as input handling and basic operations.
 *  Author/s        : Dy, Jasmine Yzabelle
 *                    Reyes, Kaitlyn Raine
 *  Section         : S22A, S13A
 *  Last Modified   : 3 / 19 / 2026
 ******************************************************************************/

#ifndef GAME_C
#define GAME_C

/*
    This function validates or invalidates user input when asked to pick an option. Prints an
    error message when given an input out of the n range.

    @param      lim     Lower limit of valid choices.
    @param      n       Number of choices.

    @return     User input, given that the input is valid.
*/

int options(int lim, int n) {
    int choice, validChoice;
    do {
        printf("--> ");
        scanf("%d", &choice);

        // BUFFER: Clears the scanf
        while (getchar() != '\n');

        if(choice >= lim && choice <= n)
            validChoice = choice;
        else {
            // ERROR MESSAGE
        printf("Invalid Input.\n"); }

    } while (choice < 1 || choice > n);
    return validChoice;
}

/*
  This function allows the user to input strings with spaces.

    @param  str   Starting address of the string.
*/
void getSpString(char *str) {
  char ch;
  int i = 0;

  do {
    scanf("%c", &ch);
    if(ch != '\n') {
      str[i++] = ch;
      str[i] = '\0'; 
    }
  } while(ch != '\n');

}

void loadPlayers(int* playerCount, Player playerFile[], FILE *fPtr, FILE *fPtr2) {
    Player buffer;
    
    if(fPtr == NULL || fPtr2 == NULL) {
      printf("Error! No file detected.\n");
    }

    else {

    while(fgets(buffer.name, 37, fPtr) != NULL) {
      buffer.name[strlen(buffer.name) - 1] = '\0';

      fscanf(fPtr2, "%d %d", &buffer.wins, &buffer.highestScore);

      if(strcmp(buffer.name, "") != 0) {
        strcpy(playerFile[*playerCount].name, buffer.name);
        playerFile[*playerCount].wins = buffer.wins;
        playerFile[*playerCount].highestScore = buffer.highestScore;
        (*playerCount)++;
        }
      
      }
    }
    fclose(fPtr);
    fclose(fPtr2);
  }

/**
 * This function will ask for the number of players
 * 
 * @return  The number of players
 */

 int getNumPlayers(){
  int numPlayers;

  do{
      printf("How many players? ");
      scanf("%d", &numPlayers);
      while (getchar() != '\n');

      if(numPlayers < 3 || numPlayers > 6)
          printf("Input again. A minimum of 3 players and a maximum of 6 players.\n");
  } while(numPlayers < 3 || numPlayers > 6);

  return numPlayers;
}

 /**
  * Asks the new player for their username and add them as a new player
  * 
  * @param playing The array where the new player will be stored
  * @param numRegPlayer The current number of registered players
  */
  void registerPlayer(Player playing[], int *numRegPlayer)
  {
    FILE *fPtr;
    FILE *fPtr2;
    User username;

    printf("Input username: ");
    getSpString(username);

    strcpy(playing[*numRegPlayer].name, username);
    playing[*numRegPlayer].wins = 0;
    playing[*numRegPlayer].highestScore = 0;

    fPtr = fopen(PLAYER_DATA, "a");
    fPtr2 = fopen(PLAYER_STATS, "a");
    fprintf(fPtr, "\n%s", playing[*numRegPlayer].name);

    fprintf(fPtr, "\n%d %d", playing[*numRegPlayer].wins, playing[*numRegPlayer].highestScore);
    (*numRegPlayer)++;

    fclose(fPtr);
    fclose(fPtr2);

 }

//  /**
//   * This functions allows the user to select the players of the game.
//   * 
//   * @param player            The list of past players.
//   * @param numRegPlayer      The current number of registered players
//   * @param totalPlaying      The number of players that will be playing
//   * @param playing           The array of players that will be playing
//   */
 void playerSelection(int playerListCount, Player players[], int* numRegPlayer, int totalPlaying, Player playing[]){
  int i;
  int choice = options(0, playerListCount);
  // DISPLAY
  printf("[0] <add new player>\n");
  
  while((*numRegPlayer) < totalPlaying) {
  for(i=0;i<playerListCount;i++) {
    printf("[%d] %s", i+1, players[i].name);
  }
  if((choice-1) == 0)
    registerPlayer(playing, numRegPlayer);
  else {
    
  }
  }


}

#endif // GAME_C