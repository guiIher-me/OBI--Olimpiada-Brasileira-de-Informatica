/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-23 */

#include <stdio.h>
#define CHUVA 'o'
#define PRATELEIRA '#'
#define PAREDE '.'

void vazar(int n, int m, char c[n][m], int i, int j) {
	if(c[i][j] == PAREDE && 
	  (i-1 >= 0 && c[i-1][j] == CHUVA ||
	   i+1 < n && j-1 >= 0 && c[i][j-1] == CHUVA && c[i+1][j-1] == PRATELEIRA ||
	   i+1 < n && j+1 < m && c[i][j+1] == CHUVA && c[i+1][j+1] == PRATELEIRA)) {
	   	
		c[i][j] = CHUVA;
		vazar(n, m, c, i, j+1);
		vazar(n, m, c, i, j-1);
		vazar(n, m, c, i+1, j);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	char c[n][m];
	
	int col_init;
	for(int j=0; j<m; j++) {
		scanf(" %c", &c[0][j]);
		
		if(c[0][j] == CHUVA)
			col_init = j;
	}
	
	for(int i=1; i<n; i++)
		for(int j=0; j<m; j++)
			scanf(" %c", &c[i][j]);
	
	vazar(n, m, c, 0, col_init+1); //direita
	vazar(n, m, c, 0, col_init-1); //esquerda
	vazar(n, m, c, 1, col_init  ); //baixo
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			printf("%c", c[i][j]);
		printf("\n");
	}
	
	return 0;
}
