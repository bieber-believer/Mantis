/******************************************************************************
 *  Description     : Container for utility functions such as input handling and basic operations.
 *  Author/s        : Dy, Jasmine Yzabelle
 *                    Reyes, Kaitlyn Raine
 *  Section         : S22A, S13A
 *  Last Modified   : 3 / 15 / 2026
 ******************************************************************************/




#ifndef GAME_C
#define GAME_C

/*
    This function validates or invalidates user input when asked to pick an option. Prints an
    error message when given an input out of the n range.

    @param      n       Number of choices.

    @return     User input, given that the input is valid.
*/

#ifndef GAME_C
#define GAME_C

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



 void createPlayer() {


 }




 /**
 * Copies the contents of one array of coordinates to another
 * @param dest The destination array
 * @param src The source array
 * @param arrSize The size of the arrays
 */
void copyCoordinates(Coordinate dest[], Coordinate src[], int arrSize)
{
  for (int i = 0; i < arrSize; i++)
    dest[i] = src[i];
}

/**
 *  Computes the average of the non-negative numbers from a given list of numbers
 *  @param arr The starting address of the array containing the list of numbers
 *  @param arrSize The size of the array
 *  @return The average of the non-negative numbers from the list of numbers
 *  @pre arr can include positive numbers, negative numbers, and zeros
 *  @pre arrSize is the correct size of arr
 */
 float getAverage(int arr[], int arrSize)
 {
   float average;
   int sum = 0, n = 0, i;
 
   for (i = 0; i < arrSize; i++)
     if (arr[i] >= 0)
     {
       sum += arr[i];
       n++;
     }
 
   if (n == 0) // prevent divide by zero
     average = 0;
   else
     average = sum / (float)n;
 
   return average;
 }

 #endif // GAME_C