/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-09-02 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXBITS 1000

// flags
bool overflow = false;
bool carry = false;

int max(int x, int y) {
    if(x > y) return x;
    return y;
}

bool sumbit(bool bit1, bool bit2) {
    int s = bit1 + bit2 + carry;
    
    if(s == 0) {carry = false; return false;}
    if(s == 1) {carry = false; return true ;}
    if(s == 2) {carry = true ; return false;}
    if(s == 3) {carry = true ; return true ;}
    
    exit(1); //unexpected error
}

void binarySum(int s1[MAXBITS], int s2[MAXBITS], int res[MAXBITS], int size) {
     for(int i=size-1; i>=0; i--)
         res[i] = sumbit(s1[i], s2[i]);
     
     overflow = carry;
}

int getMostSignificantBit(int s[MAXBITS], int size) {
    for(int i=size-1; i>=0; i--)
        if(s[i] == 1) return i;
        
    return 0;
}

void printBinary(int s[MAXBITS], int size) {
    int MSB = getMostSignificantBit(s, size);
    
    for(int i=0; i<MSB; i++)
        printf("%d ", s[i]);
    printf("%d", s[MSB]);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int s1[MAXBITS]  = {0};
    int s2[MAXBITS]  = {0};
    int res[MAXBITS] = {0};
    
    for(int i=0; i<m; i++) scanf("%d", &s1[i]);
    for(int i=0; i<n; i++) scanf("%d", &s2[i]);
    
    int max_size = max(m, n);
    binarySum(s1, s2, res, max_size);
    
    if(overflow) printf("1 ");
    printBinary(res, max_size);
    
    system("pause");
    return 0;    
}
