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
	return FALSE;
}


  Node* add(Node* root, char c){

      
        int ascii_value = 0; 
        int index = 0;
        

        ascii_value = tolower(c);		
		index = NUM_LETTERS-(ascii_max-ascii_value)-1;
        if(check_if_exist(root,index)){ 
            return root->children[index];
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

  void printWord(){

  }


int main() {

	Node* root = malloc(sizeof(Node));
  Node* const theroot = root;
	root->letter = 0;
	root->count = 0;
	for (size_t i = 0; i < NUM_LETTERS; i++){
		root->children[i] =  NULL;
	}
    char c;
    int max_word_length = 0;
    int temp = 0;
    while(1){
      c = getchar();
      if(c ==  EOF){
        root->count++;
        if(temp > max_word_length){
        max_word_length = temp;
      }
         break;
    }
    if(c == ' '){
      root->count++;
      root = theroot;
      if(temp > max_word_length){
        max_word_length = temp;
      }
      temp = 0;
      continue;
    }
    temp++;
    root = add(root,c);
   
  }

}

