#include <stdio.h>
#include <stdlib.h>

//MacKayla Smirga
//10/17/2022
//CIT 145
// Calculating Weekly Pay


//This program will calculate the weekly pay for each employee entered into the system
int main(void)
{

    int paycode;
    int hours;
    int overtime;
    int quantity;
    double wage;
    double sales;
    double salary;
    double rate;
    double pay;


    printf("Enter employee paycode: ");

    //loop until payroll clerk exits
    while ((paycode = getchar()) !=EOF) {


            //determine the paycode that was entered and prompt for hours worked and wage
            //or other important information
            //Calculate pay for the week
            switch (paycode) {

                case '1':
                    //managers earn a fixed salary
                    printf("%s", "Enter salary: ");
                    scanf("%lf", &salary);
                    //divide salary by the 52 weeks in a year to calculate weekly pay
                    pay = salary / 52;
                    break;

                case '2':
                    //employees have a normal wage and overtime pay
                    printf("%s", "Enter hours worked for the week: ");
                    scanf("%d", &hours);

                    printf("%s", "Enter wage: ");
                    scanf("%lf", &wage);

                    //if they have more than 40 hours, calculate how much overtime they have
                    overtime = 0; //reset overtime
                    if (hours > 40) {
                        overtime = hours - 40;
                        hours = 40;
                    }
                    pay = (hours * wage) + (overtime * wage * 1.5);
                    break;

                case '3':
                    //comissioned employees make a base pay plus a percentage of their sales
                    printf("%s", "Enter gross weekly sales: ");
                    scanf("%lf", &sales);

                    pay = 250 + (.057 * sales);
                    break;

                case '4':
                    printf("%s", "Enter rate per item: ");
                    scanf("%lf", &rate);

                    printf("%s", "Enter quantity of items: ");
                    scanf("%d", &quantity);

                    pay = rate * quantity;
                    break;

                case '\n':
                case '\t':
                case ' ':
                    break;

                default: //catch all invalid characters
                    puts("Invalid entry. Please try again.");
            }

            //display the employee's weekly pay
            printf("The employee's pay for the week is $%.2lf.\n", pay);
            printf("Enter employee paycode: ");

            //Clear buffer
            fflush(stdin);


        }




    }
