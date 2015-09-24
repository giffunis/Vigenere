#include <iostream>
#include "vigenere.h"
#include <stdio.h>


int main(){
    setlocale(LC_ALL, "spanish");
	string key, message;
	string words = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //words.push_back((char) 165);
    //words << "OPQRSTUVWXYZ";
	Vigenere test(words);
	//-------------------------------------------
	int opt = 0;
    cout << "Bienvenidos a la encriptacion de Vigenere" << endl;
 	do{
 		key = "\0"; message = "\0";
    	cout << "Elija una opcion del menu: " << endl;
    	cout << "1) Cifrar" << endl;
    	cout << "2) Descifrar" << endl;
    	cout << "3) Salir" << endl;
    	cin >> opt;cin.ignore(256, '\n');// para limpiar el buffer

    	switch (opt){
        	case (1):
       			cout << "Key: ";
       			cin >> key;
    			cout << "Message: ";
                getchar();
    			getline(cin,message,'\n');
				cout<< " Encrypt message: " << test.encrypt(message, key) << endl;
				break;
        	case (2):
            	cout << "Key: ";
        		cin >> key;
    			cout << "Message: ";
                getchar();
                getline(cin,message,'\n');
				cout<< "Decipher message: " << test.decipher(message, key) << endl;
            	break;
        	case (3):
            	break;
        	default:
            	cout << "opcion incorrecta, vuelva a elegir" << endl;
            	break;
    	}
 	}while( opt != 3);
	return 0;
}