#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int variable = arr[0] ; //crear una variable que va cambiando si encuentra un numero mayor al actual
  for (int i =0 ; i<size ; i++){
    if (variable <= arr[i]){
      variable = arr[i];
    }
  }
  
  return variable; }

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int reverse[size];
  int j=0;
  for (int i=size-1 ; i>=0; i--){//recorrer el arreglo al revez
    reverse[j]=arr[i];
    j++;
  }
  memcpy(arr, reverse, sizeof(int)*size);
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  int *newArray =(int*)malloc(size*sizeof(int));
  if (newArray == NULL ){
    *newSize=0;
    return NULL;
  }
  int cont=0;
  for (int i=0; i<size;i++){
    if (arr[i]%2==0){
      //Espar
      newArray[cont]=arr[i];
      cont++;
    }
  }
  *newSize=cont;
  return newArray;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
  int n= size1+size2;
  int newArray[n];
  for(int i =0; i<size1 ;i++){
    newArray[i]=arr1[i];
  }

  for (int i=size1; i<n; i++){
    newArray[i]=arr2[i-size1];
  }

  //ordenar vector 3
  int aux;
  for (int i =0; i<n; i++){
    for (int j=0; i<n-1; j++){
      if (newArray[j]<newArray[j+1]){
        aux=newArray[j];
        newArray[j]=newArray[j+1];
        newArray[j+1]=aux;
      }
    }
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 
  int ascend= 1, descend=1;
  for (int i=0; i<size; i++){
    if (arr[i]>arr[i+1]){
      ascend=0;
    }
    if (arr[i]<arr[i+1]){
      descend=0;
    }
  }

  if(ascend){
    return 1;
  }
  else if (descend){
    return -1;
  }
  else{
    return 0;
  }
  
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion){
  strcpy(libro->titulo, titulo);
  strcpy(libro->anioPublicacion, anioPublicacion);
  
  libro->autor.anioNacimiento = anioNacimiento;
  libro->autor.nombre = nombreAutor;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  Nodo *primerNodo;
  Nodo *nodoActual;

  for(int i =0; i<size ; i++){
    Nodo * nuevoNodo = (Nodo * )malloc(sizeof(Nodo));
    if(nuevoNodo==NULL){
      printf("Error en asignacion de memoria.");
      exit(EXIT_FAILURE);
    }

    nuevoNodo->numero = arr[i];
    nuevoNodo->siguiente = NULL;

    if (primerNodo == NULL){
      primerNodo=nuevoNodo;
      nodoActual= primerNodo;
    }else{
      nodoActual->siguiente =nuevoNodo;
      nodoActual =nuevoNodo;
      
    }
  }
  
  return NULL; }
