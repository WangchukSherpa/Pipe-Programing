/*
7.  Input any word up to 10 alphabets and display the number of different alphabets appearing in the
    word e.g. McGraw-Hill (Input), a = 1, c = 1, g = 1, h = 1, i = 1, l = 2, m = 1, r = 1, w = 1 (Output)
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 15

int main(int argc, char const *argv[])
{
    int file[2];

   
    if (pipe(file) == -1){
        printf("Error occured while creating pipe.\n");
        return 1;
    }

    int id = fork();
    if (id == -1){
        printf("Error ocurred with fork.\n");
        return 2;
    }

    if (id != 0){
        close(file[0]);

        char charArr[SIZE];
        int charArr_len;
        while(1){
            printf("You need to enter any word upto 10-alphabeths.\n");
            printf("Enter the word : ");
            scanf("%s", charArr);

            charArr_len = strlen(charArr);
            if(charArr_len>10){
                printf("Character limit exceeded !! TRY AGAIN.\n");
                continue;
            } else {
                break;
            }
        }

        char newCharArr[charArr_len];
        int countArr[charArr_len];
        int count = 0;
        int flag = 0;

        for (int i = 0; i < strlen(charArr); i++)
        {
            int check = 1;
            for (int j = 0; j < strlen(newCharArr); j++)
            {
                if(charArr[i]==newCharArr[j]){
                    countArr[j]++;
                    check = 0;
                    break;
                }
            }
            if(check){
                newCharArr[flag] = charArr[i];
                countArr[flag] = 1;
                flag++;
                count++;
            }
        }

        if (write(file[1], &count, sizeof(count)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }
        if (write(file[1], &newCharArr, sizeof(char)*count) == -1){
            printf("Error ocurred while Writing.\n");
            return 5;
        }
        if (write(file[1], &countArr, sizeof(int)*count) == -1){
            printf("Error ocurred while Writing.\n");
            return 6;
        }

        close(file[1]);
    } else {
        close(file[1]);

        int len;

        if(read(file[0], &len, sizeof(len)) == -1){
            printf("Error ocurred while Reading.\n");
            return 7;
        }

        char charArr[len];
        if(read(file[0], &charArr, sizeof(char)*len) == -1){
            printf("Error ocurred while Reading.\n");
            return 8;
        }

        int countArr[len];
        if(read(file[0], &countArr, sizeof(int)*len) == -1){
            printf("Error ocurred while Reading.\n");
            return 9;
        }

        for (int i = 0; i < len; i++)
        {
            printf("%c\t%d\n", charArr[i], countArr[i]);
        }

        close(file[0]);
    }

    return 0;
}