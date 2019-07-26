#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stdlib.h>

struct lista;
typedef struct lista lista_t;

struct lista_iter;
typedef struct lista_iter lista_iter_t;

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Devuelve verdadero o falso, según si la lista tiene o no elementos .
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al inicio
// de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

//devuelve el primer elemento de la lista, si esta vacia devuelve NULL
//PRE: la lsta fue creada 
//POST: borra el primer elemento de la lista
void *lista_borrar_primero(lista_t *lista);

//PRE: lista fue creada
//POST: devuelve el primer elemento,  en caso que no exista devuelve NULL
void *lista_ver_primero(const lista_t *lista);

//PRE: lista fue creada
//POST: devuelve el ultimo elemento,  en caso que no exista devuelve NULL
void *lista_ver_ultimo(const lista_t* lista);


size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la listallama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));

//PRE: las lista fue creada
//POST: crea el iterador apuntando al primer elemento de la lista 
//en caso que no se crea devulve NULL
lista_iter_t *lista_iter_crear(lista_t *lista);

//PRE: iter creado
//POST: avanza el puntero actual una posicion, en caso que no se puede avanzar de vuelve NULL
bool lista_iter_avanzar(lista_iter_t *iter);

//devuelve el elemento actual en el cual se encuentra el iterador
void *lista_iter_ver_actual(const lista_iter_t *iter);

//PRE: iter creado
//POST:si el puntero actual del iterador se encuentra en NULL devuelve true
//caso contrario es false
bool lista_iter_al_final(const lista_iter_t *iter);

//destruye el iterador
void lista_iter_destruir(lista_iter_t *iter);

//PRE: iter creado
//POST: insertamos el elemento en la posicion en la cual se encuentre el iterador
//devuelve false si el nodo_t no se crea adecuadamente
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

//devuelve el  elemento de la lista, si esta vacia devuelve NULL
//PRE: el iterador fue creada 
//POST: borra el  elemento que apunta el iterador
void *lista_iter_borrar(lista_iter_t *iter);

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);


/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

// Realiza pruebas sobre la implementación del alumno.
//
// Las pruebas deben emplazarse en el archivo ‘pruebas_alumno.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en lista.h
// (esto es, las pruebas no pueden acceder a los miembros del struct lista).
//
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.
void pruebas_lista_alumno(void);

#endif // LISTA_H