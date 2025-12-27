#include "GestioneClienti.h"
#include "model/clienti/Cliente.h"
#include "utils/utils.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


void GestioneClienti::caricaDaFile(){
    std::vector<std::string> righe_file;
    //scompatto il file di base dati in un insieme di righe
    righe_file = readCSVLines(clients_file_path);

    for (size_t i = 0; i < righe_file.size(); i++){
        //da ciascuna riga genero un cliente che andrà a riempire l'insieme dei clienti gestiti dall'applicazione
        clienti.push_back(Cliente::fromCSVLine(righe_file[i]));
    }
}

void GestioneClienti::salvaSuFile() const{
    std::vector<std::string> righe_clienti;

    for (size_t i = 0; i < clienti.size(); i++){
        //genero una lista di stringhe, formattate in csv, partendo dai clienti gestiti
        righe_clienti.push_back(clienti[i].toCsv());
    }

    //partendo dalla lista di righe, salvo su file csv
    writeCSVAtomically(clients_file_path, righe_clienti);
}



//costruttore di default
GestioneClienti::GestioneClienti(){
    clients_file_path = "/path/to/clienti.csv";
    caricaDaFile();
}

std::vector<Cliente*> GestioneClienti::getClienti(){
    
    std::vector<Cliente*> puntatori_clienti;

    for (auto& cliente : clienti){
        puntatori_clienti.push_back(&cliente);
    }
    return puntatori_clienti;
}

int GestioneClienti::getClientiNum(){
    return clienti.size();
}

Cliente* GestioneClienti::ricercaCliente(const std::string& cod_fiscale){
    
    for (auto& cliente : clienti){
        if (cliente.getCodFiscale() == cod_fiscale){
            return &cliente;
        }
    }
    return nullptr;
}

Cliente* GestioneClienti::ricercaCliente(const std::string& cod_fiscale, const std::vector<Cliente*>& clientiTarget){

    for (Cliente* cliente : clientiTarget){
        if (cliente && cliente -> getCodFiscale() == cod_fiscale){
            return cliente;
        }
    }

    return nullptr;
}

void GestioneClienti::aggiungiCliente(const std::string& nome, const std::string& cognome, const std::string& cod_fiscale, const std::string& email){
    
    Cliente new_client;
    
    new_client = Cliente(nome, cognome, cod_fiscale, email);
    clienti.push_back(new_client);
    salvaSuFile();
}

void GestioneClienti::rimuoviCliente(Cliente* clienteDaRimuovere){
    
    if (clienteDaRimuovere == nullptr){
        std::cout << "Il riferimento al cliente indicato non ha prodotto risultati, nessun cliente eliminato." << std::endl;
        return;
    }

    auto cliente = std::find_if(clienti.begin(), clienti.end(), [&clienteDaRimuovere](const Cliente& c){
        return &c == clienteDaRimuovere;
    });

    if (cliente != clienti.end()){
        clienti.erase(cliente);

        salvaSuFile();
        std::cout << "Cliente rimosso con successo, base dati aggiornata." << std::endl;
    } else {
        std::cout << "Il cliente indicato non è presente nella lista di clienti" << std::endl;
    }

};

void GestioneClienti::modificaNomeCliente(Cliente* cliente, const std::string& new_name){
    
    if (cliente) {
        cliente->setNome(new_name);
    }
}

void GestioneClienti::modificaCognomeCliente(Cliente* cliente, const std::string& new_surname){
    
    if (cliente) {
        cliente->setCognome(new_surname);
    }
}

void GestioneClienti::modificaEmailCliente(Cliente* cliente, const std::string& new_email){
    
    if (cliente) {
        cliente->setEmail(new_email);
    }
}

std::vector<Cliente*> GestioneClienti::ricercaClienteNome(const std::string& nome){

    std::vector<Cliente*> risultati_ricerca;

    for (auto& cliente : clienti){
        if (cliente.getNome() == nome){
            risultati_ricerca.push_back(&cliente);
        }
    }
    return risultati_ricerca;
}


std::vector<Cliente*> GestioneClienti::ricercaClienteNome(const std::string& nome, const std::vector<Cliente*>& clientiTarget){
    
    std::vector<Cliente*> risultati_ricerca;

    for (Cliente* cliente : clientiTarget){
        if (cliente && cliente -> getNome() == nome){
            risultati_ricerca.push_back(cliente);
        }
    }
    return risultati_ricerca;
}

std::vector<Cliente*> GestioneClienti::ricercaClienteCognome(const std::string& cognome){

    std::vector<Cliente*> risultati_ricerca;

    for (auto& cliente : clienti){
        if (cliente.getCognome() == cognome){
            risultati_ricerca.push_back(&cliente);
        }
    }
    return risultati_ricerca;
}

std::vector<Cliente*> GestioneClienti::ricercaClienteCognome(const std::string& cognome, const std::vector<Cliente*>& clientiTarget){
    
    std::vector<Cliente*> risultati_ricerca;

    for (Cliente* cliente : clientiTarget){
        if (cliente && cliente -> getCognome() == cognome){
            risultati_ricerca.push_back(cliente);
        }
    }
    return risultati_ricerca;
}

void GestioneClienti::visualizzaCliente(const Cliente* cliente){
    
    cliente -> showClient();
}

void GestioneClienti::visualizzaTutti(){

    for (auto& cliente : clienti){
        visualizzaCliente(&cliente);
    }
}