Write a C program to display as well as resets the environment variable such as path, home, root etc.
        /* C Program to Print Environment variables */
        #include <stdio.h>
         void main(int argc, char *argv[], char * envp[])
        {
           int i;
            for (i = 0; envp[i] != NULL; i++)
           {
              printf("\n%s", envp[i]);
           }
        /* set environment variable _EDC_ANSI_OPEN_DEFAULT to "Y" */
          setenv("_EDC_ANSI_OPEN_DEFAULT","Y",1);

            /* set x to the current value of the _EDC_ANSI_OPEN_DEFAULT*/
            x = getenv("_EDC_ANSI_OPEN_DEFAULT");

            printf("program1 _EDC_ANSI_OPEN_DEFAULT = %s\n",
             (x != NULL) ? x : "undefined");
        }