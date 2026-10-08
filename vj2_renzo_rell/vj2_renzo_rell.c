#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
}tocka;

typedef struct {
	int n;
	tocka* vrhovi;
}poligon;

int *podniz(int *niz, int start, int stop) {
	int *newniz = (int*)malloc((stop - start) * sizeof(int));
	if (!newniz)
		return NULL;
	for (int i = 0; i < stop - start; i++) {
		newniz[i] = niz[start + i];
	}
	return newniz;
}

int *filtriraj(int *niz2, int n, int th, int *nth) {
	int size = 0;
	for (int i = 0; i < n; i++) {
		if (niz2[i] < th)
			size++;
	}
	int *novi = (int*)malloc(size * sizeof(int));
	if (!novi)
		return NULL;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (niz2[i] < th) {
			novi[j] = niz2[i];
			j++;
		}
	}
	*nth = j;
	return novi;
}

int **podijeli(int *niz, int n) {
	int pola = 0;
	if (n % 2 == 0)
		pola = n / 2;
	else
		pola = n / 2 + 1;
	int **nizall = (int**)malloc(n * sizeof(int*));
	nizall[0] = (int*)malloc(n / 2 * sizeof(int));
	nizall[1] = (int*)malloc(n / 2 * sizeof(int));
	for (int i = 0; i < n / 2; i++) {
		nizall[0][i] = niz[i];
	}
	for (int i = n / 2; i < n; i++) {
		nizall[1][i - (n / 2)] = niz[i];
	}
	return nizall;
}

poligon* novipoligon(float *nizx, float *nizy, int n) {
	poligon* newstructpoli = (poligon*)malloc(sizeof(poligon));
	tocka* novivrh = (tocka*)malloc(n * sizeof(tocka));
	newstructpoli->vrhovi = novivrh;
	for (int i = 0; i < n; i++) {
		novivrh[i].x = nizx[i];
		novivrh[i].y = nizy[i];
	}
	newstructpoli->n = n;
	return newstructpoli;
}

tocka** pozitivni(poligon *p, int *np) {
	*np = 0;
	for (int i = 0; i < p->n; i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0)
			(*np)++;
	}
	tocka** pozicija = (tocka**)malloc(*(np) * sizeof(tocka**));
	int j = 0;
	for (int i = 0; i < sizeof(p->vrhovi); i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
			pozicija[j] = &(p->vrhovi[i]);
			j++;
		}
	}
	return pozicija;
}

void main() {
	int niz[] = { 100,293,33333,55,62,7,890002,911 };
	int start = 4;
	int stop = 6;
	int *newniz = podniz(niz, start, stop);
	for (int i = 0; i < stop - start; i++)
		printf("Brojevi izmedu su: %d \n", newniz[i]);

	int niz2[] = { 123,33,2244,59925,6346346,324,6666662,111,9000 };
	int n = 9;
	int th = 9999;
	int *nth;
	int *newniz2 = filtriraj(niz2, n, th, &nth);
	for (int i = 0; i < nth; i++)
		printf("filtrirani brojevi su: %d \n", newniz2[i]);

	int niz3[] = { 1,2,3,4,5,8,9 };
	n = 7;
	int **newniz4 = podijeli(niz3, n);
	for (int i = 0; i < n / 2; i++) {
		printf("prvi: %d\n", newniz4[0][i]);
	}
	for (int i = 0; i < n / 2; i++) {
		printf("drugi: %d\n", newniz4[1][i]);
	}

	float x[] = { -2.1, 1.3, -3.4, 6.9 ,9.7 };
	float y[] = { -4.3, 2.9, 5.1, -8.2, 9.9 };
	n = 5;
	poligon* poli = novipoligon(x, y, n);
	for (int i = 0; i < n; i++) {
		if (poli->vrhovi[i].x > 0 && poli->vrhovi[i].y > 0) {
			printf("x kordinata novog poligona je: %f\n", poli->vrhovi[i].x);
			printf("y kordinata novog poligona je: %f\n", poli->vrhovi[i].y);
			printf("\n");
		}
	}

	int np;
	tocka** dot = pozitivni(poli, &np);
	for (int i = 0; i < n; i++) {
		printf("pointer broj_vrhova.x: %f\n", poli->vrhovi[i].x);
		printf("pointer broj_vrhova.y: %f\n", poli->vrhovi[i].y);
		printf("\n");
	}
	printf("broj parnih elemenata niza kojima su kordinate pozitivne: %d\n", np);
	free(poli->vrhovi);
	free(poli);
	free(dot);
}