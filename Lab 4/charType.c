//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//February 10, 2018
//takes an in file and sorts the lines by alphabetic, numeric, punctuations, and whitespace into an out file

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>

#define MAX_STRING_LENGTH 100
void extract_chars(char* s, char* a, char* d, char* p, char* w);

int main(int argc, char* argv[]) {
  FILE* in;
  FILE* out;
  char* line;
  char* alpha;
  char* num;
  char* punct;
  char* whitespace;
  int lineNum = 1;

  if( argc != 3 ) {
    printf("Usage: %s input-file output-file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ( (in=fopen(argv[1], "r"))==NULL ) {
    printf("Unable to read from file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ( (out=fopen(argv[2], "w"))==NULL ) {
    printf("Unable to write to file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  line = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
  alpha = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
  num = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
  punct = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
  whitespace = calloc(MAX_STRING_LENGTH + 1, sizeof(char));
  assert( line != NULL && alpha != NULL && num != NULL && punct != NULL && whitespace != NULL);

  while( fgets(line, MAX_STRING_LENGTH, in) != NULL ) {
    extract_chars(line, alpha, num, punct, whitespace);
    fprintf(out, "line %d contains: \n", lineNum);

    if(strlen(alpha)==1) {
      fprintf(out, "%d alphabetic character: %s\n", (int)strlen(alpha), alpha);
    }
    else {
      fprintf(out, "%d alphabetic characters: %s\n", (int)strlen(alpha), alpha);
    }
    if(strlen(num)==1){
      fprintf(out, "%d numeric character: %s\n", (int)strlen(num), num);
    }
    else {
      fprintf(out, "%d numeric characters: %s\n", (int)strlen(num), num);
    }
    if(strlen(punct)==1) {
      fprintf(out, "%d punctuation character: %s\n", (int)strlen(punct), punct);
    }
    else {
      fprintf(out, "%d punctuation characters: %s\n", (int)strlen(punct), punct);
    }
    if(strlen(whitespace)==1) {
      fprintf(out, "%d whitespace character: %s\n", (int)strlen(whitespace), whitespace);
    }
    else {
      fprintf(out, "%d whitespace characters: %s\n", (int)strlen(whitespace), whitespace);
    }
    lineNum++;
  }

  free(line);
  line = NULL;
  free(alpha);
  alpha = NULL;
  free(num);
  num = NULL;
  free(punct);
  punct = NULL;
  free(whitespace);
  whitespace = NULL;

  fclose(in);
  fclose(out);
  return (EXIT_SUCCESS);

}

void extract_chars(char* s, char* a, char* d, char* p, char* w) {
  int i=0, j=0, x=0, y=0, z=0;
  while(s[i]!='\0' && i<MAX_STRING_LENGTH) {
    if(isalpha(s[i])) {
      a[j] = s[i];
      j++;
    }
    else if(isdigit(s[i])) {
      d[x] = s[i];
      x++;
    }
    else if(ispunct(s[i])) {
      p[y] = s[i];
      y++;
    }
    else {
      w[z] = s[i];
      z++;
    }
    i++;
  }
  a[j] = '\0';
  d[x] = '\0';
  p[y] = '\0';
  w[z] = '\0';
}
