Write a C program to display the given message ‘n’ times. (make a use of setjmp and longjmp system
call)
#include <stdio.h>
#include <setjmp.h>
jmp_buf buf;
main() {
     int x = 1,n;
     setjmp(buf); //set the jump position using buf
     printf("Hello"); // Prints a msg
     x++;
     printf(“Enter the number”);
     scanf(“%d”, &n);
     if (x <= n)
        longjmp(buf, 1); // Jump to the point located by setjmp
}
