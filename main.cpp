#include "controller/command.h"
#include "utils/utils.h"
#include "utils/Validator.h"
#include <iostream>


int main(){
    
    GestoreComandi commandManager = GestoreComandi();
    Validator checkInput = Validator();

    bool running = true;
    int comando;

    while (running){
        std::cout << "=== Benvenuti nel CRM AZIENDALE ===" << std::endl;
        commandManager.stampaComandi();
        comando = checkInput.validazioneSelezioneNum();
        running = commandManager.selettoreComandi(comando);
    }

    std::cout << "Chiusura applicazione." << std::endl;
}