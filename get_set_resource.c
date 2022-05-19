Write a C program to get and set the resource limits such as files, memory associated with a
process.

#include   <stdio.h>
#include   <sys/resource.h>
#include   <string.h>
#include   <errno.h>
#include   <unistd.h>
#include   <sys/types.h>
#include   <sys/stat.h>
#include   <fcntl.h>

int main() {

    struct rlimit old_lim, lim, new_lim;

    // Get old limits
    if( getrlimit(RLIMIT_NOFILE, &old_lim) == 0)
         printf("Old limits -> soft limit= %ld \t"
            " hard limit= %ld \n", old_lim.rlim_cur,
                                  old_lim.rlim_max);
    else
         fprintf(stderr, "%s\n", strerror(errno));

    // Set new value
    lim.rlim_cur = 3;
    lim.rlim_max = 1024;

    // Set limits
    if(setrlimit(RLIMIT_NOFILE, &lim) == -1)
        fprintf(stderr, "%s\n", strerror(errno));

    // Get new limits
    if( getrlimit(RLIMIT_NOFILE, &new_lim) == 0)
         printf("New limits -> soft limit= %ld "
          "\t hard limit= %ld \n", new_lim.rlim_cur,
                                   new_lim.rlim_max);
    else
         fprintf(stderr, "%s\n", strerror(errno));
    return 0;
}
Output:

Old limits -> soft limit= 1048576          hard limit= 1048576
New limits -> soft limit= 3                  hard limit= 1024
