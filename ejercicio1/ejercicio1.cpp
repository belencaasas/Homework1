#include <iostream>
using namespace std; 
#include <memory>


//A) 

int** matrizcuadrada(int n){ // funcion para crear una matriz cuadrada de nxn 
    int** matriz = new int*[n]; //uso punteros de tipo int para crearla 
    for (int i=0 ; i<n ; i++){
        matriz[i] = new int[n];
    }
    //la matriz inicia con el valor 1 y siguen incrementando de a 1 para la siguiente posicion
    int valorinicial = 1; 

    for (int i=0 ; i < n ; i++){
        for(int j =0; j<n ; j++){
            matriz[i][j] = valorinicial++;
        }
    }
    return matriz; 

}
//funcion para imprimir el contenido de una matriz cuadrada
void imprimematriz(int** matriz, int n){
    for (int i=0 ; i < n ; i++){
        for(int j =0; j<n ; j++){
            cout << matriz[i][j] << " "; 
        }                                
        cout << endl; 
    }
    
}

//funcion que libera la memoria ocupada por la matriz
void librerarmatriz(int** matriz, int n){
    for (int i=0 ; i<n ; i++){
        delete[] matriz[i]; 
    }
    delete[] matriz; 
}

//B) 
void imprimecontenido(int** matriz , int n){ //funcion que imprime cada numero de la matriz con su respectivo indice de fila y columna
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
    cin >> n;  
    
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
//hola