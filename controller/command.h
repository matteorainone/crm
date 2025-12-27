#pragma once

#include "../utils/Validator.h"
#include "../model/clienti/GestioneClienti.h"
#include "../model/interazioni/GestioneInterazioni.h"

#include <string>
#include <unordered_map>
#include <map>

class GestoreComandi {
    private:
        std::unordered_map<int, std::string> lista_comandi;
        std::unordered_map<int, std::string> opzioni_modifica;
        Validator validator;
        GestioneClienti client_manager;
        GestioneInterazioni interaction_manager;
        
    public:

        GestoreComandi();

        void stampaComandi();

        void aggiungiCliente();

        void visualizzaClienti();

        void modificaCliente();

        void eliminaCliente();

        std::vector<Cliente*> ricercaCliente();

        void aggiungiInterazione();

        void visualizzaInterazioni();

        void visualizzaInterazioni(const std::vector<Interazione*> interazioniTarget);

        std::vector<Interazione*> ricercaInterazione();

        bool selettoreComandi(const int& num_comando);


};