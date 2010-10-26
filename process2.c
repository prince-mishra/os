#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
	pid_t first;
        int ch;
 	first=fork();
	printf("\nChild process created. PID is : %d\nPress any key to exit :",getpid());
	scanf("%d",&ch);
}
