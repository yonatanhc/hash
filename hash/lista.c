#include "lista.h"
#include <stdlib.h>

typedef struct nodo{
	void* dato;
	struct nodo* siguiente;

}nodo_t;

nodo_t* crear_nodo(void* valor){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if ( nodo == NULL) return NULL;
	nodo->dato = valor;
	nodo->siguiente = NULL;

	return nodo;
}


struct lista{
    nodo_t* primero;
    nodo_t* ultimo;
    size_t tamanio;
};

lista_t *lista_crear(void) {
	lista_t* lista = malloc(sizeof(lista_t));
	if (lista == NULL) return NULL;
	lista->primero = NULL;
	lista->ultimo = NULL;
	lista->tamanio = 0;
	return lista;
}

bool lista_esta_vacia(const lista_t *lista) {
	return (!lista->primero && !lista->ultimo);

}

bool lista_insertar_primero(lista_t *lista, void *dato) {
	nodo_t* nodo = crear_nodo(dato);
	if (nodo == NULL) return false;
	if (lista_esta_vacia(lista)) lista->ultimo = nodo;
	else nodo->siguiente = lista->primero;
	lista->primero = nodo;
	lista->tamanio++;
	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
	nodo_t* nodo = crear_nodo(dato);
	if (nodo == NULL) return false;
	if (lista_esta_vacia(lista)) lista->primero = nodo;
	else lista->ultimo->siguiente = nodo;
	lista->ultimo = nodo;
	lista->tamanio++;
	return true;
}

void *lista_borrar_primero(lista_t *lista) {
	if (lista_esta_vacia(lista)) return NULL;
	void* aux_dato = lista->primero->dato;
	nodo_t* aux = lista->primero;
	lista->primero = aux->siguiente;
	if (!lista->primero) lista->ultimo = NULL;
	lista->tamanio--;
	free(aux);
	return aux_dato;
}

void *lista_ver_primero(const lista_t *lista) {
	if (lista_esta_vacia(lista)) return NULL;
	return lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista) {
	if (lista_esta_vacia(lista)) return NULL;
	return lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista) {
	return lista->tamanio;
}

void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	while(!lista_esta_vacia(lista)) {
		void* aux = lista_borrar_primero(lista);
		if ( destruir_dato != NULL) {
			destruir_dato(aux);
		}
	}
	free(lista);
}

struct lista_iter {
	lista_t* lista;
	nodo_t* actual;
	nodo_t* anterior;
};

lista_iter_t *lista_iter_crear(lista_t *lista) {
	lista_iter_t* iter = malloc(sizeof(lista_iter_t));
	if (iter == NULL) return NULL;
	iter->actual = lista->primero;
	iter->anterior = NULL;
	iter->lista = lista;
	return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter) {
	if (lista_iter_al_final(iter)) return false;
	iter->anterior = iter->actual;
	iter->actual = iter->actual->siguiente;
	return true;
}

void *lista_iter_ver_actual(const lista_iter_t *iter) {
	if (lista_iter_al_final(iter)) return NULL;
	return iter->actual->dato;
}

bool lista_iter_al_final(const lista_iter_t *iter) {
	return iter->actual == NULL;
}

void lista_iter_destruir(lista_iter_t *iter) {
	free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato) {
	nodo_t* nodo = crear_nodo(dato);
	if (nodo == NULL) return false;

	if (iter->anterior == NULL) iter->lista->primero = nodo;
	else iter->anterior->siguiente = nodo;
	
	if (iter->actual == NULL) iter->lista->ultimo = nodo;
	nodo->siguiente = iter->actual;
	iter->actual = nodo;
	iter->lista->tamanio++;
	return true;
}

void *lista_iter_borrar(lista_iter_t *iter) {
	if(iter->actual == NULL) return NULL;
	nodo_t* aux = iter->actual;
	iter->actual = iter->actual->siguiente;
	if (iter->anterior == NULL){
		iter->lista->primero = iter->actual;
		if (iter->actual == NULL) iter->lista->ultimo = NULL;
	}
	else{
		iter->anterior->siguiente = iter->actual;
		if (iter->actual == NULL) iter->lista->ultimo = iter->anterior;
	}
	iter->lista->tamanio--;
	void* dato = aux->dato;
	free(aux);
	return dato;
}

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){
	if (!visitar || lista_esta_vacia(lista)) return;
	nodo_t* actual = lista->primero;
	while (actual) {
		if (!visitar(actual->dato, extra)) break;
		actual = actual->siguiente;
	}
}
