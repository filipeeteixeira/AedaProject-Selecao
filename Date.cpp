#include "Date.h"

Date::Date(){
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(string date){
	vector<string> DateComponents;
	string segment;
	stringstream test(date);
	while (getline(test, segment, '/'))
	{
		DateComponents.push_back(segment);
	}
	this->year = stoi(DateComponents[2]);
	this->month= stoi(DateComponents[1]);
	this->day= stoi(DateComponents[0]);
}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const{
	return day;
}

unsigned short Date::getMonth() const{
	return month;
}
    
unsigned Date::getYear() const{
	return year;
}


// disply a Date in a nice format
ostream& operator<<(ostream& out, const Date & date){
	out << date.getDay() << '/' << date.getMonth() << '/' << date.getYear() ;
	return out;
}
