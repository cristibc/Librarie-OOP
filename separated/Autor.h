//
// Created by thege on 13.12.2021.
//

#ifndef BOOKSHOPOOP_AUTOR_H
#define BOOKSHOPOOP_AUTOR_H
#include <iostream>
#include <vector>
using std::string;

class Autor {
private:
    string nume, gen, limba;
    int varsta;



public:
    Autor(const string &nume, const string &gen, const string &limba, int varsta);

    Autor(const Autor &copie);


    const string &getNume() const;

    const string &getGen() const;

    int getVarsta() const;

    const string &getLimba() const;


    friend std::ostream &operator<<(std::ostream &os, const Autor &autor);

    Autor &operator=(const Autor &copie);



};


#endif //BOOKSHOPOOP_AUTOR_H
