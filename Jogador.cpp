#include "Jogador.h"



Jogador::Jogador(string n,string p,string c,string num){
    this->numero = num;
    this->posicao = p;
    this->clube = c;
    this->nome = n;
}
void Jogador::getInfo() {
	cout << endl << "Nome: " << this->nome << endl <<  "Posicao: " << posicao << endl << "Clube: " << clube << endl << "Numero: " << numero << endl;
}

string Jogador::getPosicao() const
{
	return posicao;
}

string Jogador::getNome() const
{
	return nome;
}

string Jogador::getClube() const
{
	return clube;
}

JogadorSelecao::JogadorSelecao(string n, string p, string c, string num, string peso, string altura, string dn,double vp):Jogador(n,p,c,num) {
    this->dNascimento =dn;
    this->altura = altura;
    this->peso = peso;
    this->valorPasse=vp;
}
void JogadorSelecao::setPeso(string p)
{
	this -> peso = p;
}
void JogadorSelecao::setAltura(string h)
{
	this->altura = h;
}
void JogadorSelecao::setPasse(double vp)
{
	this->valorPasse = vp;
}

void JogadorSelecao::getInfo() {
    Jogador::getInfo();
	cout << "Peso:" << peso << "  Altura:" << altura << "  Data Nascimento: " << dNascimento << "  Valor Passe:" << valorPasse << "M" << endl;
	cout << endl;
}
double JogadorSelecao::getPasse() {
    return this->valorPasse;
}

string JogadorSelecao::getPeso()
{
	return peso;
}

string JogadorSelecao::getAltura()
{
	return altura;
}

string JogadorSelecao::getDNas()
{
	return dNascimento;
}

ostream& operator<<(ostream& out, Jogador* jog)
{
	out << jog->getNome() << " - No " + jog->getNumero() + " - " + jog->getPosicao() + " - " + jog->getClube();
	return out;
}

ostream& operator<<(ostream& out, JogadorSelecao* jog)
{
	out << jog->getNome() << " - No " + jog->getNumero() + " - " + jog->getPosicao() + " - " + jog->getClube();
	return out;
}


