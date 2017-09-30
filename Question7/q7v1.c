/* 
No synchronization between the thread "hello" and thread "world" to show
the arbitrary order of their display
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* hello(void*);
void* world(void*);

int main(){
	pthread_t hellotd, worldtd;
	pthread_create(&hellotd,NULL,&hello,NULL);	// create hello thread
	pthread_create(&worldtd,NULL,&world,&hellotd);	// create world thread
	pthread_join(worldtd,NULL);			// wait for world thread	
	pthread_join(hellotd,NULL);			// wait for hello thread (not necessary, just to demonstrate behavior in non-synchroniztion case)
	printf("\n");
	return 0;
}

/* Prints hello */
void* hello(void* arg){
	sleep(1);					// only to compensate for the start time difference between hello and world
	printf("hello ");
	pthread_exit(NULL);
}

/* Prints hello
beforeid - thread handle that needs to complete execution before this thread.
*/
void* world(void* beforeId){
	pthread_t* before = beforeId;
	// pthread_join(*before,NULL);			// commented out to remove synchronization with hello thread.
	printf("world");
	pthread_exit(NULL);
}
