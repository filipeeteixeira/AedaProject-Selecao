//
// Created by Utilizador on 08/11/2019.
//

#ifndef FINAL_STAFF_H
#define FINAL_STAFF_H

#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include <vector>

using namespace std;

class Staff {
private:
    int salario;
    string nome, funcao, dNascimento;
public:
	Staff(string nm, string dNas, string fnc, int s);
    /** @brief * Constructs object Staff
  *
  *@param nm is the name
  *@param dNas is the birth Date
  *@param fnc is the function
  *@param s is the salary
  */

    string getNome(){return nome;}
/** @brief * Gets staff name
  *@return this->nome
*/

	string getDNascimento() { return dNascimento; }
/** @brief * Gets staff birth date
    *@return this->dNascimento
*/


	string getFuncao() { return funcao; }
/** @brief * Gets staff function
    *@return this->funcao
*/
	int getSalario() const { return this->salario; }

/** @brief * Gets staff salary
    *@return this->salario
*/

    void setFuncao(string f){this->funcao=f;}

/** @brief * Sets staff function
    *@param f is the new funtion
*/
    void setSalario(string s){this->salario=stoi(s);}

    /** @brief * Sets staff salary
    *@param s is the new salary
*/
    
	friend ostream& operator<<(ostream& out, Staff* stf);

/** @brief * Prints staff in a friendly way
    *@param stf is the pointer to the staff we want to print
*/
};

class Selecionador :public Staff{
    string nome;
    unsigned int titulosGanhos;
    vector<tuple<string,Date>> selecoes;
public:
    Selecionador(string nm, string dNas, string fnc, int s, unsigned int titulosGanhos, vector<tuple<string,Date>> sel);
    void getInfo();
    friend ostream& operator<<(ostream& out, Selecionador* sl1);
    bool operator<(Selecionador * sl1);
};

class StaffInexistente{

private:
 
    string nome;

public:
    StaffInexistente(string nome) : nome(nome) {}
    /** @brief * Constructs object Staffinexistente
*
*@param nomem is the name
*/

    string getNome() { return nome; }

};


#endif //FINAL_STAFF_H
