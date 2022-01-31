//
// Created by thege on 18.12.2021.
//

#include "Carte.h"


Carte::Carte(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare, int pret)
        : nume(nume), autor(autor), editura(editura), nrPagini(nrPagini), anPublicare(anPublicare), pret(pret) {}

const string &Carte::getNume() const {
    return nume;
}

const string &Carte::getAutor() const {
    return autor;
}

const string &Carte::getEditura() const {
    return editura;
}

int Carte::getNrPagini() const {
    return nrPagini;
}

int Carte::getAnPublicare() const {
    return anPublicare;
}

int Carte::getPret() const {
    return pret;
}

void Carte::setNume(const string &nume) {
    Carte::nume = nume;
}

void Carte::setAutor(const string &autor) {
    Carte::autor = autor;
}

void Carte::setEditura(const string &editura) {
    Carte::editura = editura;
}

void Carte::setNrPagini(int nrPagini) {
    Carte::nrPagini = nrPagini;
}

void Carte::setAnPublicare(int anPublicare) {
    Carte::anPublicare = anPublicare;
}

void Carte::setPret(int pret) {
    Carte::pret = pret;
}

std::ostream &operator<<(std::ostream &os, const Carte &carte) {
    carte.print(os << "Numele cartii: " << carte.nume << ", Autor: " << carte.autor << " Editura: " << carte.editura
       << ", Numar Pagini: "
       << carte.nrPagini << ", Anul Publicarii: " << carte.anPublicare << ", Pret: " << carte.pret << " lei"
       << std::endl);
    return os;
}

Carte::Carte(const Carte &copie) {
    this->nume = copie.nume;
    this->autor = copie.autor;
    this->editura = copie.editura;
    this->nrPagini = copie.nrPagini;
    this->anPublicare = copie.anPublicare;
    this->pret = copie.pret;

}

Carte &Carte::operator=(const Carte &copie) {
    this->nume = copie.nume;
    this->autor = copie.autor;
    this->editura = copie.editura;
    this->nrPagini = copie.nrPagini;
    this->anPublicare = copie.anPublicare;
    this->pret = copie.pret;
}

Carte::~Carte() {}

void Carte::print(std::ostream &stream) const {

}
