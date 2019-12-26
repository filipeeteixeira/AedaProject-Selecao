#include "Jogo.h"

Jogo::Jogo(string cidade, string pais, string estadio){
    this->cidade=cidade;
    this->pais=pais;
    this->estadio=estadio;
}

Jogo::Jogo(string nome, string id_conv, string cidade, string pais, string estadio)
{
	this->nome = nome;
	this->id_conv = id_conv;
	this->cidade = cidade;
	this->pais = pais;
	this->estadio = estadio;
	this->stats = stats;
}



void Jogo::getInfo() const {
	cout << "JOGO " << nome << endl << "Local - " << cidade << "," << pais << " | Estadio - " << estadio << endl << endl;
    cout << "Equipa de Arbitragem: ";
    for (auto &x:equipa_arbitragem){
        cout << x << " | ";
    }
    cout << "\n\nEquipa Nacional: \n";
    for (auto &x:jogadores_convocados){
        cout << x << endl;
    }
    cout << "\nEquipa Adversaria: \n";
    for (auto &x:equipa_adversaria){
        cout << x << endl;
    }
    cout << "\n-------------\n";
    cout << "Estatisticas";
    cout << "\n-------------\n";
    cout << "\nGolos: \n";
    for (auto &x: stats.golos){
        cout << x.first << " - " << x.second << " golo(s)" << endl;
    }
    cout << "\nMinutos Jogados: \n";
    for (auto &x: stats.minJogados){
        cout <<  x.first << " - " << x.second << " minutos" << endl;
    }
    cout << "\nKms percorridos: \n";
    for (auto &x: stats.kmPercorridos){
        cout << x.first << " - " << x.second << " kms" << endl;
    }
	cout << "\nPasses Efetuados: \n";
	for (auto& x : stats.passes) {
		cout << x.first << " - " << x.second << " passes" << endl;
	}
    cout << "\nCartoes: \n";
    for (auto &x: stats.cartoes){
        cout << x.first << " - " << x.second << endl;
    }
    cout << endl;
}

string Jogo::getNome()
{
	return nome;
}

string Jogo::getID()
{
	return id_conv;
}

string Jogo::getCidade()
{
	return cidade;
}

string Jogo::getPais()
{
	return pais;
}

string Jogo::getEstadio()
{
	return estadio;
}

vector<Jogador*> Jogo::getEquipaAdversaria() const
{
	return equipa_adversaria;
}

vector<JogadorSelecao*> Jogo::getJogadoresConvocados() const
{
	return jogadores_convocados;
}

vector<string> Jogo::getEquipaArbitragem() const
{
	return equipa_arbitragem;
}

void Jogo::addJogadorAdversario(Jogador* Adv)
{
	equipa_adversaria.push_back(Adv);
}

void Jogo::addJogadorConvocado(JogadorSelecao* jog)
{
	jogadores_convocados.push_back(jog);
}

void Jogo::RemoveJogadorConvocado(string num)
{
	typename vector<JogadorSelecao*> ::iterator x = jogadores_convocados.begin();
	for (; x != jogadores_convocados.end(); x++) {
		if ((*x)->getNumero() == (num)) {
			stats.cartoes.erase(*x);
			stats.golos.erase(*x);
			stats.minJogados.erase(*x);
			stats.passes.erase(*x);
			stats.kmPercorridos.erase(*x);
			jogadores_convocados.erase(x);
			return;
		}
	}

}

void Jogo::addEquipaArbitragem(string arb)
{
	equipa_arbitragem.push_back(arb);
}

void Jogo::setNome(string n)
{
	this->nome = n;
}

void Jogo::setCidade(string c)
{
	this->cidade = c;
}

void Jogo::setPais(string p)
{
	this->pais = p;
}

void Jogo::setEstadio(string e)
{
	this->estadio = e;
}

void Jogo::setIdConv(string id)
{
	this->id_conv = id;
}

void Jogo::setEstatisticas(JogadorSelecao* j, int golos, int passes, double km, string cart, int minJog) {
    
	stats.golos.insert(pair<JogadorSelecao*, int>(j, golos));
    
	stats.passes.insert(pair<JogadorSelecao*, int>(j, passes));

    stats.kmPercorridos.insert(pair<JogadorSelecao*, double>(j, km));
   
    stats.cartoes.insert(pair<JogadorSelecao*, string>(j, cart));

	stats.minJogados.insert(pair<JogadorSelecao*, int>(j, minJog));
}

void Jogo::showPlayerGameStats(string num,int& p, int& g, int& m, double& k, vector<string>& c) {
	bool found = false;

	for (auto& x : stats.golos) {
		if (x.first->getNumero() == num) {
			cout << "Golos: " << x.second << endl;
			g += x.second;
			found = true;
		}
	}
	if (!found)
		cout << "Golos: 0\n";
	found = false;

	for (auto& x : stats.minJogados) {
		if (x.first->getNumero() == num) {
			cout << "Minutos Jogados: " << x.second << endl;
			m += x.second;
			found = true;
		}
	}
	if (!found)
		cout << "Minutos Jogados: 0\n";
	found = false;

	for (auto& x : stats.kmPercorridos) {
		if (x.first->getNumero() == num) {
			cout << "Kms Percorridos: " << x.second << endl;
			k += x.second;
			found = true;
		}
	}
	if (!found)
		cout << "Kms Percorridos: 0\n";
	found = false;

	for (auto& x : stats.passes) {
		if (x.first->getNumero() == num) {
			cout << "Passes efetuados: " << x.second << endl;
			p += x.second;
			found = true;
		}
	}
	if (!found)
		cout << "Kms Percorridos: 0\n";
	found = false;

	for (auto& x : stats.cartoes) {
		if (x.first->getNumero() == num) {
			cout << "Cartoes: " << x.second << endl;
			c.push_back(x.second);
			found = true;
		}
	}
	if (!found)
		cout << "Cartoes: Nenhum\n";
}

int Jogo::getGolos(JogadorSelecao *j) {
    for (auto &x:stats.golos){
        if (x.first->getNumero() == j->getNumero()){
            return x.second;
        }
    }
    return 0;
}

int Jogo::getPasses(JogadorSelecao *j) {
    for (auto &x:stats.passes){
        if (x.first->getNumero() == j->getNumero()){
            return x.second;
        }
    }
    return 0;
}

double Jogo::getKms(JogadorSelecao *j) {
    for (auto &x:stats.kmPercorridos){
        if (x.first->getNumero() == j->getNumero()){
            return x.second;
        }
    }
    return 0;
}

int Jogo::getMin(JogadorSelecao *j) {
    for (auto &x:stats.minJogados){
        if (x.first->getNumero() == j->getNumero()){
            return x.second;
        }
    }
    return 0;
}

int Jogo::getCartoes(JogadorSelecao *j) {
    for (auto &x:stats.cartoes){
        if (x.first->getNumero() == j->getNumero()){
            if (x.second == "AA")
                return 2;
            else return 1;
        }
    }
    return 0;
}

ostream& operator<<(ostream& out, Jogo* jogo)
{
    out << jogo->getCidade() << ", " << jogo->getPais() << " - " << jogo->getEstadio();
    return out;
}