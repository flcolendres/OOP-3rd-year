// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 7, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   Station::Station(const std::string& s)
   {
      Utilities u;
      size_t pos = 0;
      bool more = true;
      m_stationID = ++id_generator;
      m_name = u.extractToken(s, pos, more);
      m_serialNum = stoi(u.extractToken(s, pos, more));
      m_stock = stoi(u.extractToken(s, pos, more));
      if (m_widthField < u.getFieldWidth())
         m_widthField = u.getFieldWidth();
      m_desc = u.extractToken(s, pos, more);
   }
   void Station::display(std::ostream& os, bool full) const
   {
      if (!full)
         os << setw(3) << setfill('0') << m_stationID << " | " << setfill(' ') << setw(Station::m_widthField) << left << m_name << " | "
         << setw(6) << right << setfill('0') << m_serialNum << " | " << endl;
      else
         os << setw(3) << setfill('0') << m_stationID << " | " << setw(Station::m_widthField) << setfill(' ') << left << m_name << " | "
         << setw(6) << right << setfill('0') << m_serialNum << " | " << setw(4) << setfill(' ') << m_stock << " | " << m_desc << right << endl;
   }
   size_t Station::m_widthField = 1;
   int Station::id_generator = 0;

}