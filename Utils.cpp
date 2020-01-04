#include "Utils.h"
#include <stdexcept>


JogadorSelecao * AddPlayerProcedure() {
	string name, posicao, clube, numero, peso, altura, dN;
	double salario;

	cout << "Name: ";
	getline(cin, name);
	cout << "Posicao: ";
	getline(cin, posicao);
	cout << "Clube: ";
	getline(cin, clube);
	cout << "Numero: ";
	getline(cin, numero);
	cout << "Peso: "; 
	getline(cin, peso);
	cout << "Altura: "; 
	getline(cin, altura);
	cout << "Data de Nascimento: "; 
	getline(cin, dN);
	cout << "Salario: ";
	cin >> salario;
	JogadorSelecao* new_player = new JogadorSelecao(name, posicao, clube, numero, peso, altura, dN, salario);
	return new_player;
}

Staff * AddStaffProcedure(){
    int salario;
    string nome, funcao, dNascimento,contrato;
    cout << "Name: ";
    getline(cin, nome);
    cout << "Data Nascimento: ";
    getline(cin, dNascimento);
    cout << "Funcao: ";
    getline(cin,funcao);
    cout << "Salario: ";
    cin >> salario;
    cout<<"Contrato(atual ou antigo):";
    cin>>contrato;

    Staff * new_staff = new Staff(nome,dNascimento, funcao,salario,contrato);

    return new_staff;
}

string AskPlayerProcedure() {
	string numero;
	cout << "Insira o numero do Jogador que pretende aceder: "; cin >> numero;
	return numero;
}

string AskStaffProcedure() {
    string nome;
    cout << "Insira o nome do Staff que pretende aceder: ";
    getline(cin, nome);
    return nome;
}

string AskConvocatoriaProcedure() {
	string id;
	cout << "Insira o numero da convocatoria a aceder: "; cin >> id;
	return id;
}

string AskGameProcedure() {
	string num;
	cout << "Insira o numero do jogo a aceder: "; cin >> num;
	return num;
}

string AskDateProcedure() {
    string day;
	cout << "Insira o dia de lesao: "; cin >> day;
    return day;
}
string AskProductProcedure(){
    string nome;
    cout << "Insira o produto que pretende comprar: ";
    getline(cin, nome);
    return nome;
}
Fornecedor AskFornecedorProcedure(){
    string nome, rating,produto;
    vector<string> products;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Rating: ";
    getline(cin, rating);
    cout << "Produtos?('n' se nao houver mais a adicionar)" << endl;
    do {
        getline(cin, produto);
        if (produto != "n")
            products.push_back(produto);
    } while (produto != "n");

    Fornecedor f =Fornecedor(nome,stoi(rating),products);

    return f;
}

int getCampNum(vector<Convocatoria*> c) {
	cout << "A que campeonato pretende aceder?\n";
	for (unsigned int i = 0; i < c.size(); i++) { //mostra os campeonatos a que a sele�ao foi
		cout << "Campeonato " << i + 1 << " : ";
		cout << c[i];
		cout << endl;
	}
	int i;

	cin >> i; //input do utilizador -> nr do campeonato
	i--; //-1 pq vetor come�a em 0 e op�oes do utilizador em 1
	return i;
}
