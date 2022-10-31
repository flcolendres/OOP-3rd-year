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
#include "Book.h"
using namespace std;
namespace sdds
{
   void trim(std::string& str)
   {
      size_t beginning = str.find_first_not_of(" ");
      size_t last = str.find_last_not_of(" ");
      str = str.substr(beginning, last - beginning + 1);
   }
   Book::Book(const std::string& strBook)
   {
      string str = strBook;
      m_author = str.substr(0, str.find(','));
      trim(m_author);
      str.erase(0, str.find(',') + 1);
      m_title = str.substr(0, str.find(','));
      trim(m_title);
      str.erase(0, str.find(",") + 1);
      m_cPub = str.substr(0, str.find(',')); 
      trim(m_cPub);
      str.erase(0, str.find(",") + 1);
      m_price = stod(str.substr(0, str.find(',')));
      str.erase(0, str.find(",") + 1);
      m_year = stoi(str.substr(0, str.find(',')));
      str.erase(0, str.find(",") + 1);
      m_desc = str.substr(0, str.find('\n'));
      trim(m_desc);
   }
   std::ostream& operator<<(std::ostream& ostr, const Book& B)
   {
      //AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
      if (B)
      ostr << setw(20) << B.m_author << " | " << setw(22) << B.m_title << " | " << setw(5)
         << B.m_cPub << " | " << setw(4) << B.m_year << " | " << setw(6) << fixed << setprecision(2) << B.m_price << " | " << B.m_desc << endl;
      return ostr;
   }

}
