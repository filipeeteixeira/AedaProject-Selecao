#include "Staff.h"


Staff::Staff(string nm, string dNas, string fnc, int s){
    this->nome=nm;
    this->funcao=fnc;
    this->dNascimento=dNas;
    this->salario=s;
}

ostream& operator<<(ostream& out, Staff* stf)
{
	out << "Nome :" + stf->getNome() << endl << "Data Nascimento: " << stf->getDNascimento() << endl << "Funcao: " << stf->getFuncao() << endl << "Salario: " << to_string(stf->getSalario()) << endl;
	return out;
}
