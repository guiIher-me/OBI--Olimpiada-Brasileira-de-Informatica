/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>
#define ASTERISCO '*'

void avancar(unsigned short int n, char f, 
			 char mapa[n][n], int i, int j) {

	mapa[i][j] = ASTERISCO;
	
	if(i+1 < n  && mapa[i+1][j] <= f && mapa[i+1][j] != ASTERISCO)
		avancar(n, f, mapa, i+1, j); //baixo
		
	if(j-1 >= 0 && mapa[i][j-1] <= f && mapa[i][j-1] != ASTERISCO)
		avancar(n, f, mapa, i, j-1); //esquerda
		
	if(j+1 < n  && mapa[i][j+1] <= f && mapa[i][j+1] != ASTERISCO)
		avancar(n, f, mapa, i, j+1); //direita
		
	if(i-1 >= 0 && mapa[i-1][j] <= f && mapa[i-1][j] != ASTERISCO)
		avancar(n, f, mapa, i-1, j); //cima
	
	return;
}  
  
int main() {
	unsigned short n;
	char f;
	scanf("%hu %c", &n, &f);
	
	char mapa[n][n];
	for(int i=0; i<n; i++)
		scanf("%s", &mapa[i]);
			
	avancar(n, f, mapa, 0, 0);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			printf("%c", mapa[i][j]);
		printf("\n");
	}
}
