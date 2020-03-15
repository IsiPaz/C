#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
Nombre de la función : init
Descripción de la función : inicializa la lista
——————————————–
Inputs:
lista* a, puntero del tipo lista

..................
——————————————–
Output:
void, no retorna nada.
*/

void init(lista* a){
    a->head = a->tail = a->curr = (Nodo *)malloc(sizeof(Nodo));
    a->length = 0;
}

/*
Nombre de la función :moveToStar
Descripción de la función : mueve el curr a la cabeza de la lista
——————————————–
Inputs:

lista* a, puntero a la lista que se quiere aplicar la funcion
..................
——————————————–
Output:
void, no retorna.
*/

void moveToStar(lista* a) {
    if (a->head != NULL){
        a->curr = a->head;
    }
}

/*
Nombre de la función : length
Descripción de la función : retorna el largo de la lista
——————————————–
Inputs:
lista* a, puntero a lista que se quiere medi
..................
——————————————–
Output:
int, retorna el tamaño de la lista
*/

int length(lista* a){
    int x;
    x = a->length;
    return x;
}

/*
Nombre de la función : moveToEnd
Descripción de la función : mueve el curr a la cola de la funcion
——————————————–
Inputs:
lista* a, puntero a lista que se desea mover el curr
..................
——————————————–
Output:
void, no retorna
*/

void moveToEnd(lista* a) {
    if(a->curr != a->tail){
        a->curr = a->tail;
    }
}

/*
Nombre de la función : destructor
Descripción de la función : libera la memoria del nodo head.
——————————————–
Inputs:
lista* a, recibe un puntero a la lista que se le quiere borrar el nodo head
..................
——————————————–
Output:
void, no retorna
*/

void destructor(lista* a){
    free(a->head);
    free(a);
}

/*
Nombre de la función : clear
Descripción de la función : Elimina los elementos de una lista, dejándola vacı́a.
——————————————–
Inputs:
lista* a, recibe un puntero a la lista que se le quiere aplicar clean
..................
——————————————–
Output:
void, no retorna
*/

void clear(lista* a){
    Nodo* aux;
    int i;

    if (a->length == 0){
        return;
    }
    moveToStar(a);
    for (i=0; i < a->length; ++i){
        aux = a->curr->next;
        if(a->curr->info.tipo == 'i' || a->curr->info.tipo == 'f'){
            free(a->curr->info.contenido);
            free(a->curr);
            a->curr = aux;
        }
        else{
            clear(a->curr->info.contenido);
            destructor(a->curr->info.contenido);
            free(a->curr);
            a->curr = aux;
        }
    }
    init(a);
}

/*
Nombre de la función : append
Descripción de la función : Agrega un elemento al final de la lista.
——————————————–
Inputs:
lista* a, puntero a la lista que se le hara append
dato d, dato que se ingresara al hacer append
..................
——————————————–
Output:
void, no retorna
*/

void append(lista* a, dato d){
    Nodo* aux1;
    int k;

    aux1 = a->curr;
    if (d.tipo == 'i' || d.tipo == 'f' || d.tipo == 'l'){
        if(length(a) == 0){
            if(d.tipo == 'i'){
                int* entero = (int *)malloc(sizeof(int));
                *entero = *((int *)d.contenido);
                a->curr->info.tipo = 'i';
                a->curr->info.contenido = entero;
                a->length++;
            }
            else if(d.tipo == 'f'){
                float* flotante = (float *)malloc(sizeof(float));
                *flotante = *((float *)d.contenido);
                a->curr->info.tipo = 'f';
                a->curr->info.contenido = flotante;
                a->length++;
            }
            else{
                lista* lol;
                lista* nueva = (lista*)malloc(sizeof(lista));
                init(nueva);
                lol = d.contenido;
                moveToStar(lol);

                for(k=0; k<length(lol); ++k){
                    append(nueva,lol->curr->info);
                    lol->curr= lol->curr->next;
                }

                a->curr->info.tipo = 'l';
                a->curr->info.contenido = nueva;
                a->length++;
            }
        }
        else {
            moveToEnd(a);
            a->curr->next = (Nodo *)malloc(sizeof(Nodo));
            a->tail = a->curr->next;

            if(d.tipo == 'i'){
                int* entero = (int *)malloc(sizeof(int));
                *entero = *((int *)d.contenido);
                a->tail->info.tipo = 'i';
                a->tail->info.contenido = entero;
                a->length++;
                a->curr = aux1;
            }
            else if (d.tipo == 'f'){
                float* flotante = (float *)malloc(sizeof(float));
                *flotante = *((float *)d.contenido);
                a->tail->info.tipo = 'f';
                a->tail->info.contenido = flotante;
                a->length++;
                a->curr = aux1;
            }

            else {
                lista* lol ;
                lista* nueva = (lista*)malloc(sizeof(lista));
                init(nueva);
                lol = d.contenido;
                moveToStar(lol);
                for(k=0; k<length(lol); ++k){
                    append(nueva,lol->curr->info);
                    lol->curr= lol->curr->next;
                }

                a->tail->info.tipo = 'l';
                a->tail->info.contenido = nueva;
                a->length++;
                a->curr = a->curr->next;
            }

        }
    }

    return;
}

/*
Nombre de la función : insert
Descripción de la función : Inserta un dato d en la posición i de la lista a.
——————————————–
Inputs:
lista* a, lista en la que se hará el insert.
int i, posicion i de la lista donde se quiere insertar
dato d, es el dato que se desea insertar en la lista
..................
——————————————–
Output:
void, no retorna.
*/

