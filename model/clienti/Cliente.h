#pragma once

#include <string>
#include <optional>

class Cliente {
private:
    std::string nome;
    std::string cognome;
    std::string cod_fiscale;
    std::string email;

public:
    // costruttori
    Cliente();
    Cliente(const std::string& _nome,
            const std::string& _cognome,
            const std::string& _cod_fiscale,
            const std::string& _email);

    // getter
    std::string getNome() const;
    std::string getCognome() const;
    std::string getCodFiscale() const;
    std::string getEmail() const;

    // setter
    void setNome(const std::string& nuovo_nome);
    void setCognome(const std::string& nuovo_cognome);
    void setCodFiscale(const std::string& nuovo_cdf);
    void setEmail(const std::string& nuova_email);

    // metodi
    void showClient() const;
    std::string toCsv() const;

    // metodo statico
    static Cliente fromCSVLine(const std::string& rigaCSV);
};

struct ClienteUpdate {
    std::optional<std::string> nome;
    std::optional<std::string> cognome;
    std::optional<std::string> email;
};
