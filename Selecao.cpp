#include "Selecao.h"
#include <fstream>

Selecao::Selecao():TodosSelecionadores(Selecionador("","","",0,"",0,{tuple<string,Date>("",Date("0/0/0"))}))
{
}

int Selecao::ReadFile(string PersonsFile, string JogosFile, string ConvocatoriasFile) {
	/*-----------LE FICHEIRO DAS PESSOAS------------*/
	ifstream infile1;
	infile1.open(PersonsFile);

	if (infile1.fail()) {
		cerr << "Error opening data file" << endl;
		return 1;
	}

	string type, name, posicao, clube, numero, peso, altura, dataN, passe, salario, funcao,contracto;
	string nTitulos, local, dataInicioC,tmp;
	vector<tuple<string,Date>>titulos;

	while (!infile1.eof()) {
		getline(infile1, type, ';');
		if (type == "Jogador Selecao") {
			getline(infile1, name, ';');
			getline(infile1, posicao, ';');
			getline(infile1, clube, ';');
			getline(infile1, numero, ';');
			getline(infile1, peso, ';');
			getline(infile1, altura, ';');
			getline(infile1, dataN, ';');
			getline(infile1, passe);
			JogadorSelecao* new_jogador = new JogadorSelecao(name, posicao, clube, numero, peso, altura, dataN, stoi(passe));
			TodosJogadores.push_back(new_jogador);
		}
		else if (type == "Jogador") {
			getline(infile1, name, ';');
			getline(infile1, posicao, ';');
			getline(infile1, clube, ';');
			getline(infile1, numero);

			Jogador* new_jogador = new Jogador(name, posicao, clube, numero);
			OutrosJogadores.push_back(new_jogador);
			
		}
		else if (type == "Staff") {
			getline(infile1, name, ';');
			getline(infile1, funcao, ';');
			getline(infile1, dataN, ';');
            getline(infile1, salario, ';');
            if (funcao ==  "Selecionador Nacional") {
                getline(infile1, contracto, '(');
                getline(infile1, nTitulos, ')');
                for (size_t i = 1; i <= stoi(nTitulos); i++) {
                    getline(infile1, local, ';');
                    if (i == stoi(nTitulos)) {
                        getline(infile1, dataInicioC);
                        titulos.push_back(tuple<string, Date>(local, Date(dataInicioC)));
                    } else {
                        getline(infile1, dataInicioC, ';');
                        titulos.push_back(tuple<string, Date>(local, Date(dataInicioC)));
                    }
                }
                if (stoi(nTitulos)==0)
                    getline(infile1,tmp); //remover o \n depois de ler o numero de titulos
                Selecionador new_selecionador = Selecionador(name, dataN, funcao, stoi(salario),contracto, stoi(nTitulos),
                                                             titulos);
                TodosSelecionadores.insert(new_selecionador);
                titulos.clear();
            }
            else {
                getline(infile1, contracto);
                Staff new_staff = Staff(name, dataN, funcao, stoi(salario),contracto);
                stafftotal.insert(new_staff);
            }
		}
	}
	infile1.close();
	/*---------------------------------------------*/


	/*-----------LE FICHEIRO DOS JOGOS------------*/
	ifstream infile2;
	infile2.open(JogosFile);
	if (infile2.fail()) {
		cerr << "Error opening data file" << endl;
		return 1;
	}

	Jogo *new_jogo = nullptr;
	string line;
	int line_read = 0;

	while (getline(infile2, line)) {
		if (line == "::::::::::::") {
			TodosJogos.push_back(new_jogo);
			line_read = 0;
		}
		else {
			switch (line_read) {
			case 0:
			{
				new_jogo = new Jogo("", "", "", "", ""); //cria um novo objeto Jogo a cada linha zero
				new_jogo->setNome(line);
				line_read++;
				break;
			}
			case 1:
			{
				new_jogo->setIdConv(line);
				line_read++;
				break;
			}
			case 2:
			{
				new_jogo->setCidade(line);
				line_read++;
				break;
			}
			case 3:
			{
				new_jogo->setPais(line);
				line_read++;
				break;
			}
			case 4:
			{
				new_jogo->setEstadio(line);
				line_read++;
				break;
			}
			case 5:
			{
				stringstream ss;
				ss << line;
				string arbitro;
				while (getline(ss, arbitro, ';')) {
					new_jogo->addEquipaArbitragem(arbitro);
				}
				line_read++;
				break;
			}
			default:
			{
				stringstream ss;
				ss << line;
				string typej, numeroj, golos, passes, km, cartoes, minJogados;
				getline(ss, typej, ';');
				if (typej == "Jogador Selecao") {
					getline(ss, numeroj, ';');
					getline(ss, golos, ';');
					getline(ss, passes, ';');
					getline(ss, km, ';');
					getline(ss, cartoes, ';');
					getline(ss, minJogados);
					try {
						JogadorSelecao* convocado = GetPlayerSelecao(numeroj);
						new_jogo->addJogadorConvocado(convocado); //constroi vetor de jogadores convocados para o jogo
						new_jogo->setEstatisticas(convocado, stoi(golos), stoi(passes), stod(km), cartoes, stoi(minJogados)); //adiciona as estatisticas ao jogo criado
					}
					catch (JogadorInexistente & Ji) {
						continue;
					}
				}
				else if (typej == "Jogador"){
					getline(ss, numeroj);
					Jogador* x = GetPlayerAdv(numeroj);
					new_jogo->addJogadorAdversario(x); //constroi vetor de jogadores adversarios para o jogo
				}

				line_read++;
				break;
			}
			}
		}
	}
	infile2.close();
	/*---------------------------------------------*/

	/*-----------LE FICHEIRO DAS CONVOCATORIAS------------*/
	ifstream infile3;
	infile3.open(ConvocatoriasFile);
	if (infile3.fail()) {
		cerr << "Error opening data file" << endl;
		return 1;
	}

	Convocatoria *new_convocatoria = nullptr;
	Date Beggining;
	Date Ending;

	string id_convocatoria;

	line = "";
	line_read = 0;

	while (getline(infile3, line)) {
		if (line == "::::::::::::") {
			campeonatos.push_back(new_convocatoria);
			line_read = 0;
		}
		else {
			switch (line_read) {
			case 0:
			{
				new_convocatoria = new Convocatoria("", Beggining, Ending,"");
				new_convocatoria->setId(line);
				id_convocatoria = line;
				line_read++;
				break;
			}
			case 1:
			{
				new_convocatoria->setTipoCampeonato(line);
				line_read++;
				break;
			}
			case 2:
			{
				stringstream ss;
				ss << line;
				string Nomejogo;
				Jogo * jogo_conv;
				while (getline(ss, Nomejogo, ';')) {
					try {
						jogo_conv = GetJogo(Nomejogo, id_convocatoria); //procura na selecao o jogo que est� nesta convocatoria
						new_convocatoria->addJogo(jogo_conv); //cria o vetor campeonato da convocatoria
					}
					catch (JogoInexistente & Ji) {
						continue;
					}
				}
				line_read++;
				break;
			}
			case 3:
			{
				stringstream ss;
				ss << line;
				string NumeroJog;
				JogadorSelecao* jogador_conv;
				while (getline(ss, NumeroJog, ';')) {
					try {
						jogador_conv = GetPlayerSelecao(NumeroJog); //procura na selecao o jogador que est� nesta convocatoria
						new_convocatoria->addJogadorConvocado(jogador_conv); //cria o vetor de jogadores convocados da convocatoria
					}
					catch (JogadorInexistente(&Ji)){
						continue;
					}
				}
				line_read++;
				break;
			}
			case 4:{
                stringstream ss;
                ss << line;
                string NomeStaff;
				while (getline(ss, NomeStaff, ';')) {
					try {
					    Selecionador *ns = getSelecionador(NomeStaff);
                        new_convocatoria->setSelecionadorConvocado(ns);
					}
					catch (StaffInexistente(&Si)) {
						continue;
					}
				}
                line_read++;
                break;
			    }
                case 5:{
                    stringstream ss;
                    ss << line;
                    string NomeStaff;

                    while (getline(ss, NomeStaff, ';')) {
                        try {
                           auto staff_conv = GetStaff(NomeStaff); //procura na selecao o staff desta convocatoria
                            new_convocatoria->addStaffConvocado(staff_conv); //cria o vetor de staff convocados da convocatoria
                        }
                        catch (StaffInexistente(&Si)) {
                            continue;
                        }
                    }
                    line_read++;
                    break;
                }
			case 6:
			{
				Date date1 = Date(line);
				new_convocatoria->setBegginingDate(date1);
				line_read++;
				break;
			}
			case 7:
			{
				Date date2 = Date(line);
				new_convocatoria->setEndingDate(date2);
				line_read++;
				break;
			}
            case 8:
            {
                new_convocatoria->setEstado(line);
                line_read = 0;
                break;
            }
			}
		}
	}
	infile3.close();
	/*---------------------------------------------*/

	return 0;
}

