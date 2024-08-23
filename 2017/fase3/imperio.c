/*@Author: Guilherme Cardoso <guilherme.cardoso-oliveira@unesp.br>
  @since : 2024-08-23 */
  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_FORMAT "%d"
#define PRINT_SEPARATOR "->"
#define UNKNOWN -1

typedef int Data;

typedef struct node {
	int data;
	struct node *next;
} * Node;

typedef struct ancestor {
    int descendants;
	Node head;
} * Ancestor;

bool empty(Node node) {
	return node == NULL;
}

Node node_alloc() {
	Node node = (Node) malloc(sizeof(struct node));
	if(empty(node)) exit(EXIT_FAILURE);
	return node;
}

Node node_new(Data data) {
	Node node  = node_alloc();
	node->data = data;
	node->next = NULL;
	
	return node;
}

void node_print(Node node) {
	if(empty(node)) {
		printf("[NULL]\n");
		return;	
	}
	
	printf("[");
	printf(DATA_FORMAT, node->data);
	printf("]");
	printf(PRINT_SEPARATOR);
	
	return node_print(node->next);
}

bool isInit(Ancestor list) {
	return list != NULL;
}

Ancestor new_list() {
	Ancestor list = (Ancestor) malloc(sizeof(struct ancestor));
	if(list == NULL) exit(EXIT_FAILURE);
	
	list->head = NULL;
	list->descendants = UNKNOWN;
	return list;
}

void addFirst(Ancestor list, Data data) {
	Node node = node_new(data);
    node->next = list->head;
    list->head = node;
}

int setDescendants(Ancestor *ancestors, int i) {
     if(ancestors[i]->descendants != UNKNOWN) {
         //printf("id %d previamente calculado: %d\n", i, ancestors[i]->descendants);
         return ancestors[i]->descendants;
     }
     
     if(empty(ancestors[i]->head)) {
         //printf("id %d sem descendentes (settando para 0)\n", i);
         return ancestors[i]->descendants = 0;
     }
     
     int descendants = 0;
     Node child = ancestors[i]->head;
     while(child != NULL) {
         descendants += 1 + setDescendants(ancestors, child->data);
         child = child->next;
     }
     
     //printf("id %d tem %d descendentes (settando...)\n", i, descendants);
     return ancestors[i]->descendants = descendants;
}

void print(Ancestor list) {
	node_print(list->head);
}

int main() {
    int n, i, a, b;
    scanf("%d", &n);
    
    Ancestor ancestors[n+1];
    for(i=1; i<=n; i++)
        ancestors[i] = new_list();
    
    for(i=0; i<n-1; i++) {
        scanf("%d%d", &a, &b);
        addFirst(ancestors[a], b);
    }
    
    int minDiff = n, descendants, diff;
    for(i=1; i<=n; i++) {
        setDescendants(ancestors, i);
        diff = abs(n - 2*(ancestors[i]->descendants+1));
        //print(ancestors[i]);
        //printf("[%d] Descendentes: %d | Diff: %d\n\n", i, ancestors[i]->descendants, diff);
        if(diff < minDiff) minDiff = diff;
    }
    
    printf("%d", minDiff);
    system("pause");
    return 0;
}
