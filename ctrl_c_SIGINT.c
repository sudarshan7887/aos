Write a C program that catches the ctrl-c (SIGINT) signal for the first time and display the
appropriate message and exits on pressing ctrl-c again.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigfun(int sig)
{
     printf("You have presses Ctrl-C , please press again to exit");
        (void) signal(SIGINT, SIG_DFL);
}

int main()
{
     (void) signal(SIGINT, sigfun);

        while(1) {
         printf("Hello World!
");
            sleep(1);
        }

        return(0);
}
