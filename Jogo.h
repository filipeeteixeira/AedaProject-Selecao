//
// Created by Rodrigo Abrantes on 08/11/2019.
//

#ifndef FINAL_JOGO_H
#define FINAL_JOGO_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Jogador.h"
using namespace std;

class Jogo {
private:
	string nome, cidade, pais, estadio, id_conv;
    vector<Jogador*> equipa_adversaria;
    vector<JogadorSelecao*> jogadores_convocados;
    vector<string> equipa_arbitragem;
public:
    struct Estatisticas {  //struct com as estatisticas do jogo
        map<JogadorSelecao*,int>golos;
		map<JogadorSelecao*, int>passes;
        map<JogadorSelecao*,double>kmPercorridos;
        map<JogadorSelecao*,string>cartoes;
		map<JogadorSelecao*, int>minJogados;
    };


/** @brief * Constructor of Jogo
*
* @param cidade is the game city
* @param pais is the game country
* @param estadio is the game stadium
*/
    Jogo(string cidade, string pais, string estadio);




/** @brief * Constructor of Jogo
*
 * @param nome is the game name
 * @param id_conv is the game's competition id
 * @param cidade is the game city
* @param pais is the game country
* @param estadio is the game stadium
*/
	Jogo(string nome, string id_conv, string cidade, string pais, string estadio);
	Estatisticas stats;



/** @brief * Prints game's full info
*
*/
    void getInfo() const;



/** @brief * Returns goals scored by a given player
* @param j is the pointer to the selected player
 * @return nr of scored goals
*/
    int getGolos(JogadorSelecao* j);



    /** @brief * Returns passes made by a given player
* @param j is the pointer to the selected player
 * @return nr of passes made
*/
    int getPasses(JogadorSelecao* j);



    /** @brief * Returns kms ran by a given player
* @param j is the pointer to the selected player
 * @return kms ran
*/
    double getKms(JogadorSelecao* j);



    /** @brief * Returns minutes played by a given player
* @param  j is the pointer to the selected player
 * @return minutes played
*/
    int getMin(JogadorSelecao* j);



    /** @brief * Returns nr of cards a given player got
* @param j is the pointer to the selected player
 * @return nr of cards
*/
    int getCartoes(JogadorSelecao* j);



    /** @brief * Returns game's name
 * @return this->nome
*/
	string getNome();



    /** @brief * Returns game's competition id
* @return this->id_conv
*/
	string getID();



    /** @brief * Returns game's city
* @return this->cidade
*/
	string getCidade();



    /** @brief * Returns game's country
* @return this->pais
*/
	string getPais();



    /** @brief * Returns game's stadium
* @return this->estadio
*/
	string getEstadio();



    /** @brief * Returns game's opposing team
* @return this->equipa_adversaria
*/
	vector<Jogador*> getEquipaAdversaria() const;



    /** @brief * Returns game's national team
* @return this->jogadores_convocados
*/
	vector<JogadorSelecao*> getJogadoresConvocados() const;



    /** @brief * Returns game's referee team
* @return this->equipa_arbitragem
*/
	vector<string> getEquipaArbitragem() const;



    /** @brief * Returns game's stats
* @return this->stats
*/
	Estatisticas getEstatisticas() const { return stats; };



/** @brief * Sets game's stats
     * @param j is a pointer to the player with the given stats
     * @param golos are the goals scored
     * @param passes are the passes made
     * @param kms are the kms ran
     * @param cart are the cards received
     * @param minJog the minutes played
*/

    void setEstatisticas(JogadorSelecao* j, int golos, int passes, double km, string cart,int minJog);



    /** @brief * Adds a opposition player to the game
* @param Adv is a pointer to the selected player
*/
    void addJogadorAdversario(Jogador* Adv);



    /** @brief * Adds a national player to the game
* @param jog is a pointer to the selected player
*/
	void addJogadorConvocado(JogadorSelecao* jog);



    /** @brief * Removes a national player from game
* @param num is the player number
*/
	void RemoveJogadorConvocado(string num);



    /** @brief * Adds referees to the game
* @param arb is a string with the referee name
*/
	void addEquipaArbitragem(string arb);



    /** @brief * Sets game's name
* @param n is the new name
*/

	void setNome(string n);



    /** @brief * Sets game's city
* @param c is the new city
*/
	void setCidade(string c);




    /** @brief * Sets game's country
* @param p is the new country
*/
	void setPais(string p);

    /** @brief * Sets game's arbitros
* @param arbitros is the vector of arbitros names
*/
	void setArbitros(vector<string>arbitros);


    /** @brief * Sets game's stadium
* @param e is the new stadium
*/
	void setEstadio(string e);



    /** @brief * Sets game's competition id
* @param id is the new game's competition id
*/
	void setIdConv(string id);



    /** @brief * Shows the stats of a chosen player on the game
     * @param num is the player's number
     * @param p are the passes
     * @param g are the goals
     * @param m are the minutes played
     * @param k are the kms ran
     * @param c is a vector with the received cards
*/
    void showPlayerGameStats(string num,int& p, int& g, int& m, double& k, vector<string>& c);



    /** @brief * Prints game's important information in a friendly way
     * @param jogo is a pointer to the selected game
*/

    friend ostream& operator<<(ostream& out, Jogo* jogo);
};

class JogoInexistente : public std::exception {

private:

	string nome;

public:

    /** @brief * Contructor of exception
     * @param nome the name of the unexisting player
*/


    JogoInexistente(string nome) : nome(nome) {}


};

#endif //FINAL_JOGO_H
