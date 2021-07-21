/* @Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
   @Since : 2021-07-20 */

#include <stdio.h>
#define INFINITY 1000000

void reset(unsigned short n, int matrix[n+1][n+1], int v) {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			matrix[i][j] = v;
}

int min(int a, int b) {
	return (a<b)? a : b;
}

void caminho_minimo_warshall(unsigned short n, int matrix[n+1][n+1]) {
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
}

int main() {
	unsigned short n, m;
	scanf("%hu%hu", &n, &m);
	
	int peso[n+1][n+1];
	reset(n, peso, INFINITY);
	
	unsigned short a, b, c;
	for(int i=0; i<m; i++) {
		scanf("%hu%hu%hu", &a, &b, &c);
		peso[a][b] = c;
		peso[b][a] = c;
	}
	
	caminho_minimo_warshall(n, peso);
	
	printf("%d", peso[1][n]);
	
	return 0;
}
