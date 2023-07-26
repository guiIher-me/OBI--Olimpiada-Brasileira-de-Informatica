/* @Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
   @Since: 2023-07-26  */
   
#include <stdio.h>
#include <stdbool.h>

#define MAX 500
#define CHUVA 'o'
#define PAREDE '.'
#define PRATELEIRA '#'

bool existe_abaixo(int i, int n) {
     return i+1 < n;
}

bool existe_direita(int j, int m) {
     return j+1 < m;
}

bool existe_esquerda(int j, int m) {
     return j-1 >= 0;
}

bool tem_prateleira_abaixo(char c[MAX][MAX], int i, int j, int n) {
     return existe_abaixo(i, n) && c[i+1][j] == PRATELEIRA;
}

bool tem_parede_abaixo(char c[MAX][MAX], int i, int j, int n) {
     return existe_abaixo(i, n) && c[i+1][j] == PAREDE;
}

void escorrer(char c[MAX][MAX], int i, int j, int n, int m) {
    if(c[i][j] != PAREDE) return;
    c[i][j] = CHUVA;

    if(tem_prateleira_abaixo(c, i, j, n)) {
        if(existe_direita(j, m)) escorrer(c, i, j+1, n, m); //direita
        if(existe_esquerda(j, m)) escorrer(c, i, j-1, n, m); //esquerda
    } else if(tem_parede_abaixo(c,i, j, n)) {
        escorrer(c, i+1, j, n, m); //abaixo
    }
    
    return;    
}


void print(char c[MAX][MAX], int n, int m) {
     for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			printf("%c", c[i][j]);
		printf("\n");
	}
}

int main() {
	int n, m;
	char c[MAX][MAX];
	
	scanf("%u", &n);
	scanf("%u", &m);
	
	int origem_i;
	int origem_j;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf(" %c", &c[i][j]);
			
			//origem
			if(c[i][j] == CHUVA) {
                c[i][j] = PAREDE;
				origem_i = i;
				origem_j = j;
			}
		}
	}
	
	escorrer(c, origem_i, origem_j, n, m);
	print(c, n, m);
	return 0;
}
