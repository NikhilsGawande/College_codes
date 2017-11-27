/* race condition between parent and child . 

nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./race_cond 
oouutptpuut from parent
t from child
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./race_cond 
output from paorutput fent
rom child
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./race_cond 
output from opuatrpeuntt 
from child

*/


#include <stdio.h>
#include <unistd.h>



static void charattime(char *str);
int main() {

	pid_t pid;


	if((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0 ) {
		charattime("output from child\n");
	} else {
		charattime("output from parent\n");
	}

	return 0;
}

static void charattime(char *str) {
	char *ptr;
	int c;	
	setbuf(stdout, NULL);	//set unbuffered
	for (ptr = str; (c = *ptr++) != 0; ) {
		putc(c , stdout);
	}
}
