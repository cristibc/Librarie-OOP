#include <iostream>
#include <vector>
#include <memory>

using std::string;

class Carte {
private:
    string nume, autor, editura;
    int nrPagini;
    int anPublicare;
    int pret;

// Clasa de baza a cartilor
public:
    Carte(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare, int pret)
            : nume(nume), autor(autor), editura(editura), nrPagini(nrPagini), anPublicare(anPublicare), pret(pret) {}

    const string &getNume() const {
        return nume;
    }

    const string &getAutor() const {
        return autor;
    }

    const string &getEditura() const {
        return editura;
    }

    int getNrPagini() const {
        return nrPagini;
    }

    int getAnPublicare() const {
        return anPublicare;
    }

    int getPret() const {
        return pret;
    }

    void setNume(const string &nume) {
        Carte::nume = nume;
    }

    void setAutor(const string &autor) {
        Carte::autor = autor;
    }

    void setEditura(const string &editura) {
        Carte::editura = editura;
    }

    void setNrPagini(int nrPagini) {
        Carte::nrPagini = nrPagini;
    }

    void setAnPublicare(int anPublicare) {
        Carte::anPublicare = anPublicare;
    }

    void setPret(int pret) {
        Carte::pret = pret;
    }

    friend std::ostream &operator<<(std::ostream &os, const Carte &carte) {
        os << "Numele cartii: " << carte.nume << ", Autor: " << carte.autor << " Editura: " << carte.editura
           << ", Numar Pagini: "
           << carte.nrPagini << ", Anul Publicarii: " << carte.anPublicare << ", Pret: " << carte.pret << " lei"
           << std::endl;
        return os;
    }

    Carte(const Carte &copie) {
        this->nume = copie.nume;
        this->autor = copie.autor;
        this->editura = copie.editura;
        this->nrPagini = copie.nrPagini;
        this->anPublicare = copie.anPublicare;
        this->pret = copie.pret;

    }

    Carte &operator=(const Carte &copie) {
        this->nume = copie.nume;
        this->autor = copie.autor;
        this->editura = copie.editura;
        this->nrPagini = copie.nrPagini;
        this->anPublicare = copie.anPublicare;
        this->pret = copie.pret;
    }

// Destructorul
    ~Carte() {}

};

// Clasa mostenita din Carte
class ComicBook : public Carte {
public:
    ComicBook(const string &nume, const string &autor, const string &editura, int nrPagini, int anPublicare, int pret)
            : Carte(nume, autor, editura, nrPagini, anPublicare, pret) {}


};

// Clasa de plasare a comenzilor cu functii complexe, smart pointeri, exceptii
class Order {
private:
    int pret;
    int id_order;
    std::vector<std::shared_ptr<Carte>> lista_order;


public:
    Order(int pret, int idOrder, const std::vector<std::shared_ptr<Carte>> &listaOrder) : pret(pret), id_order(idOrder),
                                                                                          lista_order(listaOrder) {}

    int getPret() const {
        return pret;
    }

    void setPret(int pret) {
        Order::pret = pret;
    }

    int getIdOrder() const {
        return id_order;
    }

    void setIdOrder(int idOrder) {
        id_order = idOrder;
    }

    const std::vector<std::shared_ptr<Carte>> &getListaOrder() const {
        return lista_order;
    }

    void setListaOrder(const std::vector<std::shared_ptr<Carte>> &listaOrder) {
        lista_order = listaOrder;
    }

    void comanda_pret() {

        for (int i = 0; i < lista_order.size(); i++)
            pret_total = pret_total + lista_order.at(i)->getPret();
        this->pret = pret_total;
    }

    void adaugareCarte(std::shared_ptr<Carte> carteComandata) {
        lista_order.push_back(carteComandata);
        std::cout << "La comanda ati adaugat: " << carteComandata->getNume() << std::endl;
    }

    void plasareComanda(int suma) {
        std::cout << "Pretul total al comenzii este: " << pret_total << std::endl;
        if (suma >= pret_total)
            std::cout << "Comanda a fost plasata cu succes" << std::endl;
        else
            throw "Pretul comenzii depaseste suma platita";
    }

    static int pret_total;

};

int Order::pret_total;

// Clasa cu functii pentru listarea si gasirea membrilor din clasa Carte
class Librarie {
private:
    string numeClient;
    string adresaClient;
    std::vector<std::shared_ptr<Carte>> &carte;

public:

    Librarie(const string &numeClient, const string &adresaClient, std::vector<std::shared_ptr<Carte>> &carte)
            : numeClient(numeClient), adresaClient(adresaClient), carte(carte) {}


    const string &getNumeClient() const {
        return numeClient;
    }

    void setNumeClient(const string &numeClient) {
        Librarie::numeClient = numeClient;
    }

