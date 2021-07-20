/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>

int main() {
	unsigned short int a, b;
	scanf("%hu%hu", &a, &b);
	
	unsigned short int c = b - a;
	printf("%hu", b + c);
	
	return 0;
}
