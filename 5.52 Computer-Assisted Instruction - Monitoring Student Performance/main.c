#include <stdio.h>
#include <stdlib.h>


// MacKayla Smirga
// CIT 145
// 10/29/2022
//Computer-Assisted Instruction - Monitoring Student Performance


//The objective is to generate multiplication problems
//And test students to input the correct answer
//We will calculate how many the student got correct
//And if it is less than 75%, we will tell the student to get help
//And then reset the program

//prototypes
int newQuestion();
void correct();
void incorrect();

//main
int main(void)
{

    //Clear buffer
    fflush(stdin);
    //randomize using current time
    srand(time(NULL));

    int answer;
    int studentAnswer;
    int rightAnswers = 0;
    double percentage;
    unsigned int i = 0;

    //ask questions until student quits
    while (studentAnswer != -1) {
        puts("Hello, please answer the following questions. Enter '-1' to quit.");
        //ask this particular student questions, until they answer 10 times
        //reset counters
        i = 0;
        rightAnswers = 0;

        while (i < 10){

            //Call question function and get the answer
            answer = newQuestion();
            //get the student's Answer
            scanf("%d", &studentAnswer);
            //student answered the question, so add to the counter
            i++;

            //if student enters -1, then break
            if (studentAnswer == -1) {
                break;
            }
            else{

                //if the student is correct, keep going
                if (answer == studentAnswer) {
                    //call function to generate positive statement
                    correct();
                    //tally correct answers
                    rightAnswers++;
                }

                //if the student is incorrect, loop until the student answers correctly
                else {
                    while (answer != studentAnswer && studentAnswer != -1 && i <10){
                        //call function to generate statement to try again
                        incorrect();
                        //get student's new answer
                        scanf("%d", &studentAnswer);
                        i++; //student answered, so tally
                    }
                    //once the student answer's correctly, congratulate them
                    if (answer == studentAnswer) {
                        puts("Very good!");
                        rightAnswers++;
                    }
                }
            }

            //if student entered -1 during this last loop, then break
            if (studentAnswer == -1) {
                break;
            }

        }

        if (studentAnswer != -1){

            //after student has answered 10 times, calculate their score
            //And tell the student how they did
            percentage = rightAnswers / 10.0;
            if (percentage < .75) {
                puts("Please ask your teacher for extra help.\n");
            }
            else {
                puts("Congratulations, you are ready to go to the next level!\n");
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
