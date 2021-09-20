#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').

   Zero terminators are not printable (therefore false) */

bool delim_character(char c){
  if(c == ' ' || c == '\t'){
    return true;
  }else{
    return false;
  }



}



/* Return true (non-zero) if c is a non-whitespace

   character (not tab or space).

   Zero terminators are not printable (therefore false) */

bool non_delim_character(char c){
  if(c == ' ' || c == '\t'){
    return false;
  }else{
    return true;
  }


}



/* Returns a pointer to the first character of the next

   space-separated word*/

char *word_start(char* str){
  for(i = 0;*(str + i)!='\0';i++){
    if(non_delim_character(*(str+1)){
	return str + i;
      }
      }


}



/* Returns a pointer to the first space character of the zero

   terminated string*/

char *end_word(char* str){
  char *first = word_start(str)
    for(i = 0;*(first + 1) != '\0';i++){
      if(delim_character(*(first + i + 1)){
	  return first + 1;
	}
	}


}

// counts the number of words or tokens

int count_tokens(char* str){





}
char *copy_str(char *inStr, short len){



}



char** tokenize(char* str){

}





void print_all_tokens(char** tokens){

}



/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     token
