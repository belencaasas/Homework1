#include <iostream>
#include <string> 
#include <chrono>
using namespace std;

//A) 
/*Utilice el tipo de dato string ya que facilita el proceso porque tiene muchos metodos internos, tambien maneja automaticamente la memoria 
necesaria para almacenar el texto*/ 

bool comparaCadenas(string& str1 , string& str2, size_t contador =0 ) {  //funcion que compara dos cadenas de texto de manera recursiva
    if(contador == str1.length() && contador == str2.length()) {
        return true; 
    }
    if (contador >= str1.length() || contador >= str2.length() || str1[contador] != str2[contador]){
        return false; 
    }
    return comparaCadenas(str1 , str2, contador +1);
}


//C) 
//funcion que recibe como parametro dos cadenas constantes que compara ambas en tiempo de compilacion usando constexpr
constexpr bool compararCadenasConste(const char* str1, const char* str2, size_t contador =0){ 
    if (str1[contador] == '\0' && str2[contador] == '\0'){
        return true; 
    }
    if(str1[contador] != str2[contador]){
        return false; 
    }
    return compararCadenasConste(str1,str2,contador +1);
}



int main(){
    string cadena1 = "Hoy es miercoles y quedan treinta dias para mi cumple.";
    string cadena2 = "Hoy es miercoles y quedan treinta dias para mi cumple.";

    //mide el tiempo que toma ejecutar la comparacion en tiempo de ejecucion
    auto startTime = chrono::high_resolution_clock:: now(); //tiempo de incio
    bool resultado= comparaCadenas(cadena1,cadena2);
    auto endTime = chrono::high_resolution_clock::now(); //finalizacion
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    if(!resultado){
        cout<< "Las cadenas son diferentes. " << endl; 
    }
    else{ 
        cout << "Las cadenas son iguales. "<< endl;
    }
    cout << "A la funcion compararCadenas le tomo " << elapsedTime.count() << " nanosegundos. \n" ;

    constexpr const char cadenaCons1[] = "Hoy es miercoles y quedan treinta dias para mi cumple.";
    constexpr const char cadenaCons2[] = "Hoy es miercoles y quedan treinta dias para mi cumple.";

    //mide el tiempo que toma ejecutar la comparacion en tiempo de compilacion
    auto startTimeCons = chrono::high_resolution_clock:: now(); 
    constexpr bool resultadoCons = compararCadenasConste(cadenaCons1,cadenaCons2);
    auto endTimeCons = chrono::high_resolution_clock::now();
    auto elapsedTimeCons = chrono::duration_cast<chrono::nanoseconds>(endTimeCons - startTimeCons);

    if(resultadoCons){
        cout << "Las cadenas en timepo de complilacion son iguales." << endl;
    }
    else{
        cout << "Las cadenas en tiempo de compliacion son diferentes." << endl; 
    }
    cout << "A la funcion compararCadenasConste en tiempo de compilacion tardo " << elapsedTimeCons.count() << " nanosegundos." << endl; 
    return 0; 
} 



