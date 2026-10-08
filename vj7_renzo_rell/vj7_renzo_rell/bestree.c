#include <stdio.h>
#include <stdlib.h>
#include "bestree.h"

BSTree NewBSTree()
{
    // Novo prazno stablo
    return NULL;
}

void AddNode(BSTree *bst, char *word)
{
    // Rekurzivno se traûi mjesto za novi Ëvor u stablu. Ako rijeË postoji u stablu, ne dodaje se.
    // bst parametar je dvostruki pokazivaË.
    if (*bst == NULL) {
        *bst = (BSTree)malloc(sizeof(Node));
        (*bst)->word = strdup(word);
        (*bst)->left = NULL;	
        (*bst)->right = NULL;
    }
    else {
        if (strcmp((*bst)->word, word) > 0) {
            AddNode((&(*bst)->left), word);
        }
        else if (strcmp((*bst)->word, word) < 0){
            AddNode((&(*bst)->right), word);
        }
        else {
            free(word);
        }
    }
}

int BSTHeight(BSTree bst)
{
    // Rekurzivno se prolazi cijelo stablo da bi se pronaöla najduûa grana (visina stabla).
    int left = 0;
    int right = 0;
    if (bst == NULL) {
        return 0;
    }
    left = BSTHeight(bst->left);
    right = BSTHeight(bst->right);
    if (left < right) {
        return right + 1;
    }
    else {
        return left + 1;
    }
}

void PrintBSTree(BSTree bst)
{
    // Ispisuje rijeËi u stablu na ekran po abecednom redu.
    // In-order öetnja po stablu (lijevo dijete, Ëvor, desno dijete)
    if (bst == NULL) {
        return;
    }
    PrintBSTree(bst->left);
    puts(bst->word);
    PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
    // Snima rijeË po rijeË iz stabla u tekstualnu datoteku. RijeËi su odvojene razmakom.
    // Pre-order öetnja po stablu (ttenutni Ëvor pa djeca)
    if (bst == NULL) {
        return;
    }
    fprintf(fd, "%s ", bst->word);
    SaveBSTree(bst->left, fd);
    SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
    // Briöe stablo (string word i sam Ëvor) iz memorije.
    // Post-order öetnja po stablu (prvo djeca pa trenutni Ëvor)
    if (bst == NULL) {
        return;
    }
    DeleteBSTree(bst->left);
    DeleteBSTree(bst->right);
    free(bst->word);
    free(bst);
}

BSTree LoadBSTree(FILE *fd)
{
    // UËitava rijeË po rijeË iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
    // RijeË duplicirati sa strdup().
    BSTree tree = NewBSTree();
    char word[1024];
    while (fscanf(fd, "%s", word) != EOF)
        AddNode(&tree, strdup(word));
    return tree;
}
