#pragma once

#define NUM_LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} Node;


void add(Node* root);


void print(const Node* root);

