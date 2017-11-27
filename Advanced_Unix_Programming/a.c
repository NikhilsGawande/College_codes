#include <stdio.h>

int main(int argc, char **argv) {	
	int i= 0, pid;
	int n = atoi(argv[1]);
	for(i = 0; i < n; i++) {
		if (pid = fork() != 0) { 
			continue;
		} else {
			sleep(atoi(argv[2]));
			return 0;
		}
		
	}
	return 0;
}
