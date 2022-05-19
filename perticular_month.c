Write a C program to display all the files from current directory which are created in a particular
month.
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
int main(intargc, char *argv[])
{
char in[100],st[100],*ch,*ch1,c,buff[512];
DIR *dp;
int i;
structdirent *ep;
struct stat sb;
charmon[100];
dp=opendir("./");
if (dp != NULL)
{
while(ep =readdir(dp))
{
if(stat(ep->d_name,&sb) == -1)
{
perror("stat");
exit(EXIT_SUCCESS);
}
strcpy(mon,ctime(&sb.st_ctime));
ch=strtok(mon," ");
ch=strtok(NULL,",");
ch1=strtok(ch," ");
if((strcmp(ch1,argv[1]))==0)
{
printf("%s\t\t%s",ep->d_name,ctime(&sb.st_ctime));
}
}
(void)closedir(dp);
}
return 0;
}
/*
[root@localhostUnix]# cc month.c
[root@localhostUnix]# ./a.out Mar
a.out Fri Mar 20 22:15:23 2020
. Fri Mar 20 22:15:23 2020
.. Fri Mar 20 22:14:29 2020
*/