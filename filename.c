#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include  <sys/types.h>
void collatz(int x, int y);
int  main(int argc, char *argv[])                                      //Main method
{
     int n = atoi(argv[1]);
     pid_t  pid = fork(); // return a process id;purpose--to create a new process 
      
     if (pid == 0){
        printf("From Child 1 init n=%d\n",n);
        collatz(n,1);
     
     
     pid_t  pid1 = fork();
     if (pid1 == 0){         
          printf("From Child 2 init n=%d\n",n+3);
          collatz(n+3,2);
          }
     else
	 {
		wait(NULL);
			
	 }
	 }	 
	          
     else
	 {
            // Parent waits for the child process to complete
               wait(NULL);
               printf("Children complete\n");
	 }
	     
}

void collatz(int num, int child)                                  //the Collatz conjecture
	{
	char info[1000];
	while(num != 1){
		 if(num%2 == 0){
			 num = num / 2;
			 sprintf(info, "From Child %d %d\n",  child, num);
			 printf("%s", info);
		 }else{
			 num = num*3 + 1;
			 sprintf(info, "From Child %d %d\n", child, num);
			 printf("%s", info);
			 
		 }
	 }
}

