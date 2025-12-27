#include "Validator.h"
#include <regex>
#include <string>
#include <iostream>

Validator::Validator()
    :   patternNome("^[A-Za-z ]+$"),
        patternCdf("^[A-Z]{6}[0-9]{2}[A-EHLMPR-T]{1}[0-9]{2}[A-Z]{1}[0-9]{3}[A-Z]{1}$"),
        patternEmail("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+(\\.[a-zA-Z0-9-]+)*\\.[a-zA-Z]{2,}$"),
        patternNum("^[+-]?\\d+(\\.\\d+)?$")
        {}

std::string Validator::validaStringhe(const std::regex& pattern){
    
    bool check = false;
    std::string valid_str;

    while (!check){
        std::cout << "Inserire valore: " << std::endl;
        std::getline(std::cin, valid_str);

        if (std::regex_match(valid_str, pattern)){
            std::cout << "Valore inserito valido" << std::endl;
            check = true;
        } else{
            std::cout << "Inserire un valore valido." << std::endl;
            std::cout << "Per Nome e Cognome: non sono ammessi numeri e caratteri speciali." << std::endl;
            std::cout << "Per il Codice Fiscale:\n1) Lunghezza 16 caratteri;\n2) Prime 6 lettere per nome e cognome;\n3) 2 cifre per anno di nascita;\n4) 1 lettera per il mese;\n5) 2 cifre per il giorno;\n6) 4 caratteri per codice comune;\n7) 1 carattere per il codice di controllo" << std::endl;
            std::cout << "Per l'email usare formato: username@dominio.aa";
        }
    }
    return valid_str;
}


std::string Validator::validaNomeCognome(){
    std::string valid_str = validaStringhe(patternNome);
    return valid_str;
}

std::string Validator::validaCDF(){
    std::string valid_str = validaStringhe(patternCdf);
    return valid_str;
}

std::string Validator::validaEmail(){
    std::string valid_str = validaStringhe(patternEmail);
    return valid_str;
}

std::string Validator::validazioneAppContr(){
    std::string valid_str;
    std::cout << "Per Appuntamento e Contratto: sono ammessi solo SI o NO." << std::endl;
    
    return valid_str = validazioneSiNo();
}

std::string Validator::validazioneSiNo(){
     bool check = false;
    std::string valid_str;
    
    while (!check){
        std::cout << "Inserire valore (SI/NO): " << std::endl;
        std::getline(std::cin, valid_str);

        std::transform(valid_str.begin(), valid_str.end(), valid_str.begin(), ::toupper);

        if ((valid_str == "SI") || (valid_str == "NO")){
            std::cout << "Valore inserito valido" << std::endl;
            check = true;
        } else{
            std::cout << "Inserire un valore valido." << std::endl;
        }
    }
    return valid_str;
}

int Validator::validazioneSelezioneNum(){
    
    std::string valid_str = validaStringhe(patternNum);
    int num = std::stoi(valid_str);

    return num; 
}