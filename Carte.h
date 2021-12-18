//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_CARTE_H
#define OOPTESTING_CARTE_H
#include <iostream>
#include <memory>
using std::string;


class Carte {
private:
    string nume, autor, editura;
    int nrPagini;
    int anPublicare;
    int pret;

// Clasa de baza a cartilor
public:
    Carte(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare, int pret);

    const string &getNume() const;

    const string &getAutor() const;

    const string &getEditura() const;

    int getNrPagini() const;

    int getAnPublicare() const;

    int getPret() const;

    void setNume(const string &nume);

    void setAutor(const string &autor);

    void setEditura(const string &editura);

    void setNrPagini(int nrPagini);

    void setAnPublicare(int anPublicare);

    void setPret(int pret);

    friend std::ostream &operator<<(std::ostream &os, const Carte &carte);

    Carte(const Carte &copie);

    Carte &operator=(const Carte &copie);

// Destructorul
    ~Carte();

};

#endif //OOPTESTING_CARTE_H
