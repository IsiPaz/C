# C
Tarea 2 de Lenguajes de Programación, semestre 2019-2

## Compilación

0. Makefile: Para compilar y correr el makefile ingrese por consola el comando "make run"

1. Para compilar es necesario el uso de un main llamado main.c que incluya las librerias
   funciones.h y lista.h

2. Inicializacion de listas: Si se quiere crear una lista se debe pedir memoria con malloc dentro del main y luego usar la funcion init()
   ej:
	lista *l = malloc(sizeof(lista));
	init(l);

3. Creacion de datos: Manualmente, como se ve acontinuación
   ej:
	int i = 23;
	dato d;

	d.contenido = &i;
	d.tipo = 'i';

4. Función map: Para usar la función map debe utilizar & delante de la funcion que se entrega como parametro
   ej:
	map(p, &doble);  //doble es la función

5. Eliminar memoria: Para eliminar la memoria es necesario que use la función clear de cada lista que se inicializa dentro del main
                     y luego se necesita llamar a la funcion destructor
   ej:
	lista* a; lista* b;

	a = (lista*)malloc(sizeof(lista));
	b = (lista*)malloc(sizeof(lista));

	init(a);
	init(b);
	.
	.
	.
	clear(a);
	destructor(a);
	clear(b);
	destructor(b);
  
