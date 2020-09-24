#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int i;

     for (i=0; i < 2; i++){
          pid = fork();
          if(pid < 0)
          {
            printf("Error");
          }
          if (pid == 0) {
            ChildProcess();
          }
          else {
            ParentProcess();    
          }
                
          }
      exit(0);
}

void  ChildProcess(void)
{ 
     srandom(time(NULL));
     int sleep_time = random() % 10;
     srandom(time(NULL));
     int loop_num = random() % 30;
     int i;
     for(i=0; i < loop_num; i++){
          printf("Child: %d  is going to sleep!\n ", getpid());
          sleep(sleep_time); 
          printf("Child Pid: is awake!\n Where is my Parent: %d\n ", getppid());
     }  
     exit(0);
}

void  ParentProcess(void)
{
      int status;
      pid_t pid = waitpid(-1, &status, 0);
      printf("Child Pid:%d has completed\n ", pid);
      printf("\n");
}
