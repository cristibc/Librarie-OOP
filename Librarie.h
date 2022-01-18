//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_LIBRARIE_H
#define OOPTESTING_LIBRARIE_H
#include <vector>
#include "Carte.h"

// Clasa cu functii pentru listarea si gasirea membrilor din clasa Carte
class Librarie {
private:
    string numeClient;
    string adresaClient;
    std::vector<std::shared_ptr<Carte>> carte;

public:

    Librarie(const string &numeClient, const string &adresaClient, std::vector<std::shared_ptr<Carte>> &carte);


    const string &getNumeClient() const;

    void setNumeClient(const string &numeClient);

    void setAdresaClient(const string &adresaClient);


    std::vector<string> search(const string &query);

    void listCarti(const string &query);


};



#endif //OOPTESTING_LIBRARIE_H
