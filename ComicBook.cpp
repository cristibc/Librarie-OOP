//
// Created by thege on 18.12.2021.
//

#include "ComicBook.h"

ComicBook::ComicBook(const string &nume, const string &creator, const string &publisher, int nrPagini, int anPublicare,
                     int pret)
        : Carte(nume, creator, publisher, nrPagini, anPublicare, pret) {}

std::ostream &operator<<(std::ostream &os, const ComicBook &cb) {
    cb.print(os << "Numele comic book-ului: " << cb.getNume() << ", Creator: " << cb.getAutor() << " Publisher: " << cb.getEditura()
                 << ", Numar Pagini: "
                 << cb.getNrPagini() << ", Anul Publicarii: " << cb.getAnPublicare() << ", Pret: " << cb.getPret() << " lei"
                 << std::endl);
    return os;
}

void ComicBook::print(std::ostream &stream) const {
}

ComicBook::~ComicBook() {

}

