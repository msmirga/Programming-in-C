#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//10/4/2022
//Sales-Commission Calculator


//main program
//We will ask the user for their sales information and calculate their salary
int main(void){

    float basepay;
    float commissionrate;
    float sales;
    float salary;

    basepay = 200;
    commissionrate = .09;


    //While loop, continue until user enter -1 to exit
    while (sales !=-1) {
        //Prompt user for sales.
        printf("%s", "Enter sales for the week in dollars: (-1 to end): "); //-1 is a sentinal value that terminates the program
        scanf("%f", &sales);

        //If the user did not enter -1, keep going as usual
        if (sales != -1) {

            //calculate salary
            salary = basepay + (sales * commissionrate);
            printf("Salary for the week is: $%.2f\n", salary);

        }
        else {
            printf("No data was entered. Goodbye.");
        }

    }


}
