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
using namespace std;

namespace sdds
{
   class Van : public Vehicle
   {
      std::string m_maker;
      char m_type;
      char m_condition;
      char m_purpose;
      double m_topSpeed;
   public:
      std::string condition() const;
      double topSpeed() const;
      std::string type() const;
      std::string usage() const;
      void display(std::ostream& out) const;
   }; 
}