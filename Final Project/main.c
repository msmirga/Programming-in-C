#include <stdio.h>
#include <stdlib.h>
#define RSIZE 18
#define BJSIZE 52


// 11/25/2022
// CIT 145
// MacKayla Smirga
//Final Project


//The purpose of this project is allow the user to play two different games
//Blackjack and roulette

//Function prototypes


//Function for if the player wins
int won(int payout, int money, int betAmount);
//Function for if the player loses
int lost(int money, int betAmount);
//Ask user how much money they want to bet
int bet(int money);


//Function for drawing next card in blackjack
int drawCard(const int deck[]);
//Function for blackjack to see if the new card drawn is an ace in order to keep track of how many aces are in hand
int countAces(const int deck[]);



//Spin roulette wheel
int spinWheel(void);
//Function for playing roulette no matter the type of bet
int playRoulette(int money, int payout, const int winningNumbers[], size_t size);

//global variable
int cardNum;


//main function
int main(void)
{

    //variables


    int money = 1000; //variable for how much money the player has, start with 1000
    int betAmount;//variable for how much the user is betting
    int payout;//ratio that player wins for their bet
    unsigned int play = 0; //used to determine whether or not to keep running the program
    unsigned int input = 0; //used to determine what the player chooses on the menus


    //black jack variables
    int playerScore; //player's main score for blackjack
    int playerElevens; //counter for how many elevens the player have to deal with ace or eleven

    int dealerScore; //dealer's main score for blackjack
    int dealerElevens; //counter for how many elevens the dealer have to deal with ace or eleven


    int deck[BJSIZE];//black jack deck


    //roulette variables

    //arrays for different types of bets on the roulette wheel
    int reds[RSIZE] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int blacks[RSIZE] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    int evens[RSIZE] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
    int odds[RSIZE] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35};
    int straight[1] = {0};




    //When the program first boots up, give the user a starter amount of money
    printf("Hello, welcome to Smirga Inc games!\n");
    printf("Your starting amount of credits: $1,000 credits.\n");

    //Create a while loop. Until the user completely quits out of the program or is out of money
    while (play != 5){


        //Show a menu that allows the user to choose which game to play, or to completely quit the program
        puts("Please choose an option below.");
        printf("1. BlackJack\n2. Roulette\n3. Check Credits\n4. Rules\n5. Quit\n");

        fflush(stdin);//reset scan

        //user enters their menu choice
        if(scanf("%d", &play) == 1){
            //Use a switch statement to determine where to go to next based off of the users input in the menu
            switch (play) {

                case 1:
                //If the user chooses to play blackjack

                    //Create another while loop. This will run until the user exits to main menu
                    input = 0; //reset to 0
                    cardNum = 0;
                    while (input != 2){

                        //Display the amount of money that the user has left. Give the user the option to bet money or quit.
                        printf("Credits: $%.2d\n1. Start\n2. Quit\n", money);

                        fflush(stdin);//reset scan
                        scanf("%d", &input); //user enters their menu choice

                        switch(input) {

                            case 1:
                            //player plays the game

                                //reset variables
                                playerScore = 0;
                                playerElevens = 0;
                                dealerScore = 0;
                                dealerElevens = 0;
                                input = 0;
                                payout = 1;


                                //Ask the user how much money they want to bet on
                                betAmount = bet(money);

                                //Create a sorted deck
                                for (int x = 0; x < BJSIZE; x++){
                                    deck[x] = x + 1;
                                }

                                srand(time(NULL));//randomize random number generator using current time

                                //Shuffle the deck, go through and shuffle it 4 times
                                for (int x = 0; x < BJSIZE*4; x++){
                                    int from = rand() %BJSIZE; //randomly choose index of card to move
                                    int to = rand() %BJSIZE; //randomly choose index of card to swap with

                                    int switchCard = deck[to]; //hold the second card as a placeholder
                                    deck[to] = deck[from]; //take the first card and swap it with the second
                                    deck[from] = switchCard; //now swap the second card
                                }



                                printf("The dealer draws: ");
                                //function for drawing a new card
                                dealerScore = drawCard(deck);
                                //add a counter for how many aces the dealer has, that way we can switch to a value of 1 if they go over 21
                                dealerElevens = countAces(deck);
                                cardNum ++;
                                printf("\nThe dealer's score is: %d\n", dealerScore);

                                printf("You draw: ");
                                playerScore = playerScore + drawCard(deck);
                                //if it was an eleven, the eleven counter goes up
                                playerElevens = countAces(deck);
                                cardNum ++;

                                printf(" and ");

                                playerScore = playerScore + drawCard(deck);
                                //if it was an eleven, the eleven counter goes up
                                playerElevens = playerElevens + countAces(deck);
                                cardNum ++;
                                //if it goes over, check if we can remove an eleven
                                if (playerScore > 21 && playerElevens > 0) {
                                    playerScore = playerScore - 10;
                                    playerElevens = playerElevens - 1;
                                }
                                if (playerScore == 21) {
                                    input = 2;
                                }

                                printf("\nYour score is: %d\n", playerScore);

                                //loop until player decides to stay
                                while (input != 2){


                                    //Ask the user if they want to hit or stay
                                    printf("1. Hit\n2. Stay\n");
                                    scanf("%d", &input); //user enters their menu choice

                                    switch(input) {

                                        case 1:
                                        //If Hit, add another card
                                            printf("You draw: ");
                                            playerScore = playerScore + drawCard(deck);
                                            //if it was an eleven, the eleven counter goes up
                                            playerElevens = playerElevens + countAces(deck);
                                            cardNum ++;
                                            //if it goes over, check if we can remove an eleven
                                            if (playerScore > 21 && playerElevens > 0) {
                                                playerScore = playerScore - 10;
                                                playerElevens = playerElevens - 1;
                                            }

                                            printf("\nYour score is: %d\n", playerScore);

                                            //if the score is over 21, the player loses. Break out of the loop.
                                            if (playerScore >= 21){
                                                input = 2;
                                            }


                                            break;

                                        case 2:
                                            break;

                                        default:
                                            printf("Invalid entry. Please try again.");
                                            break;
                                    }

                                }

                                input = 0;

                                if (playerScore > 21){
                                    money = lost(money, betAmount);
                                }

                                else {
                                //if the player score is less than or equal to 21, play the dealers hand and see who wins.
                                    if (playerScore == 21) {
                                        printf("Black Jack!\n");
                                    }

                                    //dealer will only hit while their score is under 17
                                    while (dealerScore < 17){
                                        printf("The dealer draws: ");
                                        //function for drawing a new card
                                        dealerScore = dealerScore + drawCard(deck);
                                        printf("\n");
                                        //add a counter for how many aces the dealer has, that way we can switch to a value of 1 if they go over 21
                                        dealerElevens = dealerElevens + countAces(deck);
                                        cardNum ++;
                                        //if it goes over, check if we can remove an eleven
                                        if (dealerScore > 21 && dealerElevens > 0) {
                                            dealerScore = dealerScore - 10;
                                            dealerElevens = dealerElevens - 1;
                                        }
                                    }
                                    printf("The dealer's final score is: %d\n", dealerScore);

                                    //if the player has a higher score they win, or if the dealer busts they win
                                    if (playerScore > dealerScore || dealerScore > 21) {
                                        money = won(payout, money, betAmount);
                                    }

                                    //if player has a lower score they lose
                                    else if (playerScore < dealerScore) {
                                        money = lost(money, betAmount);

                                    }

                                    //if the player and dealer have the same score, it's a tie.
                                    else {
                                        printf("It's a draw\n");
                                    }

                                }

                                printf("Play again?\n");

                                break;

                            case 2:
                            //player quits

                                break;

                            default:
                                puts("Invalid entry. Please try again.");
                                break;

                        }
                    }

                    break;


                    case 2:
                    //If the user chooses to play roulette


                        //Create another while loop. This will run until the user exits to main menu
                        input = 0;//reset to 0

                        while (input != 6){

                            straight[0] = 0; //reset to 0
                            payout = 1; //payout will be 1 except for a straight bet
                            //Display the amount of money that the user has left. Give the user the option to bet or quit.
                            printf("Credits: $%.2d\n1. Straight Up Bet\n2. Red Bet\n3. Black Bet\n4. Even Bet\n5. Odd Bet\n6. Quit\n", money);

                            fflush(stdin);//reset scan

                            //user chooses what type of bet to place
                            if(scanf("%d", &input) == 1){ //if statement to check and see if the player enters an integer
                                //if the user decides to play
                                switch(input){

                                    case 1:
                                    //straight up bet

                                        //use a while statement to determine if they chose a valid number to bet on
                                        while (straight[0] < 1 || straight[0] > 36) {

                                            //Display a menu asking the user what number to bet on
                                            printf("Choose a number between 1 and 36 that you would like to bet on: ");

                                            fflush(stdin);//reset scan

                                            if(scanf("%d", &straight[0]) == 1) { //if statement to check and see if the player enters an integer
                                                if (straight[0] < 1 || straight[0] > 36) { //if statement to check and see if the plater enters a playable option
                                                    puts("Invalid entry. Please try again.");
                                                }
                                            }

                                            else {
                                                //if the player did not enter an integer, make them choose again
                                                straight[0] = 0;
                                                puts("Invalid entry. Please try again.");
                                            }


                                        }

                                        //for this type of bet, the payout is 35
                                        payout = 35;


                                        //call the playRoulette function, using the array for red numbers as winning numbers
                                        money = playRoulette(money, payout, straight, 1);

                                        break;

                                    case 2:
                                    //red bet

                                        //for this type of bet, the payout is 1
                                        payout = 1;

                                        //call the playRoulette function, using the array for red numbers as winning numbers
                                        money = playRoulette(money, payout, reds, RSIZE);
                                        break;

                                    case 3:
                                    //black bet

                                        //call the playRoulette function, using the array for black numbers as winning numbers
                                        money = playRoulette(money, payout, blacks, RSIZE);
                                        break;

                                    case 4:
                                    //even bet

                                        //call the playRoulette function, using the array for even numbers as winning numbers
                                        money = playRoulette(money, payout, evens, RSIZE);
                                        break;


                                    case 5:
                                    //odd bet

                                        //call the playRoulette function, using the array for odd numbers as winning numbers
                                        money = playRoulette(money, payout, odds, RSIZE);
                                        break;

                                    case 6:
                                        //quit
                                        break;

                                    default:
                                        puts("Invalid entry. Please try again.");
                                        break;
                                }
                            }

                            else {
                                //if the player did not enter an integer, make them choose again
                                input = 0;
                                puts("Invalid entry. Please try again.");
                            }
                        }
                        break;

                    case 3:
                    //If the user looks at the amount of credits they currently have
                        printf("Current amount of credits: $%d.\n", money);
                        break;

                    case 4:
                    //If the user looks at the rules

                        //While loop until the user quits out of this menu
                        input = 0; //reset to 0
                        while (input != 3) {
                            printf("Which set of rules would you like to review?\n1. BlackJack\n2. Roulette\n3. Quit\n");
                            fflush(stdin);//reset scan
                            scanf("%d", &input); //user select their menu choice

                            switch(input) {

                                case 1:
                                    //display the rules to blackjack
                                    printf("\nHere are the rules to Blackjack\nThe object of the game is to have the highest hand value that does not exceed 21.");
                                    printf(" The player will receive two cards face up. The dealer will receive one card face up and one card face down.");
                                    printf(" The player will then decide to \"hit\" or \"stand\". By hitting, the player will be dealt another card.");
                                    printf(" The player can hit as many times as they like until they \"bust\" by having a value greater than 21 or they stand and end their turn.");
                                    printf(" Once the player decides to stand, the dealer will deal their own hand. The player and dealer will then compare hands.\n\n");
                                    printf("Win Condition\nThe player wins if they meet these two conditions:\n1.     Their hand value does not exceed 21.\n");
                                    printf("2.     The dealer either busts or has a lower hand value.\n\n");
                                    printf("Card Values\nPip cards (2 through 10) have face value. Face cards such as Jack, Queen, and King have a value of 10.");
                                    printf(" Aces have a value of 1 or 11 depending on which value is best for the hand. Suit does not matter.\n\n");
                                    printf("Reward\nWinners will receive the amount they bet as a reward.\n\n");
                                    break;

                                case 2:
                                    //display the rules to roulette
                                    printf("\nHere are the rules to roulette\nThe object of the game is to bet on which number a wheel will land on when spun.");
                                    printf(" The wheel is numbered 0 through 36. The player can decide to bet on a single number (1 through 36),");
                                    printf(" all odd numbers, all even numbers, all numbers colored black, or all numbers colored red.\n\n");
                                    printf("Win Condition\nThe player wins if the wheel lands on the number or category of numbers they bet on.\n\n");
                                    printf("Reward\nFor all bet types except for single bets, winners will receive the amount they bet as a reward.");
                                    printf(" For a single bet, the winner will collect 35 times what they bet.\n\n");
                                    break;

                                case 3:
                                    //quit
                                    break;

                                default:
                                    puts("Invalid entry. Please try again.");
                                    break;
                            }
                        }

                        break;


                    case 5:
                    //If the user quits

                        //Display amount of money they have left
                        printf("Thanks for playing. You earned $%d credits.\n", money);
                        break;


                    default:
                    //If the user enters an invalid entry, ask them to try again and reloop

                        puts("Invalid entry. Please try again.");
                        break;

            }
        }

        else {
            //if the player did not enter an integer, make them choose again
            play = 0;
            puts("Invalid entry. Please try again.");
        }

    }

    //If the user runs out of money, the while loop will end

}



