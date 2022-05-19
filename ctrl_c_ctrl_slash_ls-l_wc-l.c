Write a C program to implement the following unix/linux command (use fork, pipe and exec system
call). Your program should block the signal Ctrl-C and Ctrl-\ signal during the execution.
ls –l | wc –l
// C code to implement ls | wc command
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include <unistd.h>
int main(){
// array of 2 size a[0] is for
// reading and a[1] is for
// writing over a pipe
int a[2];
// using pipe for inter process communication
pipe(a);
if(!fork())
{
// closing normal stdout
close(1);
// making stdout same as a[1]
dup(a[1]);
// closing reading part of pipe
// we don't need of it at this time
close(a[0]);
// executing ls
execlp("ls","ls",NULL);
}
else
{
// closing normal stdin
close(0);
// making stdin same as a[0]
dup(a[0]);
// closing writing part in parent,
// we don't need of it at this time
close(a[1]);
// executing wc
execlp("wc","wc",NULL);
}
}