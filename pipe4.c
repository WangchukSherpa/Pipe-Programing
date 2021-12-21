
/*
4.  Input 8 numbers and display/output the result by 2X2 matrix manipulation.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 8

int main(int argc, char const *argv[])
{
    int file[2];

    if (pipe(file) == -1)
    {
        printf("Error occured with pipe operation.\n");
        return 1;
    }

    int id = fork();
    if (id == -1)
    {
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if (id == 0)
    {
        close(file[0]);

        int numArr[SIZE];
        printf("You need to enter 8 numbers to create two-matrix of size 2x2.\n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("Enter number %d : ", i + 1);
            scanf("%d", &numArr[i]);
        }

        if (write(file[1], &numArr, sizeof(numArr)) == -1)
        {
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(file[1]);
    }
    else
    {
        close(file[1]);

        int numArr[2][2];

        if (read(file[0], &numArr, sizeof(numArr)) == -1)
            printf("Error ocurred while Reading.\n");
        return 5;
    }

    printf("----Matrix 1----\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%5d", numArr[i][j]);
        }
        printf("\n");
    }

    if (read(file[0], &numArr, sizeof(numArr)) == -1)
        printf("Error ocurred while Reading.\n");
    return 6;
}

printf("----Matrix 2----\n");
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 2; j++)
    {
        printf("%5d", numArr[i][j]);
    }
    printf("\n");
}

close(file[0]);
}

return 0;
}