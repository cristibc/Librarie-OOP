//
// Created by thege on 18.12.2021.
//

#include "ComicBook.h"

ComicBook::ComicBook(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare,
                     int pret)
        : Carte(nume, autor, editura, nrPagini, anPublicare, pret) {}
