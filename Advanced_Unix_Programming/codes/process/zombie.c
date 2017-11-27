/* zombie is created when parent doesnt wait for child 

the process that has terminated but whose parent has not yet waited for it, is called zombie.

in main , pid = 6558
2nd child , parent pid = 6558
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
nik       2021  0.0  0.1  43928  4192 ?        Ss   10:58   0:04 dbus-daemon --fork --session --address=unix:abstract=/tmp/dbus-uuEoiZcbWu
nik       6559  0.0  0.0      0     0 pts/1    Z+   14:06   0:00 [zombie] <defunct>
nik       6560  0.0  0.0   4508   800 pts/1    S+   14:06   0:00 sh -c ps aux | grep 'Z'
nik       6562  0.0  0.0  14224   936 pts/1    S+   14:06   0:00 grep Z
pstree -p -s 6559
systemd(1)───lightdm(1077)───lightdm(1520)───upstart(1943)───gnome-terminal-(6268)───bash(6274)───zombie(6558)───zombie(6559)
main done

*/

#include <stdio.h>
#include <unistd.h> // fork
#include <stdlib.h> // exit
#include <sys/wait.h>


int main() {
	pid_t pid;

	char buf[60];

	if ((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0) {
		//sleep(2);
		printf("2nd child , parent pid = %d\n", getppid());
		exit(0);
	}
	printf("in main , pid = %d\n", getpid());
	sleep(3);
	system("ps aux | grep 'Z'");
	snprintf(buf, sizeof(buf), "pstree -p -s %d",pid);                                   
	printf("%s\n", buf);
	system(buf);
	printf("main done\n");
	return 0;
}
