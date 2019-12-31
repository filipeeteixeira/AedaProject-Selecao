#include "Menus.h"



void BegginingMenu(Selecao &s) {

	while (1) {
		cout << endl;
        cout << "Data:" << getCurrentDate() << endl;
		cout << "-----------------\n";
		cout << "Selecao Nacional" << endl;
		cout << "-----------------\n";
		cout << "Enter your choice and press return: " << endl;
		cout << " [1] Convocatorias\n";
		cout << " [2] Jogos\n";
		cout << " [3] Jogadores\n";
		cout << " [4] Staff\n";
		cout << " [5] Custos\n";
		cout << endl << " [0] EXIT Program.\n";
		switch (askOption()) {
			case 0:
				//s.WriteFile("..\\Populacao.txt", "..\\Jogos.txt", "..\\Convocatorias.txt");
				exit(1);
			case 1:
				ConvocatoriasSubMenu(s);
				break;
			case 2:
				JogosSubMenu(s);
				break;
			case 3:
				JogadoresSubMenu(s);
				break;
			case 4:
				StaffSubMenu(s);
				break;
			case 5:
				CustosSubMenu(s);
		}
	}
}

void ConvocatoriasSubMenu(Selecao &s) {
	cout << endl;
    cout << "Data:" << getCurrentDate() << endl;
	cout << "Enter your choice and press return: " << endl;
	cout << " [1] Fazer Convocatoria\n";
	cout << " [2] Ver Todas as Convocatorias\n";
	cout << " [3] Ver convocatoria \n";
    cout << " [4] Ver pessoal convocado a um dada convocatoria\n";
    cout << " [5] Lesionar um jogador numa dada convocatoria\n";
    cout << " [6] Ver os melhores jogadores de uma dada convocatoria\n";
	cout << endl << " [0] EXIT.\n" << endl;
	switch (askOption()) {
		case 0:
			return;
        case 1:
        {
            s.MakeConvocatoria();
            break;
        }
		case 2:
		{
			s.showAllConvocatorias();
			break;
		}
		case 3:
		{
			do {
				string id = AskConvocatoriaProcedure();
				try {
					s.showConvocatoria(id);
					break;
				}
				catch (ConvocatoriaInexistente & Ci) {
					cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
				}
			} while (1);
			break;
		}
	    case 4:
        {
            do {
                string id = AskConvocatoriaProcedure();
                try {
                    s.showPessoalConvocado(id);
                    break;
                }
                catch (ConvocatoriaInexistente & Ci) {
                    cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
                }
            } while (1);
            break;
        }
	    case 5:
        {
            do {
				try {
                string id_conv = AskConvocatoriaProcedure();
				string id_player = AskPlayerProcedure();

                string day = AskDateProcedure();
                
                s.addLesaoConvocatoria(id_conv,id_player,day);
                break;
                }
                catch (ConvocatoriaInexistente & Ci) {
                    cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
                }
				catch(JogadorInexistente & Ji){
					cout << "O jogador com o numero:  " << Ji.getNum() << " nao existe nesta convocatoria!" << endl;
				}
            } while (1);
            break;

        }
        case 6:
        {
            do {
                string id = AskConvocatoriaProcedure();
                try {
                    s.showConvocatoriaPlayerStats(id);
                    break;
                }
                catch (ConvocatoriaInexistente & Ci) {
                    cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
                }
                catch(JogadorInexistente & Ji){
                    cout << "O jogador com o numero:  " << Ji.getNum() << " nao existe nesta convocatoria!" << endl;
                }
            } while (1);
            break;

        }
	}
}

void JogosSubMenu(Selecao &s) {
    cout << "Enter your choice and press return: " << endl;
    cout << " [1] Ver Todas os Jogos de uma Convocatoria a escolha\n";
    cout << endl << " [0] EXIT.\n" << endl;
    switch (askOption()) {
        case 0:
            return;
        case 1:
        {
            do {
                string id = AskConvocatoriaProcedure();
                try {
                    s.showAllGames(id);
                    break;
                }
                catch (ConvocatoriaInexistente & Ci) {
                    cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
                }
            } while (1);
            break;
        }

    }
}

