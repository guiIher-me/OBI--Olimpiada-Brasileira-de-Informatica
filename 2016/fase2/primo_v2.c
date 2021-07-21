/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-21 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	unsigned long long n, sqrt_n;
	unsigned short k;
	scanf("%llu%hu", &n, &k);
	
	unsigned long long *num = (unsigned long long *) calloc(n+1, sizeof(unsigned long long));
	
	unsigned long long primo[k];
	for(int i=0; i<k; i++)
		scanf("%llu", &primo[i]);
	
	unsigned long long nao_primos = 0;
	
	for(int i=0; i<k; i++) {		
		for(int j=primo[i]; j<=n; j+=primo[i]) {
			if(num[j] == 0) {
				nao_primos++;
				num[j] = 1;
			}
		}
	}

	printf("%llu", n - nao_primos);
	
	free(num);
	return 0;
}
