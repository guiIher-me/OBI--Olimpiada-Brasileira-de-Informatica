/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-21 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
	unsigned long long n, sqrt_n;
	unsigned short k;
	scanf("%llu%hu", &n, &k);
	
	sqrt_n = sqrt(n) +1;
	
	unsigned short max_k = 0;
	unsigned long long primo[k];
	for(int i=0; i<k; i++) {
		scanf("%llu", &primo[i]);
		if(primo[i] <= sqrt_n) max_k = i;
	}
	
	int passo = (primo[0] == 2)? 2 : 1;
	unsigned long long cont_quase_primos = 0;

	int i, j;
	for(i=1; i<=n; i+=passo) {
		for(j=0; j<=max_k; j++) {
			printf("%d %% %d == 0?\n", i, primo[j], i % primo[j]);
			if(i % primo[j] == 0) break;
		}
		printf("J: %d\n\n", j);

		if(j > max_k) cont_quase_primos++;
	}
	
	printf("%llu", cont_quase_primos - (k - max_k));
	
	return 0;
}
