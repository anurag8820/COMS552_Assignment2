#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int choice;
	char search[20];
	char command[100];
	printf("Listing of files in the current directory.\n");
	printf("1. File names\n");
	printf("2. Hidden files\n");
	printf("3. File details\n");
	printf("4. File starting with word\n");
	printf("Enter choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			execl("/bin/ls","ls",NULL);
			break;
		case 2:
			execl("/bin/ls","ls","-a",NULL);
			break;
		case 3:
			execl("/bin/ls","ls","-l",NULL);
			break;
		case 4:
			printf("Enter search word: ");
			scanf("%s",search);
			sprintf(command,"ls -l | grep %s",search);
			execl("/bin/bash","bash", "-c", command, NULL);
			break;
		default:
			printf("Invalid choice.\n");
	}
	return 0;
}
