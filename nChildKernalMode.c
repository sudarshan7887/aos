/*Write a C program to create ‘n’ children. When the children will terminate,
display total cumulative time children spent in user and kernel mode*/

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
#include<sys/times.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int i, status;
 pid_t pid;
 time_t currentTime;
struct tms cpuTime;
if((pid = fork())==-1) //start child process
 {
 perror("\nfork error");
 exit(EXIT_FAILURE);
 }
else if(pid==0) //child process
 {
 time(&currentTime);
 printf("\nChild process started at %s",ctime(&currentTime));
 for(i=0;i<5;i++)
 {
 printf("\nCounting= %dn",i); //count for 5 seconds
 sleep(1);
 }
 time(&currentTime);
 printf("\nChild process ended at %s",ctime(&currentTime));
 exit(EXIT_SUCCESS);
 }
else
 { //Parent process
 time(&currentTime); // gives normal time
 printf("\nParent process started at %s ",ctime(&currentTime));
 if(wait(&status)== -1) //wait for child process
 perror("\n wait error");
 if(WIFEXITED(status))
 printf("\nChild process ended normally");
 else
 printf("\nChild process did not end normally");
 if(times(&cpuTime)<0) //Get process time
 perror("\nTimes error");
 else
 { // _SC_CLK_TCK: system configuration time: seconds clock tick
 printf("\nParent process user time= %fn",((double)
cpuTime.tms_utime));
 printf("\nParent process system time = %fn",((double)
cpuTime.tms_stime));
printf("\nChild process user time = %fn",((double)
cpuTime.tms_cutime));
 printf("\nChild process system time = %fn",((double)
cpuTime.tms_cstime));
 }
 time(&currentTime);
 printf("\nParent process ended at %s",ctime(&currentTime));
 exit(EXIT_SUCCESS);
 }
}
/* ---------------------------------------------------------------------------------------------------
OUTPUT (as per system)
Parent process started at Sun Mar 14 13:18:46 2021
Child process started at Sun Mar 14 13:18:46 2021
Counting= 0n
Counting= 1n
Counting= 2n
Counting= 3n
Counting= 4n
Child process ended at Sun Mar 14 13:18:51 2021
Child process ended normally
Parent process user time= 1.000000n
Parent process system time = 0.500000n
Child process user time = 2.000000n
Child process system time = 1.200000n
Parent process ended at Sun Mar 14 13:18:51 2021
*/
