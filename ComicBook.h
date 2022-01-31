//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_COMICBOOK_H
#define OOPTESTING_COMICBOOK_H

#include <ostream>
#include "Carte.h"

// Clasa mostenita din Carte
class ComicBook : public Carte {
public:
    ComicBook(const string &nume, const string &creator, const string &publisher, int nrPagini, int anPublicare, int pret);

    virtual void Timp(double viteza) override {
        int minuteCitire = getNrPagini() / viteza;
        int ore = minuteCitire / 60;
        minuteCitire = minuteCitire % 60;
        if (ore > 0)
            std::cout << "Pentru a termina comic book-ul \"" << getNume() << "\" aveti nevoie de aproximativ " << ore
                      << " ore si " << minuteCitire << " de minute" << std::endl;
        else if (ore == 0 && minuteCitire > 19)
            std::cout << "Pentru a termina comic book-ul \"" << getNume() << "\" aveti nevoie de aproximativ "
                      << minuteCitire << " de minute" << std::endl;
        else
            std::cout << "Pentru a termina comic book-ul \"" << getNume() << "\" aveti nevoie de aproximativ "
                      << minuteCitire << " minute" << std::endl;
    };

    virtual ~ComicBook();

protected:
    virtual void print(std::ostream & stream) const override;
    friend std::ostream &operator<<(std::ostream &os, const ComicBook &cb);
};


#endif //OOPTESTING_COMICBOOK_H
