#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
  CSE 109
  Sarah Botwinick
  scb219
  Program Description:Main function for a shell
  Program #2
*/
char ** getopts(char cmd[]);


int main(int argc, char *argv[]){
  // char hostcomp[] = gethostname();
  char name[100];
  gethostname(name,100);
  strcat(name,">");
  puts(name);
  int y = 3;

  //read input
  while(y == 3){
  char comstr[100];
  fgets(comstr, sizeof(comstr), stdin);
  // printf(comstr);

   //chop off end line character

   //  comstr[strlen(comstr)-1] = 0;
   // char *instr = malloc(strlen(comstr)+1);
   //  strcpy(instr, comstr);
   comstr[strlen(comstr) - 1] = '\0';
   //   printf(comstr);

   //check if command is exit
   int x = strcmp(comstr, "exit");
   if(x == 0){
     // printf("exited");
     // y = 7;
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
