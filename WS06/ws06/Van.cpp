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
#include "Van.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
   Van::Van(std::istream& is)
   {
      string str;
      getline(is, str);
      if (str[0] == 'v' || str[0] == 'V')
      {
         str.erase(0, str.find(',') + 1);
         m_maker = str.substr(0, str.find(','));
         trim(m_maker);
         str.erase(0, str.find(',') + 2);
         if (str[0] == 'p')
            m_type = "pickup";
         else if (str[0] == 'm')
            m_type = "mini-bus";
         else if (str[0] == 'c')
            m_type = "camper";
         str.erase(0, str.find(',') + 2);
         if (str[0] == 'd')
            m_purpose = "delivery";
         else if (str[0] == 'p')
            m_purpose = "passenger";
         else if (str[0] == 'c')
            m_purpose = "camping";
         str.erase(0, str.find(',') + 2);
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
   void Van::display(std::ostream& out) const
   {
      //| MAKER | TYPE | USAGE | CONDITION | TOP_SPEED |
      out << "| " << setw(8) << m_maker << " | " << setw(12) << left << m_type << " | " << setw(12) << m_purpose << " | "
         << setw(6) << m_condition << " | " << right << setw(6) << fixed << setprecision(2) << m_topSpeed << " |" << endl;
   }
}
