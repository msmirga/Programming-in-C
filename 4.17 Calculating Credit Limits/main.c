#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//10/17/2022
//CIT 145
// Calculating Credit Limits

//for this program, we will be calculating the new credit limit for three customers
//and determining if their current balance exceeds their credit limit
int main(void)
{

    int acct;
    float oglimit;
    float balance;
    float newlimit;


    //Run for three customers
    for (unsigned int counter = 1; counter <= 3; ++counter){
        printf("Customer #%lu\n", counter);

        //prompt for customer account number
        printf("%s", "Enter account number: ");
        scanf("%d", &acct);

        //prompt for customer's original credit limit
        printf("%s", "Enter original credit limit: $");
        scanf("%f", &oglimit);

        //prompt for customer's current balance
        printf("%s", "Enter current balance: $");
        scanf("%f", &balance);

        //calculate new credit limit
        newlimit = oglimit * .5;
        printf("For account #%d, the new credit limit is $%.2f.\n", acct, newlimit);

        //determine in balance is over credit limit
        if (newlimit < balance) {
            printf("The current balance of $%.2f exceeds the new credit limit.\n", balance);
        }
        //extra spacing for formatting
        printf("\n");
    }

    printf("Program terminated. Goodbye.");
}
