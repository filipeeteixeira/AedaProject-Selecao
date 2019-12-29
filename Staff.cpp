#include <tuple>
#include "Staff.h"


Staff::Staff(string nm, string dNas, string fnc, int s,string cntr){
    this->nome=nm;
    this->funcao=fnc;
    this->dNascimento=dNas;
    this->salario=s;
    this->contrato=cntr;
}

ostream& operator<<(ostream& out, Staff& stf)
{
	out << "Nome :" + stf.getNome() << endl << "Data Nascimento: " << stf.getDNascimento() << endl << "Funcao: "
	<< stf.getFuncao() << endl << "Salario: " << to_string(stf.getSalario()) << endl << "Contrato: " << stf.getContrato() << endl;
	return out;
}

Selecionador::Selecionador(string nm, string dNas, string fnc, int s,string cntr, int tG, vector<tuple<string, Date>> sel):Staff( nm, dNas, fnc, s,cntr) {
    this->titulosGanhos=tG;
    this->selecoes=sel;
}

void Selecionador::getInfo() {
    cout << endl << "Nome: " << this->getNome() << endl <<  "Titulos Ganhos: " << this->titulosGanhos << endl;
    cout << "Contrato: " << this->getContrato() << endl;
    cout << "Salario: " << this->getSalario() << endl;
    cout << "Selecoes " << endl;
    for (size_t i=0;i<this->selecoes.size();i++){
        cout << get<0>(this->selecoes[i]) << " - " << get<1>(this->selecoes[i]);
    }

}

ostream &operator<<(ostream &out, Selecionador *sl1) {
    out << "Nome: " << sl1->getNome() << "\n" <<  "Titulos Ganhos: " << to_string(sl1->titulosGanhos) << "\n";
    return out;
}

bool Selecionador::operator<(const Selecionador *sl1) const {
    if (this->titulosGanhos==sl1->titulosGanhos){
        return getNome() < sl1->getNome();
    }
    return this->titulosGanhos<sl1->titulosGanhos;
}
