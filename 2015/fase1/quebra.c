/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>
#include <stdlib.h>

#define T 200001

typedef struct node {
	char letter;
	unsigned long int next;
} Node;

int main() {
	Node index[T];
		
	unsigned long int n;
	scanf("%lu", &n);
	
	unsigned long int e, d;
	char c;
	for(int i=0; i<n; i++) {
		scanf("%lu %c%lu", &e, &c, &d);
		index[e].letter = c;
		index[e].next   = d;
	}
	
	int i;
	for(i=0; index[i].next != 1; i = index[i].next)
		printf("%c", index[i].letter);
	printf("%c", index[i].letter);
	
	return 0;
}
