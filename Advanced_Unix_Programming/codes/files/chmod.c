/*
nik@nik-Lenovo-G50-70:~/aup/codes/files$ echo "hey " > file
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ls -l file
-rw-rw-r-- 1 nik nik 5 Nov 26 01:08 file
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ./chmod 
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ls
access    chmod.c  fcntl    file1  FILE2   stat    umask.c
access.c  echo     fcntl.c  FILE1  hole    stat.c
chmod     echo.c   file     file2  hole.c  umask
nik@nik-Lenovo-G50-70:~/aup/codes/files$ ls -l file
-rw-rw---- 1 nik nik 5 Nov 26 01:08 file
nik@nik-Lenovo-G50-70:~/aup/codes/files$ 
*/

#include <sys/stat.h>
#include <stdio.h>
int main() {
	if ((chmod("./file", S_IRUSR |  S_IWUSR | S_IRGRP |  S_IWGRP) ) < 0) 
		perror("chmod error");
	
	return 0;
}

