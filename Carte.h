//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_CARTE_H
#define OOPTESTING_CARTE_H
#include <iostream>
#include <memory>
#include <vector>

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

    Carte(const Carte &copie);
    Carte & operator=(const Carte &copie);

    void review(const string &query){};

// Timp de citire al cartilor - viteza in pagini / minut
    virtual void Timp(double viteza) {
        int minuteCitire = nrPagini / viteza;
        int ore = minuteCitire / 60;
        minuteCitire = minuteCitire % 60;
        if (ore > 0)
            std::cout << "Pentru a termina cartea \"" << nume << "\" aveti nevoie de aproximativ " << ore << " ore si "
                      << minuteCitire << " de minute" << std::endl;
        else if (ore == 0 && minuteCitire > 19)
            std::cout << "Pentru a termina cartea \"" << getNume() << "\" aveti nevoie de aproximativ "
                      << minuteCitire << " de minute" << std::endl;
        else
            std::cout << "Pentru a termina cartea \"" << nume << "\" aveti nevoie de aproximativ " << minuteCitire
                      << " minute" << std::endl;
    }

// Destructorul
    virtual ~Carte();

protected:
    // Am implementat aici un virtual print pentru ca nu vad cum as putea sa dau overload operatorului << altfel
    virtual void print(std::ostream & stream) const;
    friend std::ostream &operator<<(std::ostream &os, const Carte &carte);

};

#endif //OOPTESTING_CARTE_H
