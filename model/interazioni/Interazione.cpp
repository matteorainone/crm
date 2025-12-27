#include "Interazione.h"
#include "utils/utils.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <charconv>

// costruttore di default
Interazione::Interazione() {
    id_interazione = 0;
    cod_fiscale = "AAABBB00A11C123Z";
    appuntamento = "Si";
    contratto = "No";
    note = "fissato in data 01/01/2000. Accolta richiesta supporto";
}

// costruttore parametrizzato
Interazione::Interazione(const int& _id_interazione,
            const std::string& _cod_fiscale,
            const std::string& _appuntamento,
            const std::string& _contratto,
            const std::string& _note) {
    id_interazione = _id_interazione;
    cod_fiscale = _cod_fiscale;
    appuntamento = _appuntamento;
    contratto = _contratto;
    note = _note;
}

// getter
int Interazione::getIdInterazione() const{
    return id_interazione;
}

std::string Interazione::getCodFiscale() const {
    return cod_fiscale;
}

std::string Interazione::getContratto() const {
    return contratto;
}

std::string Interazione::getAppuntamento() const {
    return appuntamento;
}

std::string Interazione::getNote() const {
    return note;
}

// setter
void Interazione::setIdInterazione(const int& new_id){
    id_interazione = new_id;
}

void Interazione::setAppuntamento(const std::string& nuovo_app) {
    appuntamento= nuovo_app;
}

void Interazione::setContratto(const std::string& nuovo_contr) {
    contratto = nuovo_contr;
}

void Interazione::setCodFiscale(const std::string& nuovo_cdf) {
    cod_fiscale = nuovo_cdf;
}

void Interazione::setNote(const std::string& nuova_nota) {
    note = nuova_nota;
}

// visualizzazione
void Interazione::showInteraction() const {
    std::cout << "Id Interazione: " << id_interazione
              << ", Codice Fiscale: " << cod_fiscale
              << ", Appuntamento: " << appuntamento
              << ", Contratto: " << contratto
              << ", Note: " << note << "\n" << std::endl;
}

// CSV
std::string Interazione::toCsv() const {
    return std::to_string(id_interazione) + ";" + cod_fiscale + ";" + appuntamento + ";" + contratto + ";" + note;
}

// parsing CSV
Interazione Interazione::fromCSVLine(const std::string& rigaCSV) {
    std::vector<std::string> campi;
    std::stringstream ss(rigaCSV);
    std::string campo;

    while (std::getline(ss, campo, ';')) {
        campi.push_back(trim(campo));
    }

    if (campi.size() != 5) {
        std::cerr << "Warning: errato parsing CSV: numero campi non corretto\n";
        return Interazione(0,"N/A", "N/A", "N/A", "N/A");
    }

    int id = std::stoi(campi[0]);

    return Interazione(id, campi[1], campi[2], campi[3], campi[4]);
}
