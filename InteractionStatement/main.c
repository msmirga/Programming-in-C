#include <stdio.h>
#include <stdlib.h>

//Project Name: While Iteration Statement
//Date: 9/29/2022
//MacKayla Smirga

int main()
{
    unsigned int counter;
    int grade;
    int total;

    float average;

    total = 0;
    counter = 0;

    printf("%s", "Enter a grade, -1 to end: "); //-1 is a sentinal value that terminates the program
    scanf("%d", &grade);

    //loop until user terminates the program
    while (grade !=-1){
        total = total + grade;
        counter = counter + 1;

        printf("%s", "Enter a grade, -1 to end: ");
        scanf("%d", &grade);
    }
    if (counter != 0 ) {
            average = (float) total/counter;

            printf("Class average is %.2f\n", average);
            //end of if statement
        }

        else {
            puts("No grades were entered");
        }
}
