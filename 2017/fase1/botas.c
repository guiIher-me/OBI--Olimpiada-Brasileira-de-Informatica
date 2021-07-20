/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>
#include <stdbool.h>

int min(int a, int b) {
	return (a < b)? a : b;
}

int main() {
	int esquerdo[61] = {0};
	int  direito[61] = {0};
	
	unsigned short int n;
	scanf("%hu", &n);
	
	short int index;
	char l;
	for(int i=0; i<n; i++) {
		scanf("%hd %c", &index, &l);
		if(l == 'E') esquerdo[index]++;
		else direito[index]++;
	}
	
	int pares = 0;
	for(int i=30; i<=60; i++)
		pares += min(esquerdo[i], direito[i]);
	
	printf("%d", pares);
	
	return 0;	
}
