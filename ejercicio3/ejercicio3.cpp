#include <iostream>
using namespace std; 
#include <memory>

/*. 

iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa
    una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de
    agregar el nodo al final de la lista.
v. erase(): borra un nodo en la posición que se le pase a la función. Similar a la
    función insert(), si la posición es mayor que el largo de la lista, se debe de borrar
    el último nodo.
vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”.
    Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y,
    muy importante para el ejercicio, sólo utilizar smart pointers.*/

struct Node{
    int value;
    unique_ptr<Node> next; //puntero al sig nodo
}; 
    
struct listaenlazada {
    unique_ptr<Node> head;
};
    
unique_ptr<Node> crear_nodo(int value){
    auto new_node = make_unique<Node>(); //make genera los punteros 
    new_node->value = value; 
    new_node->next = nullptr; 
    return new_node;
} 
    
void push_front(int value, listaenlazada& lista){ //& para q no me pase una copia 
    auto new_node = crear_nodo(value);
    new_node->next = move(lista.head);
    lista.head = move(new_node);
}
    
void push_back(int value, listaenlazada& lista){
    auto new_node = crear_nodo(value); 
    if (!lista.head) { //si la listabesta vacia la cabeza es el nuevo nodo
        lista.head = move(new_node);    
    } 
    
}

