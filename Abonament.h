//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_ABONAMENT_H
#define OOPTESTING_ABONAMENT_H
#include <vector>
#include "Carte.h"


// Design pattern - builder
class abonament {
    string nume;
    int pret_abonament;
    int reducere;
    int carti_gratuite;
    string produse_exclusive;

    friend class abonament_builder;

public:
    abonament() = default;


    friend std::ostream &operator<<(std::ostream &os, const abonament &abonament);
};

class abonament_builder {
private:
    abonament a;
public:
    abonament_builder() = default;

    abonament_builder &nume(const char *nume);

    abonament_builder &pret_abonament(int pret);

    abonament_builder &reducere(int reducere);

    abonament_builder &carti_gratuite(int nr);

    abonament_builder &produse_exclusive(const char *produse);

    abonament build();

};




#endif //OOPTESTING_ABONAMENT_H
