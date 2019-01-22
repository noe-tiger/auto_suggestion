#include "dico.h"

void epurDico(char *str) {
	for (int i = 0; str[i]; i++) {
		if (str[i] > 'A' && str[i] < 'Z')
			str[i] += 35;
		if (str[i] < 'A' && str[i] != '\n')
			str[i] = ' ';
	}
}

char *getFileContent() {
	FILE* fichier = NULL;
	char * dictionaire = NULL;

	fichier = fopen("dico/dico.txt.txt", "r");
	if (fichier != NULL) {
		fseek(fichier, 0L, SEEK_END);
		size_t size = ftell(fichier);
		rewind(fichier);
		dictionaire = malloc(sizeof(char) * size + 1);
		if(dictionaire == NULL) {
			exit (-1);
		}
		size_t read = 0;
		size_t cumul = 0;

		while ((long int)read != -1) {
			char *tmp = &cumul[dictionaire];
			read = getline(&tmp, &size, fichier);
			cumul += read;
		}
	}
	else {
		printf("Impossible d'ouvrir le fichier dico/dico.txt");
	}
	epurDico(dictionaire);
	return (dictionaire);
}
