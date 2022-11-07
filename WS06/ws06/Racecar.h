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
#include <vector>
#include <iterator>
#include "Car.h" 

namespace sdds
{
   class Racecar : public Car
   {
      double m_booster;
   public:
      Racecar(std::istream& in);
      void display(std::ostream& out) const;
      double topSpeed() const { return Car::topSpeed() + (Car::topSpeed() * m_booster); };
   };
}