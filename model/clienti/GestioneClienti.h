#pragma once
#include "Cliente.h"
#include <string>
#include <vector>

class GestioneClienti{
    private:
        std::string clients_file_path;
        std::vector<Cliente> clienti;

    public:
        void caricaDaFile();
        void salvaSuFile() const;
    
        GestioneClienti();

        std::vector<Cliente*> getClienti();

        int getClientiNum();

        Cliente* ricercaCliente(const std::string& cod_fiscale);
        Cliente* ricercaCliente(const std::string& cod_fiscale, const std::vector<Cliente*>& clientiTarget);

        void aggiungiCliente(const std::string& nome, 
                        const std::string& cognome, 
                        const std::string& cod_fiscale, 
                        const std::string& email);

        void rimuoviCliente(Cliente* clienteDaRimuovere);

        void modificaNomeCliente(Cliente* cliente,
                        const std::string& new_name);
        
        void modificaCognomeCliente(Cliente* cliente,
                        const std::string& new_surname);

        void modificaEmailCliente(Cliente* cliente,
                        const std::string& new_email);

        std::vector<Cliente*> ricercaClienteNome(const std::string& nome);

        std::vector<Cliente*> ricercaClienteNome(const std::string& nome, const std::vector<Cliente*>& clientiTarget);
        
        std::vector<Cliente*> ricercaClienteCognome(const std::string& cognome);

        std::vector<Cliente*> ricercaClienteCognome(const std::string& cognome, const std::vector<Cliente*>& clientiTarget);
        
        void visualizzaCliente(const Cliente* cliente);
        
        void visualizzaTutti();

};