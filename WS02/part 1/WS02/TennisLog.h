/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 20, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include <iostream>
#include <string>
namespace sdds
{
   struct TennisMatch
   {
      std::string tournamentID{};
      std::string tournamentName{};
      int matchID{};
      std::string matchWinner{};
      std::string matchLoser{};
   };   
   class TennisLog
   {
   public:
      TennisLog() {};
      TennisLog(const char* fileName = nullptr);
      void addMatch(TennisMatch& tm);
      TennisLog& findMatches(const char* name);
      TennisMatch& operator[](size_t);
      operator size_t();
   };
   std::ostream& operator<< (std::ostream& os, const TennisMatch& tm);
}