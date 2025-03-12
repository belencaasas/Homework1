#include <iostream>
using namespace std; 
#include <memory>


//EJERCICIO 1 
/* a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva
      una matriz cuadrada con valores como en los siguientes ejemplos para n=2 y n=3:
      𝑀2 = [1 2
            3 4] 
      𝑀3 = [1 2 3
            4 5 6
            7 8 9]

   b. Proveer un código que imprima el contenido de la matriz, utilizando un único ciclo
      for, desde el mayor valor al menor, es decir, para el ejemplo de Para 𝑀2:
        𝑀2 [1][1] = 4
        𝑀2 [1][0] = 3
        𝑀2 [0][1] = 2
        𝑀2 [0][0] = 1
    Nota: recuerde que se deben imprimir los índices de la matriz. */


//A) 

int** matrizcuadrada(int n){ //los punteros son necesarios para gestionar la memoria que se asigna --> puntero q apunta a una dire de memoria donde se almacenan enteros
    int** matriz = new int*[n];
    for (int i=0 ; i<n ; i++){
        matriz[i] = new int[n];
    }

    int valorinicial = 1; 

    for (int i=0 ; i < n ; i++){
        for(int j =0; j<n ; j++){
            matriz[i][j] = valorinicial++;
        }
    }
    return matriz; 

}

void imprimematriz(int** matriz, int n){
    cout << "M" << n << "= ["; 
    for (int i=0 ; i < n ; i++){
        for(int j =0; j<n ; j++){
            cout << matriz[i][j] << " "; //imprime el valor de cada celda
        }                                //las comillas van para inicializar una cadena q no se tiene un valor especifico
        cout << endl; //hace un salto de linea dsp de imprimir cada fila
    }
    cout << "]" << endl;
}

void librerarmatriz(int** matriz, int n){
    for (int i=0 ; i<n ; i++){
        delete[] matriz[i]; //libera cada fila
    }
    delete[] matriz; //libera el arreglo de filas
}

//B) 
void imprimecontenido(int** matriz , int n){
    int totalelem = n*n;
    for (int i= totalelem-1 ; i >= 0 ; i--){
        int fila = i/n; 
        int columna = i%n;

        cout << "M" << n << "[" << fila << "][" << columna << "] = " << matriz[fila][columna] << endl; 
    }


}


int main(){
    int n; 
    cout << "Introduce el valor del tamano de la matriz cuadrada: ";
    cin >> n;  //para la entrada del usuario se usa cin 
    
    if (n>1){
        int** matriz = matrizcuadrada(n);
        
        imprimematriz(matriz,n);

        cout << "\nEl contenido de la matriz: \n";
        imprimecontenido(matriz,n);

        librerarmatriz(matriz,n);

    }else{
        cout<<"El valor de n debe ser mayor a 1." << endl;
    }
    return 0;
}