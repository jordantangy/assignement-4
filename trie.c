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



//The add function checks for each letter if its node already exists in the tree.
//For example, a word that starts with the the letter 'a' already exists in the tree. Let's say that now, we try to add a a word that also starts with 'a' another time,
//this function will return a pointer to the node with the letter 'a', and from there, the add function will continue adding other letters.
//Such that we wont have multiple pointer to the node that contains the letter 'a' at the beginning of the word.
Node* Search_letter(Node* root, char c,int index){
        
        if(root->children[index]->letter != c){
          return root;
        }
        else 
        {
          c = getchar();
          int ascii_value = tolower(c);		
		      index = NUM_LETTERS-(ascii_max-ascii_value)-1;
          
          root = root->children[index];
         
          
          return Search_letter(root,c,index);
        }
         
    }

  Node* add(Node* root, char c){

      
        int ascii_value = 0; 
        int index = 0; 

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
    root = temp;

    return root;

    
  


   

	}


int main() {

	Node* root = malloc(sizeof(Node));
  Node* const theroot = root;
	root->letter = 0;
	root->count = 0;
	for (size_t i = 0; i < NUM_LETTERS; i++)
	{
		root->children[i] =  NULL;
	}
  
 
    char c;
    while(1){
      c = getchar();
      if(c ==  EOF){
         break;
    }
    if(c == ' '){
      root->count = (root->count)+1;
      root = theroot;
      continue;
    }
    root = add(root,c);
  }
}
