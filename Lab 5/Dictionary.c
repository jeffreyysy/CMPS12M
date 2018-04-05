//Jeffrey Yeung
//jeyyeung
//CMPS 12M
//February 21, 2018
//implementation for dictionary ADT

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"

typedef struct NodeObj{
  char* key;
  char* value;
  struct NodeObj* next;
}
NodeObj;

typedef NodeObj* Node;

Node newNode(char* k, char* v) {
  Node N = malloc(sizeof(NodeObj));
  assert(N!=NULL);
  N->key = k;
  N->value = v;
  N->next = NULL;
  return(N);
}

void freeNode(Node* pN) {
  if( pN!=NULL && *pN!=NULL ) {
    free(*pN);
    *pN = NULL;
  }
}

typedef struct DictionaryObj{
  Node head;
  Node tail;
  int numItems;
}
DictionaryObj;

Dictionary newDictionary(void) {
  Dictionary D = malloc(sizeof(DictionaryObj));
  assert(D!=NULL);
  D->head = NULL;
  D->tail = NULL;
  D->numItems = 0;
  return D;
}

void freeDictionary(Dictionary* pD) {
  if(pD!=NULL && *pD!=NULL ) {
    makeEmpty(*pD);
    free(*pD);
    *pD = NULL;
  }
}

int isEmpty(Dictionary D) {
  if( D == NULL) {
    fprintf(stderr, "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  return(D->numItems==0);
}

int size(Dictionary D) {
  if( D == NULL) {
    fprintf(stderr, "Dictionary Error: calling size() on NULL Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  return(D->numItems);
}

char* lookup(Dictionary D, char* k) {
  if( D == NULL) {
    fprintf(stderr, "Dictionary Error: calling lookup() on NULL Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  Node N = D->head;
  while( N != NULL) {
    if(strcmp(N->key,k)==0){
      return N->value;
    }
    N=N->next;
  }
  return NULL;
}

void insert(Dictionary D, char* k, char* v) {
  if(lookup(D, k) != NULL) {
    fprintf(stderr, "Dictionary Error: calling insert() on NULL Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  if(D->numItems != 0){
    Node N;
    N = newNode(k, v);
    D->tail->next = N;
    D->tail = N;
  }
  else {
    D->head = D->tail = newNode(k, v);
  }
  D->numItems++;
}

void delete(Dictionary D, char* k) {
  if( lookup(D, k)==NULL) {
    fprintf(stderr, "Dictionary Error: calling lookup() on NULL Dictionary reference\n");
    exit(EXIT_FAILURE);
  }
  D->numItems--;
  if(D->numItems==1) {
    makeEmpty(D);
  }
  else if (strcmp(D->head->key, k)) {
    Node N = D->head;
    Node curr = N;
    while(strcmp(N->key,k)) {
      curr = N;
      N=N->next;
    }
    curr->next=N->next;
    freeNode(&N);
  }
  else {
    Node N = D->head;
    Node curr = N->next;
    freeNode(&N);
    D->head=curr;
  }
}

void makeEmpty(Dictionary D) {
  Node curr1 = D->head;
  Node curr2 = D->head;
  while(curr1 != NULL) {
    curr1 = curr1->next;
    freeNode(&curr2);
    curr2 = curr1;
  }
  D->head = NULL;
  D->tail = NULL;
  D->numItems = 0;
}

void printDictionary(FILE* out, Dictionary D) {
  Node N;
  for(N=D->head; N!=NULL; N=N->next) {
    fprintf(out, "%s %s \n", N->key, N->value);
  }
}
