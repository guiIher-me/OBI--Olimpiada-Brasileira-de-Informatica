/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2024-08-22 */
  
#include <stdio.h>

int main() {
    unsigned long long n, d, i, j, soma, maneiras=0;
    scanf("%llu%llu", &n, &d);
    
    unsigned short pedacos[n];
    for(i=0; i<n; i++)
        scanf("%hu", &pedacos[i]);
    
    soma = 0;
    for(i=0, j=0; i<n; i++) {
        while(soma < d) {
            soma += pedacos[j % n];
            j++;
        }
        
        if(soma == d) maneiras++;
        
        if(soma > 0) soma -= pedacos[i];
        else j = i;
    }
    
    printf("%llu", maneiras);
    system("pause");
    return 0;
}
