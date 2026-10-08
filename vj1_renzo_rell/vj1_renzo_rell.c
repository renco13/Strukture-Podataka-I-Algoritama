#include <stdio.h>

int mystrlen(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return(i);
}

void mystrcpy(char *str1, char *str2) {
	int i = 0;
	while (str2[i] != '\0') {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	puts(str1);
}

int mystrcmp(char *str3, char *str4) {
	while ((*str3 || *str4) != '\0') {
		if (*str3 > *str4)
			return 1;
		else if (*str3 < *str4)
			return -1;
		str3++;
		str4++;
	}
	if (*str3 == *str4)
		return 0;
	return 0;
}

void mystrcat(char *str6, char *str7) {
	int i = 0;
	int j = 0;
	while (str6[i] != '\0')
		i++;
	while (str7[j] != '\0') {
		str6[i + j] = str7[j];
		j++;
	}
	str6[i + j + 1] = '\0';
	puts(str6);
}

char *mystrstr(char *str8, char *str9) {
	int i;
	int j;
	for (i = 0; str8[i] != '\0'; i++) {
		for (j = 0; str9[j] != '\0'; j++) {
			if (str8[i + j] != str9[j])
				break;
		}
		if (str9[j] == '\0')
			return &str8[i];
	}
	return NULL;
}

void reverse(char* str10, char* str11) {
	int i = 0;
	int j = 0;
	while (str10[i] != '\0')
		i++;
	while (i != 0) {
		str11[j] = str10[i - 1];
		i = i - 1;
		j++;
	}
	str11[j] = '\0';
}

void main() {
	char *str = "string";
	int strlen = mystrlen(str);
	printf("%d\n", strlen);

	char str1[4] = "";
	char *str2 = "bok";
	mystrcpy(str1, str2);

	char *str3 = "aabbaaaa";
	char *str4 = "aabbaaaa";
	int strcmp = mystrcmp(str3, str4);
	if (strcmp < 0)
		printf("str3 je kraci od str4\n");
	else if (strcmp > 0)
		printf("str4 je kraci od str3\n");
	else
		printf("oba stringa su jednake duljine\n");

	char str6[20] = "hello";
	char *str7 = "world";
	mystrcat(str6, str7);

	char *str8 = "aaabbssssaaaaacccsfscfcaasdddcca";
	char *str9 = "scf";
	char *strstr = mystrstr(str8, str9);
	if (strstr)
		printf("%d\n", strstr - str8);
	else
		puts(strstr);
	
	char *str10 = "burger";
	char str11[7] = "";
	reverse(str10, str11);
	puts(str11);
}