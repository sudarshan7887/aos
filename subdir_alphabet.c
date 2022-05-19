Write a C program that will only list all subdirectories in alphabetical order from current directory.
        #include <stdio.h>
        #include <stdlib.h>
        #include <dirent.h>

        int
        main(void)
        {
          struct dirent **namelist;
          int n;
           int i=0;
          n = scandir(".", &namelist, 0, alphasort);
          if (n < 0)
              perror("scandir");
          else {
              while (i<n) {
              printf("%s\n", namelist[i]->d_name);
             free(namelist[i]);
              i++;
              }
             free(namelist);
          }
        }