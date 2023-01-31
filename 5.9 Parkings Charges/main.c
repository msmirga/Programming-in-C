#include <stdio.h>
#include <stdlib.h>
#define SIZE 3


// MacKayla Smirga
// CIT - 145
// 10/22/2022
// Parking Charges

//The purpose of this program is to calculate the total charges for a set number of customers in a parking garage


double calculateCharges(double hours); //function prototype


int main(void)
{

    double hours[SIZE];//create an array for how long the cars park in the garage
    double totalHours = 0;
    double charge[SIZE]; //create an array for the charges for each car
    double totalCharge = 0;


    //loop for each customer
    //prompt user for how many hours the cars were parked
    for (size_t i=0; i < SIZE; i++) {


        printf("Enter hours parked for car %zu: ", i + 1);
        scanf("%lf", &hours[i]);//enter the hours into the array
        charge[i] = calculateCharges(hours[i]);//call the calculate charges function to calculate their charge

        //add to total counts
        totalHours = totalHours + hours[i];
        totalCharge = totalCharge + charge[i];

    }


    //print out totals
    printf("%7s%9s%10s\n", "Car", "Hours", "Charge");
    //loop for each car
    for (size_t x=0; x < SIZE; x++){

        //print out how many hours and the charge for each car
        printf("%7zu%9.2lf%10.2lf\n",x + 1, hours[x], charge[x]);

    }
    //print out totals
    printf("%7s%9.2lf%10.2lf\n", "Total:", totalHours, totalCharge);


}

//this function is used to calculate the charges for each car based on how long they are parked
double calculateCharges(double hours){

    //check for amount of hours. Adjust calculations accordingly
    if (hours <= 3) {
        //flat rate for the first 3 hours
        return 2;
    }

    else {
        if (hours <= 19) {
            //base pay is two. Add that on to .5 per hour, minus the initial three hours.
            return ((hours - 3) * .5) + 2;

        }

        else {
            //Max charge is $10
            return 10;

        }
    }

}
