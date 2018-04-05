//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//January 31, 2018
//takes an input of a file txt and produces an output file that has the reverse of each word on a separate line

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringReverse(char* word) {
  int i;
  int j = strlen(word) - 1;
  int temp;
  for(i = 0; i < j; i++) {
    temp = word[i];
    word[i] = word[j];
    word[j] = temp;
    j--;
  }
}

//read file
int main(int argc, char * argv[]){
  FILE *in, *out; // handles for input and output files
  char word[256]; // char array to store words from input file

  // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // open input file for reading
   in = fopen(argv[1], "r");
   if( in==NULL ){
     printf("Unable to read from file %s\n", argv[1]);
     exit(EXIT_FAILURE);
   }

   // open output file for writing
   out = fopen(argv[2], "w");
   if( out==NULL ){
     printf("Unable to write to file %s\n", argv[2]);
     exit(EXIT_FAILURE);
   }

   // read words from input file, print on separate lines to output file
   while(fscanf(in, " %s", word)!=EOF){
     stringReverse(word);
     fprintf(out, "%s\n", word);
   }

   // close input and output files
   fclose(in);
   fclose(out);

   return(EXIT_SUCCESS);
}
