/*Implementing setjump and longjump*/

/*
nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc jump.c -o jump
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./jump
in fun1 
globval = 95, autoval = 96, regval = 97, volval = 98, statval = 99.

after longjump
globval = 95, autoval = 96, regval = 97, volval = 98, statval = 99.

nik@nik-Lenovo-G50-70:~/aup/codes/process$ cc -O jump.c -o jump
nik@nik-Lenovo-G50-70:~/aup/codes/process$ ./jump
in fun1 
globval = 95, autoval = 96, regval = 97, volval = 98, statval = 99.

after longjump
globval = 95, autoval = 1, regval = 2, volval = 98, statval = 99.

*/



#include <setjmp.h>
#include <stdio.h>

void fun1 ( int , int , int, int ) ;
void fun2 () ;

int globval = 1;

static jmp_buf jumpbuf;

int main() {
	int autoval =1;
	register int regval = 2;
	volatile int volval = 3;
	static int statval = 4;


	if( setjmp(jumpbuf) != 0) {
		printf("after longjump\n");
		printf("globval = %d, autoval = %d, regval = %d, volval = %d, statval = %d.\n\n", globval, autoval, regval, volval , statval);
		return 0;

	}
	globval = 95; autoval = 96;  regval = 97; volval = 98; statval = 99;
	fun1(autoval, regval, volval, statval);
	return 0;
}

void fun1( int a, int r, int v, int s) {
	printf("in fun1 \n");
	printf("globval = %d, autoval = %d, regval = %d, volval = %d, statval = %d.\n\n", globval, a, r, v,s );
	fun2();
}	

void fun2() {
	longjmp( jumpbuf, 1);
}
