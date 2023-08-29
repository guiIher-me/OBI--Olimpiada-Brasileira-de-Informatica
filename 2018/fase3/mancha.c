/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2023-08-28 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// SYMBOLS
#define SPOT '*'
#define SKIN '.'

// STATES
#define EMPTY 0
#define START_SPOT 1
#define END_SPOT 2
#define IRREGULAR_SPOT 3

// GLOBAL VARS
bool regular = true;

// FUNCTIONS
bool is_state(unsigned short int current_state, unsigned short int selected_state) {
    return current_state == selected_state;
}

bool is_spot(char pixel) {
     return pixel == SPOT;
}

bool is_skin(char pixel) {
     return pixel == SKIN;
}

unsigned short int manage_state(unsigned short int state, char pixel) {
    if(is_state(state, EMPTY) && is_spot(pixel))
        return START_SPOT;
    
    if(is_state(state, START_SPOT) && is_skin(pixel))
        return END_SPOT;
    
    if(is_state(state, END_SPOT) && is_spot(pixel)) {
        regular = false;
        return IRREGULAR_SPOT;
    }
    
    return state;
}

int main() {
    char pixel;
    unsigned short int n;
    scanf("%hu", &n);
    
    unsigned short int line_state[MAX] = { EMPTY };
    unsigned short int col_state[MAX] = { EMPTY };
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf(" %c", &pixel);
            
            if(!regular) continue; //skip all
            line_state[i] = manage_state(line_state[i], pixel);
            col_state[j]  = manage_state(col_state[j] , pixel);
        }
    }
    
    if(regular) printf("S");
    else printf("N");
    
    system("pause");
	return 0;
}
