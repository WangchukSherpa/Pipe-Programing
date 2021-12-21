
/*
3.  Collect the Ethernet address in hexadecimal and generate the 48 bit pattern of the same.
*/
 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20

int main(int argc, char const *argv[])
{
    int f[2];

    
    if (pipe(f) == -1){
        printf("Error in pipe operation.\n");
        return 1;
    }

    int id = fork();
    if (id == -1){
        printf("Error in fork.\n");
        return 2;
    }

    if (id == 0){
        close(f[0]);

        char arr[SIZE];
        while(1) {
            printf("Enter your Ethernet address of 12 Hexadecimal characters : ");
            scanf(" %[^\n]", arr);
            
            if(strlen(arr)==12){
                printf("Address successfully inserted, conversion on-progress.\n");
                break;
            } else {
                printf("Seems like your address is not valid, Try again.\n");
                continue;
            }
        }

        if (write(f[1], &arr, sizeof(arr)) == -1){
            printf("Error ocurred while Writing.\n");
            return 4;
        }

        close(f[1]);
    } else {
        close(f[1]);

        char arr[SIZE];

        if(read(f[0], &arr, sizeof(arr)) == -1){
            printf("Error ocurred while Reading.\n");
            return 5;
        }

        printf("Conversion ready :\n");
        for (int i = 0; i < 12; i++) {
            switch (arr[i])
            {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'a':
            case 'A':
                printf("1010");
                break;
            case 'b':
            case 'B':
                printf("1011");
                break;
            case 'c':
            case 'C':
                printf("1100");
                break;
            case 'd':
            case 'D':
                printf("1101");
                break;
            case 'e':
            case 'E':
                printf("1110");
                break;
            case 'f':
            case 'F':
                printf("1111");
                break;
            default:
                printf("Ethernet address seems to contain non-hexadecimal character.\n");
                break;
            }
            printf(" ");
        }
        printf("\n");
        printf("White-spaces are provided for readibility\n");
        printf("Visit Again! (^.^)\n");

        close(f[0]);
    }

    return 0;
}