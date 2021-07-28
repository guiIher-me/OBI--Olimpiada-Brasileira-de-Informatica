/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-22 */

#include <stdio.h>
#define ZERO 0

void reset(int n, int m, unsigned int matrix[n][m], int v) {
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			matrix[i][j] = v;
}

unsigned int fatorial(unsigned int n) {
	if(n <= 1) return 1;
	return n*fatorial(n-1);
}

int main() {
	unsigned short n;
	scanf("%hu", &n);
	
	unsigned int fat = fatorial(n);
		
	unsigned int numero[n+1][n];
	reset(n+1, n, numero, ZERO);
	
	unsigned short x;
	for(unsigned int i=0; i<fat-1; i++) {
		for(int j=0; j<n; j++) {
			scanf("%hu", &x);
			numero[x][j]++;
		}
	}
	
	unsigned int v[n];
	for(unsigned int i=1; i<=n; i++)
		for(int j=0; j<n; j++)
			if(numero[i][j] != fat/n) v[j] = i;
	
	for(int i=0; i<n; i++)
		printf("%u ", v[i]);
	
	return 0;
}
