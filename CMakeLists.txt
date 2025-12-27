cmake_minimum_required(VERSION 3.10)
project(GestioneCRM)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include le intestazioni (.h) dalle varie sottocartelle
include_directories(controller)
include_directories(model/clienti)
include_directories(model/interazioni)
include_directories(utils)

# Elenca tutti i file sorgente (.cpp)
set(SOURCES
    main.cpp
    controller/command.cpp
    model/clienti/Cliente.cpp
    model/clienti/GestioneClienti.cpp
    model/interazioni/Interazione.cpp
    model/interazioni/GestioneInterazioni.cpp
    utils/utils.cpp
    utils/Validator.cpp
)

# Crea l'eseguibile
add_executable(GestioneCRM ${SOURCES})