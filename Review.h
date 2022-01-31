//
// Created by Chris on 31-Jan-22.
//

#ifndef OOPTESTING_REVIEW_H
#define OOPTESTING_REVIEW_H
#include <iostream>
#include "Carte.h"
#include <vector>

// Am implementat aici un template care poate prelua valori int, double si string
// Si alege pentru fiecare outputul potrivit
template <class T>
class Review{
private:
    T query;
    std::vector<std::shared_ptr<Carte>> carte;

public:
    Review(T query, const std::vector<std::shared_ptr<Carte>> &carte) : query(query), carte(carte) {}

    void addReview(double entry) {
        if(entry<0 || entry >10)
            std::cout<<"Introduceti o nota intre 0 si 10.0!"<<std::endl;
        else{
            for (int i = 0; i < carte.size(); i++) {
                if (carte[i]->getNume() == query) {
                    std::cout << "Ati acordat cu succes nota: " << entry << " din 10.0 pentru produsul selectat!"
                              << std::endl;
                    return;
                }

            }std::cout<<"Produsul nu a fost gasit!"<<std::endl;
        }
    }

    void addReview(string entry) {
        for (int i = 0; i < carte.size(); i++) {
            if (carte[i]->getNume() == query) {
                     std::cout<<"Ati acordat cu succes review-ul: \""<<entry<<"\"!"<<std::endl;
                     return;
            }

        }std::cout<<"Produsul nu a fost gasit!"<<std::endl;
    }

    void addReview(int entry) {
        if(entry<1 || entry >5)
            std::cout<<"Introduceti intre 1 si 5 stele!"<<std::endl;
        else {
            for (int i = 0; i < carte.size(); i++) {
                if (carte[i]->getNume() == query) {
                    if(entry>1){
                        std::cout << "Ati acordat cu succes " << entry << " stele!" << std::endl;
                        return;}
                    else{
                        std::cout <<"Ati acordat cu succes o stea!"<<std::endl;
                        return;
                    }
                }
            } std::cout<<"Produsul nu a fost gasit!"<<std::endl;
        }
    }

    virtual ~Review() {}
};

#endif //OOPTESTING_REVIEW_H
