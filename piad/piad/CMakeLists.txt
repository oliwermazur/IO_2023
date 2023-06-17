cmake_minimum_required(VERSION 3.25)
project(piad)

set(CMAKE_CXX_STANDARD 20)

add_executable(piad main.cpp Magazyn.h Magazyn.cpp Osoby_funkcje_switch.h Osoby_funkcje_switch.cpp Pracownik.h Pracownik.cpp Klient.h Klient.cpp Kierownik.h Kierownik.cpp Zamowienia.h Zamowienia.cpp)
