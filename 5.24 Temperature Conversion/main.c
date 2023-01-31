#include <stdio.h>
#include <stdlib.h>

// MacKayla Smirga
// CIT 145
// 10/22/2022
// Temperature Conversion

//The objective is to show two conversions charts.
//The first chart is Celsius to Fahrenheit, and the second is Fahrenheit to Celsius


double toCelsius(int fahrenheit); //function prototypes
int toFahrenheit(int celsius);

//main function
int main(void)
{

    //Show the Celsius to Fahrenheit conversion chart
    //For all Celsius temperatures from 0 to 100
    printf("%12s%12s\n", "Celsius", "Fahrenheit");

    for (unsigned int i=0; i <= 100; i++) {


        printf("%12d%12d\n", i, toFahrenheit(i));//call the to Fahrenheit function

    }

    //Show the Fahrenheit to Celsius conversion chart
    //For all Fahrenheit temperatures from 32 to 212
    printf("\n\n\n\n%12s%12s\n", "Fahrenheit", "Celsius");

    for (unsigned int x=32; x <= 212; x++) {


        printf("%12d%12.2f\n", x, toCelsius(x));//Call the to Celsius Fahrenheit function

    }


}

//function that converts a Fahrenheit temperature to Celsius
double toCelsius(int fahrenheit){
    double temperature;

    temperature = (fahrenheit - 32) * .5556;

    return temperature;

}

//function that converts a Celsius temperature to Fahrenheit
int toFahrenheit(int celsius){
    int temperature;

    temperature = celsius * 1.8000 + 32.00;

    return temperature;

}
