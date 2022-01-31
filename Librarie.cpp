//
// Created by thege on 18.12.2021.
//

#include "Librarie.h"

Librarie::Librarie(const string &numeClient, const string &adresaClient, std::vector<std::shared_ptr<Carte>> &carte)
        : numeClient(numeClient), adresaClient(adresaClient), carte(carte) {}

const string &Librarie::getNumeClient() const {
    return numeClient;
}

void Librarie::setNumeClient(const string &numeClient) {
    Librarie::numeClient = numeClient;
}

void Librarie::setAdresaClient(const string &adresaClient) {
    Librarie::adresaClient = adresaClient;
}

std::vector<string> Librarie::search(const string &query) {
    std::vector <std::string> rezultate;
    for (int i = 0; i < carte.size(); i++) {
        if (carte[i]->getNume() == query) {
            rezultate.push_back(query);
        }
        return rezultate;
    }
    std::cout << "Cartea nu a fost gasita" << std::endl;
}

void Librarie::listCarti(const string &query) {
    std::cout << "Cartile autorului: " << query << " din libraria noastra sunt:" << std::endl;
    for (int i = 0; i < carte.size(); i++) {
        if (carte[i]->getAutor() == query) {
            std::cout << carte[i]->getNume() << std::endl;
        }
    }
    std::cout << "--------------" << std::endl;
}
