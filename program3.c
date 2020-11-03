#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void){
	int pipefds[2];
	int num;
	char buffer[5];

	if(pipe(pipefds) == -1){
	   perror("pipe");
	   exit(EXIT_FAILURE);
	  }

	  pid_t pid = fork();

	   if(pid == 0){
	     printf("Enter a number:\n");
	     scanf("%d", &num);
	     close(pipefds[0]);
	     write(pipefds[1], &num, 5);
	     printf("Done.\n\n");
	     sleep(2);
	     exit(EXIT_SUCCESS);
	     }
	   if (pid > 0) {
		wait(NULL);
		close(pipefds[1]);
		if( num/2 == 0){
			printf("the number is a prime number\n");
			}
		       else {
			    printf("the number is not a prime number\n");
			   }
                  read(pipefds[0], &num, 5);
		  close(pipefds[0]);
		 printf("parent received number '%ls' \n", &num);
       	}
	    void sigint_handler(int isyarat);
	return EXIT_SUCCESS;
}

void sigint_handler(int syarat)
{
	printf("This program has been terminate using signal handler");
	exit(EXIT_SUCCESS);
}


