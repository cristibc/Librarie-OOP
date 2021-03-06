// Proiect OOP - Borcan Cristian-Bogdan - 262 CTI FMI UB

#include <iostream>
#include <vector>
#include <exception>
#include <memory>
#include "Carte.h"
#include "ComicBook.h"
#include "Order.h"
#include "Abonament.h"
#include "PachetPromo.h"
#include "Librarie.h"
#include "Review.h"

using std::string;


//Main-ul unde sunt apelate toate functiile

int main() {
    Carte carte1("The Hobbit", "J.R.R Tolkien", "RAO", 350, 2017, 45);
    Carte carte2("Harry Potter 1", "J.K. Rowling", "Arthur", 260, 1997, 30);
    Carte carte3("Stapanul Inelelor 1", "J.R.R Tolkien", "RAO", 640, 1954, 55);
    Carte carte4("Harry Potter 2", "J.K. Rowling", "Arthur", 310, 1998, 32);
    Carte carte5("Harry Potter 3", "J.K. Rowling", "Arthur", 350, 1999, 33);
    Carte carte6("Harry Potter 4", "J.K. Rowling", "Arthur", 420, 2000, 36);
    std::cout << carte1;
    carte1.Timp(2);

    ComicBook comic1("Spider-Man 1", "Stan Lee", "Marvel", 30, 2011, 47);
    ComicBook comic2("SuperMan 1", "Stan Lee", "Marvel", 35, 2015, 52);
    ComicBook comic3("Batman Returns", "Stan Lee", "Marvel", 55, 2013, 70);
    std::cout << comic1;
    comic1.Timp(2);


    std::vector<std::shared_ptr<Carte>> carti;
    carti.push_back(std::make_shared<Carte>(carte1));
    carti.push_back(std::make_shared<Carte>(carte2));
    carti.push_back(std::make_shared<Carte>(carte3));
    carti.push_back(std::make_shared<Carte>(carte4));
    carti.push_back(std::make_shared<Carte>(carte5));
    carti.push_back(std::make_shared<Carte>(carte6));


    try {
        std::vector<std::shared_ptr<Carte>> cartiComenzi;
        Order order1(80, 1, cartiComenzi);
        order1.adaugareCarte(std::make_shared<Carte>(carte1));
        order1.adaugareCarte(std::make_shared<Carte>(carte2));
        order1.comanda_pret();
        order1.plasareComanda(20);
    }

catch (const std::exception& e){
    std::cout<<e.what();
};
    std::cout << std::endl;

    abonament_builder b;
    abonament d = b.pret_abonament(10).reducere(5).carti_gratuite(2).produse_exclusive("Breloc special").nume(
            "Silver Tier").build();
    std::cout << d;

    std::cout << std::endl;

    Carte g = factory::got();
    Carte h = factory::hg();
    Carte v = factory::dv();

    std::cout<<g;
    std::cout<<h;
    std::cout<<v;

    std::cout << std::endl;

    Librarie lib1("Cristi", "Bucuresti", carti);
    lib1.search("Harry Potter 3");
    lib1.listCarti("J.K. Rowling");

    Review r1("Harry Potter 3", carti);
    r1.addReview("Este o carte foarte buna");
    r1.addReview(4);
    r1.addReview(8.9);

    r1.addReview(6);
    r1.addReview(12.5);

    Review r2("Carte Inexistenta", carti);
    r2.addReview("Mi-a placut foarte mult");
}

