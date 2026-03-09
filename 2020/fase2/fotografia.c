/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2026-03-09 */
  
#include <stdio.h>
#include <stdbool.h>

bool fits(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2) {
    return x2 >= x1 && y2 >= y1;
}

unsigned long area;
unsigned long calc_area(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2) {
    unsigned short diff_x = x2 - x1;
    unsigned short diff_y = y2 - y1;
    area = diff_x * diff_y;
    return area;
}

int main() {
    unsigned short a, l, n, x, y, diff_x, diff_y;
    unsigned long area, min_area = 10000;
    scanf("%hu%hu", &a, &l);
     
    scanf("%hu", &n);
    
    short best_id = -1;
    for(short i=1; i<=n; i++) {
        scanf("%hu%hu", &x, &y);
        
        // check if fits and verify area
        if(fits(a, l, x, y) && calc_area(a, l, x, y) < min_area) {          
           min_area = area;
           best_id = i;
        }
        
        // rotate and check again
        if(fits(l, a, x, y) && calc_area(l, a, x, y) < min_area) {
           min_area = area;
           best_id = i;
        }
    }
    
    printf("%hd", best_id);
    return 0;
}
