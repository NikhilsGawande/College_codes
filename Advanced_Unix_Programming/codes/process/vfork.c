/* implementing vfork 

nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc vfork.c -o vfork
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./vfork 
before vfork
pid = 3977, glob = 1, localval = 2.
 after vfork
pid = 3977, glob = 2, localval = 3.
*/


#include <unistd.h> // fork and getpid
#include <stdio.h>
int glob=1;


int main() {

	int pid;
	int localval=2;
	printf("before vfork\n");
	printf("pid = %d, glob = %d, localval = %d.\n " , getpid(), glob, localval);
	if( (pid = vfork()) < 0 ) 
		perror("fork error");
	else if ( pid  == 0 ) { //child
		glob++;
		localval++;
		_exit(0);
	} 
	// no need of sleep 
	printf("after vfork\n");
	printf("pid = %d, glob = %d, localval = %d.\n " , getpid(), glob, localval);
	
	return 0;

}

