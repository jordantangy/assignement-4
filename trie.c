#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include<ctype.h>
#define ascii_max 122





void print(const Node* root) {

}

boolean check_if_exist(Node* root, int index){
	if(root->children[index] != NULL){
		return TRUE;
	}
	else {
		return FALSE;
	}
}


void add(Node* root){

	char c = getchar();
	while (c = getchar())
	{
		if (c == EOF)
		{
			break;
		}
		int ascii_value = tolower(c);		
		int index = NUM_LETTERS-(ascii_max-ascii_value)-1;

		if(c == ' '){
			c = c--;
			int ascii_value = tolower(c);		
			int index = NUM_LETTERS-(ascii_max-ascii_value)-1;
			(root->children[index])->count = (root->children[index])->count++;
			c++;
			continue;
		}
		while(c == (root->children[index])->letter && check_if_exist(root,index) == TRUE ){
			Node* ptr= root->children[index];
			root = ptr;
			int flag = 0;
			for (size_t i = 0; i < NUM_LETTERS; i++)
			{
				if(ptr->children[i] == NULL){
					flag = 1;
				}
			}
			if (flag == 1){
				break;
			}
			else
			{
				c++;
			}
	
		}
		Node* temp = malloc(sizeof(Node));
		temp->letter=c;
		temp->count = 0;
		for (size_t i = 0; i < NUM_LETTERS; i++)
			{
				temp->children[i] = NULL;
				
			}
		root->children[index] = temp;
		root = temp;

		free(temp);
	}
		
}


int main() {

	Node* root = malloc(sizeof(Node));
	root->letter = 0;
	root->count = 0;
	*(root->children) = NULL;
	
		
		add(root);
		
	
        
    
}