/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 20, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "TennisLog.h"
using namespace sdds;
using namespace std;

std::ostream& sdds::operator<<(std::ostream& os, const TennisMatch& tm)
{
   if (tm.matchID > 0)
   {
      os.setf(ios::left);
      os << "Tourney ID : "; 
      os << tm.tournamentID << endl;
      os << "Match ID : " << tm.matchID << endl;
      os << "Tourney : "
   }
   return os;
}
