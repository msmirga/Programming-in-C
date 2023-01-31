#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//10/4/2022
//Interest Calculator

//main program
//We will ask the user for their loan information and calculate their interest
int main(void){

    float principal;
    float rate;
    int termloan;
    float interest;

    //While loop, continue until user enters -1 to exit
    while (principal !=-1) {
        //Prompt user for principal amount
        printf("%s", "Enter loan principal (-1 to end): "); //-1 is a sentinal value that terminates the program
        scanf("%f", &principal);

        //If the user did not enter -1, keep going as usual
        if (principal != -1) {

            //Prompt user for the rest of their information
            printf("%s", "Enter interest rate: ");
            scanf("%f", &rate);
            printf("%s", "Enter term of the loan in days: ");
            scanf("%d", &termloan);


            //calculate interest
            interest = principal * rate * termloan / 365;
            printf("The interest charge is: $%.2f\n", interest);

        }
        else {
            printf("No data was entered. Goodbye.");
        }

    }

}
