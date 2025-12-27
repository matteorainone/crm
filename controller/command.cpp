#include "command.h"

#include <regex>
#include <string>
#include <iostream>

GestoreComandi::GestoreComandi(){

    lista_comandi[0] = "Termina Applicazione";
    lista_comandi[1] = "Aggiungi Cliente";
    lista_comandi[2] = "Visualizza Clienti";
    lista_comandi[3] = "Modifica Cliente";
    lista_comandi[4] = "Elimina Cliente";
    lista_comandi[5] = "Ricerca Cliente";
    lista_comandi[6] = "Aggiungere interazione";
    lista_comandi[7] = "Visualizza interazioni";
    lista_comandi[8] = "Cerca interazioni";

    opzioni_modifica[1] = "Nome";
    opzioni_modifica[2] = "Cognome";
    opzioni_modifica[3] = "Email";

    validator = Validator();
    client_manager = GestioneClienti();
    interaction_manager = GestioneInterazioni();
}

void GestoreComandi::stampaComandi(){
    std::cout << "=== Menu comandi ===" << std::endl;
    std::vector<int> ordiniComandi = {0,1,2,3,4,5,6,7,8};

    for (int key : ordiniComandi){
        std::cout << key << " - " << lista_comandi[key] << std::endl;
    }
    std::cout << "=============================" << std::endl;
}

void GestoreComandi::aggiungiCliente(){
    
    std::cout << "Inserire nome cliente. " << std::endl;
    std::string nome = validator.validaNomeCognome();
    std::cout << "Inserire cognome cliente. " << std::endl;
    std::string cognome = validator.validaNomeCognome();
    std::cout << "Inserire codice fiscale cliente. " << std::endl;
    std::string cdf = validator.validaCDF();
    std::cout << "Inserire email cliente. " << std::endl;
    std::string email = validator.validaEmail();

    client_manager.aggiungiCliente(nome, cognome, cdf, email);
}

void GestoreComandi::visualizzaClienti(){
    client_manager.visualizzaTutti();
}

void GestoreComandi::modificaCliente(){

    std::cout << "Scegliere quale cliente modificare." << std::endl;
    std::vector<Cliente*> cliente_target = ricercaCliente();
    
    std::cout << "Scegliere quale elemento modificare" << std::endl;
    //stampa lista comandi
    for (const auto& [numero, opzione] : opzioni_modifica){
        std::cout << numero << ")" << opzione << std::endl;
    }
    std::cout << "Inserire numero comando: " << std::endl;
    std::string user_option;
    std::getline(std::cin, user_option);

    switch (int num = std::stoi(user_option))
    {
    case 1:
        for (auto& cliente : cliente_target){
            std::string new_name = validator.validaNomeCognome();
            client_manager.modificaNomeCliente(cliente, new_name);
        }
        std::cout << "Modifica effettuata." << std::endl;
        break;
    case 2:
        for (auto& cliente : cliente_target){
            std::string new_cognome = validator.validaNomeCognome();
            client_manager.modificaCognomeCliente(cliente, new_cognome);
        }
        std::cout << "Modifica effettuata." << std::endl;
        break;
    case 3:
        for (auto& cliente : cliente_target){
            std::string newEmail = validator.validaEmail();
            client_manager.modificaEmailCliente(cliente, newEmail);
        }
        std::cout << "Modifica effettuata." << std::endl;
    default:
        std::cout << "Inserito valore non valido. Fine processo modifica" << std::endl;
        break;
    }
    client_manager.salvaSuFile();
}

