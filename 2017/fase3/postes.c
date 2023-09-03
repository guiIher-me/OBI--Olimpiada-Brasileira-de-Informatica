/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-09-02 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned short n, x;
    scanf("%hu", &n);
    
    unsigned short substituidos = 0;
    unsigned short consertados  = 0;
    for(int i=0; i<n; i++) {
        scanf("%hu", &x);
        if(x < 50) substituidos++;
        else if(x < 85) consertados++;
    }
    
    printf("%hu %hu", substituidos, consertados);
    system("pause");
    return 0;
} 
