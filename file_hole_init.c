Write a C program to create a file with hole in it.
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>

char     buf1[] = "welcome";
char     buf2[] = "Computer science";

int main(void)
{
         int fd;

           if ((fd = creat("file_with_hole.txt",0777 )) < 0)
                    printf("creat error");

           if (write(fd, buf1, 7) != 7)
                      printf("buf1 write error");

           lseek(fd,100,SEEK_CUR);

           if (write(fd, buf2, 16) != 16)
                    printf("buf2 write error");


           exit(0);
}
