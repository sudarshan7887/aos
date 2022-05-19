Write a C program to map a given file in memory and display the content of mapped file in
reverse.

#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <unistd.h>
#include   <sys/stat.h>
#include   <fcntl.h>
#include   <sys/types.h>
#include <sys/stat.h>
#include <sys/io.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
  unsigned char *f, *g;
  int size;
  struct stat s;
  const char * file_name = argv[1];
  int fd = open(argv[1], O_RDONLY);

    int status = fstat(fd, &s);
    size = s.st_size;
    int i;
    f = (char *) mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);
    //g = (char *) mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);

    for(i = 0; i < size; i++) {
      char c;

     c = f[i];
     putchar(c);
    }
    //ABOVE THIS WORKS


    // int z = 0;
    //while(f[z] != NULL) {
    //z++;
      // printf("%d", z);
    // }
    int x;
    int y = 0;
    close(fd);

    FILE *f1;

    f1 = fopen(argv[2], "w+");

    for(x = size - 1; x >= 0; x--)
      {
        char c;

        c = f[x];
        fputc(c, f1);
    }
    return 0;
}