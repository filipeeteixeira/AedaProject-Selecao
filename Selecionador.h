//
// Created by filip on 27/12/2019.
//

#ifndef CODIGO_SELECIONADOR_H
#define CODIGO_SELECIONADOR_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include "Date.h"

using namespace std;

class Selecionador{
    string nome;
    unsigned int titulosGanhos;
    vector<tuple<string,Date>> selecoes;
public:
    Selecionador(string n, unsigned int titulosGanhos, vector<tuple<string,Date>> s);
    void getInfo();
    friend ostream& operator<<(ostream& out, Selecionador* sl1);
    bool operator<(Selecionador * sl1);
};


#endif //CODIGO_SELECIONADOR_H
