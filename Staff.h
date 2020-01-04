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
#include <unordered_set>

using namespace std;


class Staff {

private:
    int salario;
    string nome, funcao, dNascimento,contrato;
public:
    /** @brief * Constructs object Staff
     *
     *@param nm is the name
     *@param dNas is the birth Date
     *@param fnc is the function
     *@param s is the salary
     *@param cntr indicates if staff is hired or was hired
     */
	Staff(string nm, string dNas, string fnc, int s,string cntr);

    /** @brief * Gets staff name
      *@return this->nome
    */
    string getNome() const {return nome;}

    /** @brief * Gets staff birth date
        *@return this->dNascimento
    */
	string getDNascimento() const { return dNascimento; }

    /** @brief * Gets staff function
    *@return this->funcao
    */
	string getFuncao() const { return funcao; }

    /** @brief * Gets staff salary
    *@return this->salario
    */
	int getSalario() const { return this->salario; }

    /** @brief * Gets staff contract
      *@return this->contrato
    */
    string getContrato() const{return this->contrato;  }

    /** @brief * Sets staff function
    *@param f is the new funtion
    */
    void setFuncao(string f){this->funcao=f;}

    /** @brief * Sets staff salary
     *@param s is the new salary
    */
    void setSalario(string s){this->salario=stoi(s);}

    /** @brief * Sets staff contract
      *@param c is the new state of contract
    */
    void SetContrato(string c){(this->contrato=c);}

    /** @brief * Prints staff in a friendly way
    *@param stf is the staff we want to print
    */
	friend ostream& operator<<(ostream& out, const Staff& stf);

};

class Selecionador :public Staff{
    int titulosGanhos;
    vector<tuple<string,Date>> selecoes;
public:
    /** @brief * Constructs object Selecionador
     *
     *@param nm is the name
     *@param dNas is the birth Date
     *@param fnc is the function
     *@param s is the salary
     *@param cntr indicates if staff is hired or was hired
     *@param titulosGanhos is the number of earned titles
     *@param sel is a tuple with the championship won and beggining date of that championship
     */
    Selecionador(string nm, string dNas, string fnc, int s,string cntr, int titulosGanhos, vector<tuple<string,Date>> sel);

    /** @brief * Prints the competition info
    */
    void getInfo();

    /** @brief * Gets Selecionador number of earned titles
      *@return this->titulosGanhos
    */
    int getNtitulos(){return this->titulosGanhos;};

    /** @brief * Gets a vector of selecions head by selecionador
      *@return this->selecoes
    */
    vector<tuple<string,Date>> getSelecoes(){return this->selecoes;};

    /** @brief * adds one title to Selecionador
    */
    void addTituloSelecionador();

    /** @brief * Removes one title to Selecionador
    */
    void subTituloSelecionador();

    /** @brief * Sets a tuple with the championship won and respective beggining date to Selecionador
     *@param cpm is the name of the championship
     *@param data is the beggining date of the championship
    */
    void setSelecoes(string cmp, Date data);

    /** @brief * Prints Selecionador in a friendly way
    *@param sl1 is a pointer to the selecionador we want to print
    */
    friend ostream& operator<<(ostream& out, const Selecionador* sl1);

    /** @brief * Operator overload
    *@param sl1 is the Selecionador to compare
    *@return true is sl1 wining titles or name is higher than this Selecionador, false otherwise
    */
    bool operator<(const Selecionador &sl1) const;
};

class StaffInexistente{

private:
 
    string nome;

public:
    /** @brief * Constructs object Staffinexistente
    *
    *@param nome is the name
    */
    StaffInexistente(string nome) : nome(nome) {}

    /** @brief * Gets the name of the Inexistent staff
    */
    string getNome() { return nome; }

};


#endif //FINAL_STAFF_H
