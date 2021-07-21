/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-21 */

#include <stdio.h>

int main() {
	unsigned short n;
	scanf("%hu", &n);
	
	unsigned short d[n];
	int candidato = -1;
	for(int i=0; i<n; i++)
		scanf("%hu", &d[i]);
	
	int ultimo = n-1;
	
	for(int i=0; i<n; i++) {
		if((d[i] == 0 || d[i] == 5)) {
			candidato = i;
			if(d[i] < d[ultimo])
				break;
		}	
	}
	
	if(candidato == -1) {
		printf("-1");
		return 0;
	}
	
	unsigned short aux = d[candidato];
	d[candidato] = d[ultimo];
	d[ultimo] = aux;
	
	for(int i=0; i<n; i++)
		printf("%hu ", d[i]);
	
	return 0;
}
