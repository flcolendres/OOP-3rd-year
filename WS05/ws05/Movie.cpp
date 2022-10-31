/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 09, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Book.h"
using namespace std;
namespace sdds
{  
   Movie::Movie(const std::string& strMovie)
   {
      string str = strMovie;
      m_title = str.substr(0, str.find(','));
      trim(m_title);
      str.erase(0, str.find(',') + 1);
      m_year = stoi(str.substr(0, str.find(',')));
      str.erase(0, str.find(',') + 1);
      m_desc = str;
      trim(m_desc);
   }
   std::ostream& operator<<(std::ostream& ostr, const Movie& M)
   {
      ostr << setw(40) << M.m_title << " | " << setw(4) << M.m_year << " | " << M.m_desc << endl;
      return ostr;
   }
}