int Selecao::WriteFile(string PersonsFile, string JogosFile, string ConvocatoriasFile)
{	/*-----------ESCREVER FICHEIRO DAS PESSOAS------------*/
	ofstream outfile1;
	outfile1.open(PersonsFile);

	for (auto& x : TodosJogadores) {
		outfile1 << "Jogador Selecao" << ";" << x->getNome() << ";" << x->getPosicao()
			<< ";" << x->getClube() << ";" << x->getNumero() << ";" << x->getPeso() << ";" << x->getAltura()
			<< ";" << x->getDNas() << ";" << x->getPasse() << endl;
	}
	for (auto& x : OutrosJogadores) {
		outfile1 << "Jogador" << ";" << x->getNome() << ";" << x->getPosicao()
			<< ";" << x->getClube() << ";" << x->getNumero() << endl;
	}

	for (auto& x : stafftotal) {
		outfile1 << "Staff" << ";" << x.getNome() << ";" << x.getFuncao() << ";"
			<< x.getDNascimento() << ";" << x.getSalario() <<";"<<x.getContrato()<< endl;

	}
	outfile1.close();

	/*-----------ESCREVER FICHEIRO DOS JOGOS------------*/
	ofstream outfile2;
	outfile2.open(JogosFile);

	for (auto& x : TodosJogos) {
		outfile2 << x->getNome() << endl;
		outfile2 << x->getID() << endl;
		outfile2 << x->getCidade() << endl;
        outfile2 << x->getPais() << endl;
		outfile2 << x->getEstadio() << endl;

		for (size_t i = 0; i < x->getEquipaArbitragem().size(); i++) { //escreve os arbitros
			if (i == x->getEquipaArbitragem().size() - 1) {
				outfile2 << x->getEquipaArbitragem()[i] << endl;
				break;
			}
			outfile2 << x->getEquipaArbitragem()[i] << ";";
		}

		for (auto &j: x->getJogadoresConvocados()) { //escreve os jogadores da selecao
			outfile2 << "Jogador Selecao" << ";" << (j)->getNumero() << ";"
				<< x->getEstatisticas().golos[j] << ";"
				<< x->getEstatisticas().passes[j] << ";"
				<< x->getEstatisticas().kmPercorridos[j] << ";"
				<< x->getEstatisticas().cartoes[j] << ";"
				<< x->getEstatisticas().minJogados[j] << endl;
		}
		for (auto& ja : x->getEquipaAdversaria()) { //escreve os jogadores adversarios
			outfile2 << "Jogador" << ";" << (ja)->getNumero() << endl;
		}
		outfile2 << "::::::::::::" << endl;

	}
	outfile2.close();

	/*-----------ESCREVER FICHEIRO DAS CONVOCATORIAS------------*/
	ofstream outfile3;
	outfile3.open(ConvocatoriasFile);

	for (auto& x : campeonatos) {
		outfile3 << x->getId() << endl;
		outfile3 << x->getTipoCampeonato() << endl;

		for (size_t i = 0; i < x->getCampeonato().size(); i++) { //escreve o nome dos jogos
			if (i == x->getCampeonato().size() - 1) {
				outfile3 << x->getCampeonato()[i]->getNome() << endl;
				break;
			}
			outfile3 << x->getCampeonato()[i]->getNome() << ";";
		}

		for (size_t i = 0; i < x->getJogadores().size(); i++) { //escreve o numero dos jogadores
			if (i == x->getJogadores().size() - 1) {
				outfile3 << x->getJogadores()[i]->getNumero() << endl;
				break;
			}
			outfile3 << x->getJogadores()[i]->getNumero() << ";";
		}

		outfile3 << x->getSelecionador()->getNome() << endl;

		for (size_t i = 0; i < x->getStaffConvocado().size(); i++) { //escreve o nome do staff
			if (i == x->getStaffConvocado().size() - 1) {
				outfile3 << x->getStaffConvocado()[i].getNome() << endl;
				break;
			}
			outfile3 << x->getStaffConvocado()[i].getNome() << ";";
		}
		outfile3 << x->getDataInicio() << endl;
		outfile3 << x->getDataFim() << endl;
		outfile3 << x->getEstado() << endl;
		outfile3 << "::::::::::::" << endl;
	}
	outfile3.close();

	return 0;
}

