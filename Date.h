#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <chrono>
#include <ctime>

using namespace std;

class Date {
private:
    unsigned short day;
    unsigned short month;
    unsigned year;
public:


    /**
* @brief Constructor of class Date with value of day,month and year set to 0
*
*/
  Date();

    /**
* @brief Constructor of class Date
*
* @param date is the date in dd/mm/yyyy format
*/
  Date(string date);

  // GET methods

  /** @brief * Gets a Date's day
    *
    *@return this->day
    */
  unsigned short getDay() const;

    /** @brief * Gets a Date's month
    *
    *@return this->month
    */
  unsigned short getMonth() const;

    /** @brief * Gets a Date's year
    *
    *@return this->year
    */
  unsigned getYear() const;

  bool operator==(const Date &d1) const;

  bool operator<(const Date &d1) const;

    /** @brief * Prints date in a user friendly way
    *
    */

  friend ostream& operator<<(ostream& out, const Date & date);

};

int DateValidation(string date);

Date getCurrentDate();
/** @brief * returns current date in the form of class date
  *
  */