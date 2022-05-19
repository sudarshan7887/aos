Write a C program to implement the following unix/linux command on current directory
ls –l > output.txt
DO NOT simply exec ls -l > output.txt or system command from the program.
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
main(int argc, char *argv[])
{
char d[50];
if(argc==2)
{
bzero(d,sizeof(d));
strcat(d,"ls ");
strcat(d,"> ");
strcat(d,argv[1]);
system(d);
}
else
printf("\nInvalid No. of inputs");
}
/*output:-
[root@localhost unix]# cc slip23.c
[root@localhost unix]# ls
exitdemo.c hello orphan.c signaldemo.c~ x.out
exitprg.c hello1 orphan.c~ slip10.c zombie.c
exitprg.c~ hello1.c p.c slip10.c~ zombie.c~
f1.txt hello.c p.c~ slip16.c
f1.txt~ hello.txt pipedemo.c slip16.c~
f3 hello.txt~ pipedemo.c~ slip19.c
[root@localhost unix]# cat >file3
[6]+ Stopped cat > file3
[root@localhost unix]# ./a.out file3
[root@localhost unix]# cat file3
exitdemo.c hello orphan.c signaldemo.c~ x.out
exitprg.c hello1 orphan.c~ slip10.c zombie.c
exitprg.c~ hello1.c p.c slip10.c~ zombie.c~
f1.txt hello.c p.c~ slip16.c
f1.txt~ hello.txt pipedemo.c slip16.c~
f3 hello.txt~ pipedemo.c~ slip19.c
*/