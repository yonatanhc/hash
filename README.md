<h1> Tabla de Hash </h1>
tipo abstracto de datos Tabla de Hash

<h5>Primitivas del hash</h5>

typedef struct hash hash_t;<br>
typedef struct hash_iter hash_iter_t;<br>
typedef void (*hash_destruir_dato_t)(void *);<br>
hash_t *hash_crear(hash_destruir_dato_t destruir_dato);<br>
bool hash_guardar(hash_t *hash, const char *clave, void *dato);<br>
void *hash_borrar(hash_t *hash, const char *clave);<br>
void *hash_obtener(const hash_t *hash, const char *clave);<br>
bool hash_pertenece(const hash_t *hash, const char *clave);<br>
size_t hash_cantidad(const hash_t *hash);<br>
void hash_destruir(hash_t *hash);

<h5>Primitivas del iterador</h5>

hash_iter_t *hash_iter_crear(const hash_t *hash);<br>
bool hash_iter_avanzar(hash_iter_t *iter);<br>
const char *hash_iter_ver_actual(const hash_iter_t *iter);<br>
bool hash_iter_al_final(const hash_iter_t *iter);<br>
void hash_iter_destruir(hash_iter_t* iter);<br>

El iterador permite recorrer todos los elementos almacenados en el hash, sin importar el orden en el que son devueltos.

Se adjunta, además, un archivo de pruebas que se utilizan para verificar que la estructura funciona correctamente. 
El corrector automático, igualmente, añade más pruebas. 
