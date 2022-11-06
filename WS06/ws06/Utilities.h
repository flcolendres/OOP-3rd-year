/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 29, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
   Vehicle* createInstance(std::istream& in);
   void trim(std::string& str);
}