#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//10/4/2022
//Gas Mileage


//main program
//We will ask the user for their gas used and miles driven each day and calculate total gas mileage
int main(void){
    float gallons;
    float totalgallons;
    float miles;
    float totalmiles;
    float milespergallon;
    float totalmilespergallon;
    unsigned int counter;

    totalgallons = 0;
    totalmiles = 0;
    totalmilespergallon = 0;
    counter = 0;

    //While loop, continue until user enter -1 to exit
    while (gallons !=-1) {
        //Prompt user for gallons used
        printf("%s", "Enter amount of gallons used today (-1 to end): "); //-1 is a sentinal value that terminates the program
        scanf("%f", &gallons);

        //If the user did not enter -1, keep going as usual
        if (gallons != -1) {

            //Prompt user for miles
            printf("%s", "Enter miles driven today: ");
            scanf("%f", &miles);

            //sum totals
            totalgallons = totalgallons + gallons;
            totalmiles = totalmiles + miles;

            //Calculate current days mile per gallon
            milespergallon = miles/gallons;
            printf("The miles per gallon for this tank were: %.2f\n", milespergallon);

            counter = counter + 1;
        }
        //If the user did enter -1, check if they had already entered data (if the counter is greater than zero). If they did, calculate the total.
        else if (counter!=0){
            totalmilespergallon = (totalmiles/totalgallons)/counter;
            printf("The overall average miles per gallon were: %.2f\n", totalmilespergallon);
        }
        //If the user did enter - 1 and the counter is at 0, then do not calculate anything
        else {
            printf("No data was entered. Goodbye.");
        }

    }


}
