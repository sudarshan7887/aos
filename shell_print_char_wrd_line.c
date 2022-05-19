Write a C program that behaves like a shell (command interpreter). It has its own prompt say
“NewShell$”. Any normal shell command is executed from your shell by starting a child process to
execute the system program corresponding to the command. It should additionally interpret the
following command.
i) count c <filename> - print number of characters in file
ii) count w <filename> - print number of words in file
iii) count l <filename> - print number of lines in file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
char *buff,*t1,*t2,*t3,ch;
FILE *fp;
int pid;
void count(char *t2,char *t3)
{
 int charcount=0,wordcount=0,linecount=0;
 if((fp=fopen(t3,"r"))==NULL)
printf("File not found");
 else
 {
while((ch=fgetc(fp))!=EOF)
{
if(ch==' ')
 wordcount++;
else if(ch=='\n')
{
 linecount++;
 wordcount++;

}
 else
charcount++;
}

 fclose(fp);
 if(strcmp(t2,"c")==0)
printf("The total no. of characters :%d\n",charcount);
 else if(strcmp(t2,"w")==0)
 printf("The total no. of words :%d\n",wordcount);
 else if(strcmp(t2,"l")==0)
 printf("The total no. of lines :%d\n",linecount);
 else
printf("Command not found");
}
}
main()
{
 while(1)
 {
printf("myshell$");
 fflush(stdin);
t1=(char *)malloc(80);
t2=(char *)malloc(80);
t3=(char *)malloc(80);
buff=(char *)malloc(80);
fgets(buff,80,stdin);
sscanf(buff,"%s %s %s",t1,t2,t3);
if(strcmp(t1,"pause")==0)
exit(0);
else if(strcmp(t1,"count")==0)
count(t2,t3);
else
{
pid=fork();
if(pid<0)
printf("Child process is not created\n");
else if(pid==0)
{
execlp("/bin",NULL);
if(strcmp(t1,"exit")==0)
exit(0);
system(buff);
}
else
{
wait(NULL);
exit(0);
}
}
 }
}
/*
[root@localhost ass1]# ./a.out
myshell$count c a.txt
The total no. of characters :36
myshell$count w a.txt
The total no. of words :10
myshell$count l a.txt
The total no. of lines :4
myshell$ls
a.c a.out a.txt b.c count.c list.c search.c typeline.c
myshell$pause
*/
