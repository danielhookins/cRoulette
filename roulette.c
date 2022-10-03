#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "roulette.h"

int main() {
    // init rand    
    time_t t = time(NULL);
    srand(t);

    // print random number between 0 - 37
    printf("result:\t%d\n", getRandom());

    return(0);
}

int getRandom() {
    return rand() % 37;
}