#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class listasequencial {

private:
  int *dados;
  int tamanhomax;
  int tamanhoatual;

public:
  listasequencial() {
    tamanhoatual = 0;
    tamanhomax = 100;
    dados = new int[tamanhomax];
  }

  // destrutor para liberar memoria
  ~listasequencial(){
    delete[] dados;
  }

  // verifica se a lista esta vazia
  bool vazia() {
    if (tamanhoatual == 0) {
      return true;
    } else {
      return false;
    }
  }
  // verifica se a lista esta cheia
  bool cheia() {
    if (tamanhoatual == tamanhomax) {
      return true;
    } else {
      return false;
    }
  }
  // obtem tamanho atual da lista
  int tamanho() { return tamanhoatual; }

  // obtem valor do elemento 
  int elemento(int pos) {

    int dado;

    if (pos <= 0 || pos > tamanhoatual) {
      return -1;
    }
    dado = dados[pos - 1];
    return dado;
  }

  // altera valor do elemento
  bool setElemento(int pos, int novovalor){
    if (pos <= 0 || pos > tamanhoatual) {
      return false;
    }
    dados[pos - 1] = novovalor;
    return true;
  }

  // obtem posicao do elemento
  int posicao(int dado) {
    for (int i = 0; i < tamanhoatual; i++) {
      if (dados[i] == dado) {
        return i + 1;
      }
    }
    return -1;
  }
  // insere um elemento
  bool inserir(int pos, int dado) {
    if (cheia() || pos > tamanhoatual + 1 || pos <= 0) {
      return false;
    }

    for (int i = tamanhoatual; i >= pos; i--) {
      dados[i] = dados[i - 1];
    }

    dados[pos - 1] = dado;
    tamanhoatual++;
    return true;
  }
  // remove um elemento
  int remover(int pos) {
    int dado;
    if (vazia() || pos > tamanhoatual || pos <= 0) {
      return -1;
    }

    dado = dados[pos - 1];
    for (int i = pos - 1; i < tamanhoatual - 1; i++) {
      dados[i] = dados[i + 1];
    }
    tamanhoatual--;
    return dado;
  }

  // imprime a lista
  void imprimir() {
      if (vazia()) {
          cout << "Lista vazia!" << endl;
          return;
      }

      for (int i = 0; i < tamanhoatual; i++) {
          cout << dados[i] << (i < tamanhoatual - 1 ? " - " : "\n");
      }
  }
};

int main() {
  listasequencial lista;
  int escolha = 0;

  while (escolha != 9) {
    cout << "\nEscolha uma acao:" << endl;
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Verificar se esta vazia" << endl;
    cout << "3 - Verificar se esta cheia" << endl;
    cout << "4 - Obter tamanho" << endl;
    cout << "5 - Modificar um elemento" << endl;
    cout << "6 - Remover elemento" << endl;
    cout << "7 - Exibir lista" << endl;
    cout << "9 - Sair" << endl;
    cout << "Opcao: ";
    cin >> escolha;

    int pos, val;
    bool ok;
    switch (escolha) {
      case 1:
        cout << "Posicao para inserir: "; cin >> pos;
        cout << "Valor a inserir: "; cin >> val;
        ok = lista.inserir(pos, val);
        cout << (ok ? "Inserido com sucesso." : "Falha na insercao.") << endl;
        break;
      case 2:
        cout << (lista.vazia() ? "A lista esta vazia." : "A lista nao esta vazia.") << endl;
        break;
      case 3:
        cout << (lista.cheia() ? "A lista esta cheia." : "A lista nao esta cheia.") << endl;
        break;
      case 4:
        cout << "Tamanho atual: " << lista.tamanho() << endl;
        break;
      case 5:
        cout << "Posicao do elemento a modificar: "; cin >> pos;
        cout << "Novo valor: "; cin >> val;
        ok = lista.setElemento(pos, val);
        cout << (ok ? "Elemento modificado com sucesso." : "Posicao invalida.") << endl;
        break;
      case 6:
        cout << "Posicao do elemento a remover: "; cin >> pos;
        val = lista.remover(pos);
        cout << (val != -1 ? "Elemento removido: " + to_string(val) : string("Falha na remocao. Posicao invalida.")) << endl;
        break;
      case 7:
        cout << "\nConteudo da lista: " << endl; lista.imprimir();
        break;
      case 9:
        cout << "Saindo..." << endl;
        break;
      default:
        cout << "Opcao invalida." << endl;
    }
  }

  return 0;
} 