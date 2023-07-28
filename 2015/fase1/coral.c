/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-17 */
#include <stdio.h>

int main() {
	unsigned short int a, b, c, d;
	scanf("%hu%hu%hu%hu",&a, &b, &c, &d);
	
	if(a == d)
		printf("F");
	else
		printf("V");
	
	return 0;
}
