/* @Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
   @Since: 2021-07-19  */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[5][5] = {{-1, 0, 0, 3, 4},
			 	 { 0,-1, 1, 1, 4},
			 	 { 0, 1,-1, 2, 2},
			 	 { 3, 1, 2,-1, 3},
			 	 { 4, 4, 2, 3,-1}};

bool xerxes_venceu(unsigned short D, unsigned short X) {
	int vencedor = adj[D][X];
	return vencedor == X;
}

int main() {
	unsigned short n;
	scanf("%hu", &n);
	
	unsigned short jogada[n][2];
	for(int i=0; i<n; i++)
		scanf("%hu%hu", &jogada[i][0], &jogada[i][1]);
	
	unsigned short dario=0, xerxes=0;
	for(int i=0; i<n; i++) {
		if(jogada[i][0] == jogada[i][1]) continue;
		if(xerxes_venceu(jogada[i][0], jogada[i][1])) xerxes++;
		else dario++;
	}	
	
	if(dario > xerxes) printf("dario");
	else printf("xerxes");
	
	return 0;
}
