//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//February 21, 2018
//test file for Dictionary.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
   Dictionary A = newDictionary();
   char* k;
   char* v;
   char* word1[] = {"two","four","six","eight","ten"};
   char* word2[] = {"BOB","JERRY","RICHARD","WILL","CASH"};
   int i;
   for(i = 0; i < 5; i++) {
     insert(A, word1[i], word2[i]);
   }

   printDictionary(stdout,A); //prints out the array of numbers and names side by side

   for(i = 0; i < 5; i++) {
     k = word1[i];
     v= lookup(A,k);
     printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v); //prints the arrays and names again
   }

   //insert(A,"two","JOHNNY"); //program crashes since word1 array already has "two"

   delete(A,"four");
   delete(A,"six");

   printDictionary(stdout,A);//prints only the "two" "eight" and "ten"

   for(i = 0; i < 5; i++) {
     k = word1[i];
     v= lookup(A,k);
     printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v); //prints the arrays and names again, but four and six should be null
   }

   //delete(A,"four"); //deleting something that has been deleted already should be an error

   printf("%s\n", (isEmpty(A)?"true":"false")); //false since there are still 3 items
   printf("%d\n", size(A)); //size should be 3
   makeEmpty(A); //everything in the dictionary should be gone
   printf("%s\n", (isEmpty(A)?"true":"false")); //true since the makeEmpty method was called

   freeDictionary(&A);

   return(EXIT_SUCCESS);

 }
