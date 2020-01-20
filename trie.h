#pragma once

#define NUM_LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} Node;


Node* add(Node* root,char c);
Node* Search_letter(Node* root, char c,int index);
int if_space(char c);
boolean check_if_exist(Node* root, int index);
void print(const Node* root);