void insert(lista* a, int i, dato d){
    int count;
    Nodo* aux;
    Nodo* aux1;
    int k;
    aux1 = a->curr;

    if (d.tipo == 'i' || d.tipo == 'f' || d.tipo == 'l'){
        if (a->length>i){
            moveToStar(a);
            if(i==0){
                aux = a->head;
                a->head = (Nodo *)malloc(sizeof(Nodo));
                if(d.tipo == 'i'){
                    int* entero = (int *)malloc(sizeof(int));
                    *entero = *((int *)d.contenido);
                    a->head->info.tipo = 'i';
                    a->head->info.contenido = entero;
                    a->length++;
                }

                else if(d.tipo == 'f'){
                    float* flotante = (float *)malloc(sizeof(float));
                    *flotante = *((float *)d.contenido);
                    a->head->info.tipo = 'f';
                    a->head->info.contenido = flotante;
                    a->length++;
                }

                else {
                    lista* lol;
                    lista* nueva = (lista*)malloc(sizeof(lista));
                    init(nueva);
                    lol = d.contenido;
                    moveToStar(lol);
                    for(k=0; k<length(lol); ++k){
                        append(nueva,lol->curr->info);
                        lol->curr= lol->curr->next;
                    }
                    a->head->info.tipo = 'l';
                    a->head->info.contenido = nueva;
                    a->length++;
                }

                a->head->next = aux;
            }

            else{ // si no es a la cabeza
                for (count=0;count<i-1;++count){  //[a,b]
                    a->curr = a->curr->next;
                }
                aux = a->curr->next;
                a->curr->next = (Nodo *)malloc(sizeof(Nodo));
                if(d.tipo == 'i'){
                    int* entero = (int *)malloc(sizeof(int));
                    *entero = *((int *)d.contenido);
                    a->curr->next->info.tipo = 'i';
                    a->curr->next->info.contenido = entero;
                    a->length++;
                    a->curr->next->next = aux;
                    if (a->curr == a->tail){
                        a->tail = a->curr->next;
                    }

                }
                else if(d.tipo == 'f'){
                    float* flotante = (float *)malloc(sizeof(float));
                    *flotante = *((float *)d.contenido);
                    a->curr->next->info.tipo = 'f';
                    a->curr->next->info.contenido = flotante;
                    a->length++;
                    a->curr->next->next = aux;
                    if (a->curr == a->tail){
                        a->tail = a->curr->next;
                    }
                }

                else{
                    lista* lol;
                    lista* nueva = (lista*)malloc(sizeof(lista));
                    init(nueva);
                    lol = d.contenido;
                    moveToStar(lol);
                    for(k=0; k<length(lol); ++k){
                        append(nueva,lol->curr->info);
                        lol->curr= lol->curr->next;
                    }
                    a->curr->next->info.tipo = 'l';
                    a->curr->next->info.contenido = nueva;
                    a->length++;
                    a->curr->next->next = aux;
                    if (a->curr == a->tail){
                        a->tail = a->curr->next;
                    }
                }
            }

            a->curr = aux1;
        }

        return;
    }

    return;

}

/*
Nombre de la función : remov
Descripción de la función : Elimina y libera la memoria de un elemento
en la posición i de la lista.
——————————————–
Inputs:
lista* a, puntero a la lista que se le aplicara el remov
int i, posicipn del nodo a eliminar
..................
——————————————–
Output:
void, no retorna

*/

void remov(lista* a, int i){
    int count;
    Nodo* aux;


    if (a->length>i){
        if (a->length==1){  //un solo elemento
            if(a->curr->info.tipo == 'i' || a->curr->info.tipo == 'f'){
                free(a->curr->info.contenido);
                free(a->curr);
            }
            else{
                clear(a->curr->info.contenido);
                destructor(a->curr->info.contenido);
                free(a->curr);
            }
            init(a);
        }

        else if (i==0){ //cabeza
            moveToStar(a);
            aux = a->curr->next;

            if(a->curr->info.tipo == 'i' || a->curr->info.tipo == 'f'){
                free(a->curr->info.contenido);
                free(a->curr);
                a->curr = aux;
            }
            else{
                clear(a->curr->info.contenido);
                destructor(a->curr->info.contenido);
                free(a->curr);
                a->curr = aux;
            }
            a->head = aux;
            a->length--;
        }

        else { //listas con mas de un elemento
            moveToStar(a);
            for (count=0;count<i;++count){
                a->curr = a->curr->next;
            }
            aux = a->curr; //este es el que quiero eliminar
            moveToStar(a);
            for (count=0;count<i-1;++count){ //con esto llego al nodo anterior del que quiero borrar
                a->curr = a->curr->next;
            }
            if (a->curr->next == a->tail){
                a->tail=a->curr;
            }
            a->curr->next = a->curr->next->next;
            if(aux->info.tipo == 'i' || aux->info.tipo == 'f'){
                free(aux->info.contenido);
                free(aux);

            }
            else{
                clear(aux->info.contenido);
                destructor(aux->info.contenido);
                free(aux);

            }
            a->curr = a->curr->next;
        }

    }

}

/*
Nombre de la función : at
Descripción de la función : Retorna el elemento en la posición i de la lista.
——————————————–
Inputs:
lista* a, lista en la que se quiere buscar
int i, posicion de la lista en la que se quiere obtener el dato
..................
——————————————–
Output:
dato* , retorna un puntero al dato obtenido.
*/

dato* at(lista* a, int i){
    dato* d;
    Nodo* aux1;
    int count;
    aux1 = a->curr;

    if (a->length>i){
        moveToStar(a);

        if (a->length==1){ //un solo elemento en la lista
            d = &a->curr->info;
            a->curr = aux1;
            return d;
        }
        else{
            for (count=0;count<i;++count){
                a->curr = a->curr->next;
            }
            d = &a->curr->info;
            a->curr = aux1;
            return d;
        }
    }
    printf("Posicion fuera de rango");
    return NULL;
}
