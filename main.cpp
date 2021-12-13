#include <iostream>
#include <vector>
#include <memory>
#include "Autor.h"
#include "Carte.h"

using std::string;


class Librarie {
private:
    string numeClient;
    string adresaClient;
    std::vector<Carte> carte;

public:

    Librarie(const string &numeClient, const string &adresaClient, const std::vector<Carte> &carte) : numeClient(
            numeClient), adresaClient(adresaClient), carte(carte) {}

    void adaugare_carte(Carte &nume) {
        carte.push_back(nume);
    }


    const string &getNumeClient() const {
        return numeClient;
    }

    void setNumeClient(const string &numeClient) {
        Librarie::numeClient = numeClient;
    }

    void setAdresaClient(const string &adresaClient) {
        Librarie::adresaClient = adresaClient;
    }


    void search(std::string query){
        for (int i=0; i<carte.size(); i++) {
            if (carte[i].getNume() == query) {
                std::cout << query << " a fost gasita."<<std::endl;
                return;
            }
        } std::cout<< "Cartea nu a fost gasita"<<std::endl;
    }

    void listCarti(std::string query){
        std::cout<<"Cartile autorului: "<<query<<" din libraria noastra sunt:"<<std::endl;
        std::cout<<"----------"<<std::endl;
        for (int i=0; i<carte.size(); i++) {
            if(carte[i].getAutor() == query){
                std::cout<<carte[i].getNume()<<std::endl;
            }
        }std::cout<<"----------"<<std::endl;
    }



};


int main() {
    Carte carte1("The Hobbit", "J.R.R Tolkien", "RAO", 350, 2017, 45);
    Carte carte2("Harry Potter 1", "J.K. Rowling", "Arthur", 260, 1997, 30);
    Carte carte3("Stapanul Inelelor 1", "J.R.R Tolkien", "RAO", 640, 1954, 55);
    Carte carte4("Harry Potter 2", "J.K. Rowling", "Arthur", 310, 1998, 32);
    Carte carte5("Harry Potter 3", "J.K. Rowling", "Arthur", 350, 1999, 33);
    Carte carte6("Harry Potter 4", "J.K. Rowling", "Arthur", 420, 2000, 36);
    std::vector<Carte> carti;
    carti.push_back(carte1);
    carti.push_back(carte2);
    carti.push_back(carte3);
    carti.push_back(carte4);
    carti.push_back(carte5);
    carti.push_back(carte6);
    //carti.push_back(carte7);

    Librarie lib1("Cristi", "Bucuresti", carti);
    lib1.search("Harry Potter 3");
    lib1.listCarti("J.K. Rowling");


}