/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>

void selectionsort(unsigned long int n, unsigned short v[n]) {
	for(unsigned long int i=0; i < n-1; i++) {
		unsigned long int min = i;
		for(unsigned long int j=i+1; j<n; j++)
			if(v[j] > v[min])
				min = j;
		
		int aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
}

int main() {
	unsigned long int n;
	scanf("%lu", &n);
	
	unsigned short p[n];
	
	for(unsigned long int i=0; i<n; i++)
		scanf("%ud", &p[i]);
	
	selectionsort(n, p);
	
	unsigned long soma = 0;
	for(unsigned long int i=0; i<n; i++)
		if(i % 3 != 2)
			soma += p[i];
	
	printf("%lu", soma);

	return 0;
}
