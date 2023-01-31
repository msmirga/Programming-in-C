#include <stdio.h>
#include <stdlib.h>

// MacKayla Smirga
// CIT 145
// 10/22/2022
// Coin Tossing

//The objective is to simulate flipping a coin 100 times
//And to print the results

int coinFlip();//prototype

//main
int main(void)
{

    //randomize random number generator using the current time
    srand(time(NULL));

    int flip;
    int tails = 0;
    int heads = 0;

    //Flip coin 100 times
    for (unsigned int i=1; i <= 100; i = i + 1) {

        //Call coin flip function
        flip = coinFlip();

        //if it is 0, it is tails
        //add to total tails counter
        if (flip == 0) {
            puts("Tails");
            tails = tails + 1;
        }

        //if it is 1, it is heads
        //add to total heads counter
        else {
            puts("Heads");
            heads = heads + 1;
        }

    }

    //print totals
    puts("Count Flip Results Out of 100");
    printf("Heads: %d\n", heads);
    printf("Tails: %d\n", tails);
}

//function used to randomly find a number between 0 and 1
//in order to simulate a coin flip
int coinFlip(){
    int flip;
    return (rand() % 2);
}
