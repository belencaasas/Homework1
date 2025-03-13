#include <iostream>
using namespace std; 
#include <memory>


//A) 

int** matrizcuadrada(int n){ 
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
    // cout << "M" << n << "=" << endl << "["; 
    for (int i=0 ; i < n ; i++){
        for(int j =0; j<n ; j++){
            cout << matriz[i][j] << " "; 
        }                                
        cout << endl; 
    }
    // cout << "]" << endl;
}

void librerarmatriz(int** matriz, int n){
    for (int i=0 ; i<n ; i++){
        delete[] matriz[i]; 
    }
    delete[] matriz; 
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
    cin >> n;  
    
    if (n>1){
        int** matriz = matrizcuadrada(n);
        
        //imprimematriz(matriz,n);

        cout << "\nEl contenido de la matriz: \n";
        imprimecontenido(matriz,n);

        librerarmatriz(matriz,n);

    }else{
        cout<<"El valor de n debe ser mayor a 1." << endl;
    }
    return 0;
}