/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 29, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
   Car::Car(std::istream& is)
   {
      string str;
      getline(is, str);
      trim(str);
      if (str[0] == 'C' || str[0] == 'c' || str[0] == 'R' || str[0] == 'r')
      {
         str.erase(0, str.find(',') + 1);
         m_maker = str.substr(0, str.find(','));
         trim(m_maker);
         str.erase(0, str.find(',') + 1);
         trim(str);
         if (str[0] == 'n' || str[0] == ',') // ',' represents empty record
            m_condition = "new";
         else if (str[0] == 'u')
            m_condition = "used";
         else if (str[0] == 'b')
            m_condition = "broken";
         else
            throw("Invalid record!");
         str.erase(0, str.find(',') + 1);
         trim(str);
         if (isdigit(str[0]))
            m_topSpeed = stod(str);
         else
            throw("Invalid record!");
      }
   }
   void Car::display(std::ostream& out) const
   {
      //| MAKER | CONDITION | TOP_SPEED |
      out << "| " << setw(10) << m_maker << " | "
         << setw(6) << left << m_condition << " | " << right << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
   }
}