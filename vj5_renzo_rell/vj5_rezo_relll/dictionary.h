#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char* word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word*next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnikssssss
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

int filterr(Word* w);

Dictionary filterDictionary(Dictionary indict, int (*filterr)(Word* w));

Dictionary najdulja(Dictionary dict);

void brojrijeci(Dictionary dict);

void dodajnapocetak(Dictionary dict, char* rijec);

void zamjeniprvizadnji(Dictionary dict);

Dictionary razdvojizanovu(Dictionary dict);

void maknisvakodrugi(Dictionary dict);

void dodavanjeulistu(Dictionary dict, char* rijec);

void dodavanjenapocetak(Dictionary dict, char* rijec);

void dodavanjeizniza(Dictionary dict, char** rijec);

void dodavanjeuniz(Dictionary dict, char* arr[]);

void dodajnakond(Dictionary dict, char* rijec);

void okreni(Dictionary dict);

Dictionary dodavanjeizlisteunovulistu(Dictionary dict);

#endif
