#include "dico.h"

int main() {
	char word[32];
	int limit = 5;
	struct word_t *tree = NULL;

	printf("Que recherchez vous ? \n");
	scanf("%s", word);

	tree = genTree(getFileContent());

	printTree(getTree(tree, word), &limit, word[0]);
	return(0);
}
