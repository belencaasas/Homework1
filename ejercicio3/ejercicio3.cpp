#include <iostream>
using namespace std; 
#include <memory>


struct Node{
    int value;
    unique_ptr<Node> next; 
}; 
    
struct listaenlazada {
    unique_ptr<Node> head;
};

//funcion que crea un nuevo nodo con un valor dado
unique_ptr<Node> crear_nodo(int value){
    auto new_node = make_unique<Node>();  
    new_node->value = value; 
    new_node->next = nullptr; 
    return new_node;
} 

//funcion que agrega un nodo al principio de la lista con un valor dado
void push_front(int value, listaenlazada& lista){ 
    auto new_node = crear_nodo(value);
    new_node->next = move(lista.head);
    lista.head = move(new_node);
}

//funcion que agrega un nodo al final de la lista con un valor dado 
void push_back(int value, listaenlazada& lista){
    auto new_node = crear_nodo(value);  
    if (!lista.head) {  
        lista.head = move(new_node);    
    } 
    else{
        Node* current = lista.head.get(); 
        while (current->next){
            current = current->next.get();
        }
        current->next = move(new_node);
    }
} 

//funcion que inserta un nodo en una posicion especifica con un valor dado
void insert(listaenlazada& lista, int posicion, int value){
    auto new_node = crear_nodo(value);

    if (posicion == 0){
        new_node->next = move(lista.head);
        lista.head = move(new_node);
        return;
    }
    Node* current = lista.head.get(); 
    int contador = 0;  

    while (current && contador < posicion - 1){ 
        current = current->next.get();
        contador++; 
    }
    if(!current){
        cout << "La posicion ingresada esta fuera del rango, se insertara al final" << endl;
        push_back(value,lista);    
    } else { 
        new_node->next = move(current->next); 
        current->next = move(new_node); 
    }
}

//funcion que elimina un nodo en una posicion especifica con un valor dado
void erase(listaenlazada& lista , int posicion){
    if (!lista.head)return; 
    if (posicion == 0 ){
        lista.head = move(lista.head->next);  
        return;
    }
    Node* current = lista.head.get(); 
    int contador = 0; 

    while (current && contador < posicion - 1){
        current = current->next.get();
        contador++;

    if(!current->next){
        cout << "La posicion ingresada esta fuera del rango, se borrara el ultimo nodo" << endl;
        Node* temporal = lista.head.get();
        while(temporal->next && temporal->next->next){ 
            temporal = temporal->next.get();
        }
        temporal->next.reset(); 
    }else{
        current->next = move(current->next->next);
    }
}
}

//funcion que imprime todos los elementos de la lista 
void print_list (const listaenlazada& lista){ 
    Node* current = lista.head.get();
    while (current){ 
        cout << current->value;
        if (current->next){ 
            cout << "->";
            
        }
        current = current->next.get();
    }
    cout << endl; 
} 


int main(){
    listaenlazada lista; 

    push_front (1,lista);
    push_front (2,lista);

    print_list(lista);

    push_back(3,lista);
    push_back(4,lista);

    print_list(lista);

    insert(lista,2,15);

    print_list(lista);

    erase(lista,0);

    print_list(lista);

    return 0 ;


}