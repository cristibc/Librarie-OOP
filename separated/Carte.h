//
// Created by thege on 13.12.2021.
//

#ifndef BOOKSHOPOOP_CARTE_H
#define BOOKSHOPOOP_CARTE_H
#include <iostream>
#include <vector>
#include <memory>
using std::string;

class Carte {
private:
    string nume, autor, editura;
    int nrPagini;
    int anPublicare;
    int pret;

public:
    Carte(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare, int pret);

    const string &getNume() const;

    const string &getAutor() const;

    const string &getEditura() const {
        return editura;
    }

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

    ~Carte();


    void adaugareCarte(int counter) {
        string nume, autor, editura;
        int nrPagini;
        int anPublicare;
        int pret;
    }

//    std::cout<<"Se introduce o carte noua in sistem..."<<std::endl;
//    std::cout<<"Introduceti numele cartii: ";
//    getline(std::cin,nume);
//    carte[counter].setNume(nume);
//    std::cout<<"Introduceti numele autorului: ";
//    getline(std::cin, autor);
//    carte[counter].setAutor(autor);
//    std::cout<<"Introduceti numele editurii: ";
//    getline(std::cin, editura);
//    carte[counter].setEditura(editura);
//    std::cout<<"Introduceti numarul de pagini: ";
//    getline(std::cin, nrPagini);
//    carte[counter].
//    }


};


#endif //BOOKSHOPOOP_CARTE_H
