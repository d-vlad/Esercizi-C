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

int Lunghezza(char *v){
    int i,dim=0;
    for (i = 0; v[i]!='\0'; i++) {
        dim++;
    }
    return dim;
}
int cerca(char a[], int inf, int sup){
    if(inf>sup){
        return -1;
    }
    int mid=(inf+sup)/2;
    int res = (a[mid]=='a' && a[mid+1]=='b' ? 1 : 0); //questo e perche quando divido il problema in sottoproblemi potrebbe capitare che ab siano proprio a meta e vengano divisi e quindi la sequenza non sarebbe riconosciuta
    return  res + cerca(a,inf,mid) + cerca(a,mid+1,sup); //cerco nella prima parte dell'array da inf a 
}

//Main di prova
int main(){
    char vett[MAXDIM];
    printf("Inserire stringa: ");
    scanf("%s", vett);
    int elementi=cerca(vett, 0, Lunghezza(vett));
    printf("Lunghezza String: %d\n",elementi);
    return 0;
    
}