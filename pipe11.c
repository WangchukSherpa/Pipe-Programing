/*
11.  Enter a number, convert it into binary (8 bits), XOR it with 10101011 and display the number in decimal.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int file[2];


    if (pipe(file) == -1){
        printf("Error occured with pipe operation.\n");
        return 1;
    }

    int id = fork();
    if (id == -1){
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if (id == 0){
        close(file[0]);

        int num;
        printf("Enter a number : ");
        scanf("%d", &num);

        int xorNum[8] = {1, 0, 1, 0, 1, 0, 1, 1};

        int newNum[8];
        int temp = num;
        int count;

        for (count = 0; temp > 0; count++)
        {
            biNum[count] = temp%2;
            temp = temp/2;
        }

        int i = 0;
        int size = 7;

        if(count>7)
            size = count;

        while(i < 8){
            if(biNum[size] == xorNum[i]){
                newNum[i] = 0;
            } else {
                newNum[i] = 1;
            }
            i++;
            size--;
        }

        if (write(file[1], &newNum, sizeof(newNum)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(file[1]);
    } else {
        close(file[1]);

        int newNum[8];
        int num = 0;

        if(read(file[0], &newNum, sizeof(newNum)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }
        
        for (int i = 0, j = 7; i < 8; i++, j--)
        {
            num += newNum[i]*pow(2, j);
        }
        printf("The number after XORing is : %d\n", num);

        close(file[0]);
    }

    return 0;
}