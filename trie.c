#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include<ctype.h>
#define ascii_max 122

//The first three functions are helping functions that are used in the add function.

//Returns true if there is a pointer (address) in the children array at place index , return false if null.
boolean check_if_exist(Node* root, int index){
	if(root->children[index] != NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//if there is a space that separates between two words, this function will return the last char before the space
//so that we can go back to its node and update the counter.
char if_space(char c){
    int b = 0;
    int *t;
    int a = 0;
	while (1)
	{
        a = c;
         if (a == 32)
		    {
            t = &b;
            a = *t;
            return a;
            }
        b = c;
   }  
}

//The add function checks for each letter if its node already exists in the tree.
//For example, a word that starts with the the letter 'a' already exists in the tree. Let's say that now, we try to add a a word that also starts with 'a' another time,
//this function will return a pointer to the node with the letter 'a', and from there, the add function will continue adding other letters.
//Such that we wont have multiple pointer to the node that contains the letter 'a' at the beginning of the word.
Node* Search_letter(Node* root, char c,int index){
        while (root->children[index]->letter == c)
        {
            root = root->children[index];
        }
        return root; 
    }


void add(Node* root){

        
        Node* rootCopy = root; //copy the pointer of the rood node, used in case where the char detected is space.
         int ascii_value = 0; 
        int index = 0; 

         char c;
        while (c != EOF){
            c = getchar();
            char d = if_space(c);
            ascii_value = tolower(c);		
		    index = NUM_LETTERS-(ascii_max-ascii_value)-1;
            if(check_if_exist(root,index) == TRUE){ 
              root =  Search_letter(root,c,index);
        }
		Node* temp = malloc(sizeof(Node)); 
		temp->letter=c;
		temp->count = 0;
		for (size_t i = 0; i < NUM_LETTERS; i++)
			{
				temp->children[i] = NULL;
			}
		root->children[index] = temp;	

        if(c == ' '){
        ascii_value = tolower(d);		
		index = NUM_LETTERS-(ascii_max-ascii_value)-1;
        (root->children[index])->count = (root->children[index]->count)+1;
        root = rootCopy; // if the letter is space, then go back to the original root, and from there we will add the next word.
        continue;
       }

		free(temp);

	}

    

       

}

int main() {

	Node* root = malloc(sizeof(Node));
	root->letter = 0;
	root->count = 0;
	for (size_t i = 0; i < NUM_LETTERS; i++)
	{
		root->children[i] =  NULL;
	}

    

    add(root);

        
}