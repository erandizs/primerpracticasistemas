#include <stdio.h>
#include <stdlib.h>
//ZAVALA SERRANO DAMARIS ERANDI. GRUPO 402
//PARA ACEPTAR ARBOL CON NUMEROS DEL 6 AL 17
struct Nodo { //para crear el nodo o la hoja
    int dato;
    struct Nodo *izquierda; //la estructura tiene punteros del mismo tipo
    struct Nodo *derecha;
};
struct Nodo* encontrar(struct Nodo *tree,int valor){
    if(tree== NULL || tree->dato == valor){
        return tree;
    }
    if(valor < tree->dato){
        encontrar(tree->izquierda,valor);
    } else{
        encontrar(tree->derecha,valor);
    }
}

/*void mensaje(){


  //   struct Nodo *raiz;

     printf("\nInserte dato\n");
      scanf("%d",&dato);
     if(cont!=0){
        goto aqui; //para que se brinque las siguientes dos lineas si ya se ejecuto por primera vez
     }
    struct Nodo *raiz = nuevoNodo(dato);
    cont=1;
    aqui:
    insertar(raiz, dato);
     printf("\nQuiere agregar otra dato? 0:No 1:Si\n");
       scanf("%d",&resp);
     if(resp==1){
        mensaje();
     }else{
        printf("\nPreorden\n");
        preorden(raiz);
        printf("\nInorden\n");
        inorden(raiz);
        printf("\nPostorden\n");
        postorden(raiz);
     }
}
void impresiones(int raiz){
        printf("\nPreorden\n");
        preorden(raiz);
        printf("\nInorden\n");
        inorden(raiz);
        printf("\nPostorden\n");
        postorden(raiz);
}*/

struct Nodo *nuevoNodo(int dato) {//recibe en puntero
    // Solicita memoria
    size_t tamanioNodo = sizeof(struct Nodo); //size es para darle elmaximo valor posible. size_if para ver el tamaño
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);//declara segun la estructuram malloc aparta memoria y regresa el apuntador
    // Asigna el dato e inicia hojas
    nodo->dato = dato; //se le da valor a la variable dato de la estructura nodo
    nodo->izquierda = nodo->derecha = NULL;//para iniciarlos. es null para que haya espacio
    return nodo;
}

int validacion(struct Nodo *nodo, int minimo, int maximo){
	if(nodo == NULL){
		return 1;
	}
	if(nodo->dato<minimo || nodo->dato>maximo){
		return 0;
	}
	return validacion(nodo->izquierda, minimo, nodo->dato - 1) && validacion(nodo->derecha, nodo->dato + 1, maximo);
}

void validarllamar(struct Nodo *raiz) {
    if (validacion(raiz, 6, 17) == 1) { //acepta en el rango 6-17, se cambia depende el arbol
        printf("El arbol esta correcto.\n");
    } else {
        printf("El arbol no esta correcto.\n");
    }
}


void insertar(struct Nodo *nodo, int dato) {
  //aqui se ve hacia donde se va a insertar

    if (dato > nodo->dato) {//mayor va a la derecha

        if (nodo->derecha == NULL) {//si no hay dato a la derecha
            nodo->derecha = nuevoNodo(dato);//se le agrega el dato
        } else {
//AQUI SE USA LA RECURSIVIDAD
            insertar(nodo->derecha, dato);//si estaba ocupada la derecha, se inserta otro nodo. se le manda el valor del nodo de la derecha y el dato que es para comparar
        }
    } else {
        // si es menor se va a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
//RECURSIVIDAD
            // si tiene dato vuelve a ejecutar la funcion
            insertar(nodo->izquierda, dato);
        }
    }
}


void preorden(struct Nodo *nodo) {
    //raiz, todas las izquierdas y al final derechas
    if (nodo != NULL) { //si el nodo tiene dato
        printf("%d,", nodo->dato);//se imprime
        //y va mostrando los datos
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(struct Nodo *nodo) {
    //izquierda, raiz, derecha
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d,", nodo->dato); //%d es para variable entera
        inorden(nodo->derecha);
    }
}

void postorden(struct Nodo *nodo) {
    //izquierda,derecha,raiz
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}

int main(void) {
 int dato,resp,cont,resp2;
 char lado;
  // mensaje();
iniciar:
     printf("\nInserte dato\n");
      scanf("%d",&dato);
     if(cont==0){
            goto prim;


       // goto aqui; //para que se brinque las siguientes dos lineas si ya se ejecuto por primera vez
     }else{
       goto second;
     }
    prim:
    cont=1;
    struct Nodo *raiz = nuevoNodo(dato);
    goto third;
    second:
    insertar(raiz, dato);
  //  aqui:
    third:
     printf("\nQuiere agregar otra dato? 0:No 1:Si\n");
       scanf("%d",&resp);
     if(resp==1){
       // mensaje();
       goto iniciar;
     }else{
        validarllamar(raiz);
        printf("\nPreorden\n");
        preorden(raiz);
        printf("\nInorden\n");
        inorden(raiz);
        printf("\nPostorden\n");
        postorden(raiz);
     }

    struct Nodo* var_busq=NULL;

   printf("\nQuiere buscar dato? 1:Si 2:No\n");
    scanf("%d",&resp2);
       if(resp2==1){
        int dato_buscar;
        printf("\nIngrese el dato a buscar\n");
       scanf("%d",&dato_buscar);
       var_busq=encontrar(raiz,dato_buscar);
        if(var_busq!=NULL){
            printf("Dir.Memoria:=%p, Valor=%d, Izq=%d, Der=%d\n",(void*)var_busq,var_busq->dato,
                    (var_busq->izquierda != NULL) ? var_busq->izquierda->dato : -1,
                    (var_busq->derecha != NULL) ? var_busq->derecha->dato : -1);//hay operador terciario
      }
      }
    return 0;
}
