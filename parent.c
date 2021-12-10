#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
  mkfifo("mario", 0644);
  mkfifo("luigi", 0644);
  int mariopipe = open("mario",O_WRONLY);
  int luigipipe = open("luigi",O_RDONLY);
  char text[1000];
  while(1){

    printf("Please Enter Input: ");
    fgets(text,1000,stdin);
    write(mariopipe, text,sizeof(text));
    printf("Text Sent through mario: %s\n",text);
    read(luigipipe, text,1000);
    printf("Text Outputted through Luigi: %s\n",text);
  }
  return 0;
}
