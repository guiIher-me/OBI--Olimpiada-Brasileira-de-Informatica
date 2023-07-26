/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-07-26 */

#include <stdio.h>

int main() {
	unsigned short d, s;
	scanf("%hu", &d);
	
	s = ((d - 3) % 8) - 2;
	printf("%d", s);
}
