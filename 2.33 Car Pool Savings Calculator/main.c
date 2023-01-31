#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//9/29/2022
//Carpool Savings Calculator


//main program
//We will ask the user for their driving stats and use it to calculate their driving costs
int main(void)
{

    float milesperday;
    float costpergallon;
    float milespergallon;
    float parkingfees;
    float tolls;
    float total;

    //Ask the user to input their driving stats and assign them to each variable
    printf("How many total miles do you drive a day?\n");//prompt
    scanf( "%f", &milesperday);//input

    printf("What is the current cost per gallon?\n");//prompt
    scanf( "%f", &costpergallon);//input

    printf("What is your gas mileage in miles per gallon?\n");//prompt
    scanf( "%f", &milespergallon);//input

    printf("How much are your parking fees per day?\n");//prompt
    scanf( "%f", &parkingfees);//input

    printf("How much do you pay in tolls per day?\n");//prompt
    scanf( "%f", &tolls);//input

    //Calculate total cost per day
    total = (milesperday * (costpergallon/milespergallon)) + parkingfees + tolls;

    //Show user how much they could potentially save
    printf("If you started carpooling, you could save up to $%.2f per day", total);



}
