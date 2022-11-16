/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Nov. 08, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include "CrimeStatistics.h"

using namespace std;
namespace sdds
{
   CrimeStatistics::CrimeStatistics(const string& fileName)
   {
      ifstream f;
      Crime c;
      if (fileName != "crimes.txt")
         throw("Incorrect file name!");
      else
         f.open(fileName);
      while (!f.eof())
      {
         f >> c.m_province;
         f >> c.m_district;
         f >> c.m_crime;
         f >> c.m_year;
         f >> c.m_numCases;
         f >> c.m_resolved;
         crime.push_back(c);
      }
      f.close();
   }
   void CrimeStatistics::display(ostream& out) const
   {
      for_each(crime.begin(), crime.end(), [&out](Crime elem) { out << elem << endl; });
      ////update this function to display the total cases and resolved cases of the entire collection. See the sample output for the format.
      out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
      out << "|" << setw(80) << "Total Crimes:  " << accumulate(crime.begin(), crime.end(), 0, [](const int& result, const Crime& c) {return result + c.m_numCases; }) << " |" << endl;
      out << "|" << setw(80) << "Total Resolved Cases:  " << accumulate(crime.begin(), crime.end(), 0, [](const int& result, const Crime& c) {return result + c.m_resolved; }) << " |" << endl;
   }
   void CrimeStatistics::trim(std::string& str)
   {
      size_t beginning = str.find_first_not_of(" ");
      size_t last = str.find_last_not_of(" ");
      str = str.substr(beginning, last - beginning + 1);
   };
   void CrimeStatistics::sort(const string& str)
   {
      if (str == "Province")
         std::sort(crime.begin(), crime.end(), [](const Crime& c1, const Crime& c2) {  return c1.m_province < c2.m_province; });
      else if (str == "Crime")
         std::sort(crime.begin(), crime.end(), [](const Crime& c1, const Crime& c2) {  return c1.m_crime < c2.m_crime; });
      else if (str == "Cases")
         std::sort(crime.begin(), crime.end(), [](const Crime& c1, const Crime& c2) {  return c1.m_numCases < c2.m_numCases; });
      else
         std::sort(crime.begin(), crime.end(), [](const Crime& c1, const Crime& c2) {  return c1.m_resolved < c2.m_resolved; });

   }
   ostream& operator<<(std::ostream& out, const Crime& theCrime)
   {
      out << "| " << left << setw(21) << theCrime.m_province << " | " << setw(15) << theCrime.m_district << " | " << setw(20) << theCrime.m_crime << " | "
         << right << setw(6) << theCrime.m_year << " | " << setw(4) << theCrime.m_numCases << " | " << setw(3) << theCrime.m_resolved << " |";
      return out;
   }
   void CrimeStatistics::cleanList()
   {
      std::vector<Crime> newCrime(crime.size());
      transform(crime.begin(), crime.end(), newCrime.begin(), [](Crime elem)
         {
            if (elem.m_crime == "[None]")
               elem.m_crime = "";
            return elem;
         });
      copy(newCrime.begin(), newCrime.end(), crime.begin());
   }
   bool CrimeStatistics::inCollection(const std::string& str) const
   {
      return any_of(crime.begin(), crime.end(), [=](Crime elem) { return elem.m_crime == str; });;
   }
   std::list<Crime> CrimeStatistics::getListForProvince(const std::string& str) const
   {
      list<Crime> c1(crime.size());
      auto it = copy_if(crime.begin(), crime.end(), c1.begin(), [=](Crime elem) { return elem.m_province == str; });
      c1.resize(distance(c1.begin(), it));
      return c1;
   }
}