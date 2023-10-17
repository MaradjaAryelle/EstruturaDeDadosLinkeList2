#include <iostream>

using namespace std;

struct No {
    int data;
    No* prev;
    No* next;
};

void inserir(No*& head, int value) {
    No* novoNo = new No;
    novoNo->data = value;
    novoNo->prev = NULL;
    novoNo->next = NULL;

    if (!head) {
        head = novoNo;
    } else {
        No* temporario = head;
        while (temporario->next) {
            temporario = temporario->next;
        }
        temporario->next = novoNo;
        novoNo->prev = temporario;
    }
}

int encontrarMaior(No* head) {
    if (!head) {
        cout << "A lista esta vazia!" << endl;
        return -1; 
    }

    int maior = head->data;
    No* temporario = head;

    while (temporario) {
        if (temporario->data > maior) {
            maior = temporario->data;
        }
        temporario = temporario->next;
    }

    return maior;
}

int main() {
    No* head = NULL;
	int opcao = -1;
	
    inserir(head, 10);
    inserir(head, 11);
    inserir(head, 12);
    inserir(head, 13);
    inserir(head, 14);
    inserir(head, 15);
   
	while (opcao != 0) {
        cout << "\n3. Escreva um programa que encontre o maior nó em uma lista duplamente encadeada.\n";
        cout << "4. Escreva um programa que recebe uma lista duplamente encadeada e ordena ela utilizando o Merge Sort.\n";
        cout << "0. Sair\n";
        cout << "Digite o numero da questao escolhida: ";
        cin >> opcao;
    
	    switch (opcao) {
            case 3:{
                int maior = encontrarMaior(head);
    			cout << "O maior valor na lista eh: " << maior << endl;
                break;
            }
           /* case 4:{
        NAO CONSEGUI FAZER. E PESQUISANDO COMO FAZ AINDA ACHEI CONFUSO, ACHEI MELHOR NAO BOTAR
				break;
			}*/

            case 0: {
                cout << "Tchau\n";
                break;
        	}
            default: {
                cout << "Opcao invalida!\n";
                break;
        	}
		}
    }
}
