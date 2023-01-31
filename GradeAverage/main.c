#include <stdio.h>
#include <stdlib.h>

//
// Project: Grade Average
// Date: 9/15/2022
// Name: MacKayla Smirga
// Class: CIT-145
//
int main(void)
{
    unsigned int counter;
    int grade;
    int total;
    int average;

    //Initialize the program
    total = 0; //Initialize to zero
    counter = 1; //Initialize to one because this is a loop

    //collect grade for each assignment
    //there are 10 assignments
    while(counter <=10) {

        printf("%s", "Enter a grade: "); //Prompt the user to enter a grade
        scanf("%d", &grade); //read grade from the user
        total = total + grade;
        counter = counter + 1; //this is the increment of each grade entered
    }

    average = total/10 ;

    printf("Class average is %d\n", average);; //prints the class average

    return 0;
}
