#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//10/4/2022
//Salary Calculator

//main program
//We will ask the user for employee information and calculate the salary
int main(void){

    float hours;
    float otrate;
    float rate;
    float salary;

    otrate = 1.5;

    //While loop, continue until user enters -1 to exit
    while (hours !=-1) {
        //Prompt user for principal amount
        printf("%s", "Enter the amount of hours worked this week: (-1 to end): "); //-1 is a sentinal value that terminates the program
        scanf("%f", &hours);

        //If the user did not enter -1, keep going as usual
        if (hours != -1) {

            //Prompt user for hourly rate
            printf("%s", "Enter hourly rate of the worker: ");
            scanf("%f", &rate);


            //calculate salary. if it is under 40 hours, calculate straight time. If it is over, calculate overtime
            if (hours <= 40) {
                salary = hours * rate;
            }

            else {
                hours = hours - 40;
                salary = (40 * rate) + (hours * otrate * rate);
            }

            printf("This employee's salary for the week is: $%.2f\n", salary);

        }
        else {
            printf("No data was entered. Goodbye.");
        }

    }
}
