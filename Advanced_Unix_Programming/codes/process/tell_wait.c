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

void TELL_WAIT(void); /* parent/child from {Sec race_conditions} */
void TELL_PARENT(pid_t);
void TELL_CHILD(pid_t);
void WAIT_PARENT(void);
void WAIT_CHILD(void);

static void charattime(char *str);
int main() {

	pid_t pid;
	TELL_WAIT();

	if((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0 ) {
		WAIT_PARENT();
		charattime("output from child\n");
	} else {
		charattime("output from parent\n");
		TELL_CHILD(pid);
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
