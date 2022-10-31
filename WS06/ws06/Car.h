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
   class Car : public Vehicle
   {
      std::string m_maker;
      std::string m_condition;
      double m_topSpeed;
   public:
      Car(std::istream& is);
      std::string condition() const { return m_condition; };
      double topSpeed() const { return m_topSpeed; };
      void display(std::ostream& out) const;
   };
}