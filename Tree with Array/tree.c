#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//numero massimo di nodi che puo avere l'albero
#define MAXDIM 10

struct nodo{ //un nodo non e altro che una coppia con info che rappresenta il dato e parent che rappresenta il padre del nodo
    char info;
    int parent;
}
typedef struct nodo *Node;

struct tree{ //struttura dell'albero. L'albero e un insieme di nodi
    Node *nodi;
}
typedef struct tree *Tree;

Tree newTree(){
   Tree t;
   t=malloc(sizeof(struct Tree));
   t.nodi=malloc(sizeof(struct Node));
   return t;
}


int main(){
    
    
    
    
    
    return 0;
}

