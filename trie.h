#include<stdbool.h>
#define NUM_LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} Trie;

void addTrie(Trie** head, char letter);
void remove(Trie** head, char letter);
bool find(const Trie* head, char letter);
