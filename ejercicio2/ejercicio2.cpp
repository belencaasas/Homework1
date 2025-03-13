#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

//A)

enum class severidad {DEBUG = 1 , INFO , WARNING , ERROR , CRITICAL};

string nivelseveridad (severidad nivel){
    switch (nivel)
    {
    case severidad::DEBUG: return "[DEBUG]";
    case severidad::INFO: return "[INFO]";
    case severidad::WARNING: return "[WARNING]";
    case severidad::ERROR: return "[ERROR]";
    case severidad::CRITICAL: return "[CRITICAL]";
    default: return "[UNKNOWN]";
      
    }
}

void logmessage(string mensaje, severidad nivel){
    ofstream outFile("archivo_de_texto.txt" , ios::app); 
    if(!outFile.is_open()){
        cerr << "No se pudo abrir el archivo pra escribir." << endl;
        return;
    }
    outFile << nivelseveridad(nivel) << "<"<< mensaje << ">" << endl;  
    outFile.close(); 
}

int main(){
    cout << "Ingrese su mensaje: "; 
    string msj; 
    getline(cin, msj); 

    cout << " 1-DEBUG \n 2-INFO \n 3-WARNING \n 4-ERROR \n 5-CRITICAL\n";
    cout << endl << "Que opcion quiere utilizar: ";
    int level;
    cin >> level; 

    cin.ignore();  

    severidad nivel = static_cast<severidad>(level); 

    logmessage(msj, nivel);

    cout<< "El mensaje se registro correctamente." << endl;
    return 0; 
}