void JogadoresSubMenu(Selecao &s) {
    cout << "Data:" << getCurrentDate() << endl;
	cout << "Enter your choice and press return: " << endl;
	cout << " [1] Adicionar Jogador a Selecao\n";
	cout << " [2] Remover Jogador da Selecao\n";  
	cout << " [3] Alterar Jogador da Selecao\n";  
	cout << " [4] Ver Jogadores da Selecao\n";
	cout << " [5] Ver Jogador da Selecao\n";
	cout << " [6] Ver Estatisticas de Jogador\n";
	cout << " [7] Adicionar Jogador a uma convocatoria\n";
	cout << endl << " [0] EXIT Menu.\n" << endl;
	switch (askOption()) {
		case 0:
			return;
		case 1:
		{
			bool exists = false;
			do {
				JogadorSelecao* new_player = AddPlayerProcedure();
				for (auto& x : s.getAllPlayers()) {
					if (x->getNumero() == new_player->getNumero()) {
						exists = true;
						cout << "Ja existe um jogador com o numero inserido!" << endl;
						cin.ignore();
					}
				}
				if (!exists)
					s.AddPlayer(new_player);
			} while (exists);
			break;
		}
		case 2:
		{
			
			do {
				string num = AskPlayerProcedure();
				try {
					s.RemovePlayer(num);
					break;
				}
				catch (JogadorInexistente & Ji) {
					cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
				}
			} while (1);

			break;
		}
		case 3:
		{
			AlterarJogSubMenu(s);
			break;
		}
		case 4:
		{
			s.showAllPlayers();
			break;
		}
		case 5:
		{
			do {
				string num = AskPlayerProcedure();
				try {
					s.showPlayer(num);
					break;
				}
				catch (JogadorInexistente & Ji) {
					cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
				}
			} while (1);
			break;
		}
		case 6:
		{
			do {
				try {
					int campNum = getCampNum(s.getAllConvocatorias()); //s.getAllConvocatorias() � o vetor campeonatos
					s.getConvocatoria(to_string(campNum+1)); //verificar se o campeonato escolhido existe
					
					cout << "A que jogador pretende aceder?\n";
					string playerNum;
					cin >> playerNum;

					s.GetPlayerSelecao(playerNum); //verificar se o jogador escolhido existe
					s.getAllConvocatorias()[campNum]->showPlayerStatistics(playerNum);
					break;
				}
				catch (JogadorInexistente & Ji) {
					cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
				}
				catch (ConvocatoriaInexistente & Ci) {
					cout << "O Campeonato numero " << Ci.getId() << " nao existe!" << endl;
				}
			} while (1);
			break;
		}
		case 7: 
		{
			do {
				string num = AskPlayerProcedure();
				string id_conv = AskConvocatoriaProcedure();
				try {
					s.addtoConvocatoria(id_conv, num);
					break;
				}
				catch (JogadorInexistente & Ji) {
					cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
				}
				catch (ConvocatoriaInexistente & Ci) {
					cout << "O Campeonato numero " << Ci.getId() << " nao existe!" << endl;
				}
			} while (1);
			break;

		}
	}
}

void AlterarJogSubMenu(Selecao& s) {
	cout << "Insira o que pretende alterar: \n";
	cout << " [1] Atualizar Peso\n";
	cout << " [2] Atualizar Altura\n";
	cout << " [3] Atualizar Valor do Passe\n";
	cout << endl << " [0] EXIT Menu.\n" << endl;
	switch (askOption()) {
		case 0:
			return;
		case 1:
		{
			string peso;
			do {
				string num = AskPlayerProcedure();
				try {
					cout << "Insira o Peso: "; cin >> peso;
					s.GetPlayerSelecao(num)->setPeso(peso);
					break;
				}
				catch (JogadorInexistente & Ji) {
					cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
				}
			} while (1);
			break;
		}
		case 2:
		{
			do{
				string altura;
				string num = AskPlayerProcedure();
				try{
					cout << "Insira a Altura: "; cin >> altura;
					s.GetPlayerSelecao(num)->setAltura(altura);
					break;
				}
				catch (JogadorInexistente & Ji) {
					cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
				}
			} while (1);
				break;
		}
		case 3:
		{
			do{
				double vp;
				string num = AskPlayerProcedure();
				try {
					cout << "Insira o Passe: "; cin >> vp;
					s.GetPlayerSelecao(num)->setPasse(vp);
					break;
				}
				catch (JogadorInexistente & Ji) {
						cout << "O Jogador numero " << Ji.getNum() << " nao existe!" << endl;
					}
			} while (1);
			break;
		}
	}
}