std::vector<Cliente*> GestoreComandi::ricercaCliente(){

    std::vector<Cliente*> risultati_ricerca = client_manager.getClienti();

    std::cout << "Inserire nome cliente da cercare: " << std::endl;
    std::string nome;
    std::getline(std::cin, nome);
    std::cout << "Inserire cognome cliente da cercare: " << std::endl;
    std::string cognome;
    std::getline(std::cin, cognome);

   //ricerca per nome cliente fornito da utente
   if (!nome.empty() && nome != "0"){
        risultati_ricerca = client_manager.ricercaClienteNome(nome, risultati_ricerca);
   }

   //ricerca per cognome cliente fornito da utente
   if (!cognome.empty() && cognome != "0"){
    risultati_ricerca = client_manager.ricercaClienteCognome(cognome, risultati_ricerca);
   }

   if (risultati_ricerca.empty()){
    std::cout << "Nessun cliente corrispondente ai criteri di ricerca." << std::endl;
   } else if (risultati_ricerca.size() == 1){
    std::cout << "Trovato un cliente corrispondente ai parametri di ricerca: " << std::endl; 
    client_manager.visualizzaCliente(risultati_ricerca[0]);
   } else {
    std::cout << "Trovati risultati multipli: n° clienti pari a " << risultati_ricerca.size() << std::endl;
    std::cout << "Inserire codice fiscale per ottenere valore unico ? (SI/NO): " << std::endl;
    
    std::string scelta_utente = validator.validazioneSiNo();
    if (scelta_utente == "SI"){
        std::string cdf = validator.validaCDF();

        Cliente* cliente_target = client_manager.ricercaCliente(cdf, risultati_ricerca);

        std::cout << "Cliente trovato: " << std::endl;
        cliente_target -> showClient();
        risultati_ricerca.clear();
        risultati_ricerca.push_back(cliente_target);
    } else {
        std::cout << "Di seguito i clienti trovati: " << std::endl;
        for (auto& cliente : risultati_ricerca){
            client_manager.visualizzaCliente(cliente);
        }
    }
   }

   return risultati_ricerca;
}

void GestoreComandi::eliminaCliente(){
    std::vector<Cliente*> clienti_target = ricercaCliente();
    for (auto& cliente : clienti_target){
        client_manager.rimuoviCliente(cliente);
    }
}

void GestoreComandi::aggiungiInterazione(){
    
    std::cout << "Inserire codice fiscale cliente. " << std::endl;
    std::string cdf = validator.validaCDF();
    std::cout << "Inserire appuntamento cliente. " << std::endl;
    std::string appuntamento = validator.validazioneAppContr();
    std::cout << "Inserire contratto cliente. " << std::endl;
    std::string contratto = validator.validazioneAppContr();
    std::cout << "Inserire eventuali note. " << std::endl;
    std::string note;
    std::getline(std::cin, note);

    interaction_manager.aggiungiInterazione(cdf, appuntamento, contratto, note);
}

void GestoreComandi::visualizzaInterazioni(){
    std::cout << "Visualizzare tutte le interazioni salvate ? " << std::endl;
    std::string scelta_utente = validator.validazioneSiNo();
    
    if (scelta_utente == "SI"){
        interaction_manager.visualizzaTutte();
    } else {
        std::cout << "Inserire dettaglio del cliente per recuperare le interazioni." << std::endl;

        std::vector<Cliente*> clientiTarget = ricercaCliente();
        
        for (auto& cliente : clientiTarget){
            std::string cdf = cliente -> getCodFiscale();
            interaction_manager.visualizzaInterazioniCliente(cdf);
        }
    }
}

void GestoreComandi::visualizzaInterazioni(const std::vector<Interazione*> interazioniTarget){
    for (auto& interazione : interazioniTarget){
        interazione -> showInteraction();
    }
}

std::vector<Interazione*> GestoreComandi::ricercaInterazione(){
    std::cout << "Inserire codice fiscale del cliente per il quale si vogliono le interazioni." << std::endl;
    std::string cdf = validator.validaCDF();

    std::vector<Interazione*> interazioniTarget = interaction_manager.ricercaInterazioneCF(cdf);

    return interazioniTarget;
}

bool GestoreComandi::selettoreComandi(const int& num_comando){
    switch (num_comando)
    {
    case 1:
        aggiungiCliente();
        return true;
    case 2:
        visualizzaClienti();
        return true;
    case 3:
        modificaCliente();
        return true;
    case 4:
        eliminaCliente();
        return true;
    case 5:
        ricercaCliente();
        return true;
    case 6:
        aggiungiInterazione();
        return true;
    case 7:
        visualizzaInterazioni();
        return true;
    case 8:
        {
        std::vector<Interazione*> interazioni_target = ricercaInterazione();
        visualizzaInterazioni(interazioni_target);
        }
        return true;
    case 0:
        return false;
    default:
        std::cout << "Comando non riconosciuto" << std::endl;
        return true;
    }
}