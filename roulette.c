#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "roulette.h"


/**
 * Roulette Engine
 */
int main(void)
{
    // seed the random number generator
    srand(time(NULL));
    
    // Get the result
    animate_spin();
    int result = get_result();

    // Get the result as a string
    char *result_string = get_result_string(result);

    // Get the colour of the result
    char *colour = get_colour(result);

    // get the parity of the result
    char *odd_even = get_odd_even(result);

    // Print the result
    printf("\rThe result is %s, this is %s and it's parity is %s", result_string, colour, odd_even);

    // free malloc'd memory
    free(result_string);
    free(colour);
    free(odd_even);

    return 0;
}

/*
 * Spin the wheel and return a number
 */
int get_result(void)
{
    // spin wheel and return number between 0 and 37
    int num = rand() % 38;
    return num;
}

/*
 * Get a human readable string for the result
 * this is a number between 0 and 36, or 00 for 37
 */
char *get_result_string(int result){
    // Malloc a string to hold the result
    char *result_string = malloc(2);

    if (result == 37) {
        result_string = "00";
    } else {
        sprintf(result_string, "%d", result);
    }
    return result_string;
}

/*
* Determine whether the result is red or black or green
*/
char *get_colour(int result)
{
    // Malloc a string to hold the result
    char *colour = malloc(5);

    // number ranges 1-10 and 19-28, 
    // even numbers are black and
    // odd numbers are red
    if (result >= 1 && result <= 10 || result >= 19 && result <= 28) {
        if (result % 2 == 0) {
            colour = "black";
        } else {
            colour = "red";
        }
    }
    // number ranges 11-18 and 29-36, 
    // odd numbers are red and
    // even numbers are black
    else if (result >= 11 && result <= 18 || result >= 29 && result <= 36) {
        if (result % 2 == 0) {
            colour = "red";
        } else {
            colour = "black";
        }
    }
    // 0 and 00 are green
    else {
        colour = "green";
    }

    return colour;
}

/*
* Determine whether the result is odd, even or N/A
*/
char *get_odd_even(int result)
{
    // Malloc a string to hold the result
    char *odd_even = malloc(4);

    if (result == 37 || result == 0) {
        odd_even = "N/A";
    } else if (result % 2 == 0) {
        odd_even = "even";
    } else {
        odd_even = "odd";
    }
    return odd_even;
}

/*
* Animate the wheel spinning
*/
void animate_spin(void)
{
    char spinners[] = { '|', '/', '-', '\\' };
    clock_t start_time = clock();
    
    while (1) {
        for (int i = 0; i < 4; i++) {
            printf("\r%c", spinners[i]);
            fflush(stdout);
            usleep(100000);

            if((clock() - start_time)/CLOCKS_PER_SEC > 3) {
                fflush(stdout);
                return;
            }
        }
    }
}