#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 10


//Struttura dello stack
struct stack{
    int *info;
    int top;
};
typedef struct stack *Stack;

//inizializzo lo stack
Stack initStack(){
    Stack l=malloc(sizeof(struct stack));
    if(l){
        l->info= malloc(sizeof(int)*n);
        l->top=0;
    }
    return l;
}

//funzione che ritorna la cima dello stack senza eliminare l'elemento
int Top(Stack s){
    return s->info[s->top-1];
}

//funzione che ritorna true se lo stack e vuoto, false altrimenti
int StackEmpty(Stack s){
    return (s->top==0);
}

//Funzione che inserisce un elemento nella pila
void Push(Stack s, int e){
    s->info[s->top]=e;
    s->top++;
}

//Funzione che estrae un elemento dalla cima dello stack e lo elimina
int Pop(Stack s){
    if(s->top>0){
        s->top--;
        return s->info[s->top];
    }
    return -1;        
}

//Funzione che stampa lo stack dalla cima dello stack fino all'ultimo elemento
void PrintStack(Stack e){
    int i=e->top-1;
    while(i>=0){
        printf("Stack: %d \n", e->info[i]);
        i--;
    }
}

//Main di Prova
int main(){
    Stack m=initStack();
    Push(m,1);
    Push(m,2);
    Push(m,3);
    PrintStack(m);
    
    
    printf("\n\n\n");
    Pop(m);
    PrintStack(m);
    return 0;
}