void Selecao::showAllConvocatorias() const {
	for (auto& x : campeonatos) {
			x->getInfo();
	}
}

void Selecao::showConvocatoria(string id) const
{
	for (auto& x : campeonatos) {
		if (x->getId() == id) {
			x->getInfo();
			return;
		}
	}
	throw ConvocatoriaInexistente(id);
}

void Selecao::showConvocatoriaCosts(string id) const {
	for (auto& x : campeonatos) {
		if (x->getId() == id) {
			int days;
			days = x->getDuration();
			cout << "O Custo de Jogadores foi de " << x->getPlayersCost() << " custando em media " << x->getPlayersCost() / days << " por dia\n";
			cout << "O Custo de Staff foi de " << x->getStaffCost() << " custando em media " << x->getStaffCost() / days << " por dia\n";
			cout << "O Custo Total foi de " << x->getPlayersCost() + x->getStaffCost() << " custando em media " << (x->getPlayersCost() + x->getStaffCost()) / days << " por dia\n";
			return;
		}
	}
	throw ConvocatoriaInexistente(id);
}

void Selecao::ShowConvocatoriaPlayerCost(string id_conv, JogadorSelecao* j) const {
	for (auto& x : campeonatos) {
		if (x->getId() == id_conv) {
			x->showPlayerCost(j);
			return;
		}
	}
	throw ConvocatoriaInexistente(id_conv);
}

