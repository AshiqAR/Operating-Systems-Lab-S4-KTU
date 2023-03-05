#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void main(){
  int p1,p2;
  char s[20];
  p1 = open("file.txt",O_RDWR);
  char data[] = "this is a sentence";

  if(p1!=-1){
    printf("File in p1 opened\n");
    write(p1,data,sizeof(data));
    printf("Data writen into the file\n");
    close(p1);
    printf("File in pointer p1 closed\n\n");
  }

  p2 = open("file.txt",O_RDWR);
  if(p2!=-1){
    printf("File p2 opened\n");
    read(p2,s,sizeof(data));
    printf ("Data in the file: %s\n",s);
    close(p2);
    printf("File p2 closed\n");
  }
}
