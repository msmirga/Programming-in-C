#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//10/20/2022
//CIT 145
// The Twelve Days of Christmas

//This program practices uses switch statements in order to write the song "The Twelve Days of Christmas".

int main(void)
{
    unsigned int counter = 1; //start on the first day


    //loop until the song finishes (we reach 13 days)
    while (counter < 13) {

        //Start the verse
        printf("\nOn the ");
        //determine what day it is
        switch (counter) {

        case 1:
            printf("first");
            break;

        case 2:
            printf("second");
            break;

        case 3:
            printf("third");
            break;

        case 4:
            printf("fourth");
            break;

        case 5:
            printf("fifth");
            break;

        case 6:
            printf("sixth");
            break;

        case 7:
            printf("seventh");
            break;

        case 8:
            printf("eighth");
            break;

        case 9:
            printf("ninth");
            break;

        case 10:
            printf("tenth");
            break;

        case 11:
            printf("eleventh");
            break;

        case 12:
            printf("twelfth");
            break;


        }

        printf(" day of Christmas\nMy true love sent to me\n");

        switch (counter) {

        case 12:
            puts("Twelve Drummers Drumming");

        case 11:
            puts("Eleven Pipers Piping");

         case 10:
            puts("Ten Lords a Leaping");

        case 9:
            puts("Nine Ladies Dancing");

        case 8:
            puts("Eight Maids a Milking");

        case 7:
            puts("Seven Swans a Swimming");

        case 6:
            puts("Six Geese a Laying");

        case 5:
            puts("Five Golden Rings");

        case 4:
            puts("Four Calling Birds");

       case 3:
            puts("Three French Hens");

        case 2:
            puts("Two Turtle Doves, And");

        case 1:
            puts("A Partridge In A Pear Tree");

        }
        counter++;

    }
}
