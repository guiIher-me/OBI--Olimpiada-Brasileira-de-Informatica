/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-07-27 */

#include <stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
	unsigned short m, a, b, c;
	scanf("%hu", &m);
	scanf("%hu", &a);
	scanf("%hu", &b);
	
	c = m - (a + b);
	printf("%d", max(max(a, b), c));
    system("pause");
    return 0;
}
