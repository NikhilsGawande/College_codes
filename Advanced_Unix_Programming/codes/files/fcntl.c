/* Implementation of fcntl */

/*
int fcntl(int fileid, int cmd,  int *arg );

cmd = 
	duplicate an existing, F_DUPFD,
	get/set file descriptor , F_GETFD, F_SETFD  - FD_CLOEXEC
	get/set file status flags, F_GETFL , F_SETFL
	get/set asynchronous io ownership , F_GETOWN, F_SETOWN
	get/set record locks , F_GETLK, F_SETLK, 

*/

#include <fcntl.h> // fcntl
#include <stdlib.h> // atoi
#include <stdio.h>

void set_fl(int fd, int flags);
void off_fl(int fd, int flags);
void check_append(int fd, int val);

int main  (int argc, char *argv[]) {
	
	int val;
	if ( ( val = fcntl(atoi(argv[1]) , F_GETFL, 0)) < 0 ) 
		perror("fcntl error");

//	printf("%d %d %d \n", val, O_ACCMODE, O_RDONLY);


	switch ( val & O_ACCMODE) {
		case O_RDONLY :
			printf("read only\n");
			break;
		case O_WRONLY :
			printf("write only\n");
			break;
		case O_RDWR : 
			printf("read and write\n");
			break;
	}
	



	if (val & O_NONBLOCK) 
		printf("Not blocking mode\n");
	
	if (val & O_APPEND) {		// implementing set_fl and off_fl
		off_fl(atoi(argv[1]), O_APPEND);
		check_append(atoi(argv[1]), val);
		set_fl(atoi(argv[1]), O_APPEND);
		check_append(atoi(argv[1]), val);
	}

	return 0;
}

void check_append(int fd, int val) {
	if ( (val = fcntl(fd, F_GETFL, 0) ) < 0) {
		perror("fcntl error") ;
	}
	if (val & O_APPEND) 
		printf("Append mode\n");
	else 
		printf("Not an append mode\n");
}

void set_fl(int fd, int flags) { // flags are file status flagsto turn on 
	int val;
	if ( (val = fcntl(fd, F_GETFL, 0) ) < 0) {
		perror("fcntl error") ;
	}
	val |= flags; 	// turn on flags
	
	if( fcntl(fd, F_SETFL, val) < 0) {
		perror("fcntl failed");
	}

}

void off_fl(int fd, int flags) { // flags are file status flags to turn off 
	int val;
	if ( (val = fcntl(fd, F_GETFL, 0) ) < 0) {
		perror("fcntl error") ;
	}
	val &= ~flags; 	// turn off flags
	
	if( fcntl(fd, F_SETFL, val) < 0) {
		perror("fcntl failed");
	}

}

/* execution 
nik@nik-Lenovo-G50-70:~/aup/codes/files$ cc fcntl.c -o fcntl 
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./fcntl 0 < /dev/tty
read only
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./fcntl 1 > file
nik@nik-Lenovo-G50-70:~/aup/codes/files$ cat file
write only
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./fcntl 2 2>>file
write only
Not an append mode
Append mode
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./fcntl 2 2<>file
read and write

*/
