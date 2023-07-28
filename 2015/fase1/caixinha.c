/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-07-28 */

#include <stdio.h>

unsigned int max(int a, int b) {
    if (a > b) return a;
    return b;
}

unsigned int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int main() {
	unsigned int n, m;
    unsigned int init, restante, minimo, maximo, possibilidades;
	unsigned long long maneiras = 0;
	
	scanf("%u%u", &n, &m);
	
	if(3*m < n) {
        printf("0");
        system("pause");
        return 0;
    }
    
    
	init = max(1, n - 2*m);
    for(int i=init; i<=m; i++) {
        restante = n - i;
        minimo = max(1, restante - m);
        maximo = min(restante - 1, m);
        
        possibilidades = maximo - minimo + 1;
        maneiras += possibilidades;
    }
    
    printf("%llu", maneiras);
    system("pause");
    return 0;
}
