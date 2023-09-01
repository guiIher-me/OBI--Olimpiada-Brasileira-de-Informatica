/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-09-01 */
  
#include <stdio.h>
#include <stdbool.h>
#include<math.h>

/* Formulas:
 * A = 2 * (L + C) - 4
 * B = (L - 2) * (C - 2)
 * (L * C) = (A + B)  =>  C = (A + B) / L
 */

bool equalA(int A, float L, float C) {
     return A == 2 * (L + C) - 4;
}

bool equalB(int B, float L, float C) {
     return B == (L - 2) * (C - 2);
}

int main()  {
    int A, B;
    float L, C;
    scanf("%d %d", &A, &B);
    
    int limite = (int) (A + B) / 2;
    bool found = false;
    
    for(int i=2; i <= limite; i++) {
        L = (float) i;
        C = (float) (A + B) / L;
        
        if(equalA(A, L, C) && equalB(B, L, C)) {
            found = true;
            break;
        }
    }
    
    float min = fmin(L, C);
    float max = fmax(L, C);
    
    if(!found) printf("-1 -1");
    else printf("%d %d", (int) min, (int) max);
 
    system("pause");
    return 0;
}
    
