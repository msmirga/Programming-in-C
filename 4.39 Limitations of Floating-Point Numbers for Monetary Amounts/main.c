#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//10/17/2022
//CIT 145
// Limitations of Floats for Monetary Amounts

//This program is used to test why we should not use floats for Monetary Amounts
//This is due to the loss of precision
int main(void)
{
    float price;

    price = 1000000.00;
    price = price + 0.12;

    printf("%.2f", price);
}
