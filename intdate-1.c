////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      sendsig.c division.c
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

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int count = 0; //count times for SIGUSR1

/* The handler that handles SIGALRM.
 */
void SIGALRM_handler() {
    time_t curr;
    time(&curr);
    if (time(&curr) == -1) {
		    printf("Error with time.\n");
		    exit(1);
	  }
    char* str_time = ctime(&curr);
    if (str_time == NULL) {
        printf("Error with coverting time.\n");
        exit(1);
    }
    printf("PID: %d | Current Time: %s", getpid(), str_time);
    alarm(3);
}

/* The handler that catches SIGUSR1.
 */
void SIGUSR_handler() {
    printf("SIGUSR1 caught!\n");
    count++;
} 

/* The handler that handlers SIGINT.
 */   
void SIGINT_handler() {
    printf("\nSIGINT recieved\n");
    printf("SIGUSR1 was recieved %d times. Exiting now\n", count);
    exit(0);
}

/*The main handles SIGALRM, SIGINT, SIGUSR1 signals
 *argc: the number of arguments
 *argv: char pointer that stores arguments
 */
int main(int argc, char *argv[]) {
    struct sigaction act;
    memset (&act, 0, sizeof(act));
    act.sa_handler = SIGALRM_handler;
    if (sigaction(SIGALRM, &act, NULL) != 0){
        printf("error with sigacgtion.\n");
		    exit(1);
	  }
	  if (alarm(3) != 0) {
		    exit(1);
	  }
	  
    struct sigaction act_two;
	  memset (&act_two, 0, sizeof(act_two));
	  act_two.sa_handler = SIGUSR_handler;
    if (sigaction (SIGUSR1, &act_two, NULL) != 0) {
	    	printf("Error with sigacgtion.\n");
        exit(1);
	  }

	  struct sigaction act_three;
	  memset (&act_three, 0, sizeof(act_three));
	  act_three.sa_handler = SIGINT_handler;
	  if (sigaction (SIGINT, &act_three, NULL) != 0) {
		    printf("Error with sigacgtion.\n");
        exit(1);
	  }
    printf("Pid and time will be printed every 3 seconds.\n");
	  printf("Enter ^C to end the program.\n");

    while(1) {
	  }
	  return (0);
}