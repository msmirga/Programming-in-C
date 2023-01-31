#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//Cit 145
//10/6/2022
//Fibonacci Calculator
//


unsigned long long int fibonacci(unsigned int n);//prototype
//works like a global variable/function
int main()
{
    unsigned int number;
    printf("%s", "Enter an integer value : ");//prompt for input
    scanf("%u", &number);//scan the input

    unsigned long long int result = fibonacci(number);

    printf("Fibonacci(%u)= %llu\n", number, result); //calculate the value of the fibonacci number

}

unsigned long long int fibonacci(unsigned int n) {

    if ( 0 == n || 1 == n) {
        return n;
    }
    else {
        return fibonacci( n - 1 ) + fibonacci(n - 2);
    }
}
