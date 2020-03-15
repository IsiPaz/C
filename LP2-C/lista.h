#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct dato {
    void* contenido;
    char tipo;
} dato;

typedef struct Nodo {
    dato info;
    struct Nodo *next;
} Nodo;

typedef struct lista {
    Nodo* head;
    Nodo* tail;
    Nodo* curr;
    int length;
} lista;

void init(lista* a);
void moveToStar(lista* a);
int length(lista* a);
void moveToEnd(lista* a);
void destructor(lista* a);
void clear(lista* a);
void append(lista* a, dato d);
void insert(lista* a, int i, dato d);
void remov(lista* a, int i);
dato* at(lista* a, int i);

#endif
