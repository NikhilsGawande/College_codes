/* implementing stat */

#include <sys/stat.h>
#include <stdio.h>

int main(int argc , char * argv[]) {
	int i;
	struct stat buf;
	for (i = 1; i < argc; i++) {
		printf("%s : " , argv[i]);
		if( lstat(argv[i],&buf) == -1) {
			perror("lstat error");
			continue;
		}
		if (S_ISREG(buf.st_mode))
			printf("regular");
		else if (S_ISDIR(buf.st_mode))
			printf("directory");
		else if (S_ISCHR(buf.st_mode))
			printf("character file");
		else if (S_ISBLK(buf.st_mode))
			printf("block file");
		else if (S_ISFIFO(buf.st_mode)) 
			printf("fifo file");
		else if (S_ISLNK(buf.st_mode)) 
			printf("link file");
		else if (S_ISSOCK(buf.st_mode))
			printf("socket");
		else 
			printf("unknown");
		printf("\n");

	}
	return 0;
}
