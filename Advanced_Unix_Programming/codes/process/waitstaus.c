/* catching child signals */


/*
execution 

nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./waitstatus 
normal termination , termination status = 7
abnormal termination , signal no = 6
abnormal termination , signal no = 8

*/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h> // fork
#include <stdlib.h> //exit

void pr_exit(int);


int main() {
	pid_t pid;
	int status;

	if ( (pid = fork() ) < 0) 
		perror("fork error"); 
	else if (pid == 0) 
		exit(7);
	if (wait(&status) != pid) {
		perror("wait error");
	}
	pr_exit(status);

	if((pid = fork()) < 0) 
		perror("fork error") ;
	else if( pid == 0) 
		abort();
	
	if (wait(&status) != pid) {
		perror("wait error");
	}
	pr_exit(status);


	if((pid = fork()) < 0) 
		perror("fork error") ;
	else if( pid == 0) 
		status /= 0;
	
	if (wait(&status) != pid) {
		perror("wait error");
	}
	pr_exit(status);

	
	return 0;

}


void pr_exit(int status) {
	

	if(WIFEXITED(status)) 
		printf("normal termination , termination status = %d\n", WEXITSTATUS(status) );
	
	else if(WIFSIGNALED(status)) 
		printf("abnormal termination , signal no = %d\n", WTERMSIG(status), 
		#ifdef WCOREDUMP 
			WCOREDUMP(status) ?  "core dump generated" : "") ;
		#else 
			 "" );
		#endif
	else if (WIFSTOPPED(status)) 
		printf("child stopped, signal no = %d \n", WSTOPSIG(status));

	else if (WIFCONTINUED(status)) 
		printf("child continued");

} 
	
