#pragma once
#include <vector>
#include <tuple>
#include "Jogador.h"
#include "Staff.h"
#include "Date.h"
#include "Convocatoria.h"
#include "Jogo.h"
#include <tuple>
#include "BST.h"
#include "Date.h"
#include <unordered_set>
#include "queue"
#include "Fornecedor.h"

struct staffhash
{
    int operator() (const Staff & staff1) const
    {
        return(staff1.getNome().size()+ staff1.getSalario()+staff1.getFuncao().size());


    }
};
struct staffeq{
    bool operator() (const Staff & staff1, const Staff & staff2) const
    { return staff1.getNome()==staff2.getNome();

    }
};


typedef unordered_set<Staff,staffhash,staffeq> tabHstaff;

class Selecao {

    tabHstaff stafftotal;//possui a info do vetor equipa tecnica e do vetor staff convocado
    vector<Convocatoria *> campeonatos; //vetor com as diferentes convocatorias da sele�ao
    vector<JogadorSelecao *> TodosJogadores; //vetor com todos os jogadores da sele��o
    vector<Staff> TodosStaffs;
    vector<Jogador *> OutrosJogadores; //vetor com jogadores de equipas adversarias com que a sele�ao ja jogou
    vector<Jogo *> TodosJogos;
    //vector<Staff*> EquipaTecnica;
    BST<Selecionador> TodosSelecionadores;

    vector<Staff> staff_atual;
    vector<Staff> staff_antigo;

public:
    /** @brief * National Team empty constructor
*/


    priority_queue<Fornecedor> fornecedores;


    Selecao();


    void updateStaff();


    /** @brief * Reads the necessary files to populate the program
* @param PersonsFile is the file with the people
 * @param JogosFile is the game's file
  * @param ConvocatoriasFile is the competition's file
     * @return 0 if success
*/
    int ReadFile(string PersonsFile, string JogosFile, string ConvocatoriasFile);


    /** @brief * Writes the necessary files to save the program
* @param PersonsFile is the file with the people
* @param JogosFile is the game's file
* @param ConvocatoriasFile is the competition's file
 * @return 0 if success
*/
    int WriteFile(string PersonsFile, string JogosFile, string ConvocatoriasFile);


    /** @brief * Shows all competition's full info
*/
    void showAllConvocatorias() const;


    /** @brief * Shows selected competition's full info
     * @param id is the competition id
*/
    void showConvocatoria(string id) const;


    /** @brief * Shows selected competition's costs
 * @param id is the competition id
*/
    void showConvocatoriaCosts(string id) const;


    /** @brief * Shows the cost of a selected player on a chosen competition
 * @param id_conv is the competition id
 * @param j is a pointer to the selected player
*/
    void ShowConvocatoriaPlayerCost(string id_conv, JogadorSelecao *j) const;


    /** @brief * Shows the best stats on a chosen competition
* @param id_conv is the competition id
*/
    void showConvocatoriaPlayerStats(string id) const;

    /** @brief * Shows the info on all games on a chosen competition
* @param id is the competition id
*/
    void showAllGames(string id) const;

    /** @brief * Shows all national players
*/
    void showAllPlayers() const;

    /** @brief * Shows the player with the given number
* @param numero is the player's number
*/
    void showPlayer(string numero) const;

    /** @brief * Shows all national staff
*/
    void showAllStaff() const;

/** @brief * Allows to modify the staff info;
 */
    void modifyStaff(Staff st);

    void showAllSelecionadoresC() const;

    void showAllSelecionadoresD() const;

    void showAllSelecionadoresN(int n) const;

    /** @brief * Shows all national costs
*/
    void showAllCosts() const;

    /** @brief * Shows people selected for a given competition
     * @param id is the competition's id
*/
    void showPessoalConvocado(string id) const;


    /** @brief * Adds a player to the national team
 * @param j is a pointer to the selected player
*/
    void AddPlayer(JogadorSelecao *j);

    /** @brief * Removes a player from national team
* @param numero is the player number
*/
    void RemovePlayer(string numero);

    /** @brief * Adds a staff to the national team
* @param s is a pointer to the selected staff
*/
    void AddStaff(Staff *s);

    /** @brief * Removes a staff from national team
* @param nome is the staff name
*/
    void RemoveStaff(string nome);

    /** @brief * Adds a player to a selected competition
 * @param id_conv is the competition's id
 * @param id_player is the player's number
*/
    void addtoConvocatoria(string id_conv, string id_player);

    void AddJogotoConvocatoria(string id_conv);

    /** @brief * Adds a a player injury to a chosen competition
* @param id_conv is the competition's id
* @param id_player is the player's number
 * @param day is the injury day
*/
    void addLesaoConvocatoria(string id_conv, string id_player, string day);

    void MakeConvocatoria();

    vector<Staff> GetStaffAtual();

    vector<Staff> GetStaffAntigo();

    void atualizarEstadoConvocatoria(string estado, string id_conv);

    /** @brief * Gets a pointer to a player with the given number
* @param numero is the player's number
* @return  pointer to the object with that number
*/

    JogadorSelecao *GetPlayerSelecao(string numero);

    /** @brief * Gets a pointer to a national player with the given number in a chosen competition
* @param numero is the player's number
 * @param id is the competition's id
* @return  pointer to the object with that number in that competition
*/
    JogadorSelecao *GetPlayerConvocatoria(string numero, string id);


    /** @brief * Gets a pointer to an opposition player with the given number in a chosen competition
* @param numero is the player's number
* @param id is the competition's id
* @return  pointer to the object with that number in that competition
*/
    Jogador *GetPlayerAdv(string numero);

    /** @brief * Gets a pointer to a game with the given name in a chosen competition
* @param name is the game's name
* @param id is the competition's id
* @return  pointer to the object with that name in that competition
*/
    Jogo *GetJogo(string name, string id);

    /** @brief * Gets a pointer to a competition with the given id
* @param id is the competition's id
* @return  pointer to the object with that id
*/
    Convocatoria *getConvocatoria(string id);

    /** @brief * Gets a staff member with the given name
* @param nome is the staff's name
* @return   object with that name
*/
    Staff GetStaff(string nome);

    /** @brief * Gets a vector with pointers to all competitions
* @return  vector with pointers to all competitions
*/
    vector<Convocatoria *> getAllConvocatorias() const;

    /** @brief * Gets a vector with pointers to all players
* @return  vector with pointers to all players
*/
    vector<JogadorSelecao *> getAllPlayers() const;

    vector<Staff> getAllStaff() const;

    /** @brief * Gets a vector with  all staff
* @return  vector with  all staffs
*/

    Selecionador *getSelecionador(string nome) const;



    /** @brief * Buys a product from the highest ranked supplier
*@param fornecedores is the priority queue with the suppliers
     * @param product is the product the user wants to buy
*/
    void buyProduct(string product, priority_queue<Fornecedor> &fornecedores);


    /** @brief * Shows all Supplier information
*/
    void showAllFornecedores();

    /** @brief * Adds a supplier to the queue
*@param object supplier to be added
*/

    void addFornecedor(Fornecedor f);

    /** @brief * Removes a supplier from the queue
*@param object supplier to be removed
*/

    void removeFornecedor(string nome);


    /** @brief * Sets a chosen supplier's rating
*@param nome is the name of the supplier to change
     * @param rating is the new rating
*/
    void setFornecedorRating(string nome,int rating);

    /** @brief Checks if a given supplier already exists
*@param nome is the name of the supplier
     * @return true if it already exists,false otherwise
*/
    bool existeFornecedor(string nome);


};

