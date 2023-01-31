#include <stdio.h>
#include <stdlib.h>
#define ISSUES 5

// MacKayla Smirga
// CIT 145
// 11/10/2022
// Polling


//The purpose of this program is to create a poll
//And allow users to rate how important certain political issues are
//On a scale from 1 to 10
//This is then documented and the data is displayed in a grid format
//It will also display averages, as well as the issues with the highest overall rating
//And the lowest overall ratings

int main(void)
{

    //Create a pointer for arrays of topics
    const char *topics[ISSUES] = {
        "Tax",
        "Environmental",
        "Reproductive Rights",
        "Local Economy",
        "Unemployment"
    };

    //Store users rating
    int rating;

    //Array to tally ratings
    int allRatings[ISSUES][10] = { 0 };

    //Array for total
    double total[ISSUES] = {0};

    //Counter used to calculate average
    double counter = 0;

    //Variable used to determine if the program should continue
    int userContinue = 1;



    //Loop until we exit the program
    while (userContinue != 2) {

        //Loop to ask questions 1-5
        for (unsigned int i = 0; i <= (ISSUES - 1); i++){

            //Ask the user questions i, using a pointer
            printf("How important are %s issues to you on a scale from 1 (least important) to 10 (most important)?: ", topics[i]);
            scanf("%d", &rating);


            //Increase total points
            total[i] = total[i] + rating;


            //Tally the rating
            allRatings[i][rating - 1]++;



        }

        counter ++;

        //ask if the user wants to exit
        printf("Do you wish to continue? \n{1: Yes}\n{2:  No}\n");
        scanf("%d", &userContinue);

        if (userContinue != 1 && userContinue != 2 ) {
            printf("Invalid entry. Do you wish to continue? \n{1: Yes}\n{2:  No}\n");
            scanf("%d", &userContinue);
        }
    }

    //User exits the program
    //Create a chart showing the results
    puts("           Ratings:   1   2   3   4   5   6   7   8   9  10   AVG\n");
    printf("%19s", "Questions:");

    //loop results for each questions
    for (unsigned int j = 0; j <= (ISSUES - 1); j++){
        //loop results for each rating
        printf("\n%19s", topics[j]);
        for (unsigned int x = 0; x <= 9; x ++){
            printf("%4d", allRatings[j][x]);
        }

        //show average rating for that issue
        printf("%6.2lf", total[j]/counter );

    }

    //Next we will be finding the issues with the lowest ratings
    //As well as the issues with the highest rating

    //first we initialize with the first element in the array
    int min = total[0];
    int max = total[0];


    //loop through the array to find the lowest rating
    for (int i = 1; i < ISSUES; ++ i) {

        //compare the element on the array
        //if that element is smaller than the min, then make that the min
        if (total[i] < min) {
            min = total[i];
        }

        //if that element is greater than the max, then make that the max
        if (total[i] > max) {
            max = total[i];
        }
    }

    //Now we are going to loop through all of the issues
    //And show that issue if it matches the lowest/highest rating
    //This way if there are multiple issues with that same rating
    //We show all of those issue

    printf("\n\nThe following issue(s) scored the lowest total rating of %d point(s):\n\n", min);

    for (int j = 0; j < ISSUES; ++ j) {
        if (total[j] == min ){
            printf("%s Issues\n", topics[j]);
        }
    }

    printf("\n\nThe following issue(s) scored the highest total rating of %d point(s):\n\n", max);

    for (int k = 0; k < ISSUES; ++ k) {
        if (total[k] == max ){
            printf("%s Issues\n", topics[k]);
        }
    }
}

