//
// Created by thege on 18.12.2021.
//

#ifndef OOPTESTING_ORDER_H
#define OOPTESTING_ORDER_H
#include "Carte.h"
#include <memory>
#include <vector>

// Clasa de plasare a comenzilor cu functii complexe, smart pointeri, exceptii
class Order {
private:
    int pret;
    int id_order;
    std::vector<std::shared_ptr<Carte>> lista_order;


public:
    Order(int pret, int idOrder, const std::vector<std::shared_ptr<Carte>> &listaOrder);

    int getPret() const;

    void setPret(int pret);

    int getIdOrder() const;

    void setIdOrder(int idOrder);

    const std::vector<std::shared_ptr<Carte>> &getListaOrder() const;

    void setListaOrder(const std::vector<std::shared_ptr<Carte>> &listaOrder);

    void comanda_pret();

    void adaugareCarte(std::shared_ptr<Carte> carteComandata);

    void plasareComanda(int suma);

    static int pret_total;

};





#endif //OOPTESTING_ORDER_H
