#include <unistd.h>

void main(void){
  char *programName = "ls";
  char *arg1 = "-l";
  execlp(programName,programName,arg1,NULL);
}
