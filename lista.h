#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int valor;
    struct Node * sig;
} node;


node * crearNodo( int valor) {
    node * auxp = (node *)malloc(sizeof(node));
    auxp->valor = valor;
    auxp->sig = NULL;
    return auxp;
}


void insertarFinal(node **lp, node **np){
    
    if (*lp == NULL) {
        *lp = *np;
        return;
    }
    node * auxp;
    for(auxp= *lp; auxp->sig != NULL; auxp=auxp->sig);
    auxp->sig = *np;
    return;

}

void imprimir(node *lp) {
    node * auxp;
    for(auxp=lp; auxp != NULL; auxp=auxp->sig)
        printf("%i->", auxp->valor);;
    printf("NULL\n");
}


void insertarInicio(node **lp,node **np){
    node * auxp; node * puntero;
    
    if (*lp==NULL){
        *lp= *np;
        return;
    }
        puntero=*lp;
        *lp=*np;
        (*np)->sig=puntero;

    }

void duplicarNodo(node *lp, node **np){
    if(lp==NULL){
        printf("La lista esta vacia no se puede duplicar");
        return;
    }
    *np = crearNodo(lp->valor);
}

void head(node *lp, node **np){
    if (lp==NULL){
        printf("La lista esta vacia");
        return;
    }
    duplicarNodo(lp,np);   
}

void duplicarLista(node *lp, node ** np){
    if (lp==NULL){
        printf("La lista esta vacia");
        return;
    }
    *np = NULL;
    node *auxp; node *duplicado = NULL;
    for (auxp=lp;auxp !=NULL;auxp=auxp->sig){
        duplicarNodo(auxp, &duplicado);
        insertarFinal(np, &duplicado);
    }
}