Write a C program that behaves like a shell (command interpreter). It has its own prompt say
“NewShell$”. Any normal shell command is executed from your shell by starting a child process to
execute the system program corresponding to the command. It should additionally interpret the
following command.
i) typeline +10 <filename> - print first 10 lines of file
ii) typeline -20 <filename> - print last 20 lines of file
iii) typeline a <filename> - print all lines of file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
char *buff,*t1,*t2,*t3,ch;
FILE *fp;
int pid;
void typeline(char *t2,char *t3)
{
int i,n,count=0,num;
if((fp=fopen(t3,"r"))==NULL)
printf("File not found\n");
if(strcmp(t2,"a")==0)
{
while((ch=fgetc(fp))!=EOF)
printf("%c",ch);
fclose(fp);
return;
}
n=atoi(t2);
if(n>0)
{
i=0;
while((ch=fgetc(fp))!=EOF)
{
if(ch=='\n')
i++;
if(i==n)
break;
printf("%c",ch);
}
printf("\n");
}
else
{
count=0;
while((ch=fgetc(fp))!=EOF)
if(ch=='\n')
count++;
fseek(fp,0,SEEK_SET);
i=0;
while((ch=fgetc(fp))!=EOF)
{
if(ch=='\n')
i++;
if(i==count+n-1)
break;
}
while((ch=fgetc(fp))!=EOF)
printf("%c",ch);
}
fclose(fp);
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
else if(strcmp(t1,"typeline")==0)
typeline(t2,t3);
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
[root@localhost ass1]# cc typeline.c
[root@localhost ass1]# ./a.out
myshell$typeline a s.txt
hello aa welcome
dyp bb
tybcs aa dyp
good morning
dyp gm
myshell$typeline -2 s.txt
good morning
dyp gm
myshell$typeline +3 s.txt
hello aa welcome
dyp bb
tybcs aa dyp
myshell$ls
#a.c# a.out ass2 a.txt b.c count.c list.c search.c s.txt typeline.c
myshell$pause
*/