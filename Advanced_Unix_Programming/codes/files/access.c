/* access implementation 
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./access /etc/shadow
access error: Permission denied
read error: Permission denied
root@nik-Lenovo-G50-70:/home/nik/aup/codes/files# chown root access
root@nik-Lenovo-G50-70:/home/nik/aup/codes/files# chmod u+s access
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./access /etc/shadow
access error: Permission denied
opened for reading


*/

#include <fcntl.h>
#include <unistd.h> // unistd
#include <stdio.h>
int main(int argc, char* argv[]) {
	if (access(argv[1] , R_OK) < 0) 
		perror("access error");
	else 
		printf("read access ok!\n");

	if ( open(argv[1] , O_RDONLY) < 0) 
		perror("read error");
	else 
		printf("opened for reading\n");

	return 0;
}

