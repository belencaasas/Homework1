#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

/* En este ejercicio, se pide crear un sistema log que permite agregar entradas a un
archivo mediante el llamado a una función logMessage definida en pseudo código de
la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente
mencionadas. El formato esperado en una línea del archivo de log es el siguiente:

[ERROR] <Mensaje>
[INFO] <Mensaje>
etc.
Verifique su funcionamiento con al menos una entrada de cada tipo.*/

enum class severidad {DEBUG = 1 , INFO , WARNING , ERROS , CRITICAL};

void logmessage(string mensaje, int NivelSeveridad){
    int NivelSeveridad = 5;
    switch (NivelSeveridad)
    {
    case 1: 
    
       
    }


}

void creararchivo(){
    ofstream outFile("archivo_de_texto.txt", ios::app);

    if(!outFile.is_open()){
        cerr << "No se pudo crear el archivo de salida." << endl;
        return 1;

    }
}

int main(){
    cout << "Ingrese su mensaje: "; 
    string msj;
    cin.ignore();
    getline(cin, msj);
    cout << " 1-DEBUG \n 2-INFO \n 3-WARNING \n 4-ERROR \n 5-CRITICAL\n";
    cout << endl << "Que opcion quiere utilizar: ";
    int level;
    cin >> level; 

    logmessage(msj, level)
}