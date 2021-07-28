/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-22 */

#include <stdio.h>

int main() {
	int n, d, a;
	scanf("%d%d%d", &n, &d, &a);
	
	if(d >= a) printf("%d", d-a); //  . . * > > > > * . .
	else printf("%d", (n-a) + d); //  > > * . . . . * > >
	
	return 0;
}
