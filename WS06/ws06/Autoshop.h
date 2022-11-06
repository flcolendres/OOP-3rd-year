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
#include "Vehicle.h"
namespace sdds
{
   class Autoshop
   {
      std::vector<Vehicle*> m_vehicles{};
   public:
      Autoshop() {};
      Autoshop(const Autoshop& A);
      Autoshop& operator=(const Autoshop& A);
      Autoshop(Autoshop&& A);
      Autoshop& operator=(Autoshop&& A);
      ~Autoshop();
      Autoshop& operator+=(Vehicle* theVehicle);
      void display(std::ostream& out) const;
   };
}