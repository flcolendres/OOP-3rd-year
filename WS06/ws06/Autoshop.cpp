/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 29, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <vector>
#include <iterator>
#include "Autoshop.h"

using namespace std;
namespace sdds
{
   Autoshop::Autoshop(const Autoshop& A)
   {
      *this = A;
   }
   Autoshop::Autoshop(Autoshop&& A)
   {
      *this = move(A);
   }
   Autoshop& Autoshop::operator=(const Autoshop& A)
   {
      if (this != &A)
         m_vehicles = A.m_vehicles;
      return *this;
   }
   Autoshop& Autoshop::operator=(Autoshop&& A)
   {
      if (this != &A)
         m_vehicles = move(A.m_vehicles);
      return *this;
   }
   Autoshop::~Autoshop()
   {
      int i = 0;
      for (auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++, i++)
         delete m_vehicles[i];
   }
   Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
   {
      m_vehicles.push_back(theVehicle);
      return *this;
   }
   void Autoshop::display(std::ostream& out) const
   {
      //for (auto e : m_vehicles)
      //   e->display(out);
      for (auto itr = m_vehicles.begin(); itr != m_vehicles.end(); itr++)
         (*itr)->display(out);
   }
}
