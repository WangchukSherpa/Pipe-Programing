//1.  Enter two numbers from one end of the pipe and get the sum from the other end.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int file[2];
    if (pipe(file) == -1){
        printf("Error in pipe operation.\n");
        return 1;
    }


    int ip = fork();

    if (ip == -1){
        printf("Error in fork.\n");
        return 2;
    }

    if (ip == 0){

        close(file[0]);

        int i, j, sum;
        printf("Input first number : ");
        scanf("%d", &i);
        printf("Input second number : ");
        scanf("%d", &j);

        sum = i + j;


        if (write(file[1], &sum, sizeof(int)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }


        close(file[1]);
    } else {

        close(file[1]);

        int result;


        if(read(file[0], &result, sizeof(int)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }


        printf("Got this result from child process : %d\n", result);


        close(file[0]);
    }

    return 0;
}
