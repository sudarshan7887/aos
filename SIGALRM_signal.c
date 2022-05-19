Write a C program to send SIGALRM signal by child process to parent process and parent process
make a provision to catch the signal and display alarm is fired.(Use Kill, fork, signal and sleep
system call)

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <stdlib.h>


void Dingdong()
{
    printf("Ding!");
    exit(1);

}

int main(int argc, char *argv[])
{

     if(argc!=3)

     {
          printf("How much seconds you want to sleep the child process\n");
     }

     int PauseSecond=(argv[1]);

     {
          if(fork()==0)
          {
              printf("waiting for alarm to go off\n");
              printf("%d second pause",PauseSecond);
              sleep(PauseSecond);
              kill(getpid(),SIGALRM);
          }
          else {
              printf("Alarm application starting\n", getpid());
                signal(SIGALRM,Dingdong);
                printf("done");
           }

      }




}