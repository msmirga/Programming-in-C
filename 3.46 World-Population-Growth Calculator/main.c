#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//CIT 145
//10/4/2022
//World Population Growth Calculator

//main program
//We will ask the user for information regarding the world population, and make future population estimates off of these numbers.
int main(void){

    float population;
    float rate;
    unsigned int counter;

    counter = 1;


    //Prompt user for world population information
    printf("%s", "Enter the current world population: ");
    scanf("%f", &population);
    printf("%s", "Enter the current world population growth rate: ");
    scanf("%f", &rate);

    //calculate and display future estimated populations
    //loop for the next five years
    while (counter <= 5) {
        population = (rate * population) + population;
        printf("The estimated world population in %d year(s) is %.0f\n", counter, population);
        counter = counter + 1;

    }


}
