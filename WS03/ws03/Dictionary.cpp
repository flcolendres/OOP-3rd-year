/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 28, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Dictionary.h"
using namespace sdds;
using namespace std;

std::ostream& sdds::Dictionary::display(std::ostream& ostr) const
{
   ostr << std::setw(20) << m_term << ": " << m_definition;
   return ostr;
}

sdds::Dictionary::operator bool()
{
   return m_term != "";
}

Dictionary& Dictionary::operator=(const Dictionary& D)
{
   setTerm(D.getTerm());
   setDefinition(D.getDefinition());
   return *this;
}

bool sdds::Dictionary::operator==(const Dictionary& D)
{
   return getTerm() == D.getTerm();
}

ostream& sdds::operator<<(std::ostream& ostr, const Dictionary& D)
{
   return D.display(ostr);
}
