
/*
6.  Enter any hexadecimal number and display the equivalent decimal and binary numbers.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

        long unsigned int hexNum;
        printf("Enter any hexadecimal number : ");
        scanf("%x", &hexNum);

        if (write(file[1], &hexNum, sizeof(hexNum)) == -1)
        {
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(file[1]);
    }
    else
    {
        close(file[1]);

        long unsigned int decNum;
        int biNum[50];

        if (read(file[0], &decNum, sizeof(decNum)) == -1)
        {
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        printf("In Decimal : %ld\n", decNum);
        printf("In Binary : ");

        long unsigned int temp = decNum;
        int count;
        for (count = 0; temp > 0; count++)
        {
            biNum[count] = temp % 2;
            temp = temp / 2;
        }
        for (count = count - 1; count >= 0; count--)
        {
            printf("%d", biNum[count]);
        }
        printf("\n");

        close(file[0]);
    }

    return 0;
}