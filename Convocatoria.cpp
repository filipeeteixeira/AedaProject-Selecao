
#include "Convocatoria.h"
#include "Date.h"

Convocatoria::Convocatoria(string tc, Date di, Date df){
    this->tipo_campeonato=tc;
    this->data_inicio=di;
    this->data_fim=df;
    this->estado=estado;
}

void Convocatoria::addJogo(Jogo *j) {
    campeonato.push_back(j);
}

void Convocatoria::addJogadorConvocado(JogadorSelecao * j) {
	jogadoresConvocados.push_back(j);
}

void Convocatoria::RemoveJogadorConvocado(string num)
{
	typename vector<JogadorSelecao*> ::iterator x = jogadoresConvocados.begin();
	for (; x != jogadoresConvocados.end(); x++) {
		if ((*x)->getNumero() == (num)) {
			jogadoresConvocados.erase(x);
			return;
		}
	}
}

void Convocatoria::addStaffConvocado(Staff  s) {
    this->staffConvocado.push_back(s);
}

void Convocatoria::getInfo() const {
    cout << "---------------\n";
    cout << "Convocatoria(" << id << ")" << endl;
	cout << "---------------\n";
    cout << "Tipo de Campeonato: " << tipo_campeonato << endl;
    cout << "Data de inicio: " << data_inicio << endl;
    cout << "Data de fim: " << data_fim << endl;
    cout << "Selecionador: " << SelecionadorConvocado->getNome() << endl;
    cout << "Jogos(" << campeonato.size() << "):\n";
    for (auto &x :campeonato){
		cout << x << endl;
    }
}

int Convocatoria::getNumJogos() const {
    return this->campeonato.size();
}

void Convocatoria::showPlayers() const {

	string sort;

	bool valid = false;

	do {
		cout << "\nQuer ver os jogadores ordenado por nome ou numero?\n";
		cin >> sort;
		if (sort == "nome" || sort == "numero")
			valid = true;
		else cout << "Categoria invalida!\n";
	} while (!valid);

	vector<JogadorSelecao*> v = this->getJogadores();

	PlayerBubbleSort(v, sort);

	cout << "-------------\n";
	cout << "Jogadores\n";
	cout << "-------------\n";
	cout << "-------------\n";

	for (auto& x : v) {
		if (x->eJogadorNacional()) {
			cout << x << endl;
			cout << "\n";
		}
	}
}

void Convocatoria::showStaff() const {

	string sort;

	bool valid = false;

	cout << "-------------\n";
	cout << "Staff\n";
	cout << "-------------\n";

	do {
		cout << "\nQuer ver o staff ordenado por nome ou salario?\n";
		cin >> sort;
		if (sort == "nome" || sort == "salario")
			valid = true;
		else cout << "Categoria invalida!\n";
	} while (!valid);

	vector<Staff> v = this->getStaffConvocado();

	StaffBubbleSort(v, sort);

	for (auto x : v) {
		cout << x << endl;
	}
	cout << endl;
}

void Convocatoria::showPlayerStatistics(string num) {
    int i = 1;
	int goalsT = 0, minsT = 0, passesT = 0;
    double kmsT = 0.0;
    vector<string> cartoesT = {};
    for (auto &x:campeonato){
        cout << "Jogo n " << i << " - " << x << endl;
        x->showPlayerGameStats(num,passesT,goalsT,minsT,kmsT,cartoesT);
        cout << endl;
        i++;
    }
	cout << "\n-----------------------\n";
    cout << "Totais do Campeonato\n";
	cout << "-----------------------\n";
    cout << "Golos Marcados: " << goalsT << " Media: " << (double)goalsT/this->getNumJogos() << endl;
    cout << "Minutos Jogados: " << minsT << " Media: " << (double)minsT/this->getNumJogos() << endl;
	cout << "Passes efetuados: " << passesT << "Media: " << (double)passesT / this->getNumJogos() << endl;
    cout << "Kms Percorridos: " << kmsT << " Media: " << kmsT/this->getNumJogos() << endl;
    cout << "Cartoes\n";
    int numAmarelo = 0,numVermelhoDireto = 0,numVermelhoAcumulado = 0;
    for (auto &x:cartoesT)
    {
		if (x == "A")
			numAmarelo++;
        else if(x == "V")
            numVermelhoDireto++;
        else if (x == "AA"){
            numVermelhoAcumulado++;
            numAmarelo = numAmarelo + 2;
        }
    }
    cout << "Amarelo: " << numAmarelo << endl << "Vermelho Direto: " << numVermelhoDireto << endl << "Vermelho por Acumulacao de Amarelos: " << numVermelhoAcumulado << endl;
    cout <<"Total de cartoes: " << numAmarelo + numVermelhoAcumulado + numVermelhoDireto << " Media: " << (numAmarelo + numVermelhoAcumulado + numVermelhoDireto)/this->getNumJogos() << endl << endl;
}

