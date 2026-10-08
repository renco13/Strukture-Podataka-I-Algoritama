#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

Dictionary create() {
	Dictionary dict = (Word*)malloc(sizeof(Word));
	dict->word = NULL;
	dict->count = 0;
	dict->next = NULL;
	return dict;
}

void destroy(Dictionary dict) {
    while (dict != NULL) {
        Dictionary delete = dict;
        dict = dict->next;
        free(delete->word);
        free(delete);
    }
}

void add(Dictionary dict, char *str) {
    Dictionary temp = dict;
    Dictionary new = (Dictionary)malloc(sizeof(Word));
    if (!new)
        puts("Malloc error");
    new->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(new->word, str);
    new->count = 1;
    while (temp->next != NULL) {
        if (strcmp(temp->next->word, str) == 0) {
            temp->next->count++;
            free(new->word);
            free(new);
            return;
        }
        else if (strcmp(temp->next->word, str) > 0) {
            new->next = temp->next;
            temp->next = new;
            return;
        }
        temp = temp->next;
    }
    temp->next = new;
    new->next = NULL;
}

int filterr(Word* w) {
    if (w != NULL && w->word != NULL) {
        if (strlen(w->word) > 2) {
            if (w->count > 4 && w->count < 11)
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

void print(Dictionary dict) {
    dict = dict->next;
    while (dict != NULL) {
        printf("%d - ", dict->count);
        puts(dict->word);
        dict = dict->next;
    }
}

Dictionary filterDictionary(Dictionary indict, int (*filterr)(Word* w)) {
    Dictionary temp = indict;
    while (temp->next != NULL) {
        if (filterr(temp->next) != 1) {
            Dictionary del = temp->next;
            temp->next = temp->next->next;
            free(del->word);
            free(del);
        }
        else
            temp = temp->next;
    }
    return indict;
}

//

Dictionary najdulja(Dictionary dict) {
    Dictionary tmp = dict->next;
    Dictionary max = dict->next;
    while (tmp != NULL) {
        if (strlen(tmp->word) > strlen(max->word)) {
            max = tmp;
        }
        tmp = tmp->next;
    }
    return max;
}

void brojrijeci(Dictionary dict) {
    int count = 0;
    dict = dict->next;
    while(dict != NULL) {
        dict = dict->next;
        count++;
    }
    printf("%d\n", count);
}

void dodajnapocetak(Dictionary dict, char* rijec) {
    Dictionary tmp = dict->next;
    Dictionary novi = malloc(sizeof(Word));
    novi->word = strdup(rijec);
    novi->count = 1;
    novi->next = tmp;
    dict->next = novi;
}

void zamjeniprvizadnji(Dictionary dict) {
    Dictionary predzadnji = dict;
    Dictionary prvi = dict->next;
    Dictionary zadnji = dict->next;
    while (zadnji->next != NULL) {
        zadnji = zadnji->next;
        predzadnji = predzadnji->next;
    }
    dict->next = zadnji;
    zadnji->next = prvi->next;
    predzadnji->next = prvi;
    prvi->next = NULL;
}

Dictionary razdvojizanovu(Dictionary dict) {
    Dictionary tmp = dict->next;
    Dictionary novi = create();
    Dictionary tmp2 = novi;
    while (tmp != NULL) {
        if (strcmp(tmp->word, "c") > 0) {
            Dictionary novaric = malloc(sizeof(Word));
            novaric->word = strdup(tmp->word);
            novaric->count = 1;
            novaric->next = NULL;
            tmp2->next = novaric;
            tmp2 = tmp2->next;
        }
            tmp = tmp->next;
        
    }
    return novi;
}

void maknisvakodrugi(Dictionary dict) {
    Dictionary prev = dict;
    Dictionary curr = dict->next;
    prev = curr;
    curr = curr->next;
    while(curr != NULL) {
        Dictionary del = curr;
        curr = curr->next;
        prev->next = curr;
        free(del->word);
        free(del);
        curr = curr->next;
        prev = prev->next;
    }
}

void dodavanjeulistu(Dictionary dict, char* rijec) {
    Dictionary tmp = dict->next;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    Dictionary novi = malloc(sizeof(Word));
    novi->word = strdup(rijec);
    novi->count = 1;
    novi->next = NULL;
    tmp->next = novi;
}

void dodavanjenapocetak(Dictionary dict, char* rijec) {
    Dictionary tmp = dict->next;
    Dictionary novi = malloc(sizeof(Word));
    novi->word = strdup(rijec);
    novi->count = 1;
    dict->next = novi;
    novi->next = tmp;
}

void dodavanjeizniza(Dictionary dict, char* rijec[]) {
    Dictionary tmp = dict->next;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    int i = 0;
    while (i < 3) {
        Dictionary novi = malloc(sizeof(Word));
        novi->word = strdup(rijec[i]);
        novi->count = 1;
        novi->next = NULL;
        tmp->next = novi;
        tmp = tmp->next;
        i++;
    }
}

void dodavanjeuniz(Dictionary dict, char* arr[]) {
    Dictionary tmp = dict->next;
    int i = 0;
    while (tmp != NULL) {
        arr[i] = strdup(tmp->word);
        i++;
        tmp = tmp->next;
    }
}

void dodajnakond(Dictionary dict,char* rijec) {
    Dictionary prev = dict->next;
    Dictionary curr = prev->next;
    while (prev != NULL) {
        if (strcmp(prev->word, rijec) == 0) {
            Dictionary novi = malloc(sizeof(Word));
            novi->word = strdup("xd");
            novi->count = 1;
            novi->next = curr;
            prev->next = novi;
            return;
        }
        curr = curr->next;
        prev = prev->next;
    }
}

void okreni(Dictionary dict) {
    Dictionary temp1 = dict->next;
    dict->next = NULL;
    while (temp1 != NULL) {
        Dictionary temp2 = temp1;
        temp1 = temp1->next;
        temp2->next = dict->next;
        dict->next = temp2;
    }
}

Dictionary dodavanjeizlisteunovulistu(Dictionary dict) {
    Dictionary tmp = dict->next;
    Dictionary tmp2 = create();
    Dictionary novalista = tmp2;
    while (tmp != NULL) {
        if (strcmp(tmp->word, "d") > 0) {
            Dictionary novi = malloc(sizeof(Word));
            novi->word = strdup(tmp->word);
            novi->count = 1;
            novi->next = NULL;
            tmp2->next = novi;
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return novalista;
}
