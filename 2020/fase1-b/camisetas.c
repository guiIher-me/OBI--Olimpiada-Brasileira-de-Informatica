/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-07-27 */

#include <stdio.h>

int main() {
	unsigned short n, t, p_solicitados = 0, m_solicitados = 0, p, m;
	scanf("%hu", &n);
	
	for(int i=0; i<n; i++) {
        scanf("%hu", &t);
        if(t == 1) p_solicitados++;
        else m_solicitados++;
    }
    
    scanf("%hu", &p);
    scanf("%hu", &m);

    if(p >= p_solicitados && m >= m_solicitados)
         printf("S");
    else
        printf("N");
    
    system("pause");
    return 0;
}
