#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int i, j, pid;
	pid = fork();
	if(pid == 0){
		for(i = 0; i<500; i++)
			printf("Child: %d\n", i);
	}
	else{
		for(j=0; j<500; j++)
			printf("Parent: %d\n", j);
	}
	return 0;
}
