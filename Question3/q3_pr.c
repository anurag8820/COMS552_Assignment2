#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>
#include <sched.h>

int main(){
	int i = 0, j = 0, pid, nc;
	pid = fork();
	if(pid == 0){
		printf("Initial child priority: %d\n",getpriority(PRIO_PROCESS,0));
		nc = nice(PRIO_MAX);
		if(nc == -1)
			printf("Error incrementing nice value: %s\n",strerror(errno));
		printf("Updated child priority: %d\n",getpriority(PRIO_PROCESS, 0));
		for(i = 0; i<500; i++)
			printf("Child: %d\n",i);
	}
	else{
		printf("Parent resumes.\n");
		for(j=0; j<500; j++)
			printf("Parent: %d\n",j);
	}
	return 0;
}
