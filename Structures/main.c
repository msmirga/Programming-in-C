#include <stdio.h>
#include <stdlib.h>

// Name: MacKayla
// Course: CIT 415
// Project: Structured Program Development
// Data: 9-22-2022


//main program function
int main(void)
{
    //initialize the variables
    unsigned int passes = 0;
    unsigned int failures = 0;
    unsigned int student = 1;
    int result;

    //prompt user for results
    while (student <=10){
        printf("%s", "ENTER RESULT (1 = pass, 2 = fail)");
        scanf("%d", &result);

        //determine if the result is a pass or fail, add to the variables
        if (result == 1){
            passes = passes + 1;
        }
        else {
            failures = failures + 1;
        }
        student = student + 1;
    } //end the loop

    //display results
    printf("Passed %u\n", passes);
    printf("Failed %u\n", failures);

    if (passes >= 8) {
        puts("You earned a bonus from the instructor!");
    }
    else {
        puts("Sorry, you did not pass, try again!");
    }
}
