#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Project Name: Compounded Interest Calculator
//Class: CIT 145
//Date: 9/29/2022
//Name: MacKayla Smirga

int main()
{
    double principal = 5000000;
    double rate = .04;

    printf("%4s%21s\n", "Year", "Amount on Deposit");

    for(unsigned int year = 1; year <= 30; ++year){
        double amount = principal * pow(1.0 + rate, year);

        printf("%4u%21.2f\n", year, amount);
    }

}
