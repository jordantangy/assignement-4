#include<stdbool.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Trie;


void addTrie(TrieNode** head, int data);
void remove(TrieNode** head, int data);
bool find(const TrieNode* head, int data);
void print(const TreeNode*);