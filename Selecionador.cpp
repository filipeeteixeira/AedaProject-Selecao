//
// Created by filip on 27/12/2019.
//
#include "Selecionador.h"

Selecionador::Selecionador(string n, unsigned int tG, vector<tuple<string, Date>> s) {
    this->nome=n;
    this->titulosGanhos=tG;
    this->selecoes=s;
}

void Selecionador::getInfo() {
    cout << endl << "Nome: " << this->nome << endl <<  "Titulos Ganhos: " << this->titulosGanhos << endl;
    cout << "Selecoes: " << endl;
    for (size_t i=0;i<this->selecoes.size();i++){
        cout << get<0>(this->selecoes[i]) << " - " << get<1>(this->selecoes[i]);
    }
}

ostream &operator<<(ostream &out, Selecionador *sl1) {
    out << "Nome: " << sl1->nome << "\n" <<  "Titulos Ganhos: " << to_string(sl1->titulosGanhos) << "\n";
}

bool Selecionador::operator<(Selecionador *sl1) {
    if (this->titulosGanhos==sl1->titulosGanhos){
        return this->nome < sl1->nome;
    }
    return this->titulosGanhos<sl1->titulosGanhos;
}
