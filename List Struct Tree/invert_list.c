#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Dichiarazione della struttura della lista*/
struct lista{
    int info;
    struct lista *next;
};
typedef struct lista *Tlista;


/*Funzione che permette di stampare gli elementi di una lista*/
void stampa_lista(Tlista l){
    while(l!=NULL){
        printf("%d ", l->info);
        l=l->next;
    }
}

/*Funzione che inserisce l'elemento elem in fondo alla lista*/
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

/*Funzione che elimina la lista*/
void destroy(Tlista *l){
    if(*l!=NULL)
        destroy(&((*l)->next));
        free(*l);
}

/*Inserisce l'elemento elem in testa alla lista*/
int prepend(Tlista *l, int elem){
    if(*l){
        Tlista newcell=malloc(sizeof(Tlista));
        if(newcell){
            newcell->next=(*l);
            newcell->info=elem;
            (*l)=newcell;
            return 1;
        }
        else
            return 0;
    }
    if(*l==NULL){
        Tlista newcell=malloc(sizeof(Tlista));
        if(newcell){
            newcell->next=NULL;
            newcell->info=elem;
            *l=newcell;
            return 1;
        }
        else return 0;
    }
}

/*Dato una lista invertire tutti gli elementi*/
void inverti(Tlista *l){
    Tlista m=NULL;
    while(*l){
        prepend(&m, (*l)->info);
        Tlista tmp=*l;
        *l=((*l)->next);
        free(tmp);
    }
    *l=m;
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
    inverti(&l);
    stampa_lista(l);

    destroy(&l);

return 0;
}
