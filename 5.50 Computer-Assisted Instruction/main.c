#include <stdio.h>
#include <stdlib.h>

// MacKayla Smirga
// CIT 145
// 10/29/2022
// Computer Assisted Instruction


//The objective is to generate multiplication problems
//And test students to input the correct answer

int newQuestion(); // prototype

//main
int main(void)
{

    //use the current time in order to randomize the random number generator
    srand(time(NULL));

    int answer;
    int studentAnswer;

    puts("Hello, please answer the following questions. Enter '-1' to quit.");

    //ask questions until student quits
    while (studentAnswer != -1) {

        //Call question function and calculate the answer
        answer = newQuestion();
        //get the student's Answer
        scanf("%d", &studentAnswer);

        //if the student is correct, keep going
        if (answer == studentAnswer) {
            puts("Very good!");
        }

        //if the student is incorrect, loop until the student answers correctly
        else {
            while (answer != studentAnswer && studentAnswer != -1){
                puts("No, please try again.");
                //get student's new answer
                scanf("%d", &studentAnswer);
            }
            //once the student answer's correctly, congratulate them
            if (answer == studentAnswer) {
                puts("Very good!");
            }
        }

    }
}

//function used to generate a question
int newQuestion(){

    //generate two random positive one-digit integers
    int first = 1 + (rand() % 9);
    int second = 1 + (rand() % 9);

    //create question based off of generate integers
    printf("How much is %d times %d?\n", first, second);

    //return answer
    return first * second;

}