void Selecao::showConvocatoriaPlayerStats(string id) const {
	for (auto& x : campeonatos) {
		if (x->getId() == id) {
			x->showBestStats();
			return;
		}
	}
	throw ConvocatoriaInexistente(id);
}

void Selecao::showAllGames(string id) const {
    bool found= false;
	for (auto& x : TodosJogos) {
		if (x->getID() == id) {
			x->getInfo();
			found = true;
		}
	}
	if(!found)
	throw ConvocatoriaInexistente(id);
}

void Selecao::showAllPlayers() const{
	for (auto& x : TodosJogadores) {
		if (x->eJogadorNacional())
			x->getInfo();
	}
}

void Selecao::showPlayer(string numero) const{
	for (auto& x : TodosJogadores) {
		if (x->getNumero() == numero) {
			x->getInfo();
			return;
		}
	}
	throw JogadorInexistente(numero);
}

void Selecao::showAllStaff() const {
    unordered_set<Staff,staffhash,staffeq>::const_iterator iteratorH=stafftotal.begin();
    while (iteratorH != stafftotal.end()) {
        cout << (*iteratorH);
        iteratorH++;
    }
}
void Selecao::modifyStaff(Staff st){
      unordered_set<Staff,staffhash,staffeq>::const_iterator iteratorH=stafftotal.begin();
    while (iteratorH != stafftotal.end()) {
        if (st.getNome()==(*iteratorH).getNome())stafftotal.erase(iteratorH);
        stafftotal.insert(st);
        iteratorH++;
    }
}


void Selecao::showAllCosts() const {
	double playerCosts = 0, staffCosts = 0, totalCosts = 0;
	int totalDays = 0;
	for (auto& x : campeonatos) {
		playerCosts += x->getPlayersCost();
		staffCosts += x->getStaffCost();
		totalCosts += x->getPlayersCost() + x->getStaffCost();
		totalDays += x->getDuration();
	}
	cout << "O Custo de Jogadores foi de " << playerCosts << " custando em media " << playerCosts / totalDays << " por dia\n";
	cout << "O Custo de Staff foi de " << staffCosts << " custando em media " << staffCosts / totalDays << " por dia\n";
	cout << "O Custo Total foi de " << totalCosts << " custando em media " << totalCosts / totalDays << " por dia\n";
}

