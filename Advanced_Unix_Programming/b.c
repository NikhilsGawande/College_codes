#include <stdio.h>
#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h> // for truncate
#include <stdlib.h> // for system call
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
int main() {


	char path_name[50];
	int size;
	char command[50];
	printf("#Please enter path :");
	scanf("%s", path_name);
	int fd, fd2;
	char *buffer;
	int buf_length;
	if(access(path_name, W_OK) == 0) {
		printf("#File name : %s \n#File contents before truncate: \n ", path_name);
		snprintf(command, sizeof(command) , "cat %s" , path_name);
		system(command);
		printf("\n\n ");
		fd = open(path_name, O_RDWR);			
		printf("#Please enter number to truncate file :");
		scanf("%d",&size);
		buffer = (char *)malloc(size+1);
		//truncate(path_name, size);	
		//lseek(fd, size, SEEK_SET);
		read(fd, buffer, size + 1);
		//printf("%s",buffer);
		close(fd);
		fd = open(path_name, O_WRONLY | O_TRUNC);
		write(fd, buffer, size);
		//printf("%d, %d \n", size, strlen(buffer));
		buf_length = strlen(buffer);
		if(buf_length < size) {
			while (buf_length < size) {
				write(fd, "0", 1);
				buf_length++;
			} 
		}		
		printf("#File name :%s \n#File contents after truncate: \n ", path_name);
		snprintf(command, sizeof(command) , "cat %s" , path_name);
		system(command);
		printf("\n");
		close(fd); 
	} else {
		printf("File dont have write permission");
	}



	return 0;

}
