
#include <stdio.h>
#include <stdbool.h>

bool cortar_metade(float metade, int c1, int c2) {
	return (c1 > metade && c2 < metade) ||
		   (c1 < metade && c2 > metade);
}

bool divisao_igual(int n,int x1,int y1,int x2,int y2) {
	float metade = n / 2 + .5;
	return cortar_metade(metade, x1, x2) || 
		   cortar_metade(metade, y1, y2);
}

int main() {
	int n;
	scanf("%d", &n);
	
	int x1, x2, y1, y2;
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);	
	
	if(divisao_igual(n, x1, y1, x2, y2)) printf("S");
	else printf("N");
	
	return 0;
}
