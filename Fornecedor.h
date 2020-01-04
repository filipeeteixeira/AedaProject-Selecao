//
// Created by Utilizador
//

#ifndef UNTITLED_FORNECEDOR_H
#define UNTITLED_FORNECEDOR_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Fornecedor {
    string nome;
    int reputacao;
    vector<string> tiposProduto;
public:
    /** @brief * Fornecedor Constructor
*@param nome is the supplier's name
* @param rep is the supplier's reputation
*@param tipos is the supplier's products
    */
    Fornecedor(string nome, int rep,vector<string> tipos);

    /** @brief * Returns a supplier's reputation
*@return Reputation
    */
    int getReputacao() const {return this->reputacao;};


    /** @brief * Sets a supplier's reputation
*@param rep is the new reputation
*/
    void setReputacao(int rep) {this->reputacao = rep;};


    /** @brief * Returns a supplier's name
*@return Name
*/
    string getNome() const {return this-> nome;};

    /** @brief * Makes a purchase of a given product to the highest ranked supplier
*@return User review after the buy(int)
*/
    int compra();



    /** @brief * Checks if a supplier has a given product
*@param product is the product to search for
* @return true if found, false otherwise
*/
    bool stock(string product);


    /** @brief * Returns the supplier's products
*@return vector with all the supplier's products
*/
    vector<string> getProdutos() {return this-> tiposProduto;};
};


/** @brief * Operator overload+
*@param f1 is the first supplier
* @param f2 is the second supplier
*@return true is f1's rating is less than f2's rating, false otherwise
*/
bool operator<(const Fornecedor& f1, const Fornecedor& f2);
#endif //UNTITLED_FORNECEDOR_H
