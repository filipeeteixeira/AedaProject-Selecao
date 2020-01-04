#include <fstream>
#include "Convocatoria.h"
#include "Fornecedor.h"


/** @brief * Asks for params to build player object and return a pointer to that same object
*
*@return JogadorSeleçao*
*/
JogadorSelecao * AddPlayerProcedure();

/** @brief * Asks for params to build staff object and return a pointer to that same object
*
*@return Staff*
*/
Staff * AddStaffProcedure();

/** @brief * Asks for the number of the player user wants to access and returns that number
*
*@return string PlayerNumber
*/

string AskPlayerProcedure();

/** @brief * Asks for the number of the competition user wants to access and returns that number
*
*@return string CompetitionNumber
*/
string AskConvocatoriaProcedure();

/** @brief * Asks for the name of the staff user wants to access and returns that name
*
*@return string StaffName
*/

string AskStaffProcedure();

/** @brief * Asks for the day user wants injure a player and returns that day
*
*@return InjuryDay
*/

string AskDateProcedure();

/** @brief * Returns the position of the chosen competition on the param vector
*@param c is a vector with all the competitions
*@return Position of the chosen competition
*/

int getCampNum(vector<Convocatoria*> c);

/** @brief * Returns the name of the product the user wants to buy
*@return String with the product name
*/
string AskProductProcedure();


/** @brief * Returns the supplier with a given name
*@return Supplier with the given name
*/
Fornecedor AskFornecedorProcedure();

