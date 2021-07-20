/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-20 */
  
#include <stdio.h>
#define N 101

int main() {
	unsigned short n, c, m;
	scanf("%hu%hu%hu", &n, &c, &m);
	
	unsigned short carimbada[N] = {0};
	unsigned short x;
	for(int i=0; i<c; i++) {
		scanf("%hu", &x);
		carimbada[x] = 1;
	}
	
	unsigned short y;
	unsigned short figurinhas_compradas_carimbadas = 0;
	for(int i=0; i<m; i++) {
		scanf("%hu", &y);
		if(carimbada[y]) {
			carimbada[y] = 0;
			figurinhas_compradas_carimbadas++;
		}
	}
	
	printf("%hu", c - figurinhas_compradas_carimbadas);
	
	return 0;
}
