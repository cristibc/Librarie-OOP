//
// Created by thege on 18.12.2021.
//

#include "Abonament.h"

abonament_builder &abonament_builder::nume(const char *nume) {
    a.nume = nume;
    return *this;
}

abonament_builder &abonament_builder::pret_abonament(int pret) {
    a.pret_abonament = pret;
    return *this;
}

abonament_builder &abonament_builder::reducere(int reducere) {
    a.reducere = reducere;
    return *this;
}

abonament_builder &abonament_builder::carti_gratuite(int nr) {
    a.carti_gratuite = nr;
    return *this;
}

abonament_builder &abonament_builder::produse_exclusive(const char *produse) {
    a.produse_exclusive = produse;
    return *this;
}

abonament abonament_builder::build() {
    return a;

}

std::ostream &operator<<(std::ostream &os, const abonament &abonament) {
    os << "Nume abonament: " << abonament.nume << ", Pretul abonamentului: " << abonament.pret_abonament
       << ", Reducere articole: "
       << abonament.reducere << "%" << ", Numar carti gratuite: " << abonament.carti_gratuite << ", Produse exclusive: "
       << abonament.produse_exclusive << std::endl;
    return os;
}
