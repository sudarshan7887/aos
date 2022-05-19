Write a C program to display the last access and modified time of a given file.

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
             char filename[] = "c:\\test.txt";
             char timeStr[ 100 ] = "";
             struct stat buf;
             time_t ltime;
             char datebuf [9];
             char timebuf [9];

             if (!stat(filename, &buf))
             {
                           strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime( &buf.st_mtime));
                           printf("\nLast modified date and time = %s\n", timeStr);
             }
             else
             {
                           printf("error getting atime\n");
             }
             _strtime(timebuf);
             _strdate(datebuf);
             printf("\nThe Current time is %s\n",timebuf);
             printf("\nThe Current Date is %s\n",datebuf);
             time( &ltime );
             printf("\nThe Current time is %s\n",ctime( &ltime ));
             printf("\Diff between current and last modified time ( in seconds ) %f\n", difftime(ltime ,buf.st_mtime )
);
             return 0;
}
