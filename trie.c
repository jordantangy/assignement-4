#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


void print(const Node* head) {

}


int main() {
	char letter ='\0';
	Node *head = NULL;
	#pragma warning(suppress : 4996)
	while (scanf("%c", &letter) == 0) {
		add(&head, letter);
	}
	return 0;
}