//
// Created by Utilizador
//

#ifndef UNTITLED_FORNECEDOR_H
#define UNTITLED_FORNECEDOR_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Fornecedor {
    string nome;
    int reputacao;
    vector<string> tiposProduto;
public:
    Fornecedor(string nome, int rep,vector<string> tipos);

    int getReputacao() const {return this->reputacao;};
    void setReputacao(int rep) {this->reputacao = rep;};
    string getNome() const {return this-> nome;};
    int compra();
    bool stock(string product);
    vector<string> getProdutos() {return this-> tiposProduto;};
};

bool operator<(const Fornecedor& f1, const Fornecedor& f2);
#endif //UNTITLED_FORNECEDOR_H
