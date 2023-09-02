/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-09-02 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHAIRS 3
bool available_chair[CHAIRS] = {true, true, true};

int checkAvailableChair(unsigned short positions) {
    int count = 0;
    int index = positions % CHAIRS;
    
    while(!available_chair[index]) {
        index = ++positions % CHAIRS;
        if(++count >= CHAIRS) return -1;
    }
    
    available_chair[index] = false;
    return index;
}

int main() {
    unsigned short a, b;
    scanf("%hu%hu", &a, &b);
    
    checkAvailableChair(a);
    checkAvailableChair(b);
    int c_index = checkAvailableChair(0);
    
    printf("%d", c_index);
    system("pause");
    return 0;
}