void Selecao::showPessoalConvocado(string id) const {
	for (auto& x : campeonatos) {
		if (x->getId() == id) {
			cout << endl;
			x->showPlayers();
			x->showStaff();
			return;
		}
	}
	throw ConvocatoriaInexistente(id);
}

Convocatoria* Selecao::getConvocatoria(string id) {
	typename vector<Convocatoria*> ::iterator x = campeonatos.begin();
	for (; x != campeonatos.end(); x++) {
		if ((*x)->getId() == (id)) {
			return (*x);
		}
	}
	throw ConvocatoriaInexistente(id);
}

JogadorSelecao * Selecao::GetPlayerSelecao(string numero){
	typename vector<JogadorSelecao*> ::iterator x = TodosJogadores.begin();
	for (; x != TodosJogadores.end(); x++) {
		if ((*x)->getNumero() == (numero) && (*x)->eJogadorNacional()) {
			return (*x);
		}
	}
	throw JogadorInexistente(numero);
}

JogadorSelecao* Selecao::GetPlayerConvocatoria(string numero, string id)
{
	vector<JogadorSelecao*> jog;
	bool found_conv = false;
	typename vector<Convocatoria*>::iterator x = campeonatos.begin();
	for (; x != campeonatos.end(); x++) {
		if ((*x)->getId() == id) {
			jog = (*x)->getJogadores();
			found_conv = true;
		}
	}
	if (!found_conv)
		throw ConvocatoriaInexistente(id);

	typename vector<JogadorSelecao*>::iterator y = jog.begin();
	for (; y != jog.end(); y++) {
		if ((*y)->getNumero() == numero) {
			return (*y);
		}
	}
	throw JogadorInexistente(numero);
}

Jogador* Selecao::GetPlayerAdv(string numero) {
	typename vector<Jogador*> ::iterator x = OutrosJogadores.begin();
	for (; x != OutrosJogadores.end(); x++) {
		if ((*x)->getNumero() == numero ) {
			return (*x);
		}
	}
	throw JogadorInexistente(numero);
}

Jogo* Selecao::GetJogo(string name, string id)
{
	typename vector<Jogo*>::iterator x = TodosJogos.begin();
	for (; x != TodosJogos.end(); x++) {
		if ((*x)->getNome() == name && (*x)->getID()==id) {
			return (*x);
		}
	}
	throw JogoInexistente(name);
}

void Selecao::AddPlayer(JogadorSelecao* j){
	TodosJogadores.push_back(j);
}

void Selecao::RemovePlayer(string numero){
	bool jogador_existe = false;
	typename vector<JogadorSelecao*> ::iterator x = TodosJogadores.begin();
	for (; x != TodosJogadores.end(); x++) { //elimina de todos os jogadores da selecao
		if ((*x)->getNumero() == (numero)) {
			jogador_existe = true;
			TodosJogadores.erase(x);
			break;
		}
	}
	if(!jogador_existe)
		throw JogadorInexistente(numero);

	typename vector<Jogo*> ::iterator y = TodosJogos.begin();
	for (; y != TodosJogos.end(); y++) { //elimina de todos os jogos onde pertence
		for (size_t i = 0; i < (*y)->getJogadoresConvocados().size(); i++) {
			if ((*y)->getJogadoresConvocados()[i]->getNumero() == numero) {
				(*y)->RemoveJogadorConvocado(numero);
				break;
			}
		}
	}

	typename vector<Convocatoria*> ::iterator z = campeonatos.begin();
	for (; z != campeonatos.end(); z++) { //elimina de todas as convocatorias onde pertence
		for (size_t i = 0; i < (*z)->getJogadores().size(); i++) {
			if ((*z)->getJogadores()[i]->getNumero() == numero) {
				(*z)->RemoveJogadorConvocado(numero);
				break;
			}
		}
	}
}

void Selecao::RemoveStaff(string nome){
    for (auto itr=stafftotal.begin(); itr != stafftotal.end(); itr++) {
        if ((*itr).getNome() == nome) {
            stafftotal.erase(itr);
            return;
        }
    }
    throw StaffInexistente(nome);
}


