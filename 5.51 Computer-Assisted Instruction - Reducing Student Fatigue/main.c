#include <stdio.h>
#include <stdlib.h>

// MacKayla Smirga
// CIT 145
// 10/29/2022
//Computer Assisted Instruction - Reducing Student Fatigue

//The objective is to generate multiplication problems
//and testing a student on the answer.
//To keep the student engaged, the program will also
//vary the responses it provides the student

//prototypes
int newQuestion();
void correct();
void incorrect();

//main
int main(void)
{

    //randomize using current time
    srand(time(NULL));

    int answer;
    int studentAnswer;
    puts("Hello, please answer the following questions. Enter '-1' to quit.");
    //ask questions until student quits
    while (studentAnswer != -1) {

        //Call question function and get the answer
        answer = newQuestion();
        //get the student's Answer
        scanf("%d", &studentAnswer);

        //if the student is correct, keep going
        if (answer == studentAnswer) {
            //call function to generate positive statement
            correct();
        }

        //if the student is incorrect, loop until the student answers correctly
        else {
            while (answer != studentAnswer && studentAnswer != -1){
                //call function to generate statement to try again
                incorrect();
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

    //create question based off of integers
    printf("How much is %d times %d?\n", first, second);

    //return answer
    return first * second;

}

//if the student answers correctly, generate a random positive statement
void correct(){

    int x;

    //randomize between 0 through 4
    x = rand() % 4;

    //use random generated number to choose which statement to use
    switch(x){

        case 0:
            puts("Very good!");
            break;

        case 1:
            puts("Excellent!");
            break;

        case 2:
            puts("Nice work!");
            break;

        case 3:
            puts("Keep up the good work!");
            break;

    }
}

//if the student answers incorrectly, generate a random statement to have them try again
void incorrect(){

    int y;

    //randomize between 0 through 4
    y = rand() % 4;

    //use the randomly generate number to choose which statement to use
    switch(y){

        case 0:
            puts("No. Please try again.");
            break;

        case 1:
            puts("Wrong. Try again.");
            break;

        case 2:
            puts("Don't give up!");
            break;

        case 3:
            puts("No, keep trying.");
            break;

    }
}
