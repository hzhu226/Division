////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        division.c
// Other Files:      sendsig.c intdate.c
// Semester:         CS 354 Fall 2018
//
// Author:           Haotian Zhu
// Email:            hzhu226@wisc.edu
// CS Login:         haotian
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int num = 0; //the number of success

/* The handler that prints the error message.
 */
void SIGFPE_handler() {
    printf("Error: a division by 0 operation was attemped.\n");
	  printf("Total number of operations completed successfully: %i\n", num);
	  printf("The program will be terminated.\n");
	  exit(1);
}

/* The handler that prints the exit code 
 */
void SIGINT_handler() {
    printf("\nTotal number of operations successfully completed: %i\n", num);
	  printf("The program will be terminated.\n");
	  exit(0);
}

/*The main catches interupts
 *argc: the number of arguments
 *argv: char pointer that stores arguments
 */
int main(int argc, char *argv[]) {
    char buffer [100];
    int num1;
    int num2;
    
    struct sigaction action;
	  memset (&action, 0, sizeof(action));
	  action.sa_handler = SIGFPE_handler;
	  if (sigaction(SIGFPE, &action, NULL) != 0) {
        printf("Error with sigacgtion.\n");
		    exit(1);
	  }
     
    struct sigaction action_two;
	  memset (&action_two, 0, sizeof(action_two));
	  action_two.sa_handler = SIGINT_handler;
	  if (sigaction(SIGINT, &action_two, NULL) != 0) {
        printf("Error with sigacgtion.\n");
		    exit(1);
	  }
     
    while(1) {
      printf("Enter first integer: ");
		  if (fgets(buffer, 100, stdin) != NULL) {
			    num1 = atoi(buffer);
		  }
      else {
          printf("Error with first integer./n");
          exit(1);
      }
      printf("Enter second integer: ");
      if (fgets(buffer, 100, stdin) != NULL) {
			    num2 = atoi(buffer);
		  }
      else {
          printf("Error with second integer./n");
          exit(1);
      }
      int result = num1 / num2;
      int remainder = num1 % num2;
      num++;
      printf("%d / %d is %d with a remainder of %d\n", num1, num2, result, remainder);
    }
    return 0;
}

