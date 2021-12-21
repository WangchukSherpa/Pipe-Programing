

/*
8.  Input numbers 1 â€“ 9 in any order and display the corresponding cardinality
    e.g. 2 (Input), Second (output)
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 15

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

        char numArr[SIZE];
        printf("You need to enter numbers (1-9) in any order (e.g., 453465).\n");
        printf("Enter the number : ");
        scanf("%s", numArr);
        
        if (write(file[1], &numArr, sizeof(numArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(file[1]);
    } else {
        close(file[1]);

        char numArr[SIZE];

        if(read(file[0], &numArr, sizeof(numArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        for (int i = 0; i < strlen(numArr); i++)
        {
            switch (numArr[i])
            {
            case '1':
                printf("First\n");
                break;
            case '2':
                printf("Second\n");
                break;
            case '3':
                printf("Third\n");
                break;
            case '4':
                printf("Fourth\n");
                break;
            case '5':
                printf("Fifth\n");
                break;
            case '6':
                printf("Sixth\n");
                break;
            case '7':
                printf("Seventh\n");
                break;
            case '8':
                printf("Eighth\n");
                break;
            case '9':
                printf("Nineth\n");
                break;
            }   
        }
        
        close(file[0]);
    }

    return 0;
}