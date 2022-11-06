/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 29, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <sstream>
#include "Car.h"
#include "Van.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   Vehicle* createInstance(std::istream& in)
   {
      stringstream s;
      string str;
      getline(in, str);
      s << str;
      if (s.str()[0] == 'c' || s.str()[0] == 'C')
         return new Car(s);
      else if (s.str()[0] == 'V' || s.str()[0] == 'v')
         return new Van(s);
      else
         return nullptr;
   }
   void trim(std::string& str)
   {
      size_t beginning = str.find_first_not_of(" ");
      size_t last = str.find_last_not_of(" ");
      str = str.substr(beginning, last - beginning + 1);
   }
}
