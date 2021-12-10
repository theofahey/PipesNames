#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
  char text[1000];
  int mariopipe = open("mario",O_RDONLY);
  int luigipipe = open("luigi", O_WRONLY);
  while(1){
  read(mariopipe,text,sizeof(text));
  int i,hold,length;
  length = strlen(text);
  for (i = 0; i < length/2;i++){
   hold = text[i];
   text[i] = text[length - i - 1];
   text[length - i - 1] = hold;
 }
 write(luigipipe,text,sizeof(text));
}
return 0;
}
