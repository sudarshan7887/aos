#include "apue.h" 
#include <fcntl.h> 
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) 
int main(void) 
{ 
    umask(0); 
    if (creat("foo", RWRWRW) < 0) err_sys("creat error for foo"); 
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); 
    if (creat("bar", RWRWRW) < 0) err_sys("creat error for bar"); 
    exit(0); 
    }

#include "apue.h" 
int main(void) 
{ 
    struct stat statbuf; /* turn on set-group-ID and turn off group-execute */ 
    if (stat("foo", &statbuf) < 0) err_sys("stat error for foo"); 
    if (chmod("foo", (statbuf.st_mode & �S_IXGRP) | S_ISGID) < 0) err_sys("chmod error for foo"); 
    /* set absolute mode to "rw-r--r--" */ 
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) err_sys("chmod error for bar"); 
    exit(0); 
    }
