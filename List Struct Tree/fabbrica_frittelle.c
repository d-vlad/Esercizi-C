#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
E' Carnevale, e l'esame di oggi vi chiede di gestire una fabbrica di frittelle.
Per fare una confezione di frittelle ci vogliono: 1 etto di farina, 3 uova, 2 cucchiai di olio, e 3 cucchiai di zucchero.
Ogni confezione di frittelle, una volta prodotta, sarà inserita in un pacco (che può contenere più confezioni) etichettato
con il nome del cliente ed inserita in una lista di pacchi pronti per essere ritirati.
Useremo i seguenti tipi
*/

typedef struct {
    int farina; /* etti di farina */
    int uova; /* numero uova */
    int olio; /* cucchiai di olio */
    int zucchero; /* cucchiai di zucchero */
} Dispensa;

struct Pacco{
    char nome_cliente[10];
    int n_confezioni;
    struct Pacco* next;
};
typedef struct Pacco *ListaPacchi;

/*
Esercizio 1: Implementare la seguente funzione:
int produci(Dispensa* d);
La procedura produci restituisce il numero massimo di confezioni di frittelle che si possono produrre con le quantità
presenti nella dispensa *d. All'uscita della funzione, i valori dei campi di *d dovranno ovviamente essere decrementati in
ragione degli ingredienti effettivamente consumati.

*/

int produci(Dispensa* d){
    int frittelle=0;
    while(d->farina>=1 && d->olio>=2 && d->zucchero>=3 && d->uova>=3){
        d->farina-=1;
        d->olio-=2;
        d->zucchero-=3;
        d->uova-=3;
        frittelle++;
    }
    return frittelle;
}


/*
Esercizio 2: Implementare la seguente procedura:
ListaPacchi aggiungiPacco(ListaPacchi l, char* cliente, int numero_confezioni);
La procedura aggiungiPacco aggiunge in coda alla lista l un nuovo pacco, destinato al cliente di nome cliente,
e contenente numero_confezioni confezioni di frittelle.
*/
int AggiungiPacco(ListaPacchi *l, char *cliente, int numero_confezioni){
    if(*l==NULL){
        (*l)=malloc(sizeof(struct Pacco));
        if((*l)){
            (*l)->next=NULL;
            (*l)->n_confezioni=numero_confezioni;
            strcpy((*l)->nome_cliente, cliente);
            return 1;
        }
        else return 0;
    }
    AggiungiPacco(&((*l)->next), cliente, numero_confezioni);
}

/*
Esercizio 3: Implementare la seguente procedura:
void ritiraPacco(ListaPacchi* l, char* cliente);
La procedura ritiraPacco deve eliminare dalla lista l tutti i pacchi corripondenti al cliente di nome cliente
presenti nella lista.
*/
void RitiroPacco(ListaPacchi *l, char *cliente){
    int uguali=strcmp((*l)->nome_cliente, cliente);
    if(uguali==0){
        ListaPacchi tmp=(*l);
        (*l)=(*l)->next;
        free(tmp);
    }
    while((*l)->next){
        uguali=strcmp((*l)->next->nome_cliente, cliente);
        if(uguali==0){
            ListaPacchi tmp=(*l)->next;
            (*l)=tmp->next;
            free(tmp);
        }
        (*l)=(*l)->next;
    }
}


void stampa_lista(ListaPacchi l){
    while(l->next){
        printf("Cliente: %s \t Confezioni: %d\n", l->nome_cliente, l->n_confezioni);
        l=l->next;
    }
}


int main(){
    int i;
    ListaPacchi l=NULL;
    for(i=0; i<10; i++){
        int confezioni=rand()%10;
        char cliente[]="Ciao";
        AggiungiPacco(&l,cliente,confezioni);
    }
    stampa_lista(l);
    printf("\n\n");

return 0;
}
