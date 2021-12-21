/*
2.  Input two numbers, through the child process and find their product and quotient
    in the parent process. If there is any error during the processing, display the error.
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     
#include <sys/wait.h>   

int main(int argc, char const *argv[])
{
    int f1[2], f2[2];
   if ((pipe(f1) == -1) || (pipe(f2) == -1)){
        printf("Error in pipe operation.\n");
        return 1;
    }

    
    int ip = fork();
       if (ip == -1){
        printf("Error in fork..\n");
        return 2;
    }

    if (ip == 0){
        
        close(f1[0]);
        close(f2[0]);

        int a, b;
        printf("Input first number : ");
        scanf("%d", &a);
        printf("Input second number : ");
        scanf("%d", &b);

        
        if (write(f1[1], &a, sizeof(int)) == -1){
            printf("Error ocurred while Writing f1.\n");
            return 4;
        }
        
        if (write(f2[1], &b, sizeof(int)) == -1){
            printf("Error ocurred while Writing f2.\n");
            return 5;
        }

        
        close(f1[1]);
        close(f2[1]);
    } else {
        
        close(f1[1]);
        close(f2[1]);
        int x, y;

       
        if(read(f1[0], &x, sizeof(int)) == -1){
            printf("Error ocurred while Reading f1.\n");
            return 6;
        } 
        
        if(read(f2[0], &y, sizeof(int)) == -1){
            printf("Error ocurred while Reading f2.\n");
            return 7;
        } 


        int mul = x*y;
        printf("Product of two number is : %d\n", mul);

        if (y != 0){
            float que = (float)x/y;
            printf("Quotient of two number is : %.2f\n", que);
        }
        else
            printf("Division error, divisor is 0\n");
        
       
        close(f1[0]);
        close(f2[0]);
    }

    return 0;
}