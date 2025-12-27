#include "utils.h"
#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        // La stringa è tutta spazi o vuota
        return "";
    }
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

std::vector<std::string> readCSVLines(const std::string& filePath) {
    std::vector<std::string> righe;
    std::ifstream file(filePath);

    if(!file.is_open()){
        std::cerr << "Errore, impossibile aprire il file csv: " << filePath << std::endl;
        return righe; //vettore vuoto
    }

    std::string riga;
    while (std::getline(file, riga)){
        //si evitano le righe vuote
        if(!riga.empty()){
            righe.push_back(riga);
        }
    }

    file.close();
    return righe;
}

bool writeCSVAtomically(const std::string& destFilePath, std::vector<std::string>& righe){
    
    // 1. Nome file temporaneo
    std::string tempFilePath = destFilePath + ".tmp";

    // 2. Scrittura sul file temporaneo
    std::ofstream tempFile(tempFilePath, std::ios::out | std::ios::trunc);

    if (!tempFile.is_open()) {
        std::cerr << "Errore: impossibile creare il file temporaneo "
                  << tempFilePath << std::endl;
        return false;
    }

    for (const std::string& riga : righe) {
        tempFile << riga << '\n';
        if (!tempFile.good()) {
            std::cerr << "Errore durante la scrittura del file temporaneo\n";
            tempFile.close();
            std::remove(tempFilePath.c_str());
            return false;
        }
    }

    tempFile.close();

    // 3. Sostituzione atomica del file finale
    std::remove(destFilePath.c_str());

    if (std::rename(tempFilePath.c_str(), destFilePath.c_str()) != 0) {
        std::cerr << "Errore: impossibile sostituire il file "
                  << destFilePath << std::endl;
        std::remove(tempFilePath.c_str());
        return false;
    }

    return true;
}