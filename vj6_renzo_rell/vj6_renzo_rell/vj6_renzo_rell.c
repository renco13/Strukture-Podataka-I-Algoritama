#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int prioritet;
    void* podaci;
} Element;

typedef struct {
    Element* niz;
    int n;
} Niz;

void print(Niz* qju) {
    for (int i = 0; i < qju->n; i++)
        printf("%d ", qju->niz[i].prioritet);
}

void zamjena_dva(Element* a, Element* b) {
    Element tmp = *a;
    *a = *b;
    *b = tmp;
}

void zamjena(Niz* qju, int roditelj_i, int i) {
    Element tmp = qju->niz[roditelj_i];
    qju->niz[roditelj_i] = qju->niz[i];
    qju->niz[i] = tmp;
}

void prema_vrhu(Niz* qju,int i) {
    if (i == 0)
        return;
    int roditelj_i = (i - 1) / 2;
    Element dite = qju->niz[i];
    Element roditelj = qju->niz[roditelj_i];
    if (dite.prioritet <= roditelj.prioritet)
        return;
    zamjena(qju, roditelj_i, i);
    prema_vrhu(qju, roditelj_i);
}

void prema_vrhu_iterativno(Niz* qju, int i) {
    if (i == 0)
        return;
    int roditelj_i = (i - 1) / 2;
    Element roditelj = qju->niz[roditelj_i];
    while (qju->niz[i].prioritet > roditelj.prioritet) {
        zamjena(qju, roditelj_i, i);
        i = roditelj_i;
        roditelj_i = (i - 1) / 2;
        roditelj = qju->niz[roditelj_i];
    }
}

void prema_dnu(Niz* qju, int i) {
    if (i == 0)
        return;
    int livodite = 2 * i + 1;
    int desnodite = 2 * i + 2;
    if (livodite >= qju->niz)
        return;
    Element* roditelj_element = &(qju->niz[i]);
    Element* livodite_element = &(qju->niz[livodite]);
    if (desnodite >= qju->niz) {
        if (livodite_element > roditelj_element->prioritet) {
            zamjena_dva(roditelj_element, livodite_element);
        }
        return;
    }
    Element* desnodite_element = &(qju->niz[desnodite]);
    if ((roditelj_element->prioritet < livodite_element->prioritet) || (roditelj_element->prioritet < desnodite_element->prioritet)) {
        if (livodite_element->prioritet > desnodite_element->prioritet) {
            zamjena_dva(roditelj_element, livodite_element);
            prema_dnu(qju, livodite);
        }
        else {
            zamjena_dva(roditelj_element, desnodite_element);
            prema_dnu(qju, desnodite);
        }
    }
}

void prema_dnu_iterativno(Niz* qju, int i) {
    if (i == 0)
        return;
    Element* roditelj_element;
    Element* livodite_element = NULL;
    Element* desnodite_element;
    while (1) {
        int livodite = 2 * i + 1;
        int desnodite = 2 * i + 2;
        if (livodite >= qju->niz)
            return;
        roditelj_element = &(qju->niz[i]);
        livodite = &(qju->niz[livodite]);
        if (desnodite >= qju->niz) {
            if (livodite_element > roditelj_element->prioritet)
                zamjena_dva(roditelj_element, livodite_element);
            return;
        }
        desnodite_element = &(qju->niz[desnodite]);
        if ((roditelj_element->prioritet < livodite_element->prioritet) || (roditelj_element->prioritet < desnodite_element->prioritet)) {
            if (livodite_element->prioritet > desnodite_element->prioritet) {
                zamjena_dva(roditelj_element, livodite_element);
                i = livodite;
            }
            else {
                zamjena_dva(roditelj_element, desnodite_element);
                i = desnodite;
            }
        }
        else
            return;
    }
}

void makni_vrh(Niz* qju) {
    if (qju->n <= 0)
        return;
    // Element top = qju->niz[0];
    Element bot = qju->niz[qju->n - 1];
    qju->niz[0] = bot;
    qju->niz[qju->n - 1].prioritet = -900000;
    qju->n-= 1;
    // prema_dnu(qju, 0);
    prema_dnu_iterativno(qju, 0);
}

void dodaj(Niz* qju, int prioritet) {
    int i = qju->n++;
    qju->niz[i].prioritet = prioritet;
    // prema_vrhu(qju, i);
    prema_vrhu_iterativno(qju, i);
}

int main() {
    int N = 100;;
    Niz* qju = (Niz*)malloc(sizeof(Niz));
    qju->n = 0;
    qju->niz = (Element*)malloc(sizeof(Element) * N);
    if (!qju->niz)
        puts("Malloc error");
    int arr[] = {1,3,2,4,301,5,6,8,12,43,85,9000};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < arr_len; i++)
        dodaj(qju, arr[i]);
    print(qju);
    puts("Prema vrhu");
    makni_vrh(qju);
    print(qju);
    puts("Bez vrha");
    free(qju->niz);
    free(qju);
    
    return 0;
}
