#include <iostream>
#include <string>

class Lista {
private:
    std::string nomePet, tipoPet, racaPet;
    int idadePet;
    Lista *anterior, *proximo;
public:
    Lista** Inserir(Lista**, std::string, std::string, int, std::string);
    void ListarGeral(Lista**);
    void ListarCaes(Lista**);
    void ListarGatos(Lista**);
    Lista** Remover(Lista**, std::string, std::string, bool*);
    void Pesquisar(Lista**, std::string, std::string);
    Lista** Esvaziar(Lista**);
};

