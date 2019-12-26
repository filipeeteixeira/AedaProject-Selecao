#ifndef FINAL_JOGADOR_H
#define FINAL_JOGADOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jogador {
private:
    string nome,posicao,clube,numero;
public:
    /**
    * @brief Constructor of class Jogador
    *
    * @param n is the name
    * @param p is the position
    * @param c the club
    * @param num the number
    */
    Jogador(string n,string p,string c,string num);

    /**
* @brief prints player info
*
*
*/
    virtual void getInfo(); //retorna todas as informações do Jogador

    /**
* @brief Checks if a player is from the nacional team
*
*
@return true if it is false otherwise
*/
    virtual bool eJogadorNacional(){return false;};

    /**
* @brief Returns a player number
*
@return this->numero
*/
    virtual string getNumero() const{return numero;};


    /**
* @brief  Overloads << operator so it can print the vital information of a player
*
*
* @param c the club

@return this->numero
*/
	friend ostream& operator<<(ostream& out, Jogador* jog);


    /**
* @brief Returns a player position
*
*
@return this->posicao
*/

	virtual string getPosicao() const;


    /**
* @brief Returns a players nome
*
*
@return this->posicao
*/
	virtual string getNome() const;


    /**
* @brief Returns a players Club
*
*
@return this->clube
*/
	virtual string getClube() const;
};

class JogadorSelecao :public Jogador{
private:
    string peso,altura,dNascimento;
    double valorPasse;
public:
    void getInfo();

    /**
* @brief Constructor of class Jogador Selecao
*
* @param n is the name
* @param p is the position
* @param c the club
* @param num is the number
* @param peso is the weight
* @param altura is the height
* @param dn the birthdate
* @param vp the marketValue
*/
    JogadorSelecao(string n,string p,string c,string num,string peso,string altura, string dn,double vp);

    bool eJogadorNacional(){return true;};
    string getNumero() const{return Jogador::getNumero();};


    /**
* @brief * Sets a players peso to a parameter p
*
*@param p is the peso
*/
	void setPeso(string p);

    /**
* @brief Sets a players altura to a parameter h
*
*@param h is the altura
*/
	void setAltura(string h);

    /**
* @brief Sets a players posse to a parameter h
*
*@param vp is the valorPasse
*/
	void setPasse(double vp);

    /**
* @brief Gets a players passe
*
*
@return this->valorPasse
*/
	double getPasse();

    /**
* @brief Gets a players peso
*
*
@return this->peso
*/
	string getPeso();

    /**
* @brief Gets a players altura
*
*
@return this->altura
*/
	string getAltura();

    /**
* @brief Gets a players data de nascimento
*
*
@return this->dNascimento
*/
	string getDNas();

	friend ostream& operator<<(ostream& out, JogadorSelecao* jog);
};

class JogadorInexistente : public std::exception {

private:
	/**
	 * N do jogador nao existente
	 */
	string num;

public:
	/**
	 * Construtor da classe
	 * @param num do jog nao existente
	 */
	JogadorInexistente(string num) : num(num) {}

	/**
	 * Metodo de acesso ao num do jog que nao existe
	 * @return num do jog nao existente
	 */
	string getNum() { return num; }

};


#endif //FINAL_JOGADOR_H