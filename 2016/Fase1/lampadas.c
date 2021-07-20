/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-17 */
#include <stdio.h>

int main() {
	unsigned short int IA, IB, FA, FB;
	scanf("%hu%hu%hu%hu", &IA, &IB, &FA, &FB);
	
	if(IA == FA && IB == FB)
		printf("0");
	else if(IA != FA) // (IA != FA && IB == FB || IA != FA && IB != FB) equivale a IA != FA
		printf("1");
	else
		printf("2");
	
	return 0;
}
