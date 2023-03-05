// create a sample directory and some random files

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct dirent *d_ptr;
void main(){
  char s[10];
  DIR *dirPtr;
  printf("opendir and readdir\n");
  printf("Enter the directory name: ");
  scanf(" %s",s);
  dirPtr = opendir(s);
  if(dirPtr == NULL){
    printf("directory not exit !\n");
    exit(1);
  }

  printf("Contents in the directory\n");
  while (d_ptr = readdir(dirPtr)) {
    printf("%s\n",d_ptr->d_name);
  }
  closedir(dirPtr);
}
