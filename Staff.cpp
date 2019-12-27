#include <tuple>
#include "Staff.h"


Staff::Staff(string nm, string dNas, string fnc, int s){
    this->nome=nm;
    this->funcao=fnc;
    this->dNascimento=dNas;
    this->salario=s;
}

ostream& operator<<(ostream& out, Staff* stf)
{
	out << "Nome :" + stf->getNome() << endl << "Data Nascimento: " << stf->getDNascimento() << endl << "Funcao: "
	<< stf->getFuncao() << endl << "Salario: " << to_string(stf->getSalario()) << endl;
	return out;
}

Selecionador::Selecionador(string nm, string dNas, string fnc, int s, unsigned int tG, vector<tuple<string, Date>> sel):Staff(nm,dNas,fnc,s) {
    this->nome=nm;
    this->titulosGanhos=tG;
    this->selecoes=sel;
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
