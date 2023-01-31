#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Project Name: Game of Crabs
// Date: 11/03/2022
// Course: Cit-145
//Name: MacKayla Smirga

//create a prototype
enum Status{CONTINUE, WON, LOST};

int rollDice(void);

//Main program function
int main(void)
{
    srand(time(NULL));

    int myPoint;
    enum Status gameStatus;
    int sum = rollDice();

    switch(sum) {

        case 7: //player WINS the game
        case 11: //player WINS the game

            gameStatus = WON;

            break;

        case 2: //player loses the game
        case 3:
        case 12:

            gameStatus = LOST;
            break;

        default:

            gameStatus = CONTINUE;
            myPoint = sum;
            printf("My points are: %d\n", myPoint);
            break;
    }

    while (CONTINUE == gameStatus){
        sum = rollDice();

        if (sum == myPoint) {
            gameStatus = WON;
        }
        else {
            if (7 == sum){
                gameStatus = LOST;
            }
        }
    }

    if (WON == gameStatus){
        puts("The player won the game!");
    }

    else {
        puts("The player lost the game. :( ");
    }
}

int rollDice(void){

    int die1 = 1 + (rand() % 6);
    int die2 = 1 + (rand() % 6);

    printf("The player rolled the dice %d + %d = %d\n", die1, die2, die1 + die2);

    return die1 + die2; //return


}
