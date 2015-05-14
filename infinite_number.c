#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Questo programma prende in input un numero infinitamente grande e lo inserisce
in una lista di interi.

*/

/*
Dichiarazione tipo lista interi
*/
struct lista{
	int info;
	struct lista *next;
};
typedef struct lista *Tlista;

/*
Dato un carattere lo trasforma in numero
*/
int trasforma_char(char a){
	if(a=='0')
		return 0;
	if(a=='1')
		return 1;
	if(a=='2')
		return 2;
	if(a=='3')
		return 3;
	if(a=='4')
		return 4;
	if(a=='5')
		return 5;
	if(a=='6')
		return 6;
	if(a=='7')
		return 7;
	if(a=='8')
		return 8;
	if(a=='9')
		return 9;
}

/*
La funzioen Append inserisce un elemento in fondo alla lista l
e ritorna 1 se e andato tutto a buon fine 0 altrimenti
*/

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

/*
Questa funzione legge da standard input un numero infinitamente grande e lo inserisce in una lista di interi
*/
int leggi_and_insert(Tlista *l){
	char *str;
	size_t buffer=100;
	str=malloc(sizeof(char)*buffer);
	printf("Inserire numero: ");
	int dim=getline(&str, &buffer, stdin);
	int i;
	for(i=0; str[i]!='\0'; i++){
		int numero=trasforma_char(str[i]);
		if(numero>=0 && numero<=9)
			append(l,numero);
	}
	return dim-1;
}


/*
Questa funzione Stampa gli elementi di una lista
*/
void stampa_lista(Tlista l){
	while(l!=NULL){
		printf("%d", l->info);
		l=l->next;
	}
}


int main(){
	Tlista lst=NULL;
	leggi_and_insert(&lst);
	stampa_lista(lst);
	printf("\n\n");
	return 0;
}
