#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXDIM 100

/*
La funzione addiacenti controlla se nelle prime due posizioni e presente ab sono adiacenti in una stringa
    es:
        addiacenti(ab.................adacacsaab) -> 1
*/
int addiacenti(char *v){
    if((v[0])=='a' && ((v[1]))=='b'){
        return 1;
    }
    return 0;
}


/*
Ritorna il numero di sequenze ab presenti nella stringa passata come parametro
    es:
    controllaSequenza(cababcab) -> 3 in quanto ci sono 3 sequenze di ab 
*/
int controllaSequenza(char *array){
    int sequenze=0;
    while(array[0]!='\0' && array[1]!='\0') {
        sequenze = sequenze + addiacenti(array);
        array++;
    }
    return sequenze;
}

//Main di prova
int main(){
    char vett[MAXDIM];
    printf("Inserire stringa: ");
    scanf("%s", vett);
    int elementi=controllaSequenza(vett);
    printf("Lunghezza String: %d\n",elementi);
    return 0;
    
}