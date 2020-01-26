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


void print(Node* root, char* word, int counter) {
    boolean hasSon = FALSE;
    Node* son = NULL;
    for (size_t i = 0; i < NUM_LETTERS; i++) {
        if (root->children[i] != NULL) {
            hasSon = TRUE;
            son = root->children[i];
            word[counter] = son->letter;
            print(son, word, counter + 1);
        }
    }
    if (!hasSon) {
        word[counter] = '\0';
        if (root->count > 0) {
            printf("%s\t%ld\n", word, root->count);
        }
    }
}


void printBack(Node* root, char* word, int counter) {
    boolean hasSon = FALSE;
    Node* son = 0;
    for (int i = NUM_LETTERS - 1; i >= 0; i--) {
        if (root->children[i] != NULL) {
            hasSon = TRUE;
            son = root->children[i];
            word[counter] = son->letter;
            printBack(son, word, counter + 1);
        }
    }
    if (!hasSon) {
        word[counter] = '\0';
        if (root->count > 0) {
            printf("%s\t%ld\n", word, root->count);
        }
    }
}

void end(Node* root) {
    Node* son = 0;
    for (size_t i = 0; i < NUM_LETTERS; i++) {
        if (root->children[i] != NULL) {
            hasSon = TRUE;
            son = root->children[i];
            end(son);
        }
    }
    free(root);
}


int main(int argc, char* argv[]) {
    size_t wordCounter = 0;
    size_t tempCounter = 0;
    Node* root = malloc(sizeof(Node));
    Node* const theRoot = root;
    root->letter = '\0';
    root->count = 0;
    for (size_t i = 0; i < NUM_LETTERS; i++) {
        root->children[i] = 0;
    }
    char c;
    while (1) {
        c = getchar();
        if (c == EOF) {
            root->count++;
            if (tempCounter > wordCounter) {
                wordCounter = tempCounter;
                tempCounter = 0;
            }
            break;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            root->count++;
            root = theRoot;
            if (tempCounter > wordCounter) {
                wordCounter = tempCounter;
                tempCounter = 0;
            }
            continue;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            root = add(root, c);
            tempCounter++;
        }
    }
    root = theRoot;
    if (argc == 1) {
        char* temp = (char*)malloc(wordCounter + 1);
        print(root, temp, 0);
        free(temp);
    }
    else {
        char* temp = (char*)malloc(wordCounter + 1);
        printBack(root, temp, 0);
        free(temp);
    }
    end(wordCounter);
}