/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 20, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include<fstream>
#include "TennisLog.h"
using namespace sdds;
using namespace std;

std::ostream& sdds::operator<<(std::ostream& os, const TennisMatch& tm)
{
   if (tm.matchID > 0)
   {
      os.width(20);
      os.fill('.');
      os << "Tourney ID"; os << " : " << endl;
      os.setf(ios::left);
      os.width(30);
      os.fill('.');
      os << tm.tournamentID << endl;
      os.unsetf(ios::left);
      os.width(20);
      os.fill('.');
      os << "Match ID"; os << " : ";
      os.setf(ios::left);
      os.width(30);
      os.fill('.');
      os << tm.matchID << endl;
      os.unsetf(ios::left);
      os.width(20);
      os.fill('.');
      os << "Tourney"; os << " : ";
      os.setf(ios::left);
      os.width(30);
      os.fill('.');
      os << tm.tournamentName << endl;
      os.unsetf(ios::left);
      os.width(20);
      os.fill('.');
      os << "Winner"; os << " : ";
      os.setf(ios::left);
      os.width(30);
      os.fill('.');
      os << tm.matchWinner << endl;
      os.unsetf(ios::left);
      os.width(20);
      os.fill('.');
      os << "Loser"; os << " : ";
      os.setf(ios::left);
      os.width(20);
      os.fill('.');
      os << tm.matchLoser << endl << endl;
   }
   return os;
}

sdds::TennisLog::TennisLog(const char* fileName)
{
   TennisMatch* tm;
   int numMatches = 0;
   string str;
   ifstream f;
   f.open("tennis-data.csv");
   if (f.is_open())
   {
      while (!f.eof())
      {
         getline(f, str);
         if (str[0] >= '0' && str[0] <= '9') numMatches++;
      }
      tm = new TennisMatch[numMatches];
      f.clear();
      f.seekg(0);
      getline(f, str, '\n');
      for (int i = 0; i < numMatches && !f.eof(); i++)
      {
         getline(f, str, ',');
         tm[i].tournamentID = str.c_str();
         getline(f, str, ',');
         tm[i].tournamentName = str.c_str();
         f >> tm[i].matchID;
         f.ignore(',');
         getline(f, str, ',');
         tm[i].matchWinner = str.c_str();
         getline(f, str, '\n');
         tm[i].matchLoser = str.c_str();
         f.ignore(1000, '\n');
      }
   }
}

void sdds::TennisLog::addMatch(TennisMatch& tm)
{
   TennisMatch* newTennis;
   int i = sizeof(tm);
   newTennis = new TennisMatch[i + 1];
   newTennis = &tm;

}

TennisLog& sdds::TennisLog::findMatches(const char* name)
{
   // // O: insert return statement here
}
