//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_PACHETPROMO_H
#define OOPTESTING_PACHETPROMO_H
#include <vector>
#include "Carte.h"


// Design pattern - factory

class pachetPromo {
    string nume;
    int reducere;
    string serie;
    string tip_cover;

public:
    pachetPromo(const string &nume, int reducere, const string &serie, const string &tipCover);

    friend std::ostream &operator<<(std::ostream &os, const pachetPromo &promo);
};

class pachetPromo_factory {
public:
    static pachetPromo got() { return pachetPromo("Winter is coming", 20, "A Song of Ice and Fire", "Hardcover"); }
    static pachetPromo lotr() { return pachetPromo("Middle-Earth", 30, "The Lord of the Rings", "Paperback"); }
    static pachetPromo hg() { return pachetPromo("Mockingjay", 15, "The Hunger Games", "Hardcover"); }

};


#endif //OOPTESTING_PACHETPROMO_H
