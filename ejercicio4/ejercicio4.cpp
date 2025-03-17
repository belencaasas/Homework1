#include <iostream>
#include <string> 
#include <chrono>
using namespace std;

//A) 
//voy a usar strings dsp explico el porque  - FALTA ESTO 
//PREGUNTA --> TEMA MAYUSCULAS , LO TENGO QUE MANEJAR? 
//TEMA MAIN? 

/*bool comparaCadenas(string& str1 , string& str2, size_t contador =0 ) { //el &  las cadenas no se modifican dentro de la funcion y no se realizaz una copia = mejora la eficiencia
    if(contador == str1.length() && contador == str2.length()) {//si llegas al final de la cadena termina
        return true; 
    }
    if (contador >= str1.length() || contador >= str2.length() || str1[contador] != str2[contador]){
        return false; 
    }
    return comparaCadenas(str1 , str2, contador +1);
}*/

/*int main(){
    string cadena1,cadena2;
    cout << "Ingrese la primera cadena: ";
    getline(cin,cadena1); //getline lee toda una linea de texto

    cout<< "Ingrese la segunda cadena: ";
    getline(cin,cadena2);

    bool resultado= comparaCadenas(cadena1,cadena2);
    if(!resultado){
        cout<< "Las cadenas son diferentes. " << endl; 
    }
    else{ 
        cout << "Las cadenas son iguales. "<< endl;
    }
    return 0; 

}*/



//B) 
/*bool comparaCadenas(string& str1 , string& str2, size_t contador =0 ) { //el &  las cadenas no se modifican dentro de la funcion y no se realizaz una copia = mejora la eficiencia
    if(contador == str1.length() && contador == str2.length()) {//si llegas al final de la cadena termina
        return true; 
    }
    if (contador >= str1.length() || contador >= str2.length() || str1[contador] != str2[contador]){
        return false; 
    }
    return comparaCadenas(str1 , str2, contador +1);
}

int main(){
    string cadena1,cadena2;
    cout << "Ingrese la primera cadena: ";
    getline(cin,cadena1); //getline lee toda una linea de texto

    cout<< "Ingrese la segunda cadena: ";
    getline(cin,cadena2);

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
    cout << "A compararCadenas le tomo: " << elapsedTime.count() << " nanosegundos. " << endl;
    return 0; 

} */

//C) 
//???? 
//PREGUNTAR 
