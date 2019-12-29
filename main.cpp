
#include "Convocatoria.h"
#include "Menus.h"
#include "Utils.h"
#include <fstream>
#include "Selecao.h"


int main() {

	Selecao s; //cria o objeto selecao

	/*ao ler os 3 ficheiros constroi-se o objeto seleçao
	1- criar os objetos de staff e jogadores que existem
	2- criar os objetos de jogos que existem
	3- criar os objetos de convocatorias que existem
	-a seleção contem vetores com o staff, os jogadores os jogos e as convocatorias*/
	s.ReadFile("..//Populacao.txt", "..//Jogos.txt","..//Convocatorias.txt");

	/*começa o programa com o menu principal*/
	BegginingMenu(s);

}

