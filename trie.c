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
    index = NUM_LETTERS - (ascii_max - ascii_value) - 1;
    if(check_if_exist(root,index)){ 
        return root->children[index];
    }
    Node* temp = (Node*) malloc(sizeof(Node)); 
    temp->letter = c;
    temp->count = 0;
    for (size_t i = 0; i <= NUM_LETTERS; i++) {
        temp->children[i] = NULL;
    }
    root->children[index] = temp;
    return temp;
}


void print(Node* root, char* worde, int counter) {
    boolean hasSon = FALSE;
    Node* temp = NULL;
    char* tempWorde = (char*)malloc((sizeof(char) * counter) + 1);
    *tempWorde = '/0';
    for (size_t i = 0; i < NUM_LETTERS; i++) {
        if (root->children[i] != NULL) {
            hasSon = TRUE;
            temp = root->children[i];
            char* wP = worde;
            char* tP = tempWorde;
            for (size_t i = 0; i < counter; i++) {
                *tP = *wP;
                tP++;
                wP++;
            }
            if (worde != NULL) free((void*)worde);
            if (root->letter == 0) {
                *tP = '\0';
                tP--;
                *tP = root->letter;
            }
            break;
        }
    }
    if (hasSon) {
        counter++;
        print(temp, tempWorde, counter);
        return;
    }
    else {
        if (root->count > 0) {
            printf("%s%c\t%ld", worde, root->letter, root->count);
        }
        free((void*)root);
    }
}
 

int main() {
    Node* root = malloc(sizeof(Node));
    Node* const theRoot = root;
    root->letter = 0;
    root->count = 0;
    for (size_t i = 0; i <= NUM_LETTERS; i++){
        root->children[i] =  0;
    }
    char c;
    while(1){
        c = getchar();
        if(c == EOF){
            root->count++;
        break;
        }
        if(c == ' ' || c == '\n' || c == '\t'){
            root->count++;
            root = theRoot;
            continue;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            root = add(root, c);
        }
    }
    root = theRoot;
    while (root != NULL) {
        print(root, NULL, 0);
        root = theRoot;
    }
   
}