//read from stdin and write to stdout

#include <stdio.h>
#include <unistd.h> // read and write
int main() {

	char buf[4016];
	int n;
	while((n = read(STDIN_FILENO, buf, 4016)) > 0) {
		if(write(STDOUT_FILENO, buf, n) != n) 
			perror("Write failed");
	}
	if( n < 0) {
		perror("read failed");
	}

	return 0;
}
