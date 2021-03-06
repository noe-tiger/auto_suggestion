#include <string.h>
#include "dico.h"

char* mystrdup(char* str, int depth){
	char* copy = malloc(sizeof(char) * depth + 1);
	if (!copy)
		exit (-1);
	for (int i = 0; i < depth; i++) {
		copy[i] = str[i];
	}
	copy[depth] = 0;
	return copy;
}

void createblank(word* blank){
	for (int i = 0; i < 26; i++) {
		((long *)blank)[i] = 0;
	}
	blank->curent = strdup("");
}

void createSon(word *tree, char *str, int depth) {
	while ((*str < 'a' || *str > 'z') && *str != '\n')
		str++;
	if (str[0] >= 'a' && str[0] <= 'z') {
		if (((long *)tree)[str[0] - 'a'] == 0) {
			word *tmp = malloc(sizeof(word));
			if (!tmp)
				exit (-1);
			createblank(tmp);
			((long *)tree)[str[0] - 'a'] = (long)tmp;
		}
		createSon((word *)((long *)tree)[str[0] - 'a'], str + 1, depth + 1);
	}
	if (str[0] == '\n') {
		tree->curent = mystrdup(str - depth, depth);
	}
}

word *genTree(char* str) {
	word *tree = malloc(sizeof(word));

	if (tree == NULL){
		exit (-1);
	}
	createblank(tree);
	createSon(tree, str, 0);
	for (int i = 0; str[i]; i++) {
		if (str[i] == '\n' && str[i + 1])
			createSon(tree, &str[i + 1], 0);
	}
	return tree;
}

word *getTree(word *tree, char *enter) {
	for (int i = 0; enter[i]; i++) {
		tree = (word *)((long *)tree)[enter[i] - 'a'];
		if (!tree)
			return NULL;
	}
	return tree;
}

void printTree(word *tree, int *limit, char base) {
	if (tree == NULL) {
		printf("NO WORD FOUND plase only use a-z characters\n");
		exit (-1);
	}
	if (*limit == 0)
		return ;
	if (tree->curent[0] != 0) {
		printf("found %c%s\n", base, tree->curent);
		limit[0]--;
	}
	for (int i = 0; i < 26; i++) {
		if (((long *)tree)[i] != 0)
			printTree((word *)((long *)tree)[i], limit, base);
	}
}
