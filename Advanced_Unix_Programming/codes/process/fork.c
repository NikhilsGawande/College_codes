/*

implementing fork 

nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc fork.c -o fork
nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc fork.c -o fork
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./fork 
pid = 3846, glob = 2, localval = 3.
pid = 3845, glob = 1, localval = 2.

*/

#include <unistd.h> // fork and getpid
#include <stdio.h>
int glob=1;


int main() {

	int pid;
	int localval=2;

	if( (pid = fork()) < 0 ) 
		perror("fork error");
	else if ( pid  == 0 ) { //child
		glob++;
		localval++;
	} else {		//parent
		sleep(2);
	}

	printf("pid = %d, glob = %d, localval = %d.\n" , getpid(), glob, localval);
	
	return 0;

}

