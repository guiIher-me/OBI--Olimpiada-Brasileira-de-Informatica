/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-17 */
#include <stdio.h>
#include <stdbool.h>

#define ESTRELA 1
#define SAIDA  2
#define ORIGEM 3
#define VISITADA 4

bool sala_existe(int n, int m, int i, int j) {
	return i >= 0 && i < n &&
		   j >= 0 && j < m;
}

int mover(int n, int m, unsigned short sala[n][m], int ia, int ja) {
	int i = ia;
	int j = ja;
	sala[i][j] = VISITADA;
	
	i = ia - 1;
	j = ja;
	if(sala_existe(n, m, i, j) && sala[i][j] == ESTRELA)
		return 1 + mover(n, m, sala, i, j); //cima
		
	i = ia + 1;
	j = ja;
	if(sala_existe(n, m, i, j) && sala[i][j] == ESTRELA)
		return 1 + mover(n, m, sala, i, j); //baixo
	
	i = ia;
	j = ja - 1;
	if(sala_existe(n, m, i, j) && sala[i][j] == ESTRELA)
		return 1 + mover(n, m, sala, i, j); //esquerda
	
	i = ia;
	j = ja + 1;
	if(sala_existe(n, m, i, j) && sala[i][j] == ESTRELA)
		return 1 + mover(n, m, sala, i, j); //direita
	
	return 2;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	unsigned short sala[n][m];
	
	int ia=0, ja=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%hu", &sala[i][j]);
			
			if(sala[i][j] == ORIGEM) {
				ia = i;
				ja = j;	
			}
		}
	}
	
	printf("%d", mover(n, m, sala, ia, ja));
	return 0;
}