void AlterarStaffSubMenu(Selecao& s) {
    cout << "Insira o que pretende alterar: \n";
    cout << " [1] Atualizar Funcao\n";
    cout << " [2] Atualizar Salario\n";
    cout << endl << " [0] EXIT Menu.\n" << endl;
    switch (askOption()) {
        case 0:
            return;
        case 1:
        {
			do {
				string funcao;
				string nome = AskStaffProcedure();
				try {
					cout << "Insira a funcao: "; cin >> funcao;
					Staff st=s.GetStaff(nome);
					st.setFuncao(funcao);
					s.modifyStaff(st);
					break;
				}
				catch (StaffInexistente & Si) {
					cout << "Elemento do staff: " << Si.getNome() << " nao existe!" << endl;
				}
			} while (1);
            break;
        }
        case 2:
        {
			do {
				string salario;
				string nome = AskStaffProcedure();
				try {
					cout << "Insira o salario: "; cin >> salario;
                    Staff st=s.GetStaff(nome);
                    st.setSalario(salario);
                    s.modifyStaff(st);
					break;
				}
				catch (StaffInexistente & Si) {
					cout << "Elemento do staff: " << Si.getNome() << " nao existe!" << endl;
				}
			} while (1);
            break;
        }
    }
}

void StaffSubMenu(Selecao &s) {
    cout << endl;
    cout << "Data:" << getCurrentDate() << endl;
    cout << "Enter your choice and press return: " << endl;
    cout << " [1] Adicionar Staff a Selecao\n";
    cout << " [2] Remover Staff da Selecao\n"; 
    cout << " [3] Alterar Staff da Selecao\n";  
    cout << " [4] Ver Staff total\n";
    cout << " [5] Ver Selecionadores\n";
    cout << " [6] Ver Staff atual\n";
    cout << " [7] Ver staff antigo\n";
    cout << endl << " [0] EXIT Menu.\n" << endl;
    switch (askOption()) {
        case 0:
            return;
        case 1:
        {
            Staff* new_staff = AddStaffProcedure();
            s.AddStaff(new_staff);
            break;
        }
        case 2:
        {

            do {
                string name = AskStaffProcedure();
                try {
                    s.RemoveStaff(name);
                    break;
                }
                catch (StaffInexistente & Si) {
                    cout << "O Staff chamado " << Si.getNome() << " nao existe!" << endl;
                }
            } while (1);

            break;
        }
        case 3:
        {
            AlterarStaffSubMenu(s);
            break;
        }
        case 4:
        {
            s.showAllStaff();
            break;
        }
        case 5:
        {
            s.showAllSelecionadores();
            break;
        }
        case 6:
        {

            break;
        }
        case 7:
        {
            break;
        }
    }
}

void CustosSubMenu(Selecao &s){
    cout << "Enter your choice and press return: " << endl;
    cout << " [1] Ver Custos Totais de um Campeonato\n";
    cout << " [2] Ver Custos Totais de todos os Campeonatos \n";
    cout << " [3] Ver Custos de um Jogador num Campeonato \n";
    cout << endl << " [0] EXIT.\n" << endl;
    switch (askOption()) {
        case 0:
            return;
        case 1:
        {
            do {
                string id = AskConvocatoriaProcedure();
                try {
                    s.showConvocatoriaCosts(id);
                    break;
                }
                catch (ConvocatoriaInexistente & Ci) {
                    cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
                }
            } while (1);
            break;
        }
        case 2:
        {
            s.showAllCosts();
            break;
        }
        case 3:
        {
            do {
                string id_conv = AskConvocatoriaProcedure();
                string id_player = AskPlayerProcedure();
                
                try {
					JogadorSelecao* j = s.GetPlayerConvocatoria(id_player,id_conv);
                    s.ShowConvocatoriaPlayerCost(id_conv,j);
                    break;
                }
                catch (ConvocatoriaInexistente & Ci) {
                    cout << "A convocatoria com o id:  " << Ci.getId() << " nao existe!" << endl;
                }
				catch (JogadorInexistente & Ji) {
					cout << "O jogador com o numero:  " << Ji.getNum() << " nao existe nesta convocatoria!" << endl;
				}
            } while (1);
        }
    }
}

int askOption() {
	int option = 0;

	cin >> option;

	if (cin.fail()) {
		cin.clear();
		option = -1;
	}
	cin.ignore();

	return option;
}