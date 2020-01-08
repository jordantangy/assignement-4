#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#define ascii_max 122



void print(const Node* root) {

}

void add(Node** root, char word){

	int index = NUM_LETTERS-(ascii_max-word)-1;
	
	Node* temp = malloc(sizeof(Node));
	temp->letter=word;
	temp->count = 0;
	temp->children[index] = NULL;
	*root = temp;
}




int main() {
	char letter = 0;
	
	Node *root = malloc(sizeof(Node));
	root->letter = NULL;
	root->count = 0;
	*(root->children) = NULL;










	while (letter != '\n') {
		scanf("%c",&letter);
		printf("%c\n", letter);
		add(&root, letter);

	}
	return 0;
}