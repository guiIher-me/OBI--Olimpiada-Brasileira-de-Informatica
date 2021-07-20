/* @Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
   @Since: 2020-11-04  */

#include <stdio.h>
#define MAX 100

void mapa(char m[MAX][MAX], int i, int j, int l, int c) {
	m[i][j] = 'x';
	
	if(i-1>=0 && m[i-1][j] == 'H') return mapa(m, i-1, j, l, c); //cima
	if(i+1<l  && m[i+1][j] == 'H') return mapa(m, i+1, j, l, c); //baixo
	if(j-1>=0 && m[i][j-1] == 'H') return mapa(m, i, j-1, l, c); //esquerda
	if(j+1<c  && m[i][j+1] == 'H') return mapa(m, i, j+1, l, c); //direita
	
	printf("%d %d", i+1, j+1);
	return;
}

int main() {
	int l, c;
	char m[MAX][MAX];
	
	scanf("%u", &l);
	scanf("%u", &c);
	
	int origem_i;
	int origem_j;
	for(int i=0; i<l; i++) {
		for(int j=0; j<c; j++) {
			scanf(" %c", &m[i][j]);
			
			//origem
			if(m[i][j] == 'o') {
				origem_i = i;
				origem_j = j;
			}
		}
	}
	
	mapa(m, origem_i, origem_j, l, c);
	return 0;
}