vector<Convocatoria*> Selecao::getAllConvocatorias() const
{
	return campeonatos;
}

vector<JogadorSelecao*> Selecao::getAllPlayers() const
{
	return TodosJogadores;
}

vector<Staff> Selecao::getAllStaff() const
{vector<Staff>TodosStaff;
    for(auto x:stafftotal){
        TodosStaff.push_back(x);
    }
    return TodosStaff;
}


Staff Selecao::GetStaff(string nome)
{

    for (auto& x:stafftotal) {
        if (x.getNome() == nome) {
            return x;
        }
    }

    throw StaffInexistente(nome);
}

void Selecao::AddStaff(Staff* s) {
    stafftotal.insert(*s);
}

void Selecao::addLesaoConvocatoria(string id_conv,string id_player,string day){
	bool found_player = false;
	for (auto& x : getConvocatoria(id_conv)->getJogadores()) { //para ver se o jogador pedido existe nesta convocatoria pedida
		if (x->getNumero() == id_player) {
			found_player = true;
			break;
		}
	}
	if (!found_player)
		throw JogadorInexistente(id_player);

	bool found_convocatoria = false;
    for (auto &x: campeonatos){
        if (x->getId() == id_conv){
            x->addLesao(id_player,day);
			found_convocatoria = true;
        }
    }
	if (!found_convocatoria)
		throw ConvocatoriaInexistente(id_conv);

}

void Selecao::addtoConvocatoria(string id_conv, string id_player){
	bool found = false;
	bool found_convocatoria = false;
	for (auto& x : campeonatos) {
		if (id_conv == x->getId()) {
			found_convocatoria = true;
			for (auto& y : x->getJogadores()) {
				if (y->getNumero() == id_player) {
					cout << "O jogador ja existe na convocatoria\n";
					found = true;
					return;
				}
			}
			if (!found)
				x->addJogadorConvocado(Selecao::GetPlayerSelecao(id_player));
		}
	}
	if (!found_convocatoria)
		throw ConvocatoriaInexistente(id_conv);
}

void Selecao::showAllSelecionadoresC() const {
    BSTItrIn<Selecionador>it(TodosSelecionadores);
    while(!it.isAtEnd()){
        cout << endl << "------------";
        it.retrieve().getInfo();
        it.advance();
    }
}

Selecionador* Selecao::getSelecionador(string nome) const {
    BSTItrIn<Selecionador>it(TodosSelecionadores);
    while(!it.isAtEnd()){
        if(it.retrieve().getNome()==nome){
            return (&it.retrieve());
        }
        it.advance();
    }
    throw StaffInexistente(nome);
   }

void Selecao::MakeConvocatoria() {
    Convocatoria *c1=new Convocatoria("",Date("0/0/0"),Date("0/0/0"),"");
    string tipoC,id, data_i, data_f, seleci;
    cout << "Insira o tipo de campeonato: ";
    getline(cin,tipoC);
    c1->setTipoCampeonato(tipoC);

    bool id_exists=false;
    do {
        cout << "Insira um id para a convcocatoria: " << endl;
        getline(cin,id);
        for(auto &conv: campeonatos){
            if (conv->getId()==id) {
                id_exists = true;
                break;
            }
        }
        if (id_exists)
            cout << "O id inserido ja se encontra atribuido!"<< endl;
    }while(id_exists);
    c1->setId(id);

    do {
        cout << "Insira a data de inicio (DD/MM/AAAA): ";
        getline(cin, data_i);
    }while(DateValidation(data_i) == 1);
    c1->setBegginingDate(Date(data_i));

    do {
        cout << "Insira a data de fim(DD/MM/AAAA): ";
        getline(cin, data_f);
    }while(DateValidation(data_f) == 1);
    c1->setEndingDate(Date(data_f));

    bool selecionador_exists=false;
    do {
        cout << "Insira o Nome do Selecionador Convocado:" << endl;
        BSTItrIn<Selecionador > it(TodosSelecionadores);
        while (!it.isAtEnd()) {
            cout << it.retrieve().getNome() << endl;
            it.advance();
        }
        getline(cin,seleci);
        BSTItrIn<Selecionador > it1(TodosSelecionadores);
        while (!it1.isAtEnd()) {
            if (it1.retrieve().getNome() == seleci) {
                it1.retrieve().setSelecoes(c1->getTipoCampeonato(), c1->getDataInicio());
                c1->setSelecionadorConvocado(&it1.retrieve());
                selecionador_exists=true;
            }
            it1.advance();
        }
    }while(!selecionador_exists);
    string estado;
    do {
        cout << "Insira o estado da convocatoria ('Ganho', 'Perdido' ou 'A decorrer'): " << endl;
        getline(cin, estado);
    }while(estado != "Ganho" || estado != "Perdido" || estado != "A decorrer");
    c1->setEstado(estado);
    campeonatos.push_back(c1);
    if (estado=="Ganho"){
        getSelecionador(seleci)->addTituloSelecionador();
    }

    int counter=0;
    do{
        string PlayerN;
        cout << "Insira o numero dos jogadores a convocar (6): " << endl;
        try {
            for (auto j: TodosJogadores) {
                cout << j << endl;
            }
            getline(cin, PlayerN);
            addtoConvocatoria(c1->getId(), PlayerN);
        }catch(JogadorInexistente(&Ji)){
            cout << "Jogador Inexistente"<< endl;
            continue;
        }
        counter++;
    }while(counter<6);
    cout << "NOTA: Para inserir jogos na convocatoria aceda ao menu jogos (depois de terem ocorrido)!"<<endl;
}

