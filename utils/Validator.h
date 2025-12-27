#pragma once

#include <string>
#include <regex>

class Validator {
    private:
        std::regex patternNome;
        std::regex patternCdf;
        std::regex patternEmail;
        std::regex patternNum;
        //validazione stringhe in input 
        std::string validaStringhe(const std::regex& pattern);
    public:
        Validator();

        std::string validaNomeCognome();

        std::string validaCDF();

        std::string validaEmail();
        
        std::string validazioneAppContr();

        std::string validazioneSiNo();

        int validazioneSelezioneNum();

};