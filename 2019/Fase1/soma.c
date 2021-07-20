/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>

int main() {
	unsigned long int n, k;
	scanf("%lu%lu", &n, &k);
	
	unsigned short int v[n];
	
	unsigned long int i, j;
	for(i=0; i<n; i++)
		scanf("%lu", &v[i]);
	
	unsigned long long int sum;
	unsigned long long int retangulos = 0;
	for(i=0; i<n; i++) {
		for(j = i, sum=v[i]; sum <= k && j < n; j++, sum += v[j]) {
			if(sum == k) {
				retangulos++;
			}
		}
	}
	
	printf("%llu", retangulos);
	
	return 0;
}
