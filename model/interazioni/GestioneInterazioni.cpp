#include "GestioneInterazioni.h"
#include "model/interazioni/Interazione.h"
#include "utils/utils.h"
#include <string>
#include <vector>


void GestioneInterazioni::caricaDaFile(){
    std::vector<std::string> righe_file;
    //scompatto il file di base dati in un insieme di righe
    righe_file = readCSVLines(interactions_file_path);
    int max_id = 0;

    for (size_t i = 0; i < righe_file.size(); i++){
        //da ciascuna riga genero un cliente che andrà a riempire l'insieme delle interazioni tra clienti gestite dall'applicazione
        interazioni.push_back(Interazione::fromCSVLine(righe_file[i]));
        if (interazioni[i].getIdInterazione() > max_id){
            max_id = interazioni[i].getIdInterazione();
        }
    }
    next_id = max_id + 1;
}

void GestioneInterazioni::salvaSuFile() const{
    std::vector<std::string> righe_interazioni;

    for (size_t i = 0; i < interazioni.size(); i++){
        //genero una lista di stringhe, formattate in csv, partendo dalle interazioni gestite
        righe_interazioni.push_back(interazioni[i].toCsv());
    }

    //partendo dalla lista di righe, salvo su file csv
    writeCSVAtomically(interactions_file_path, righe_interazioni);
}

Interazione* GestioneInterazioni::ricercaInterazione(const int& id_interazione){
    
    for (auto& interazione : interazioni){
        if (interazione.getIdInterazione() == id_interazione){
            return &interazione;
        }
    }

    return nullptr;
}

std::vector<Interazione*> GestioneInterazioni::ricercaInterazioneCF(const std::string& cod_fiscale){
    std::vector<Interazione*> interazioni_target;

    for (auto& interazione : interazioni){
        if (interazione.getCodFiscale() == cod_fiscale){
            interazioni_target.push_back(&interazione);
        }
    }

    return interazioni_target;
}


//costruttore di default
GestioneInterazioni::GestioneInterazioni(){
    next_id = 0;
    interactions_file_path = "path/to/interazioni.csv";
    caricaDaFile();
}

std::vector<Interazione*> GestioneInterazioni::getInterazioni(){
    std::vector<Interazione*> puntatori_interazioni;

    for (auto& interazione : interazioni){
        puntatori_interazioni.push_back(&interazione);
    }
    return puntatori_interazioni;
}


void GestioneInterazioni::aggiungiInterazione(const std::string& cod_fiscale, const std::string& appuntamento, const std::string& contratto, const std::string& note){
    
    Interazione nuova_interazione;
    
    nuova_interazione = Interazione(next_id, cod_fiscale, appuntamento, contratto, note);
    interazioni.push_back(nuova_interazione);
    next_id ++;
    salvaSuFile();
    
}

void GestioneInterazioni::visualizzaInterazioniCliente(const std::string& cod_fiscale){
    
    for (auto& interazione : ricercaInterazioneCF(cod_fiscale)){
        interazione -> showInteraction();
    }
}

void GestioneInterazioni::visualizzaTutte() const{

    for (auto& interazione : interazioni){
        interazione.showInteraction();
    }
}