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
 *
 *
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

