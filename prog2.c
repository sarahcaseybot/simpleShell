#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
  Sarah Botwinick
  scb219
  Program Description:Main function for a shell
*/
char ** getopts(char cmd[]);


int main(int argc, char *argv[]){
  char name[100];
  gethostname(name,100);
  strcat(name,">");
  puts(name);
  int y = 3;

  //read input
  while(y == 3){
  char comstr[100];
  fgets(comstr, sizeof(comstr), stdin);

   //chop off end line character


   comstr[strlen(comstr) - 1] = '\0';


   //check if command is exit
   int x = strcmp(comstr, "exit");
   if(x == 0){
     return 0;
   }
   else{
     char**  newargv = getopts(comstr);
   if (fork() == 0) {
     execvp(newargv[0], newargv);
   } else {
     wait(NULL);
   }
   }
  }
  return 0;
}
