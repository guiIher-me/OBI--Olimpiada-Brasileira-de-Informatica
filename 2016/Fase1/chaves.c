/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-17 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 102

bool valido(unsigned short int n, char s[n][MAX]) {
	int chaves = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; s[i][j] != '\0'; j++) {
			if(s[i][j] == '{') chaves++;
			else if(s[i][j] == '}') chaves--;
			
			if(chaves < 0) return false;
		}
	}
	
	return chaves == 0;
	
}

int main() {
	unsigned short int n;
	scanf("%hu", &n);
	
	fflush(stdin);
	
	char s[n][MAX];
	for(int i=0; i<n; i++)
		fgets(s[i], MAX, stdin);
			
	if(valido(n, s)) printf("S");
	else printf("N");
	
	return 0;
}
