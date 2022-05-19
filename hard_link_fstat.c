Write a C program to find file properties such as inode number, number of hard link, File
permissions, File size, File access and modification time and so on of a given file using fstat() system
call.
#include    <unistd.h>
#include    <fcntl.h>
#include    <stdio.h>
#include    <sys/stat.h>
#include    <sys/types.h>

int main(int argc, char **argv)
{
         if(argc != 2)
                  return 1;

            int file=0;
            if((file=open(argv[1],O_RDONLY)) < -1)
                     return 1;

            struct stat fileStat;
            if(fstat(file,&fileStat) < 0)
                     return 1;

            printf("Information for %s\n",argv[1]);
            printf("---------------------------\n");
            printf("File Size: \t\t%d bytes\n",fileStat.st_size);
            printf("Number of Hard Links: \t%d\n",fileStat.st_nlink);
            printf("File inode: \t\t%d\n",fileStat.st_ino);

            //printf("Last file access:                   %s", ctime(&fileStat.st_atime));
           //printf("Last file modification:             %s", ctime(&fileStat.st_mtime));

            printf("File Permissions: \t");
            printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
            printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
           printf( (fileStat.st_mode   &   S_IXGRP)   ?   "x"   :   "-");
           printf( (fileStat.st_mode   &   S_IROTH)   ?   "r"   :   "-");
           printf( (fileStat.st_mode   &   S_IWOTH)   ?   "w"   :   "-");
           printf( (fileStat.st_mode   &   S_IXOTH)   ?   "x"   :   "-");
           printf("\n");
           close(file);
           return 0;

}
