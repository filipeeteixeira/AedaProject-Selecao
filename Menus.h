#include "Selecao.h"
#include "Utils.h"


using namespace std;

/** @brief  Starts the Initial menu
* @param s is the national team to be analyzed
*/
void BegginingMenu(Selecao &s);


/** @brief Starts the Competition's menu
* @param s is the national team to be analyzed
*/

void ConvocatoriasSubMenu(Selecao &s);

/** @brief Starts the Game's menu
* @param s is the national team to be analyzed
*/

void JogosSubMenu(Selecao &s);

/** @brief Starts the Player's menu
* @param s is the national team to be analyzed
*/

void JogadoresSubMenu(Selecao &s);

/** @brief Starts the Staff's menu
* @param s is the national team to be analyzed
*/

void StaffSubMenu(Selecao &s);

/** @brief Starts the Alterate Player's menu
* @param s is the national team to be analyzed
*/

void AlterarJogSubMenu(Selecao& s);

/** @brief Starts the Alterate Staff's menu
* @param s is the national team to be analyzed
*/

void AlterarStaffSubMenu(Selecao &s);

/** @brief  Starts the Costs's menu
* @param s is the national team to be analyzed
*/

void CustosSubMenu(Selecao &s);



/** @brief * Starts the Supplier's menu
*@param s is the national team to be analyzed
*/
void FornecedoresSubMenu(Selecao &s);



void SelecionadoresSubMenu(Selecao &s);

/** @brief  Asks the user to chose an option(in numbers)
* @return option
*/

int askOption();
