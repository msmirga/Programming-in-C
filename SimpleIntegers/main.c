#include <stdio.h>
#include <stdlib.h>
//
// Project: Simple Integer Value
// Date: 9/15/2022
// Name: MacKayla Smirga
// Course: CIT-145 - FALL 22
//


//Main function
int main(void)
{
    int integer1;
    int integer2;
    int integer3;

    printf("Enter the first integer value \n");
    //prompts user to enter value
    scanf("%d", &integer1);


    printf("Enter the second integer value \n");
    //prompts user to enter value
    scanf("%d", &integer2);

    printf("Enter the third integer value \n");
    scanf("%d", &integer3);


    //variable sum
    int sum;
    sum = integer1 + integer2 + integer3;

    printf("Sum is %d\n", sum);
}
