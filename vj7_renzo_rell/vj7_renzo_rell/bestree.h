#ifndef BESTREE_H
#define BESTREE_H
#include <string.h>

// »vor stabla sa pokazivaËom na rijeË i na djecu Ëvora
typedef struct Node {
    char *word;
    struct Node *left, *right;
} Node;

// Stablo odnosno pokazivaË na korijen stabla
typedef Node* BSTree;

BSTree NewBSTree();

void AddNode(BSTree *bst, char *word);

int BSTHeight(BSTree bst);

void PrintBSTree(BSTree bst);

void SaveBSTree(BSTree bst, FILE *fd);

void DeleteBSTree(BSTree bst);

BSTree LoadBSTree(FILE *fd);

#endif
