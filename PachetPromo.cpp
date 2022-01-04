//
// Created by thege on 18.12.2021.
//

#include "PachetPromo.h"

promoCarti::promoCarti(const string &nume, int reducere, const string &serie, const string &tipCover) : nume(nume),
                                                                                                          reducere(reducere),
                                                                                                          serie(serie),
                                                                                                          tip_cover(tipCover) {}

promoVinyl::promoVinyl(const string &nume, int reducere, const string &album, const string &gen, const string &artist) : nume(nume),
                                                                                                        reducere(reducere),
                                                                                                        album(album),
                                                                                                        gen(gen),
                                                                                                        artist(artist) {}

promoManga::promoManga(const string &nume, int reducere, const string &serie, const string &gen, const string &tipCover) : nume(nume),
                                                                                                        reducere(reducere),
                                                                                                        serie(serie),
                                                                                                        gen(gen),
                                                                                                        tip_coperta(tipCover) {}


std::ostream &operator<<(std::ostream &os, const promoCarti &promoC) {
    os << "Numele promotiei: " << promoC.nume << ", Reducere pachet: " << promoC.reducere << "%"
       << ", Serie inclusa: " << promoC.serie << ", Tip Cover: "
       << promoC.tip_cover << std::endl;
    return os;


}

std::ostream &operator<<(std::ostream &os, const promoVinyl &promoV) {
    os << "Numele promotiei : " << promoV.nume << ",  Reducere pachet: " << promoV.reducere << "%"<< ", Albumul inclus: " << promoV.album << ", Genul: "
       << promoV.gen << ", Artistul/Trupa: "<<promoV.artist << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const promoManga &promoM) {
    os << "Nume Manga: " << promoM.nume << ", Reducere pachet: " << "%" <<promoM.reducere << " Serie: " << promoM.serie << ", Gen: "
       << promoM.gen << ", Tipul Copertei: " << promoM.tip_coperta << std::endl;
    return os;
}
