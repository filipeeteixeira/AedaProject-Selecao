//
// Created by Utilizador on 02/01/2020.
//

#include "Fornecedor.h"

Fornecedor::Fornecedor(string nome, int rep, vector<string> tipos) {
    this->nome = nome;
    this->reputacao = rep;
    this->tiposProduto=tipos;
}
int Fornecedor::compra() {
    cout << "Deseja deixar uma avaliacao?(s/n)" << endl;
    char option;
    cin >> option;
    if (option == 'n')
        return 0;
    else {
        int rating = 0;

        cout << "Esta satisfeito com a compras neste fornecedor?(s/n)" << endl;
        char compras;
        cin >> compras;
        if (compras == 's')
            rating++;
        else rating--;

        cout << "Esta satisfeito com a variedade de produtos deste fornecedor?(s/n)" << endl;
        char variedade;
        cin >> variedade;
        if (variedade == 's')
            rating++;
        else rating--;

        cout << "Esta satisfeito com a rapidez neste fornecedor?(s/n)" << endl;
        char rapidez;
        cin >> rapidez;
        if (rapidez == 's')
            rating++;
        else rating--;

        return rating;
    }
}

bool Fornecedor::stock(string product) {
    for (auto &x: this->tiposProduto) {
        if (product == x)
            return true;
    }
    return false;
}

bool operator<(const Fornecedor &f1, const Fornecedor &f2) {
    return f1.getReputacao() < f2.getReputacao();
}