//function for drawing card in blackjack
int drawCard(const int deck[]){

    int value; //the value of the card


    //first to determine the value of the card, we will take the card number (1-52)
    //and we will find the remainder when we divide by 13.
    //We divide by 13 because there are 13 cards per suit (Ace through King)
    //The remainder will be 0-12. For simplicity, add one.
    //This will be the value of the card
    value = (deck[cardNum] % 13) + 1;

    switch(value) {

        case 1:
        //ace

            printf("Ace of ");
            value = 11;
            break;
        case 11:
        //jack

            printf("Jack of ");
            value = 10;
            break;

        case 12:
        //queen

            printf("Queen of ");
            value = 10;
            break;

        case 13:
        //king

            printf("King of ");
            value = 10;
            break;

        default:
        //all normal cards

            printf("%d of ", value);
            break;

    }


    //to find the suit, find the value of the card (1-52), subtract by one.
    //Then integer divide by 13 (so that we will get a full integer)
    //There will be four possible outcomes, 0-3
    //Depending on which outcome, assign a suit
    switch((deck[cardNum] - 1) / 13) {

        case 0:
            printf("Hearts");
            break;

        case 1:
            printf("Spades");
            break;

        case 2:
            printf("Diamonds");
            break;

        case 3:
            printf("Clubs");
            break;
    }


    return value;
}

