
/*
5.  Enter/Input 10 numbers and display the numbers in ascending order.
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

void insertionSort(int arr[], int n);

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

        int aArr[SIZE];

        printf("You have to enter %d numbers.\n", SIZE);
        for(int i = 0; i < SIZE; i++){
            printf("Input a number -> ");
            scanf("%d", &aArr[i]);
        }

        if (write(file[1], &aArr, sizeof(aArr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(file[1]);
    } else {
        close(file[1]);

        int bArr[SIZE];

        if(read(file[0], &bArr, sizeof(bArr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        insertionSort(bArr, SIZE);

        for(int i = 0; i < SIZE; i++){
            printf("%d\t", bArr[i]);
        }
        printf("\n");

        close(file[0]);
    }
    return 0;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}