/*
  Sarah Botwinick
  scb219
  Program Description:getopts file for my shell
*/
#include <string.h>
#include <stdlib.h>

char ** getopts(char cmd[]){

  //split into tokens
char *token = strtok(cmd, " ");
//create a counter variable
 int place = 0;
 while( token != NULL){
   place++;
   token = strtok(NULL, " ");
 }

//create array for tokens
 char** tokarray;
 tokarray= malloc((sizeof (char*))*place);
 token = strtok(cmd, " ");
 int x = 0;

 while(token !=NULL){

   tokarray[x] = malloc(place + 1);
   //add tokens to array
   strcpy(tokarray[x], token);
   x++;
   token = strtok( NULL, " ");
 }

 return tokarray;

 
}
