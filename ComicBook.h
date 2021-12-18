//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_COMICBOOK_H
#define OOPTESTING_COMICBOOK_H
#include "Carte.h"

// Clasa mostenita din Carte
class ComicBook : public Carte {
public:
    ComicBook(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare, int pret);


};



#endif //OOPTESTING_COMICBOOK_H