//check if the new card drawn is an ace, and if so, raise the ace counter by one
int countAces(const int deck[]){

    int ace = 0;



    if ((deck[cardNum] % 13) + 1 == 1){
        ace = 1;

    }

    return ace;

}

//function for playing roulette
int playRoulette(int money, int payout, const int winningNumbers[], size_t size){
    //used to determine what the roulette wheel lands on
    int wheel;
    //used to determine how much the player bets
    int betAmount;
    //variable used as a boolean to help determine in the winner won or not
    unsigned int win = 0;

    //Ask the user how much money they want to bet on
    betAmount = bet(money);

    //"Spin the wheel" and see if the player won
    wheel = spinWheel();

    //check and see if its a red
    //loop through all of the values in the reds array and see if it matches what the wheel lands on
    //if so, the player wins, and we break out
    //otherwise, the player loses
    for (unsigned int x = 0; x < size; ++x) {
        if (winningNumbers[x] == wheel){
            win = 1;
            break;
        }
    }

    //If the player won
    if (win == 1) {
        money = won(payout, money, betAmount);
    }

    //If the player lost
    else {
        money = lost(money, betAmount);
    }

    return money;

}

//function to spin roulette wheel
int spinWheel(void){

    srand(time(NULL));//randomize random number generator using current time

    int wheel = (rand() % 37);

    printf("The wheel landed on: %d\n", wheel);
    return wheel;

}

