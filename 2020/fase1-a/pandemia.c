/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-07-27 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int main() {
	unsigned short n, m, i, r, a;
	unsigned short total_infectados = 1;
	bool infectado[MAX+1] = {false};
	
	scanf("%hu%hu", &n, &m);
	scanf("%hu%hu", &i, &r);
	
    infectado[i] = true;
	
	for(int j=1; j<=m; j++) {
        scanf("%hu", &a);
        
        unsigned short reuniao[MAX] = {0};
        unsigned short total_infectados_na_reuniao = 0;
        for(int k=0; k<a; k++) {
            scanf("%hu", &reuniao[k]);
            if(infectado[reuniao[k]] && j >= r)
                total_infectados_na_reuniao++;
        }
        
        if(total_infectados_na_reuniao > 0) {
            for(int k=0; k<a; k++)
                infectado[reuniao[k]] = true;
                
            total_infectados += a - total_infectados_na_reuniao;
        }
        
    }
	
	printf("%hu", total_infectados);
	return 0;
}
