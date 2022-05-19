Write a C program which receives file names as command line arguments and display those
filenames in ascending order according to their sizes.
(e.g $ a.out a.txt b.txt c.txt, …)
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
structfilelist
{
charfname[100];
intfsize;
};
int main(intargc,char *argv[])
{
DIR *dp;
inti,j,k;
structdirent *ep;
struct stat sb;
charmon[100];
structfilelist f1[100],temp;
j=0;
for(i=1;i<argc;i++)
{
dp=opendir("./");
if (dp!=NULL)
{
while(ep=readdir(dp))
{
if((strcmp(ep->d_name,argv[i]))==0)
{
stat(ep->d_name,&sb);
strcpy(f1[j].fname,ep->d_name);
f1[j].fsize=sb.st_size;
j++;
break;
}
}
}
(void)closedir(dp);
}
for(i=0;i<j;i++)
{
for(k=0;k<=j;k++)
{
if(f1[i].fsize< f1[k].fsize)
{
temp=f1[k];
f1[k]=f1[i];
f1[i]=temp;
}
}
}
for(i=0;i<j;i++)
{
printf("%s\t%d\n",f1[i].fname,f1[i].fsize);
}
return 0;
}
/*[root@localhostsppuslipquestions]# cc slip20.c
[root@localhostsppuslipquestions]# ./a.out slip12.c a1.c q12.c
a1.c 465
q12.c 596
slip12.c 803
*/