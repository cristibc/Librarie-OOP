//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_PACHETPROMO_H
#define OOPTESTING_PACHETPROMO_H
#include <vector>
#include <ostream>
#include "Carte.h"


// Design pattern - factory

class promoCarti{
    string nume;
    int reducere;
    string serie;
    string tip_cover;

public:
    promoCarti(const string &nume, int reducere, const string &serie, const string &tipCover);

    friend std::ostream &operator<<(std::ostream &os, const promoCarti &promoC);
};


class promoVinyl {
    string nume;
    int reducere;
    string album;
    string gen;
    string artist;

public:
    promoVinyl(const string &nume, int reducere, const string &album, const string &gen, const string &artist);

    friend std::ostream &operator<<(std::ostream &os, const promoVinyl &promoV);

};

class promoManga {
    string nume;
    int reducere;
    string serie;
    string gen;
    string tip_coperta;

public:
    promoManga(const string &nume, int reducere, const string &serie, const string &gen, const string &tipCover);

    friend std::ostream &operator<<(std::ostream &os, const promoManga &promoM);

};



class factory {
public:
    static promoCarti got() { return promoCarti("Winter is coming", 20, "A Song of Ice and Fire", "Hardcover"); }
    static promoCarti lotr() { return promoCarti("Middle-Earth", 30, "The Lord of the Rings", "Paperback"); }
    static promoCarti hg() { return promoCarti("Mockingjay", 15, "The Hunger Games", "Hardcover"); }

    static promoVinyl am() { return promoVinyl("Crawling back to you", 30, "AM", "Indie Rock", "Arctic Monkeys"); }
    static promoVinyl yzs() { return promoVinyl("Bound 2 You", 25, "Yeezus", "Hip-Hop", "Kanye West"); }
    static promoVinyl flw() { return promoVinyl("Golf Wang", 35, "Flower Boy", "Jazz-Rap", "Tyler, the Creator"); }

    static promoManga aot() { return promoManga("Attack on titan", 15, "Shingeki no Kyojin", "Super Power, Military", "Paperback"); }
    static promoManga dn() { return promoManga("Shinigami", 20, "Death Note", "Psychological", "Paperback"); }
    static promoManga fma() { return promoManga("Ouroboros", 25, "Fullmetal Alchemist", "Action Comedy", "Paperback"); }

};


#endif //OOPTESTING_PACHETPROMO_H
