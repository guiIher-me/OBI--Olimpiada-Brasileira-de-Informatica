/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-29 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	float p;
	int g;
	scanf("%f%d", &p, &g);
	float min = 1000.0*p/g;
	for(int i=1; i<n; i++) {
		scanf("%f%d", &p, &g);
		
		if(1000.0*p/g < min)
			min = 1000.0*p/g;
	}
	
	printf("%.2f", min);
	
	return 0;
}
