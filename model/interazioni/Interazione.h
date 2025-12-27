#pragma once

#include <string>

class Interazione {
private:
    int id_interazione;
    std::string cod_fiscale;
    std::string appuntamento;
    std::string contratto;
    std::string note;

public:
    // costruttori
    Interazione();
    Interazione(const int& _id_interazione,
            const std::string& _cod_fiscale,
            const std::string& _appuntamento,
            const std::string& _contratto,
            const std::string& _note);

    // getter
    int getIdInterazione() const;
    std::string getCodFiscale() const;
    std::string getAppuntamento() const;
    std::string getContratto() const;
    std::string getNote() const;

    // setter
    void setIdInterazione (const int& new_id);
    void setAppuntamento(const std::string& nuovo_app);
    void setContratto(const std::string& nuovo_cotratto);
    void setCodFiscale(const std::string& nuovo_cdf);
    void setNote(const std::string& nuova_nota);

    // metodi
    void showInteraction() const;
    std::string toCsv() const;

    // metodo statico
    static Interazione fromCSVLine(const std::string& rigaCSV);
};
