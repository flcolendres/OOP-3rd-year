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
      if (str[0] == 'C' || str[0] == 'c')
      {
         str.erase(0, str.find(',') + 1);
         m_maker = str.substr(0, str.find(','));
         trim(m_maker);
         str.erase(0, str.find(',') + 1);
         trim(str);
         if (str[0] == 'n')
            m_condition = "new";
         else if (str[0] == 'u')
            m_condition = "used";
         else if (str[0] == 'b')
            m_condition = "broken";
         str.erase(0, str.find(',') + 1);
         if (stoi(str))
         {
            m_topSpeed = stod(str);
         }
      }
   }
   void Car::display(std::ostream& out) const
   {
      //| MAKER | CONDITION | TOP_SPEED |
      out << "| " << setw(10) << m_maker << " | " 
         << setw(6) << left << m_condition << " | " << right << setw(6) << fixed << setprecision(2) << m_topSpeed << " |" << endl;
   }
}