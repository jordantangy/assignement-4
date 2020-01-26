#pragma once

#define NUM_LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} Node;


boolean check_if_exist(Node* root, int index);
Node* add(Node* root, char c);
void print(Node* root, char* word, int counter);
void printBack(Node* root, char* word, int counter);
void end(Node* root);
