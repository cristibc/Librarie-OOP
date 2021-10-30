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

    void search(string query) {
        int nrCarti = this->listaCarti.size();
        for (int i = 0; i < nrCarti; i++)
            if (query = listaCarti[i])
                std::cout << "Cartea a fost identificata in stoc" << std::endl;
            else std::cout << "Cartea nu a fost identificata in stoc" << std::endl;
    }



};

class Autor {
private:
    string nume, gen, limba;
    int varsta;

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

    void findLike() {
        int nrCarti = this->listaCarti.size();
        for (int i = 0; i < nrCarti; i++) {
            if (getGen() == getGen(i))
                std::cout << "Am mai gasit o carte din genul cautat: " << std::endl;
        }
        std::cout << "Nu am gasit nici o carte de genul acesta" << std::endl;
    }
};

class Librarie {
private:
    std::vector<Carte> listaCarti;
    std::vector<Autor> listaAutori;
    string numeClient;
    int adresaClient;

public:

    Librarie(const std::vector<Carte> &listaCarti, const std::vector<Autor> &listaAutori, const string &numeClient,
             int adresaClient) : listaCarti(listaCarti), listaAutori(listaAutori), numeClient(numeClient),
                                 adresaClient(adresaClient) {}

    void adaugare_carte(Carte &carte) {
        listaCarti.push_back(carte);
    }

    void adaugare_autor(Autor &autor) {
        listaAutori.push_back(autor);
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

    void stocCarti() {
        std::cout << "In librarie poti gasi: " << this->listaCarti.size() << " carti.";

    }

};


int main() {
    Carte carte1("Verity", "Colleen Hoover", "Epic", 293, 2018, 45);
    Carte carte2("Harry Potter 1", "J.K. Rowling", "Arthur", 260, 1997, 30);
    Carte carte3("Stapanul Inelelor 1", "J.R.R Tolkien", "RAO", 640, 1954, 55)
    Carte carte3("Stapanul Inelelor 2", "J.R.R Tolkien", "RAO", 352, 1954, 50)
    Carte carte3("Stapanul Inelelor 3", "J.R.R Tolkien", "RAO", 416, 1955, 56)
    Carte carte4("Harry Potter 2", "J.K. Rowling", "Arthur", 310, 1998, 32);
    Carte carte5("Harry Potter 3", "J.K. Rowling", "Arthur", 350, 1999, 33);
    Carte carte6("Harry Potter 4", "J.K. Rowling", "Arthur", 420, 2000, 36);

    Carte search("Harry Potter");
    carte1.findLike();

}
