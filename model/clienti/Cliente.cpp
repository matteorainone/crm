#include "Cliente.h"
#include "utils/utils.h"

#include <iostream>
#include <sstream>
#include <vector>

// costruttore di default
Cliente::Cliente() {
    nome = "Paolo";
    cognome = "Rossi";
    cod_fiscale = "AAABBB00A11C123Z";
    email = "paolo.rossi@example.com";
}

// costruttore parametrizzato
Cliente::Cliente(const std::string& _nome,
                 const std::string& _cognome,
                 const std::string& _cod_fiscale,
                 const std::string& _email) {
    nome = _nome;
    cognome = _cognome;
    cod_fiscale = _cod_fiscale;
    email = _email;
}

// getter
std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getCognome() const {
    return cognome;
}

std::string Cliente::getCodFiscale() const {
    return cod_fiscale;
}

std::string Cliente::getEmail() const {
    return email;
}

// setter
void Cliente::setNome(const std::string& nuovo_nome) {
    nome = nuovo_nome;
}

void Cliente::setCognome(const std::string& nuovo_cognome) {
    cognome = nuovo_cognome;
}

void Cliente::setCodFiscale(const std::string& nuovo_cdf) {
    cod_fiscale = nuovo_cdf;
}

void Cliente::setEmail(const std::string& nuova_email) {
    email = nuova_email;
}

// visualizzazione
void Cliente::showClient() const {
    std::cout << "Nome: " << nome
              << ", Cognome: " << cognome
              << ", Codice Fiscale: " << cod_fiscale
              << ", Email: " << email << "\n" << std::endl;
}

// CSV
std::string Cliente::toCsv() const {
    return nome + ";" + cognome + ";" + cod_fiscale + ";" + email;
}

// parsing CSV
Cliente Cliente::fromCSVLine(const std::string& rigaCSV) {
    std::vector<std::string> campi;
    std::stringstream ss(rigaCSV);
    std::string campo;

    while (std::getline(ss, campo, ';')) {
        campi.push_back(trim(campo));
    }

    if (campi.size() != 4) {
        std::cerr << "Warning: errato parsing CSV: numero campi non corretto\n";
        return Cliente("N/A", "N/A", "N/A", "N/A");
    }

    return Cliente(campi[0], campi[1], campi[2], campi[3]);
}