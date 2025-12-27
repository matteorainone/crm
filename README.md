# CRM per impresa di assicurazioni

## Contesto del progetto

InsuraPro Solutions si dedica a migliorare l'efficienza e la qualità del servizio clienti per le imprese di assicurazioni, sviluppando un avanzato sistema di Customer Relationship Management (CRM) che facilita la gestione delle informazioni sui clienti e delle loro interazioni con l'azienda.

Le imprese di assicurazioni necessitano di un metodo sistematico e centralizzato per gestire le informazioni sui clienti e tracciare le interazioni. Molti sistemi attuali sono frammentati o non user-friendly, ostacolando l’efficacia operativa e la soddisfazione del cliente.

InsuraPro Solutions offrirà un’applicazione console interattiva sviluppata in C++ che permetterà agli utenti di gestire le informazioni sui clienti e le loro interazioni in modo efficiente e intuitivo, migliorando così il servizio clienti e la gestione interna.

## Requisiti del progetto

1. ***OOP in C++***: Implementare i concetti di OOP per una struttura robusta e flessibile.
2. ***Struttura Dati***: Creare una struttura di dati per memorizzare le informazioni sui clienti e le loro interazioni.
3. ***Interfaccia Utente***: Sviluppare un’interfaccia da linea di comando interattiva e intuitiva.
4. ***Funzionalità***:
    - *Aggiunta di un Cliente*: Inserimento di nuovi clienti nel CRM.
    - *Visualizzazione dei Clienti*: Visualizzare tutti i clienti presenti.
    - *Modifica di un Cliente*: Modificare i dettagli di un cliente esistente.
    - *Eliminazione di un Cliente*: Rimuovere clienti dal CRM.
    - *Ricerca di un Cliente*: Cercare clienti per nome o cognome.
    - *Gestione delle Interazioni*: Aggiungere, visualizzare e cercare interazioni per ogni cliente (per interazioni si intendono gli appuntamenti da parte della forza vendita e i       contratti stipulati).
    - *Salvataggio e Caricamento Dati*: Salvare i dati dei clienti e delle interazioni in un file (testo o CSV) e caricarli all’avvio.

**Interfaccia Utente**: L’interfaccia sarà basata su riga di comando, con un menu principale che offre opzioni chiare per tutte le operazioni necessarie, assicurando un'esperienza utente fluida e accessibile.

## Struttura progetto 

Il progetto in questione è stato sviluppato considerando le seguenti scelte progettuali:

1. la base dati del CRM, che garantisce persistenza delle informazioni, sarà costituita da due file, uno per i clienti ed uno per le interazioni dei clienti con l'azienda;
2. avviata l'applicazione, i dati verranno caricati in memoria per velocizzare il caricamento e le operazioni di modifica, cancellazione, inserimento di nuovi elementi (verranno previsti salvataggi periodici su file, in modo da ridurre il rischio di perdita di modifiche, o triggerare processi di salvataggio su file a seguito di modifiche importanti o alla chiusura dell'applicazione);
3. vengono usate le classi ***Cliente*** ed **Interazione*** per incapsulare i dati delle omonime entità, nonché i metodi per gestire tali informazioni;
4. vengono definite le classi ***GestioneClienti*** e ***GestioneInterazioni*** per mantenere in memoria le informazioni relative a Clienti e Interazioni, nonché i
    metodi per effettuare operazioni di inserimento, modifica, cancellazione e caricamento/salvataggio su file;
5. come da specifica, all'utente finale dell'applicazione sarà consentito l'utilizzo della stessa solo tramite barra di comando e tramite l'utilizzo delle sole funzionalità richieste.

## Istruzioni per l'utilizzo
Per utilizzare e testare il seguente progetto in locale, è necessario procedere alla sua compilazione.
Per farlo, è necessario mettersi nella directory principale del progetto, eseguire il seguente comando per eseguire la build:

`g++ -std=c++17 main.cpp controller/command.cpp model/clienti/Cliente.cpp model/clienti/GestioneClienti.cpp model/interazioni/Interazione.cpp model/interazioni/GestioneInterazioni.cpp utils/utils.cpp utils/Validator.cpp -I. -o main.exe`

In caso di compilatore differente, è necessario aggiornare il comando di conseguenza.
