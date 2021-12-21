
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  fork();
  fork();
  fork();
  fork();
  printf("Hello world\n");
  return 0;
}