void Convocatoria::setTipoCampeonato(string tc)
{
	this->tipo_campeonato = tc;
}

void Convocatoria::setId(string id)
{
	this->id = id;
}

void Convocatoria::setBegginingDate(Date x)
{
	this->data_inicio = x;
}

void Convocatoria::setEndingDate(Date y)
{
	this->data_fim = y;
}

string Convocatoria::getId() const
{
	return id;
}
string Convocatoria::getTipoCampeonato() const
{
	return tipo_campeonato;
}
Date Convocatoria::getDataInicio() const
{
	return data_inicio;
}
Date Convocatoria::getDataFim() const
{
	return data_fim;
}
vector<JogadorSelecao*> Convocatoria::getJogadores() const
{
	return jogadoresConvocados;
}
vector<Jogo*> Convocatoria::getCampeonato() const
{
	return campeonato;
}
vector<Staff> Convocatoria::getStaffConvocado() const
{
	return staffConvocado;
}

int Convocatoria::getDuration() const {
	return data_fim.getDay() - data_inicio.getDay() + 1;

}
void Convocatoria::addLesao(string id_player, string day) {
    lesoes.insert(pair<string,string>(id_player,day));
}
void Convocatoria::showPlayerCost(JogadorSelecao *j) {
    bool found=false;
    for (auto &x: lesoes){
        if (x.first == j->getNumero()){
            cout << "O jogador escolhido lesionou-se durante a competicao no dia " << x.second << endl;
            cout << "O custo ate ao dia de lesao foi de: " << ((double)stoi(x.second) - (double)data_inicio.getDay()) * 0.1 * j->getPasse() << endl;
            cout << "O custo desde o dia da lesao foi de: " <<  3 * ((double)stoi(x.second) - (double)data_inicio.getDay() + 1) * 0.1 * j->getPasse() << endl;
            found = true;
        }
    }
    if(!found){
        cout << "o custo do jogador no campeonato foi de: " << 0.1 * j->getPasse() * this->getDuration();
    }
}
double Convocatoria::getPlayersCost() const {
	double total = 0;

	int days;
	days = Convocatoria::getDuration();

	for (auto& x : jogadoresConvocados) {
		bool found = false;
		for (auto& y : lesoes) {
			if (y.first == x->getNumero()) {
				total += 0.1 * x->getPasse() * ((double)stoi(y.second) - (double)data_inicio.getDay()) + 0.3 * x->getPasse() * ((double)data_fim.getDay() - (double)stoi(y.second) + (double)1);
				found = true;
			}
		}
		if (!found) {
			total += days * 0.1 * x->getPasse();
		}

	}
	return total;
}
double Convocatoria::getStaffCost() const {
	double total = 0;

	int days;
	days = Convocatoria::getDuration();

	for (auto x : staffConvocado) {
		total += days * 0.1 * x.getSalario();
	}
	return total;
}
void Convocatoria::showBestStats() const {

    int bestGoals=0,tempGoals=0;
    string bestScorer;

    for(auto &x: jogadoresConvocados) {
        for (auto &y: campeonato) {
            tempGoals += y->getGolos(x);
        }
        if (tempGoals >= bestGoals) {
            bestGoals = tempGoals;
            bestScorer = "N(" + x->getNumero() + ") " + x->getNome();
            tempGoals = 0;
        }
        else tempGoals=0;
    }
    cout << "\nO melhor marcador foi " << bestScorer << " com " << bestGoals << " golos." << endl;

    int bestPasses=0,tempPasses=0;
    string bestPasser;
    for(auto &x: jogadoresConvocados) {
        for (auto &y: campeonato) {
            tempPasses += y->getPasses(x);
        }
        if (tempPasses > bestPasses) {
            bestPasses = tempPasses;
            bestPasser = "N(" + x->getNumero() + ") " + x->getNome();
            tempPasses = 0;
        }
        else tempPasses = 0;
    }
    cout << "\nO melhor passador foi " << bestPasser << " com " << bestPasses<< " passes." << endl;

    double bestRun=0,tempRun=0;
    string bestRunner;
    for(auto &x: jogadoresConvocados) {
        for (auto &y: campeonato) {
            tempRun += y->getKms(x);
        }
        if (tempRun > bestRun) {
            bestRun = tempRun;
            bestRunner = "N(" + x->getNumero() + ") " + x->getNome();
            tempRun = 0;
        }
        else tempRun = 0;
    }
    cout << "\nO melhor corredor foi " << bestRunner << " com " << bestRun<< " kms." << endl;

    int bestMinutes=0,tempMin=0;
    string mostPlayed;
    for(auto &x: jogadoresConvocados) {
        for (auto &y: campeonato) {
            tempMin += y->getMin(x);
        }
        if (tempMin > bestMinutes) {
            bestMinutes = tempMin;
            mostPlayed = "N(" + x->getNumero() + ") " + x->getNome();
            tempMin = 0;
        }
        else tempMin = 0;
    }
    cout << "\nO jogador mais jogado foi " << mostPlayed << " com " << bestMinutes<< " minutos jogados." << endl;

    int mostCards=0,tempCards=0;
    string worstFairPLayer;
    for(auto &x: jogadoresConvocados) {
        for (auto &y: campeonato) {
            tempCards += y->getCartoes(x);
        }
        if (tempCards > mostCards) {
            mostCards = tempCards;
            worstFairPLayer = "N(" + x->getNumero() + ") " + x->getNome();
            tempCards = 0;
        }
        else tempCards=0;
    }
    cout << "\nO jogador com mais cartoes foi " << worstFairPLayer << " com " << mostCards << " cartoes." << endl;

}