void Selecao::AddJogotoConvocatoria(string id_conv){
    string nome, cidade, pais, estadio;
    bool convocatoria_existe=false;
    Convocatoria *convocatoriaToAdd;
    for (auto &convocatoria: campeonatos){
        if(convocatoria->getId()==id_conv){
            convocatoria_existe=true;
            convocatoriaToAdd=convocatoria;
        }
    }
    if(!convocatoria_existe)
        throw ConvocatoriaInexistente(id_conv);

    Jogo *new_jogo= new Jogo("","","","","");
    new_jogo->setIdConv(id_conv);
    cout << "Insira o nome do jogo (ex. PORxESP): " << endl;
    getline(cin,nome);
    new_jogo->setNome(nome);
    cout << "Insira a cidade: " << endl;
    getline(cin,cidade);
    new_jogo->setCidade(cidade);
    cout << "Insira o Pais: " << endl;
    getline(cin,pais);
    new_jogo->setPais(pais);
    cout << "Insira o estadio: " << endl;
    getline(cin,estadio);
    new_jogo->setEstadio(estadio);

    int counter=0;
    do{
        string PlayerN;
        cout << "Insira o numero dos 5 jogadores convocados que jogaram: " << endl;
        try {
            for(auto &j : getConvocatoria(id_conv)->getJogadores()){
                cout << j << endl;
            }
            bool jogador_existe=false;
            getline(cin, PlayerN);
            for(auto &j : getConvocatoria(id_conv)->getJogadores()){
                if (j->getNumero()==PlayerN) {
                    jogador_existe=true;
                    new_jogo->addJogadorConvocado(j);
                }
            }
            if(!jogador_existe)
                throw JogadorInexistente(PlayerN);
        }catch(JogadorInexistente(&Ji)){
            cout << "Jogador Inexistente"<< endl;
            continue;
        }
        counter++;
    }while(counter<5);
    convocatoriaToAdd->addJogo(new_jogo);
}

void Selecao::showAllSelecionadoresD() const {
    BSTItrIn<Selecionador>it(TodosSelecionadores);
    vector<Selecionador>tmp;
    while(!it.isAtEnd()){
        tmp.push_back(it.retrieve());
        it.advance();
    }
    reverse(tmp.begin(),tmp.end());
    for (auto &j: tmp) {
        j.getInfo();
        cout << endl << "------------";
    }
}

void Selecao::showAllSelecionadoresN(int n) const {
    BSTItrIn<Selecionador>it(TodosSelecionadores);
    bool exist=false;
    while(!it.isAtEnd()){
        if(it.retrieve().getNtitulos() >= n) {
            it.retrieve().getInfo();
            cout << endl << "------------";
            exist=true;
        }
        it.advance();
    }
    if(!exist){
        cout << "Nao existem Selecionadores com esse numero minimo de titulos!" << endl;
    }
}
