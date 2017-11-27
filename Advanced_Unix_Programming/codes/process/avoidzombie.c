/*to avoid creating zombie process and parent also dont wait for the child process to execute 

nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc avoidzombie.c -o avoidzombie
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./avoidzombie 
in main , pid = 5656
2nd child , parent pid = 1943
main done

*/

#include <stdio.h>
#include <unistd.h> // fork
#include <stdlib.h> // exit
#include <sys/wait.h>


int main() {
	pid_t pid;

	if ((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0) {
		if ((pid = fork()) < 0 ) 
			perror("fork error");
		else if ( pid > 0) 
			exit(0);
		
		sleep(2);
		printf("2nd child , parent pid = %d\n", getppid());
		exit(0);
	}
	if (waitpid(pid, NULL, 0) != pid) 
		perror("waitpid error");



	printf("in main , pid = %d\n", getpid());
	sleep(3);
	printf("main done\n");
	return 0;
}
