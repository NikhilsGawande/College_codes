//program to create hole in file, need file named 'file'
//to check hole in file use od -c

#include <stdio.h>
#include <fcntl.h> // for O_RDWR, open
#include <unistd.h> // for close , write 

int main() {

	int fd;
	char buf1[10]= "abcdefghij";
	fd = open("./file" , O_RDWR );
	if( write(fd, buf1, 10) != 10) {
		perror("buf1 write error");
	}
	//offset now 10

	if( lseek(fd, 10000, SEEK_SET) == -1) {
		perror("lseek error");
	}

	if (write(fd, buf1, 10) != 10 ) {
		perror("buf1 write error(2)") ;
	}

	close(fd);
}
		
