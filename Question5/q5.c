#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

char msg[100];

int main(int argc, char* argv[]){
	int time;
	void my_secretary();
	time = atoi(argv[2]);
	strcpy(msg, argv[1]);
	signal(SIGALRM, my_secretary);
	alarm(time);
	for(;;);
}

void my_secretary(){
	printf("%s\n",msg);
	exit(0);
}
