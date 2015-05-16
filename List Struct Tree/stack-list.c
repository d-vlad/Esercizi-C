#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Dichiarazione struttura Stack*/
struct lista {
    int info;
    struct lista *next;
};
typedef struct lista *Stack;

/*Funzione Push inserisce l'elemento nello Stack*/
int push(Stack *l, int elem){
    if(*l==NULL){
        (*l)=malloc(sizeof(struct lista));
        if((*l)){
            (*l)->next=NULL;
            (*l)->info=elem;
            return 1;
        }
        else return 0;
    }
    push(&((*l)->next), elem);
}


/*Funzione Pop estrae l'ultimo elemento inserito nello Stack e ritorna il suo valore*/
int pop(Stack *s){
    if((*s)->next->next==NULL){
        int num=(*s)->next->info;
        free((*s)->next);
        (*s)->next=NULL;
        return num;
    }
    return pop(&((*s)->next));
}

/*Ritorna 1 se lo stack e vuoto 0 altrimenti*/
int is_empty(Stack s){
    return s==NULL;
}

void stampa_stack(Stack s){
    if(s!=NULL){
        stampa_stack(s->next);
        printf("%d\n", s->info);
    }
}

int main(){
 Stack l=NULL;
 int i;
 for(i=0; i<10; i++){
    int k=rand()%10;
    push(&l, k);
 }
 printf("Stack: \n");
 stampa_stack(l);

 printf("\n\n");
 pop(&l);
 printf("Dopo la pop: \n");
 stampa_stack(l);
return 0;
}

