#include <iostream>
#include <vector>

using std::string;

class Carte {
private:
    string nume, autor, editura;
    int nrPagini;
    int anPublicare;
    int pret;

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

    ~Carte() {
        std::cout << "A fost apelat destructorul" << std::endl;
    }


    void adaugareCarte(int counter) {
        string nume, autor, editura;
        int nrPagini;
        int anPublicare;
        int pret;
    }

        std::cout<<"Se introduce o carte noua in sistem..."<<std::endl;
        std::cout<<"Introduceti numele cartii: ";
        getline(std::cin,nume);
        carte[counter].setNume(nume);
        std::cout<<"Introduceti numele autorului: ";
        getline(std::cin, autor);
        carte[counter].setAutor(autor);
        std::cout<<"Introduceti numele editurii: ";
        getline(std::cin, editura);
        carte[counter].setEditura(editura);
        std::cout<<"Introduceti numarul de pagini: ";
        getline(std::cin, nrPagini);
        carte[counter].

    }



};

class Autor {
private:
    string nume, gen, limba;
    int varsta;
    std::vector<Carte> carti;

public:
    Autor(const string &nume, const string &gen, const string &limba, int varsta) : nume(nume), gen(gen), limba(limba),
                                                                                    varsta(varsta) {}

    Autor(const Autor &copie) {
        this->nume = copie.nume;
        this->gen = copie.gen;
        this->varsta = copie.varsta;
        this->limba = copie.limba;
    }


    const string &getNume() const {
        return nume;
    }

    const string &getGen() const {
        return gen;
    }

    int getVarsta() const {
        return varsta;
    }

    const string &getLimba() const {
        return limba;
    }


    friend std::ostream &operator<<(std::ostream &os, const Autor &autor) {
        os << "Nume autor: " << autor.nume << ", Genul: " << autor.gen << ", Varsta autorului: " << autor.varsta
           << ", Limba: "
           << autor.limba << std::endl;
        return os;
    }

    Autor &operator=(const Autor &copie) {
        this->nume = copie.nume;
        this->gen = copie.gen;
        this->varsta = copie.varsta;
        this->limba = copie.limba;
    }

    void search(std::string query){
        for (int i=0; i<carte.size(); i++)
            if(carte[i].getNume() == query)
                std::cout<<query<<" a fost gasita.";
            else std::cout<<"Cartea nu a fost gasita";

    }

};

class Librarie {
private:
    string numeClient;
    int adresaClient;
    std::vector<Carte> carte;

public:

    Librarie(const string &numeClient, int adresaClient, const std::vector<Carte> &carte) : numeClient(numeClient),
                                                                                            adresaClient(adresaClient),
                                                                                            carte(carte) {}

    void adaugare_carte(Carte &nume) {
        carte.push_back(nume);
    }


    const string &getNumeClient() const {
        return numeClient;
    }

    void setNumeClient(const string &numeClient) {
        Librarie::numeClient = numeClient;
    }

    int getAdresaClient() const {
        return adresaClient;
    }

    void setAdresaClient(int adresaClient) {
        Librarie::adresaClient = adresaClient;
    }





};


int main() {
    Carte carte1("Verity", "Colleen Hoover", "Epic", 293, 2018, 45);
    Carte carte2("Harry Potter 1", "J.K. Rowling", "Arthur", 260, 1997, 30);
    Carte carte3("Stapanul Inelelor 1", "J.R.R Tolkien", "RAO", 640, 1954, 55);
    Carte carte4("Harry Potter 2", "J.K. Rowling", "Arthur", 310, 1998, 32);
    Carte carte5("Harry Potter 3", "J.K. Rowling", "Arthur", 350, 1999, 33);
    Carte carte6("Harry Potter 4", "J.K. Rowling", "Arthur", 420, 2000, 36);
    carte1.search("Harry Potter");


}
