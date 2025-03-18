#include <iostream>
#include <string> 
#include <fstream>
#include <stdexcept>

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
    default: return "0"; //se chequea antes que no entra
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


//B) 
void logmessage(string mensaje_de_error, string archivo, int linea ){
    ofstream outFile("archivo_de_texto.txt", ios::app);
    if(!outFile.is_open()){
        cerr << "No se pudo abrir el archivo para guardar el mensaje de error. " << endl; 
        return; 
    }
    outFile << "[ERROR] " << mensaje_de_error; 
    outFile << "En el archivo " << archivo; 
    outFile << "En la linea " << linea << endl ; 

    outFile.close();

}

void logmessage(string mensaje_de_acceso , string nombre_de_ususario){
    ofstream outFile("archivo_de_texto.txt", ios::app);
    if(!outFile.is_open()){
        cerr << "No se pudo abrir el archivo para guardar el mensaje de error. " << endl; 
        return; 
    }
    outFile << "[SECURITY] " << mensaje_de_acceso << endl;
    outFile << "por el usuario " << nombre_de_ususario << endl; 

    outFile.close();
}

int main(){
    try{
        cout << "Ingrese su mensaje: "; 
        string msj; 
        getline(cin, msj); 

        cout << " 1-DEBUG \n 2-INFO \n 3-WARNING \n 4-ERROR \n 5-CRITICAL\n";
        cout << endl << "Que opcion quiere utilizar: "; //EROR SI NO PASA UN NUMERO DEL 0-5  !!!NO ME SALTA ERROR
        int level;
        cin >> level; 

        if (cin.fail()){
            cin.clear();
            cin.ignore(9999, '\n');
            throw invalid_argument("parametro incorrecto");
        }

        cin.ignore();  

        severidad nivel = static_cast<severidad>(level); 

        logmessage(msj, nivel);

        cout<< "El mensaje se registro correctamente." << endl;

        string mensaje_de_error;
        string archivo;
        int linea;

        cout<< "ingrese su mensaje de error: ";
        getline(cin,mensaje_de_error);

        cout << "ingrese el archivo donde lo quiere guardar: "; 
        getline(cin,archivo);

        cout<< "ingrese la lina donde lo quiere guardar: ";  
        cin >> linea;

        logmessage (mensaje_de_error,archivo,linea); 

        string mensaje_de_acceso; 
        string nombre_de_usuario; 

        cout<< "Ingrese el mensaje de acceso: ";
        getline(cin,mensaje_de_acceso);

        cout<< "ingrese el nombre del usuario: ";
        getline(cin,nombre_de_usuario);

        logmessage (mensaje_de_acceso,nombre_de_usuario);
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        logmessage(e.what(), __FILE__, __LINE__);
    }

    return 0; 
}
