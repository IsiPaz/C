#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "funciones.h"



/*
Nombre de la función : print1
Descripción de la función : imprime la lista, Se muestra en un formato adecuado la lista por pantalla,
se debe lograr notar claramente las listas anidadas.
——————————————–
Inputs:
(lista* a), puntero a lista que se desea imprimir

..................
——————————————–
Output:
void , no retorna
*/

void print1 (lista* a){
    int count;
    Nodo* aux1;
    aux1 = a->curr;
    moveToStar(a);
    printf("[");

    for (count=0;count<length(a);count++){
        char x;
        x = a->curr->info.tipo;
        if(x == 'i'){
            printf("%d",*((int *)a->curr->info.contenido));
            if (a->curr!=a->tail){
                printf(",");
            }
        }

        else if(x == 'f'){
            printf("%f",*((float *)a->curr->info.contenido)); //ojo con esto %.1f
            if (a->curr!=a->tail){
                printf(",");
            }
        }

        else if (x=='l'){

            lista* l ;
            l = (lista *)a->curr->info.contenido;
            print1(l);
            if (a->curr!=a->tail){
                printf(",");
            }
        }

        else{
            printf("dato incorrecto\n");
        }

        a->curr = a->curr->next;
    }
    printf("]");

    a->curr=aux1;
}

/*
Nombre de la función : print
Descripción de la función : funcion que llama a print1 e imprime un '\n' al final de cada lista
——————————————–
Inputs:
lista* a, puntero a lista que se imprimirá
..................
——————————————–
Output:
void, no retorna
*/

void print(lista* a){
    print1(a);
    printf("\n");
}

/*
Nombre de la función : sum
Descripción de la función : Suma total de los elementos de la lista. En caso de una
lista vacia, esta se considera como 0
——————————————–
Inputs:
(lista* a), puntero a la lista que se quiere aplicar la funcion sum

..................
——————————————–
Output:
(float), suma total de los elementos de la lista
*/

float sum(lista* a){
    float suma=0;
    int count;
    int c;
    float b;
    Nodo* aux1 = a->curr;
    moveToStar(a);

    for (count=0;count<length(a);count++){
        char x;
        x = a->curr->info.tipo;
        if( x=='i'){
            c = *((int *)a->curr->info.contenido);
            suma=suma+c;
        }

        else if (x=='f'){
            b = *((float *)a->curr->info.contenido);
            suma=suma+b;
        }

        else{
            lista* l ;
            l = (lista *)a->curr->info.contenido;

            if(length(l)==0){
                suma=suma;
            }
            else{
                b=sum(l);
                suma=suma+b;
            }
        }
        a->curr = a->curr->next;
    }
    a->curr=aux1;
    return suma;
}

/*
Nombre de la función :average
Descripción de la función : Se calcula el promedio total de la lista, si existe una
lista anidada, se calcula primero el promedio de la lista interna y el resultado es usado para
el calculo del promedio total. En caso de una lista vacı́a, no se considera para el calculo
del promedio.
——————————————–
Inputs:
(lista* a) puntero a la lista que se le aplicara average
..................
——————————————–
Output:
(float), retorna el promedio total de la lista en una variable del tipo float
*/

float average(lista* a){
    float prom=0,suma=0,b;
    int count,c,z=0;
    Nodo* aux1 = a->curr;
    moveToStar(a);

    for (count=0;count<length(a);count++){
        char x;
        x = a->curr->info.tipo;
        if( x=='i'){
            c = *((int *)a->curr->info.contenido);
            suma=suma+c;
            z=z+1;
        }

        else if (x=='f'){
            b = *((float *)a->curr->info.contenido);
            suma=suma+b;
            z=z+1;
        }

        else{
            lista* l ;
            l = (lista *)a->curr->info.contenido;
            if(length(l)==0){
                suma=suma;
            }
            else{
                b=average(l);
                suma=suma+b;
                z=z+1;
            }
        }
        a->curr = a->curr->next;
    }
    if(suma==0 && z==0){
        return 0;
    }
    else{
        prom = suma/z;
        a->curr=aux1;
        return prom;
    }
}

/*
Nombre de la función :map
Descripción de la función : Aplica una funcion f entregada como parametro a cada
uno de los elementos de la lista. Si hay un lista anidada, aplica la funcion a cada elementos
de esta.
——————————————–
Inputs:
(lista* a) puntero a la lista que se le aplicara la funcion f
(dato (*f)(dato)) puntero a la funcion f
..................
——————————————–
Output:
(lista*) retorna un puntero a una nueva lista con los elementos luego de aplicar la funcion f.
*/

lista* map(lista* a,dato (*f)(dato)){
    lista* nueva; lista* extra;
    dato* auxiliar;
    dato copy;
    int i;
    int largo = length(a);
    moveToStar(a);
    nueva = (lista*)malloc(sizeof(lista));
    init(nueva);

    auxiliar = at(a,1);
    for(i=0; i<largo; ++i){
        auxiliar = at(a,i);

        if (auxiliar->tipo == 'i'){
            int j = *((int *)auxiliar->contenido);
            copy.tipo = 'i';
            copy.contenido = &j;
            append(nueva,f(copy));
        }

        else if (auxiliar->tipo == 'f'){
            float j = *((float *)auxiliar->contenido);
            copy.tipo = 'f';
            copy.contenido = &j;
            append(nueva,f(copy));
        }

        else if (auxiliar->tipo == 'l'){
            extra = map((lista *)auxiliar->contenido,f);
            copy.tipo = 'l';
            copy.contenido = extra;
            append(nueva,copy);
            clear(extra);
            destructor(extra);
        }

        else{
            printf("dato incorrecto\n");
            return NULL;
        }
    }

    return nueva;
}
