/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>
#define T 3

void bubble(int v[T]) {
	for(int i=0; i<T; i++) {
		for(int j=0; j<T-i-1; j++) {
			if(v[j] > v[j+1]) {
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}	
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	int pokemon[T];
	for(int i=0; i<T; i++)
		scanf("%d", &pokemon[i]);
	
	bubble(pokemon);
	
	int qtd_pokemons = 0;
	for(int i=0; i<T; i++) {
		if(pokemon[i] > n) break;
		
		n-=pokemon[i];
		qtd_pokemons++;
	}
		
	printf("%d", qtd_pokemons);
	return 0;
}
