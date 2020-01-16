#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include<ctype.h>
#define ascii_max 122


boolean check_if_exist(Node* root, int index){
	if(root->children[index] != NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

char if_space(){
    char c;
    int b = 0;
    int *t;
    int a = 0;
	while (1)
	{
        c = getchar();
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

Node* Search_letter(Node* root, char c,int index){
        while (root->children[index]->letter = c)
        {
            root = root->children[index];
        }
        return root; 
    }


void add(Node* root){

        char d = if_space();

         int ascii_value = 0; 
        int index = 0; 

         char c;
        while (c != EOF){
            c = getchar();
          
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