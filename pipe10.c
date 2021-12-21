
/*
10.  Enter a word and display the word in reverse order.
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20

void reverse_string(char arr[]);

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
        
        char aArr[SIZE];

        printf("Enter a word : ");
        scanf("%[^\n]", aArr);

        if (write(file[1], &aArr, sizeof(aArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(file[1]);
    } else {
        close(file[1]);

        char bArr[SIZE];

        if(read(file[0], &bArr, sizeof(bArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        } 

        reverse_string(bArr);

        close(file[0]);
    }

    return 0;
}

void reverse_string(char arr[]){
    int len = strlen(arr);
    for(int i=0; i < len; i++, len--){
        char flag = arr[i];
        arr[i] = arr[len-1];
        arr[len -1] = flag;
    }
    printf("Reversed string is : ");
    puts(arr);
}