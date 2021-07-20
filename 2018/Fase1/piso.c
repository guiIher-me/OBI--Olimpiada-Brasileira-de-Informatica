/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-19 */
  
#include <stdio.h>
 
int main() {
	int l, c;
	scanf("%i%i", &l, &c);
	
	printf("%i\n", l*c + (l-1) * (c-1));
	printf("%i", 2*(l-1) + 2*(c-1));
	
	return 0;
}
