#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
typedef struct orden{
    int valor;
    struct orden *izq, *der;
}orden;
 
typedef orden *pto;
 
void insertNodo (pto *raiz, int dato);
void imprimir (pto raiz);
pto búsqueda (pto raiz, int dato);
int nivel (pto raiz, int dato);
 

void arbol (pto *raiz, int *dato);
 
int main (){
 
    pto raiz;
    int dato, i=1, aux,valor;
    raiz = NULL;

    insertNodo (&raiz, 6);
    insertNodo (&raiz, 5);
    insertNodo (&raiz, 11);
    insertNodo (&raiz, 4);
    insertNodo (&raiz, 12);
    insertNodo (&raiz, 3);
    insertNodo (&raiz, 9);
    insertNodo (&raiz, 21);
 
    //Imprimimos el Arbol en orden
    printf("inserta el numero que quieres conocer (considere que se utilizara el arbol mostrado en el pizarron): ");
    scanf("%d",&valor);

    aux = nivel (raiz, valor);
    printf ("\nEl nivel es  : %d\n", aux);
 
system ("PAUSE");
return 0;
}
 
 
//Insertamos numeros//
void insertNodo (pto *raiz, int dato){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(orden));
        (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{
        if (dato <= (*raiz)->valor){
            insertNodo (&(*raiz)->izq, dato);
        }else{
            insertNodo (&(*raiz)->der, dato);
        }
    }
}
//imprimimos arbol//
void imprimir (pto raiz){
    if (raiz != NULL){
        imprimir (raiz->izq);
        printf ("%d, ", raiz->valor);
        imprimir (raiz->der);
    }
}
//Busqueda//
pto búsqueda (pto raiz, int dato){
    if (raiz == NULL){
        return NULL;
    }else{
        if (dato == raiz->valor){
            return raiz;
        }else{
            if (dato < raiz->valor){
                return búsqueda (raiz->izq, dato);
            }else{
                return búsqueda (raiz->der, dato);
            }
        }
    }
} 
//nivel//
int nivel (pto raiz, int dato){
    int nivel=1;
    pto actual=raiz;
    while (actual!=NULL){
        if (dato == actual->valor){           
            return nivel;
        }else{
            nivel++;
            if (dato < actual->valor){               
                actual=actual->izq;
            }else{
                if (dato > actual->valor){               
                    actual=actual->der;
                }
            }
        }
    }
printf("\n inexistente.\n");
return 0;
}