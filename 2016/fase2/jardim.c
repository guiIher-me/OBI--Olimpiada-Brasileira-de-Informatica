/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2021-07-22 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct point {
	float x;
	float y;
} Point;

/**
 * Transforma uma medida de radianos para graus
 * @param radianos: recebe uma medida em radianos
 * @param P2: Ponto 2
 * @return a medida em graus
 */
float radianos_para_graus(float radianos) {
	return radianos * 180 / M_PI;
}

/**
 * Determina se 3 pontos são colineares
 * @param P1: Ponto 1
 * @param P2: Ponto 2
 * @param P3: Ponto 3
 * @return true: se o determinante for 0, false caso contrário
 */
bool colineares(Point p1, Point p2, Point p3) {
	int det = p1.x*p2.y + p1.y*p3.x + p2.x*p3.y - (p3.x*p2.y + p3.y*p1.x + p2.x*p1.y);
	return det == 0;
}

/**
 * Encontra o comprimento de dois pontos
 * @param P1: Ponto 1
 * @param P2: Ponto 2
 * @return O comprimento P1P2
 */
float comprimento(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/**
 * Encontra o ângulo a partir de 3 pontos
 * @param P1: Ponto 1
 * @param P2: Ponto 2 (o ponto do angulo a ser descoberto)
 * @param P3: Ponto 3
 * @return O angulo em graus
 */
float angulo(Point p1, Point p2, Point p3) {
	float a = comprimento(p1,p3);
	float b = comprimento(p2,p3);
	float c = comprimento(p2,p1);
	float alpha = acos((pow(a,2) - pow(b,2) - pow(c,2)) / (-2*a*c));
	
	return ceil(radianos_para_graus(alpha));
}

/**
 * Encontra o ângulo a partir de 3 pontos
 * @param P1: Ponto 1
 * @param P2: Ponto 2 (o ponto do angulo a ser descoberto)
 * @param P3: Ponto 3
 * @return O angulo em graus
 */
Point ponto_medio(Point p1, Point p2) {
	Point pm;
	
	pm.x = (float) (p1.x + p2.x) / 2;
	pm.y = (float) (p1.y + p2.y) / 2;
	 
	return pm;
}

/**
 * Verifica se dois pontos são iguais
 * @param P1: Ponto 1
 * @param P2: Ponto 2
 * @return true se os pontos se coincidirem, false caso contrário
 */
bool pontos_iguais(Point p1, Point p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

/**
 * Verifica se duas retas são concorrentes
 * @param P1: Ponto 1 (segmento de reta 1)
 * @param P2: Ponto 2 (segmento de reta 1)
 * @param p3: Ponto 3 (segmento de reta 2)
 * @param p4: Ponto 4 (segmento de reta 2)
 * @return true se os pontos se coincidirem, false caso contrário
 */
bool retas_concorrentes(Point p1, Point p2, Point p3, Point p4) {
	return true;
}

int main() {
	Point p[8];
	
	int x, y;
	for(int i=1; i<=7; i++) {
		scanf("%d%d", &x, &y);
		p[i].x = (float) x;
		p[i].y = (float) y;
	}
	
	if(angulo(p[2], p[1], p[3]) < 90 && 
	   comprimento(p[1], p[2]) == comprimento(p[1], p[3]) && 
	   colineares(p[2], p[3], p[4]) && colineares (p[3], p[4], p[5]) &&
	   pontos_iguais(ponto_medio(p[2], p[3]), ponto_medio(p[4], p[5])) &&
	   comprimento(p[2], p[3]) > comprimento(p[4], p[5]) &&
	   angulo(p[2], p[4], p[6]) == 90 && angulo(p[3], p[5], p[7]) == 90 &&
	   comprimento(p[4], p[6]) == comprimento(p[5], p[7]) &&
	   retas_concorrentes(p[1], p[6], p[2], p[3]))
	   printf("S");
	else printf("N");
	
	return 0;
}
