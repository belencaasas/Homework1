#include <iostream>
#include <string> 
#include <fstream>
#include <stdexcept>

using namespace std;

//A)

//defino una clase para enumerar los niveles de severidad
enum class severidad {DEBUG = 1 , INFO , WARNING , ERROR , CRITICAL, BELU , SECURITY};

string nivelseveridad (severidad nivel){
    switch (nivel)
    {
    case severidad::DEBUG: return "[DEBUG]";
    case severidad::INFO: return "[INFO]";
    case severidad::WARNING: return "[WARNING]";
    case severidad::ERROR: return "[ERROR]";
    case severidad::CRITICAL: return "[CRITICAL]";
    case severidad::BELU: return "[BELU]";
    case severidad::SECURITY: return "[SECURITY]";
    default: return "0"; //se chequea antes que no entra
    }
}

//funciom que guarda un mensaje en un archivo de texto con su nivel de severidad correspondiente
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

//es una funcion sobrecargada que guarda un mensaje de erro junto con el archivo y la linea que le pasa el usuario
void logmessage(string mensaje_de_error, string archivo, int linea ){
    ofstream outFile("archivo_de_texto.txt", ios::app);
    if(!outFile.is_open()){
        cerr << "No se pudo abrir el archivo para guardar el mensaje de error. " << endl; 
        return; 
    }
    outFile << "[ERROR] " << mensaje_de_error; 
    outFile << " en el archivo " << archivo; 
    outFile << " en la linea " << linea << endl ; 

    outFile.close();

}

//funcion sobrecargada que guarda un mensaje de acceso y el nombre del usuario
void logmessage(string mensaje_de_acceso , string nombre_de_ususario){
    ofstream outFile("archivo_de_texto.txt", ios::app);
    if(!outFile.is_open()){
        cerr << "No se pudo abrir el archivo para guardar el mensaje de error. " << endl; 
        return; 
    }
    outFile << "[SECURITY] " << mensaje_de_acceso ;
    outFile << ": por el usuario " << nombre_de_ususario << endl; 

    outFile.close();
}

int main(){
    try{
        cout << "Ingrese su mensaje: "; 
        string msj; 
        getline(cin, msj); 

        cout << " 1-DEBUG \n 2-INFO \n 3-WARNING \n 4-ERROR \n 5-CRITICAL\n 6-BELU\n 7-SECURITY\n";
        cout << endl << "Que opcion quiere utilizar: "; 
        int level;
        cin >> level; 

        if (cin.fail()){
            cin.clear();
            cin.ignore(9999, '\n');
            throw invalid_argument("El parametro es incorrecto ");
        }

        cin.ignore();  

        severidad nivel = static_cast<severidad>(level); 

        logmessage(msj, nivel);

        cout<< "El mensaje se registro correctamente." << endl;

        string mensaje_de_error;
        string archivo;
        int linea;

        if(level == 4){
            cout<< "ingrese su mensaje de error: ";
            getline(cin,mensaje_de_error);

            cout << "ingrese el archivo donde lo quiere guardar: "; 
            getline(cin,archivo);

            cout<< "ingrese la lina donde lo quiere guardar: ";  
            cin >> linea;

            logmessage (mensaje_de_error,archivo,linea); 
        }

        if(level == 7){
            string mensaje_de_acceso; 
            string nombre_de_usuario; 

            cout<< "Ingrese el mensaje de acceso: ";
            getline(cin,mensaje_de_acceso);
        
            cout<< "ingrese el nombre del usuario: ";
            getline(cin,nombre_de_usuario);

            logmessage (mensaje_de_acceso,nombre_de_usuario);
        }
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
        logmessage(e.what(), __FILE__ ,  __LINE__);
        return 1;
    }

    return 0; 
}
