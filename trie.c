#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#define ascii_max 122



void print(const Node* root) {

}

void add(Node* root, char* word){

	
	int index = NUM_LETTERS-(ascii_max-*word)-1;

	if(isNull(root,index) == 0){
		Node* temp = malloc(sizeof(Node));
		temp->letter=*word;
		temp->count = 0;
		*(temp->children) = NULL;
		root->children[index] = temp;
	}
	else{
		*root++;
		*word++;
		add(root,word);
	}
		
	
	

}

boolean isNull(Node* ptr, int index){
	if(ptr->children[index] == NULL){
		return 0;
	}
	else{
		return 1;
	}	
}

char* getword(char w[]){

    int counter = 0;
	char* c = w;
    while (*c != ''){
        counter++;
        c++;
    }
	return c;

}

int main() {
	
	
	Node *root = malloc(sizeof(Node));
	root->letter = NULL;
	root->count = 0;

	char word[30] = {0};
    char *wordP = word;
    while(1){
        scanf("%c", wordP);
        if (*wordP == ' '){
            *wordP = '\n';
            break;
        }
		add(root,wordP);
        wordP++;
    }
}