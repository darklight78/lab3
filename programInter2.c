#include <stdio.h> /*output file dia output2.out*/
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>


int main(void)
{
	void sigint_handler(int isyarat);
	void sigtstp_handler(int isyarat);
	void sigquit_handler(int isyarat);

	if(signal(SIGINT, sigint_handler) == SIG_ERR)
		printf("can not reach signal\n");
	if(signal(SIGTSTP, sigtstp_handler) == SIG_ERR)
		printf("tak boleh access signal\n");
	if(signal(SIGQUIT, sigquit_handler) == SIG_ERR)
		printf("tak boleh access signal\n");
	while(1)
	   sleep(1);
	return 0;
}
void sigint_handler(int isyarat)
{
	printf("This is special signal handler for SIGINT\n");
	exit(1);
}
void sigtstp_handler(int isyarat)
{
	printf("This is special signal handler for SIGTSTP\n");
}
void sigquit_handler(int isyarat)
{
	printf("This is sepcial signal handler for SIGQUIT\n" );
}

