Write a C program to move the content of file1.txt to file2.txt and remove the file1.txt from directory.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define buffersize 10000
int main()
{
char source[25],destination[25]; //Source and destination filename
char buffer[buffersize]; //Character buffer
ssize_t read_in,write_out; //Number of bytes returned by single read and write operation
printf(“Enter source file name”);
scanf(“%s”,&source);
printf(“%s”,source);
int sourcefiledesc = open(source,O_RDONLY); //Source file open in read only mode
if(sourcefiledesc < 0 )
{
printf(“Source file not Exist”); //Source file not found
}
else
{
printf(“Enter destination file name”);
scanf(“%s”,&destination);
/* Destination file open in write mode and if not found then create*/
int destfiledesc = open(destination,O_WRONLY | O_CREAT);
while((read_in = read(sourcefiledesc,&buffer,buffersize))>0)
{
write_out = write(destfiledesc,&buffer,read_in);
}
if (remove(sourcefiledesc) == 0)
     printf("File Deleted successfully");
   else
     printf("Unable to delete the file");
close(sourcefiledesc);
close(destfiledesc);
}
return 0;
}