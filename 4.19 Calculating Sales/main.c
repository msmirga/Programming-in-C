#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//10/17/2022
//CIT 145
// Calculating Sales

//for this program, we will be calculating the total retail value of all products sold last week.
int main(void)
{
    float totalone;
    float totaltwo;
    float totalthree;
    float totalfour;
    float totalfive;
    int product;
    int quantity;


    //loop until user exits
    while (product != -1) {

        //Ask the user for product code
        printf("%s", "Please enter product number.\nHit '-1' to exit.\n");
        scanf("%d", &product);

        //If the user does not exit, prompt for quantity sold
        if (product != -1) {
            printf("%s", "Please enter quantity sold.\n");
            scanf("%d", &quantity);

            //determine the product that was entered and add the price to the total for the week for that product.
            switch (product) {

                case 1:
                    totalone = quantity * 2.98;
                    break;

                case 2:
                    totaltwo = quantity * 4.50;
                    break;

                case 3:
                    totalthree = quantity * 9.98;
                    break;

                case 4:
                    totalfour = quantity * 4.49;
                    break;

                case 5:
                    totalfive = quantity * 6.87;
                    break;

                case '\n':
                case '\t':
                case ' ':
                    break;

                default: //catch all invalid characters
                    puts("Invalid entry. Please try again.");
            }
        }


    }

    //display summary for everything sold this week
    puts("\nTotal income for each product sold this week:");
    printf("Product 1: $%.2f\n", totalone);
    printf("Product 2: $%.2f\n", totaltwo);
    printf("Product 3: $%.2f\n", totalthree);
    printf("Product 4: $%.2f\n", totalfour);
    printf("Product 5: $%.2f\n", totalfive);

}
