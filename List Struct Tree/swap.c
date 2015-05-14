#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    int info;
    struct lista *next;
};
typedef struct lista *Tlista;

/*Funzione Che scambia due interi tra di loro*/
void swap_int(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

/*Funzione che data una lista scambia l'elemento in posizione i con l'elemento in posizione j*/
void swap(Tlista l, int i, int j){
    Tlista l1=l;
    Tlista l2=l;
    int k;
    for(k=0; k<i-1; ++k)
        l1=l1->next;

    for(k=0; k<j-1; ++k)
        l2=l2->next;

    swap_int(&(l1->info), &(l2->info));
}

/*Funzioni Ausiliarie */
void stampa_lista(Tlista l){
    while(l!=NULL){
        printf("%d ", l->info);
        l=l->next;
    }
}

int append(Tlista *l, int elem){
    if(*l==NULL){
        *l=malloc(sizeof(Tlista));
        if(*l){
            (*l)->next=NULL;
            (*l)->info=elem;
            return 1;
        }
        else{
            return 0;
        }
    }
    append(&((*l)->next), elem);
}

void destroy(Tlista *l){
    if(*l!=NULL)
        destroy(&((*l)->next));
        free(*l);
}

int main(){
    Tlista l=NULL;
    int i;
    for(i=0; i<10; i++){
        int k=rand()%100;
        append(&l, k);
    }
    printf("Lista Originale:");
    stampa_lista(l);
    printf("\n");

    printf("Lista Modificata:");
    swap(l, 2,5);
    stampa_lista(l);

    destroy(&l);

return 0;
}
