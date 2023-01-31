#include <stdio.h>
#include <stdlib.h>
#define SIZE 15 // defined size of the array
int main()
{
    int s[SIZE]; //array size

    for (size_t j = 0; j <SIZE; ++j){ //for loop to iterate the size
        s[j] = 2 + 2 * j;
    }

    printf("%s%13s\n", "Element", "Value"); //print out of the elements and corresponding position
    for (size_t j = 0; j <SIZE; ++j) {
            printf("%7u%13d\n", j, s[j]);
    }
}
