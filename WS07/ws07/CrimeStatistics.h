/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Nov. 08, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include <iostream>
#include <vector>
#include <list>
namespace sdds
{
   struct Crime
   {
      std::string m_province{};
      std::string m_district{};
      std::string m_crime{};
      int m_numCases{};
      int m_year{};
      int m_resolved{};
      Crime() {};
   };
   class CrimeStatistics
   {
      std::vector<Crime> crime;
   public:
      CrimeStatistics(const std::string& fileName);
      void display(std::ostream& out) const;
      void trim(std::string& str);
      void sort(const std::string& str);
      void cleanList();
      bool inCollection(const std::string& str) const;
      std::list<Crime> getListForProvince(const std::string& str) const;
   };
   std::ostream& operator<<(std::ostream& out, const Crime& theCrime);


}