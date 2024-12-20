#include "lista.h"

using namespace std;

int main() {
    Lista** P;
    Lista obj;
    string nome, tipo, raca;
    int idade, op;
    bool achei;

    P = new Lista*[2];
    P[0] = NULL;
    P[1] = NULL;

    do {
        system("clear");
        cout << "############ MENU ##############\n\n";
        cout << "1 - Cadastrar Pet\n";
        cout << "2 - Excluir Pet\n";
        cout << "3 - Listagem Geral\n";
        cout << "4 - Listagem de cães\n";
        cout << "5 - Listagem de gatos\n";
        cout << "6 - Pesquisar\n";
        cout << "7 - Sair\n";
        cout << "Escolha a opção: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Digite o nome do pet: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o tipo do pet (Cão/Gato): ";
                getline(cin, tipo);
                cout << "Digite a idade do pet: ";
                cin >> idade;
                cout << "Digite a raça do pet: ";
                cin.ignore();
                getline(cin, raca);
                P = obj.Inserir(P, nome, tipo, idade, raca);
                cout << "Pet cadastrado com sucesso!\n";
                break;

            case 2:
                cout << "Digite o nome do pet a ser excluído: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o tipo do pet (Cão/Gato): ";
                getline(cin, tipo);
                P = obj.Remover(P, nome, tipo, &achei);
                if (achei) {
                    cout << "Pet excluído com sucesso!\n";
                } else {
                    cout << "Pet não encontrado!\n";
                }
                break;

            case 3:
                cout << "Listagem Geral de Pets:\n";
                obj.ListarGeral(P);
                break;

            case 4:
                cout << "Listagem de Cães:\n";
                obj.ListarCaes(P);
                break;

            case 5:
                cout << "Listagem de Gatos:\n";
                obj.ListarGatos(P);
                break;

            case 6:
                cout << "Digite o nome do pet: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o tipo do pet (Cão/Gato): ";
                getline(cin, tipo);
                obj.Pesquisar(P, nome, tipo);
                break;

            case 7:
                cout << "Saindo do programa...\n";
                break;

            default:
                cout << "Opção inválida!\n";
                break;
        }

        cout << "Tecle Enter para continuar!";
        cin.ignore().get();
    } while (op != 7);

    return 0;
}
