#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//9/29/2022
//BMI Calculator


//main program
//We will ask the user for their stats and use it to calculate their BMI
int main(void)
{
    int weight;
    int height;
    int bmi;

    //prompt the user for their weight and record the variable
    printf("Please enter your weight in pounds:");
    scanf( "%d", &weight );

    //prompt the user for their height and record the variable
    printf("Please enter your height in inches: ");
    scanf( "%d", &height);

    //Calculate BMI
    bmi = (weight * 703)/(height * height);


    //Show the user's BMI and what categories the BMIs fall in
    printf("Your Body Mass Index is %d\n", bmi);
    printf("BMI VALUES\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\nOverweight: between 25 and 29.9\nObese: 30 or greater\n");


}
