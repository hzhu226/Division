////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        sendsig.c
// Other Files:      intdate.c division.c
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
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

/*The main sends signal to other program
 *argc: the number of arguments
 *argv: char pointer that stores arguments
 */
int main(int argc, char *argv[]) {
    if(argc!=3){
        fprintf(stderr,"Usage: <signal type> <pid>\n");
	      exit(1);
    }
    
    if (strcmp(argv[1], "-i") == 0) { 
        kill(atoi(argv[2]), SIGINT);
    } else if (strcmp(argv[1], "-u") == 0) {
        kill(atoi(argv[2]), SIGUSR1);
    } else {
        printf("Error with parameter.\n");
        exit(1);
    }
    
    return 0;
}
    