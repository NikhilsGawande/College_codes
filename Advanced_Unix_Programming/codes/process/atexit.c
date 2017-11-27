/* implementation of atexit */

/* execution 
nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc atexit.c -o atexit
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./atexit 
main is done
my exit 2
my exit 1

*/

#include <stdio.h>
#include <stdlib.h> // atexit

void my_exit1 () {
	printf("my exit 1\n");
}

void my_exit2 () {
	printf("my exit 2\n");
}
int main() {
	if (atexit(my_exit1) != 0) 
		perror("atexit error");
	if (atexit(my_exit2) != 0) 
		perror("atexit error");
	printf("main is done\n");
	return 0;
}
