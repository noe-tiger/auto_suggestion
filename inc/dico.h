#include<stdio.h>
#include<stdlib.h>

#ifndef DICTIONARY_PROJET_
# define DICTIONARY_PROJET_

typedef struct word_t {

	struct word_t *a;
	struct word_t *b;
	struct word_t *c;
	struct word_t *d;
	struct word_t *e;
	struct word_t *f;
	struct word_t *g;
	struct word_t *h;
	struct word_t *i;
	struct word_t *j;
	struct word_t *k;
	struct word_t *l;
	struct word_t *m;
	struct word_t *n;
	struct word_t *o;
	struct word_t *p;
	struct word_t *q;
	struct word_t *r;
	struct word_t *s;
	struct word_t *t;
	struct word_t *u;
	struct word_t *v;
	struct word_t *w;
	struct word_t *x;
	struct word_t *y;
	struct word_t *z;

	char *curent;

}	word;



char *getFileContent();
word *genTree(char* str);
void printTree(word *tree, int *limit, char base);
word *getTree(word *tree, char *enter);




#endif
