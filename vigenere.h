#include <iostream>
#include <string>

using namespace std;

class Vigenere{
private:
	string words_;
public:
	Vigenere(string words);
	string encrypt(string message, string key);
	string decipher (string encrypted, string key);
	void change (string words);
};

Vigenere::Vigenere(string words):
	words_(words){    setlocale(LC_ALL, "spanish");
};

string Vigenere::encrypt(string message, string key){
	string cadena = "\0"; 
    int cont = 0, pos = 0, move = 0, long_words = 0, long_key = 0, long_message = 0;
    int pos1 =0, pos2 = 0;
    long_key = key.length();
    long_message = message.length();
    long_words = words_.length();
    //cout << long_message<< endl;
    for(int i = 0; i < long_message; i++){
        if( ((int)message[i]) != 32){
        	pos1 = (int)words_.find(message[i]);
        	pos2 = (int)words_.find(key[cont%long_key]);
            pos = (pos1 + pos2)%long_words;
            if(pos > long_words)
            	move = pos - long_key;
            else
            	move = pos;
            cadena.push_back(words_[move]);
            cont++;
        }
        /*else{
            cadena.push_back((char) 32);
        }*/
    }
    return cadena;
}


string Vigenere::decipher(string message, string key){
    string cadena = "\0"; 
    int cont = 0, pos = 0, move = 0, long_words = 0, long_key = 0, long_message = 0;
    int pos1 =0, pos2 = 0;
    long_key = key.length();
    long_message = message.length();
    long_words = words_.length();
   // cout << long_message<< endl;
    for(int i = 0; i < long_message; i++){
        if( ((int)message[i]) != 32){
            pos1 = (int)words_.find(message[i]);
            pos2 = (int)words_.find(key[cont%long_key]);
            pos = (pos1 - pos2)%long_words;
            if(pos < 0)
                move = long_words + pos;
            else
                move = pos;
            cadena.push_back(words_[move]);
            cont++;
        }
        else{
            cadena.push_back((char) 32);
        }
    }
    return cadena;
}