//function used to ask player how much money they want to bet
int bet(int money){

    //reset bet to zero
    int betAmount = 0;


    while (betAmount == 0 ) {
        //Ask how much the user would like to bet
        printf("Enter how much you would like to bet: $");
        fflush(stdin);//reset scan

        if ((scanf("%d", &betAmount)) == 1) { //this if statement checks and makes sure a valid input has been entered
            //If the player bets more money than they have, make them rechoose
            if (betAmount > money) {
                betAmount = 0;
                printf("You only have $%.2d credits. Please bet a smaller amount.\n", money);

            }

            else {
                //if the player bets a figure less than zero, make them rechoose
                if (betAmount <= 0){
                    betAmount = 0;
                    printf("You must bet at least $1. Please bet a different amount.\n");

                }
            }
        }

        else {
            //if the player enters an invalid input, make them renter
            betAmount = 0;
            puts("Invalid entry.");
        }

    }


}

//if the user wins a game
int won(int payout, int money, int betAmount){
    money = money + betAmount*payout;
    printf("Congratulations! You won $%d.\n", betAmount*payout);
    return money;
}

//if the user loses a game
int lost(int money, int betAmount){
    money = money - betAmount;
    printf("Oh no, you lost $%d.\n");

    //check and see if player still has money
    //if the player is out of money, they can no longer play
    if (money <= 0){
        printf("You now have $0 credits.\n");
        printf("Thanks for playing!");
        exit(0);
    }

    return money;
}