    void setAdresaClient(const string &adresaClient) {
        Librarie::adresaClient = adresaClient;
    }


    void search(std::string query) {
        for (int i = 0; i < carte.size(); i++) {
            if (carte[i]->getNume() == query) {
                std::cout << query << " a fost gasita." << std::endl;
                return;
            }
        }
        std::cout << "Cartea nu a fost gasita" << std::endl;
    }

    void listCarti(std::string query) {
        std::cout << "Cartile autorului: " << query << " din libraria noastra sunt:" << std::endl;
        for (int i = 0; i < carte.size(); i++) {
            if (carte[i]->getAutor() == query) {
                std::cout << carte[i]->getNume() << std::endl;
            }
        }
        std::cout << "--------------" << std::endl;
    }


};

// Design pattern - builder

class abonament {
    string nume;
    int pret_abonament;
    int reducere;
    int carti_gratuite;
    string produse_exclusive;

    friend class abonament_builder;

public:
    abonament() = default;


    friend std::ostream &operator<<(std::ostream &os, const abonament &abonament);
};

class abonament_builder {
private:
    abonament a;
public:
    abonament_builder() = default;

    abonament_builder &nume(const char *nume) {
        a.nume = nume;
        return *this;
    }

    abonament_builder &pret_abonament(int pret) {
        a.pret_abonament = pret;
        return *this;
    }

    abonament_builder &reducere(int reducere) {
        a.reducere = reducere;
        return *this;
    }

    abonament_builder &carti_gratuite(int nr) {
        a.carti_gratuite = nr;
        return *this;
    }

    abonament_builder &produse_exclusive(const char *produse) {
        a.produse_exclusive = produse;
        return *this;
    }

    abonament build() {
        return a;

    }

};

std::ostream &operator<<(std::ostream &os, const abonament &abonament) {
    os << "Nume abonament: " << abonament.nume << ", Pretul abonamentului: " << abonament.pret_abonament
       << ", Reducere articole: "
       << abonament.reducere << "%" << ", Numar carti gratuite: " << abonament.carti_gratuite << ", Produse exclusive: "
       << abonament.produse_exclusive << std::endl;
    return os;
}


// Design pattern - factory

class pachetPromo {
    string nume;
    int reducere;
    string serie;
    string tip_cover;

public:
    pachetPromo(const string &nume, int reducere, const string &serie, const string &tipCover) : nume(nume),
                                                                                                 reducere(reducere),
                                                                                                 serie(serie),
                                                                                                 tip_cover(tipCover) {}

    friend std::ostream &operator<<(std::ostream &os, const pachetPromo &promo) {
        os << "Numele promotiei: " << promo.nume << ", Reducere pachet: " << promo.reducere << "%"
           << ", Serie inclusa: " << promo.serie << ", Tip Cover: "
           << promo.tip_cover << std::endl;
        return os;
    }
};

class pachetPromo_factory {
public:
    static pachetPromo got() { return pachetPromo("Winter is coming", 20, "A Song of Ice and Fire", "Hardcover"); }

};

//Main-ul unde sunt apelate toate functiile

int main() {
    Carte carte1("The Hobbit", "J.R.R Tolkien", "RAO", 350, 2017, 45);
    Carte carte2("Harry Potter 1", "J.K. Rowling", "Arthur", 260, 1997, 30);
    Carte carte3("Stapanul Inelelor 1", "J.R.R Tolkien", "RAO", 640, 1954, 55);
    Carte carte4("Harry Potter 2", "J.K. Rowling", "Arthur", 310, 1998, 32);
    Carte carte5("Harry Potter 3", "J.K. Rowling", "Arthur", 350, 1999, 33);
    Carte carte6("Harry Potter 4", "J.K. Rowling", "Arthur", 420, 2000, 36);
    std::cout << carte1;

    ComicBook comic1("Spider-Man 1", "Stan Lee", "Marvel", 30, 2011, 47);
    ComicBook comic2("SuperMan 1", "Stan Lee", "Marvel", 35, 2015, 52);
    ComicBook comic3("Batman Returns", "Stan Lee", "Marvel", 55, 2013, 70);
    std::cout << comic1;

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
    catch (const char *Exceptie) {
        std::cout << "Exceptie: " << Exceptie << std::endl;
    }

    abonament_builder b;
    abonament d = b.pret_abonament(10).reducere(5).carti_gratuite(2).produse_exclusive("Breloc special").nume(
            "Silver Tier").build();
    std::cout << d;

    pachetPromo g = pachetPromo_factory::got();
    std::cout << g;

    Librarie lib1("Cristi", "Bucuresti", carti);
    lib1.search("Harry Potter 3");
    lib1.listCarti("J.K. Rowling");


}

