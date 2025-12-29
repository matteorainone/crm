#pragma once
#include "Interazione.h"
#include <string>
#include <vector>

class GestioneInterazioni{
    private:
        int next_id;
        std::string interactions_file_path;
        std::vector<Interazione> interazioni;

        void caricaDaFile();
        void salvaSuFile() const;
        

    public:
        GestioneInterazioni();

        Interazione* ricercaInterazione(const int& id_interazione);
        std::vector<Interazione*> ricercaInterazioneCF(const std::string& cod_fiscale);

        std::vector<Interazione*> getInterazioni();

        void aggiungiInterazione(const std::string& cod_fiscale, 
                        const std::string& appuntamento, 
                        const std::string& contratto,
                        const std::string& note);

        void visualizzaInterazioniCliente(const std::string& cod_fiscale);
        
        void visualizzaTutte() const;

        void rimuoviInterazioniCliente(const std::string& cod_fiscale);

};