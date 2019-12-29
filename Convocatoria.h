#ifndef FINAL_CONVOCATORIA_H
#define FINAL_CONVOCATORIA_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Jogo.h"
#include "Staff.h"
#include "Date.h"
#include "Jogador.h"

using namespace std;

class Convocatoria {
	vector<Jogo*> campeonato;
	vector<JogadorSelecao*> jogadoresConvocados;
	vector<Staff*> staffConvocado;
	Selecionador* SelecionadorConvocado;
	string tipo_campeonato, id;
	Date data_inicio, data_fim;
	map<string,string> lesoes;
public:

    /** @brief * Competition Constructor
     * @param tc is the competition type
     * @param di is an object date with the beggining date
     * @param df is an object date with the ending date
*/
    Convocatoria(string tc, Date di, Date df);



    /** @brief * Adds a Game to the competition
 * @param j is a pointer to the game
*/
	void addJogo(Jogo* j);



    /** @brief * Adds an injury to the game
* @param id_player is the number of the injured player
 * @param day is the day of the injury
*/
	void addLesao(string id_player,string day);



    /** @brief * Adds a selected player to the competition
* @param j is a pointer to the player
*/
	void addJogadorConvocado(JogadorSelecao* j);



    /** @brief * Removes a selected player from the competition
* @param num is the players number
*/
	void RemoveJogadorConvocado(string num);



    /** @brief * Adds a selected staff member to the competition
* @param s is a pointer to the staff member
*/
	void addStaffConvocado(Staff* s);


	void setSelecionadorConvocado(Selecionador *s);


    /** @brief * Prints the competition info
*/
	void getInfo() const;



    /** @brief * Returns the cost of all the players
* @return total cost of the competition's  national players
*/
	double getPlayersCost() const;


    /** @brief * Returns the cost of all the staff
* @return total cost of the competition's  staff
*/
	double getStaffCost() const;


    /** @brief * Returns the competition's duration
* @return duration of the competition
*/
	int getDuration() const;




    /** @brief * Returns the competition's number of games
* @return competition's number of games
*/
	int getNumJogos() const;



    /** @brief * shows the cost of a selected player
* @param j is a pointer to the player
*/
	void showPlayerCost(JogadorSelecao* j);


    /** @brief * Shows the competition's national selected players
*/
	void showPlayers() const;


    /** @brief * Shows the competition's national selected staff
*/
	void showStaff() const;



    /** @brief * Shows the competition's statistics for a given player
     * @param num is the players number
*/
	void showPlayerStatistics(string num);



    /** @brief * Shows the competition's best player in each category
*/
	void showBestStats() const;


    /** @brief * Sets competition's type
     * @param tc is the competition's type
*/
	void setTipoCampeonato(string tc);


    /** @brief * Sets competition's id
   * @param id is the competition's id
*/
	void setId(string id);

    /** @brief * Sets competition's beggining date
* @param x is the competition's beggining date
*/
	void setBegginingDate(Date x);


    /** @brief * Sets competition's ending date
* @param y is the competition's ending date
*/
	void setEndingDate(Date y);


    /** @brief * Gets competition's type
* @return this->tipo_campeonato
*/
	string getTipoCampeonato() const;



    /** @brief * Gets competition's id
* @return this->id
*/
	string getId() const;


    /** @brief * Gets competition's beggining date
* @return beggining date
*/
	Date getDataInicio() const;


    /** @brief * Gets competition's ending date
* @return ending date
*/
	Date getDataFim() const;


    /** @brief * Gets competition's national players
* @return vector with pointers to the national players on the competition
*/
	vector<JogadorSelecao*>getJogadores() const;


    /** @brief * Gets competition's games
* @return vector with pointers to games on the competition
*/
	vector<Jogo*>getCampeonato() const;

    /** @brief * Gets competition's national staff
* @return vector with pointers to the national staff on the competition
*/
	vector<Staff*>getStaffConvocado() const;

    /** @brief * Prints competition in a friendly way
* @param cnv is a pointer to the competition
*/

	friend ostream& operator<<(ostream& out, Convocatoria* cnv);
};

class ConvocatoriaInexistente{

private:
	string id;
public:


    /** @brief * Unexisting competition class constructor
* @param id is the competition's id
*/
	ConvocatoriaInexistente(string id) : id(id) {}



    /** @brief * Gets Unexisting competition's id
* @return Unexisting competition's id
*/
	string getId() { return id; }

};

/** @brief * Sorts players based on number or name
* @param v is a vector of pointers to national players to be sorted
 * @param type is the criteria
*/
void StaffBubbleSort(vector<Staff*>& v, string type);


/** @brief * Sorts staff based on salary or name
* @param v is a vector of pointers to national staff to be sorted
 * @param type is the criteria
*/
void PlayerBubbleSort(vector<JogadorSelecao*>& v, string type);

#endif