ostream& operator<<(ostream& out, Convocatoria* cnv)
{
	out << cnv->getTipoCampeonato() << " - Data: " << cnv->getDataInicio() << " ate " << cnv->getDataFim();
	return out;
}

void Convocatoria::setSelecionadorConvocado(Selecionador *s) {
    this->SelecionadorConvocado=s;
}

void Convocatoria::setEstado(string estado) {
    this->estado=estado;
}

void swapPlayer(JogadorSelecao** xp, JogadorSelecao** yp)
{
	JogadorSelecao* temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void swapStaff(Staff* xp, Staff* yp)
{
	Staff* temp = xp;
	xp = yp;
	yp = temp;
}


void PlayerBubbleSort(vector<JogadorSelecao*>& v, string type)
{

	if (type == "nome") {
		int i, j;
		bool swapped;
		for (i = 0; i < v.size() - 1; i++)
		{
			swapped = false;
			for (j = 0; j < v.size() - i - 1; j++)
			{
				if (v[j]->getNome() > v[j + 1]->getNome())
				{
					swapPlayer(&v[j], &v[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break
			if (swapped == false)
				break;
		}
	}
	else {
		int i, j;
		bool swapped;
		for (i = 0; i < v.size() - 1; i++)
		{
			swapped = false;
			for (j = 0; j < v.size() - i - 1; j++)
			{
				if (stoi(v[j]->getNumero()) > stoi(v[j + 1]->getNumero()))
				{
					swapPlayer(&v[j], &v[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break
			if (swapped == false)
				break;
		}
	}
}

void StaffBubbleSort(vector<Staff> v, string type)
{
	if (type == "nome") {
		int i, j;
		bool swapped;
		for (i = 0; i < v.size() - 1; i++)
		{
			swapped = false;
			for (j = 0; j < v.size() - i - 1; j++)
			{
				if (v[j].getNome() > v[j + 1].getNome())
				{
					swapStaff(&v[j], &v[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break
			if (swapped == false)
				break;
		}
	}
	else {
		int i, j;
		bool swapped;
		for (i = 0; i < v.size() - 1; i++)
		{
			swapped = false;
			for (j = 0; j < v.size() - i - 1; j++)
			{
				if (v[j].getSalario() > v[j + 1].getSalario())
				{
					swapStaff(&v[j], &v[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break
			if (swapped == false)
				break;
		}
	}
}