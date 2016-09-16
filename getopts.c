/*
  CSE 109
  Sarah Botwinick
  scb219
  Program Description:getopts file for my shell
  Program #2
*/
#include <string.h>
#include <stdlib.h>

char ** getopts(char cmd[]){

 
  //char ncmd[sizeof(cmd)];
//strcpy(ncmd, cmd);
  //split into tokens
char *token = strtok(cmd, " ");
//create a counter variable
 int place = 0;
 while( token != NULL){
   place++;
   token = strtok(NULL, " ");
 }
//int x = sizeof(token);
//create array for tokens
 char** tokarray;
 tokarray= malloc((sizeof (char*))*place);
 token = strtok(cmd, " ");
 int x = 0;

 while(token !=NULL){
   //   int stringlength = strlen(place);
   tokarray[x] = malloc(place + 1);
   //add tokens to array
   strcpy(tokarray[x], token);
   x++;
   token = strtok( NULL, " ");
 }

 return tokarray;

 
}
