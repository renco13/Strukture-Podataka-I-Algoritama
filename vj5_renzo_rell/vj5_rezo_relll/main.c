#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

int readWord(FILE *fd, char *buffer)
{
    int c;
    do {
        c = fgetc(fd);
        if(c == EOF)
            return 0;
    } while(!isalpha(c));
    do {
        *buffer = tolower(c);
        buffer++;
        c = fgetc(fd);
        if(c == 146)
            c = '\'';
    } while(isalpha(c) || c == '\'');
    *buffer = '\0';
    return 1;
}

int main()
{
    FILE *fd;
    char buffer[1024];
    Dictionary dict;
    fd = fopen("liar.txt", "rt");
    if (!fd)
        printf("Error opening file.\n");
    dict = create();
    while(readWord(fd, buffer)) {
        //printf("%s\n", buffer);
        add(dict, buffer);
    }
    fclose(fd);
    print(dict);
    puts("\n \n \n --------------------------- \n \n \n");
    dict = filterDictionary(dict, filterr);
    print(dict);
    destroy(dict);
    
//    
    
//    brojrijeci(dict);
//    dict = najdulja(dict);
//    puts(dict->word);
//    dodajnapocetak(dict, "xd");
//    zamjeniprvizadnji(dict);
//    Dictionary nova = razdvojizanovu(dict);
//    print(nova);
//    maknisvakodrugi(dict);
//    dodavanjeulistu(dict, "roko");
//    dodavanjeulistu(dict, "sinisa");
//    dodavanjeulistu(dict, "bartul");
//    dodavanjenapocetak(dict, "roko");
//    dodavanjenapocetak(dict, "sinisa");
//    dodavanjenapocetak(dict, "bartul");
//    char* arr[] = {"roko", "sinisa", "bartul"};
//    dodavanjeizniza(dict, &arr);
    
//    char* arr[80];
//    dodavanjeuniz(dict, &arr);
//    
//    print(dict);
//    for (int i = 0; i < 8; i++) {
//        puts(arr[i]);
//    }
//    dodajnakond(dict, "d");
//    okreni(dict);
//    Dictionary dict2 = dodavanjeizlisteunovulistu(dict);
//    print(dict2);
    
//    print(dict);
    return 0;
}
