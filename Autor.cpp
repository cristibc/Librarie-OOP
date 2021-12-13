//
// Created by thege on 13.12.2021.
//

#include "Autor.h"

Autor &Autor::operator=(const Autor &copie) {
    this->nume = copie.nume;
    this->gen = copie.gen;
    this->varsta = copie.varsta;
    this->limba = copie.limba;
}

std::ostream &operator<<(std::ostream &os, const Autor &autor) {
    os << "Nume autor: " << autor.nume << ", Genul: " << autor.gen << ", Varsta autorului: " << autor.varsta
       << ", Limba: "
       << autor.limba << std::endl;
    return os;
}

const string &Autor::getLimba() const {
    return limba;
}

int Autor::getVarsta() const {
    return varsta;
}

const string &Autor::getGen() const {
    return gen;
}

const string &Autor::getNume() const {
    return nume;
}

Autor::Autor(const Autor &copie) {
    this->nume = copie.nume;
    this->gen = copie.gen;
    this->varsta = copie.varsta;
    this->limba = copie.limba;
}

Autor::Autor(const string &nume, const string &gen, const string &limba, int varsta) : nume(nume), gen(gen), limba(limba),
                                                                                       varsta(varsta) {}
