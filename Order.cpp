//
// Created by thege on 18.12.2021.
//

#include "Order.h"

Order::Order(int pret, int idOrder, const std::vector<std::shared_ptr<Carte>> &listaOrder) : pret(pret), id_order(idOrder),
                                                                                             lista_order(listaOrder) {}

int Order::getPret() const {
    return pret;
}

void Order::setPret(int pret) {
    Order::pret = pret;
}

int Order::getIdOrder() const {
    return id_order;
}

void Order::setIdOrder(int idOrder) {
    id_order = idOrder;
}

const std::vector<std::shared_ptr<Carte>> &Order::getListaOrder() const {
    return lista_order;
}

void Order::setListaOrder(const std::vector<std::shared_ptr<Carte>> &listaOrder) {
    lista_order = listaOrder;
}

void Order::comanda_pret() {

    for (int i = 0; i < lista_order.size(); i++)
        pret_total = pret_total + lista_order.at(i)->getPret();
    this->pret = pret_total;
}

void Order::adaugareCarte(std::shared_ptr<Carte> carteComandata) {
    lista_order.push_back(carteComandata);
    std::cout << "La comanda ati adaugat: " << carteComandata->getNume() << std::endl;
}

void Order::plasareComanda(int suma) {
    std::cout << "Pretul total al comenzii este: " << pret_total << std::endl;
    if (suma >= pret_total)
        std::cout << "Comanda a fost plasata cu succes" << std::endl;
    else
        throw "Pretul comenzii depaseste suma platita";
}

int Order::pret_total;
