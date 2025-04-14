#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct Pessoa{
    string nome;
    int chave;
    Pessoa(){
        nome = "";
        chave = 0;
    }
};

class Hash{
private:
    int tamanho;
    Pessoa **pessoas;
public:
    Hash(int tamanho){
        this->tamanho = tamanho;
        pessoas = new Pessoa*[10];
        for(int i = 0; i < 10; i++){
            pessoas[i] = new Pessoa[tamanho/10];
        }
    }
    ~Hash(){
        for(int i = 0; i < 10; i++){
            delete[] pessoas[i];
        }
        delete[] pessoas;
    }
    int funcaoHash1(int chave){
        return chave % 10;
    }
    int funcaoHash2(int chave){
        return chave % tamanho/10;
    }
    void inserir(int chave, string nome){
        int pos1 = funcaoHash1(chave);
        int pos2 = funcaoHash2(chave);
        if(pessoas[pos1][pos2].chave == 0){
            pessoas[pos1][pos2].chave = chave;
            pessoas[pos1][pos2].nome = nome;
            cout << "Pessoa inserida!" << endl;
            return;
        }
        cout << "Posicao ocupada" << endl;
    }
    void remover(int chave){
        int pos1 = funcaoHash1(chave);
        int pos2 = funcaoHash2(chave);
        if(pessoas[pos1][pos2].chave == chave){
            pessoas[pos1][pos2].chave = 0;
            pessoas[pos1][pos2].nome = "";
            cout << "Pessoa removida!" << endl;
            return;
        }
        cout << "Pessoa nao encontrada!" << endl;
    }
    void buscar(int chave){
        int pos1 = funcaoHash1(chave);
        int pos2 = funcaoHash2(chave);
        if(pessoas[pos1][pos2].chave == chave){
            cout << "Pessoa encontrada!" << endl;
            cout << "Nome: " << pessoas[pos1][pos2].nome << endl;
            return;
        }
        cout << "Pessoa nao encontrada!" << endl;
    }
};

int main(){
    Hash hash(100);
    hash.inserir(1383, "Lucas");
    hash.inserir(22948, "Joao");
    hash.inserir(24829, "Joao");
    hash.inserir(3584, "Maria");
    hash.inserir(4222, "Ana");
    hash.inserir(5384, "Pedro");
    hash.inserir(629, "Paulo");
    hash.inserir(7443, "Carlos");
    hash.inserir(82, "Fernanda");
    hash.inserir(9, "Juliana");
    hash.inserir(10, "Roberto");

    hash.buscar(1383);
    hash.buscar(22948);
    return 0;
}