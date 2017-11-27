/* implementing umask 
after execution

nik@nik-Lenovo-G50-70:~/aup/codes/files$ ls -l FILE*
-rw-rw-rw- 1 nik nik 0 Nov 26 00:59 FILE1
-rw------- 1 nik nik 0 Nov 26 00:59 FILE2

*/

#include <fcntl.h>
#include <stdio.h>

#define RWRWRW ( S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH )
int main() {
	umask(0);
	if(open("./file1", O_CREAT) == -1) 
		perror("open error");

	if(creat("./FILE1", RWRWRW) == -1) 
		perror("open error");
	
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
	
	if(creat("./FILE2", RWRWRW) == -1) 
		perror("open error");

	return 0;
}
