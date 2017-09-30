#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wait.h>
#include <unistd.h>

int generateRandomNumber(){
	int rnd;
	srand(time(NULL));		// initialize random number generator with seed as the current system time.
	rnd = rand();
	return rnd;
}

int main(){
	int fd1[2];			// child 1 - o/p ; child 2 - i/p
	int fd2[2];			// child 1 - i/p ; child 2 - o/p
	pipe(fd1);
	pipe(fd2);
	if(fork() == 0){
		int rnd = generateRandomNumber();
		int rndby2;
		write(fd1[1],&rnd,sizeof(int));
		read(fd2[0],&rndby2,sizeof(int));
		printf("Child 1: Random number generated = %d\n",rnd);
		printf("Child 1: Random number divided by 2 received = %d\n",rndby2);
		exit(0);
	}
	else if(fork() == 0){
		int rnd, rndby2;
		read(fd1[0],&rnd,sizeof(int));
		rndby2 = rnd/2;
		write(fd2[1],&rndby2,sizeof(int));
		printf("Child 2: Random number received = %d\n",rnd);
		printf("Child 2: Random number divided by 2 sent out = %d\n",rndby2);
		exit(0);
	}
	else{
		wait(0);
		wait(0);
		printf("Parent: The child processes have terminated.\n");
	}
	return 0;
}
