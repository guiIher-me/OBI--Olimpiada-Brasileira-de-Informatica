/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-18 */

#include <stdio.h>
#include <stdbool.h>

#define BOLAS 8

bool possivel() {
	int d;
	int contador[10] = {0};
  
	for(int i=0; i<BOLAS; i++) {
		scanf("%d", &d);
		
		contador[d]++;
		if(contador[d] > BOLAS/2) return false;
	}
  
	return true;
}

int main() {
  if (possivel()) printf("S");
  else printf("N");

  return 0;
}
