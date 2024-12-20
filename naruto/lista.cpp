#include "lista.h"

Lista** Lista::Inserir(Lista** R, std::string nome, std::string tipo, int idade, std::string raca) {
    Lista* novo = new Lista();
    novo->nomePet = nome;
    novo->tipoPet = tipo;
    novo->idadePet = idade;
    novo->racaPet = raca;
    novo->anterior = nullptr;
    novo->proximo = nullptr;

    // Verificando se a lista está vazia
    if (R[0] == nullptr) {
        R[0] = novo;
        R[1] = novo;
    } else {
        Lista* atual = R[0];
        Lista* anterior = nullptr;
        // Encontrando a posição correta para inserção
        while (atual != nullptr && (atual->nomePet < nome || (atual->nomePet == nome && atual->tipoPet == "Gato"))) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == nullptr) {
            novo->proximo = R[0];
            R[0]->anterior = novo;
            R[0] = novo;
        } else if (atual == nullptr) {
            anterior->proximo = novo;
            novo->anterior = anterior;
            R[1] = novo;
        } else {
            anterior->proximo = novo;
            novo->anterior = anterior;
            novo->proximo = atual;
            if (atual != nullptr) {
                atual->anterior = novo;
            }
        }
    }
    return R;
}

void Lista::ListarGeral(Lista** R) {
    Lista* aux = R[0];
    if (aux == nullptr) {
        std::cout << "Nenhum pet cadastrado.\n";
        return;
    }
    while (aux != nullptr) {
        std::cout << aux->nomePet << " - " << aux->tipoPet << " - " << aux->idadePet << " anos - " << aux->racaPet << "\n";
        aux = aux->proximo;
    }
}

void Lista::ListarCaes(Lista** R) {
    Lista* aux = R[0];
    if (aux == nullptr) {
        std::cout << "Nenhum pet cadastrado.\n";
        return;
    }
    while (aux != nullptr) {
        if (aux->tipoPet == "Cão") {
            std::cout << aux->nomePet << " - " << aux->tipoPet << " - " << aux->idadePet << " anos - " << aux->racaPet << "\n";
        }
        aux = aux->proximo;
    }
}

void Lista::ListarGatos(Lista** R) {
    Lista* aux = R[0];
    if (aux == nullptr) {
        std::cout << "Nenhum pet cadastrado.\n";
        return;
    }
    while (aux != nullptr) {
        if (aux->tipoPet == "Gato") {
            std::cout << aux->nomePet << " - " << aux->tipoPet << " - " << aux->idadePet << " anos - " << aux->racaPet << "\n";
        }
        aux = aux->proximo;
    }
}

Lista** Lista::Remover(Lista** R, std::string nome, std::string tipo, bool* achei) {
    Lista* atual = R[0];
    Lista* anterior = nullptr;

    while (atual != nullptr && (atual->nomePet != nome || atual->tipoPet != tipo)) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        *achei = false;
        return R;
    }

    *achei = true;
    if (atual == R[0] && R[0] != R[1]) {
        R[0] = atual->proximo;
        R[0]->anterior = nullptr;
    } else if (atual == R[0] && R[0] == R[1]) {
        R[0] = nullptr;
        R[1] = nullptr;
    } else if (atual == R[1]) {
        R[1] = anterior;
        R[1]->proximo = nullptr;
    } else {
        anterior->proximo = atual->proximo;
        if (atual->proximo != nullptr) {
            atual->proximo->anterior = anterior;
        }
    }

    delete atual;
    return R;
}

void Lista::Pesquisar(Lista** R, std::string nome, std::string tipo) {
    Lista* aux = R[0];
    while (aux != nullptr) {
        if (aux->nomePet == nome && aux->tipoPet == tipo) {
            std::cout << "Pet encontrado:\n";
            std::cout << aux->nomePet << " - " << aux->tipoPet << " - " << aux->idadePet << " anos - " << aux->racaPet << "\n";
            return;
        }
        aux = aux->proximo;
    }
    std::cout << "Pet não cadastrado.\n";
}

Lista** Lista::Esvaziar(Lista** R) {
    Lista* aux = R[0];
    while (aux != nullptr) {
        R[0] = R[0]->proximo;
        delete aux;
        aux = R[0];
    }
    R[0] = nullptr;
    R[1] = nullptr;
    return R;
}
