#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	fork();
	fork();
	printf("Parent Process Id is %d\n",getppid());
}
