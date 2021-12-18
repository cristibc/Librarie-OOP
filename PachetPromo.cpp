//
// Created by thege on 18.12.2021.
//

#include "PachetPromo.h"

pachetPromo::pachetPromo(const string &nume, int reducere, const string &serie, const string &tipCover) : nume(nume),
                                                                                                          reducere(reducere),
                                                                                                          serie(serie),
                                                                                                          tip_cover(tipCover) {}

std::ostream &operator<<(std::ostream &os, const pachetPromo &promo) {
    os << "Numele promotiei: " << promo.nume << ", Reducere pachet: " << promo.reducere << "%"
       << ", Serie inclusa: " << promo.serie << ", Tip Cover: "
       << promo.tip_cover << std::endl;
    return os;
}
