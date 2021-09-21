#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <string.h>

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').

   Zero terminators are not printable (therefore false) */

bool delim_character(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return true;
  }else{
    return false;
  }



}

/* Return true (non-zero) if c is a non-whitespace

   character (not tab or space).

   Zero terminators are not printable (therefore false) */

bool non_delim_character(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return false;
  }else{
    return true;
  }


}



/* Returns a pointer to the first character of the next

   space-separated word*/

char *word_start(char* str){
  for(int i = 0;*(str + i)!='\0';i++){
    if(non_delim_character(*(str+1))){
	return str + i;
      }
      }


}



/* Returns a pointer to the first space character of the zero

   terminated string*/

char *end_word(char* str){
  char *first = word_start(str);
    for(int i = 0;*(first +i) != '\0';i++){
      if(delim_character(*(first + i + 1))){
	  return first + 1;
	}
	}


}

// counts the number of words or tokens

int count_tokens(char* str){
  int count = 0;
  for (int i =0; *(str +i) != '\0'; i++){
    if(non_delim_character(*(str+i))){
      if(delim_character(*(str+i+ 1))){
	    count++;
	  }
	
	  }
     }
      return count;


}
char *copy_str(char *inStr, short len){
  char *temp = (char *)malloc(len);
  for (int i =0; i<len; i++){
    *(temp+i) = *(inStr + i);
  }
  *(temp + len) = '\n';
  return temp;


}



char** tokenize(char* str){
  char tokens = count_tokens(str) + 1;
  char **token_array = (char **)malloc(sizeof(char *) *(tokens+1));


  int i =0;
  token_array[i] = strtok(str, " ");
  for(i = 1; i< tokens; i++){
    token_array[i] = strtok(NULL, " ");

  }
  token_array[i++] = '\0';
  return token_array;

}





void print_all_tokens(char** tokens){
  for(int i =0; *(tokens + i)!= '\0'; i++){
    printf( "token[%d]=%s\n",i, *(tokens +i)); 
  }
}



 int main(){
   char test1[] = "test one tokenizer lab";
   print_all_tokens(tokenize(test1));
   return 0;
     }



/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     token
*/
