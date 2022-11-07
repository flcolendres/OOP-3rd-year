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
#include <sstream>
#include "Racecar.h"
using namespace std;
namespace sdds
{
   Racecar::Racecar(std::istream& in) : Car(in)
   {
      string s;
      in.seekg(0);
      getline(in, s);
      s.erase(0, s.find_last_of(',') + 1);
      m_booster = stod(s);
   }
   void Racecar::display(std::ostream& out) const
   {
      Car::display(out);
      out << "*";
   }
}
