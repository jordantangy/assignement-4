#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#define ascii_max 122



void print(const Node* root) {

}

void add(Node* root, char* word){

	
	int index = NUM_LETTERS-(ascii_max-*word)-1;
	Node* temp = malloc(sizeof(Node));
	temp->letter=word;
	temp->count = 0;
	root->children[index] = temp;
	
}

int main() {
	
	
	Node *root = malloc(sizeof(Node));
	root->letter = NULL;
	root->count = 0;
	
	return 0;
}