/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 04, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <iomanip>
#include "Reservation.h"
//using namespace sdds;
using namespace std;

namespace sdds {
   Reservation& Reservation::operator=(const Reservation& R)
   {
      if (this != &R)
      {
         m_reservationID = R.m_reservationID;
         m_reservationName = R.m_reservationName;
         m_email = R.m_email;
         m_day = R.m_day;
         m_hour = R.m_hour;
      }
      return *this;
   }
   void Reservation::update(int day, int time)
   {
      m_day = day;
      m_hour = time;
   }

   Reservation::Reservation(const std::string& res)
   {
      //ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
      string str = res;
      m_reservationID = str.substr(0, str.find(':'));
      trim(m_reservationID);
      str.erase(0, str.find(':') + 1);
      m_reservationName = str.substr(0, str.find(','));
      trim(m_reservationName);
      str.erase(0, str.find(",") + 1);
      m_email = str.substr(0, str.find(','));
      trim(m_email);
      str.erase(0, str.find(",") + 1);
      m_numPeople = stoi(str.substr(0, str.find(',')));
      str.erase(0, str.find(",") + 1);
      m_day = stoi(str.substr(0, str.find(',')));
      str.erase(0, str.find(",") + 1);
      m_hour = stoi(str.substr(0, str.find(',')).c_str());
   }
   std::ostream& operator<<(std::ostream& ostr, const Reservation& R)
   {
      //overload the insertion operator to insert the contents of a reservation object into an ostream object:

      //if the hour is between 6AM and 9AM (inclusive), the kitchen serves breakfast:
      //    Reservation ID : NAME  <email>    Breakfast on day DAY @ HOUR : 00 for #PARTY_SIZE people.
      if (R.m_hour >= 6 && R.m_hour <= 9)
      {
         ostr << "Reservation " << right << setw(10) << R.m_reservationID << ": " << right << setw(22) << R.m_reservationName + "  " << left << setw(24)
            << "<" + R.m_email + ">";
         ostr << "Breakfast" << " on day " << R.m_day << " @ " << R.m_hour << ":00 for " << R.m_numPeople << (R.m_numPeople > 1 ? " people." : " person.") << endl;
      }

      //if the hour is between 11AM and 3PM(inclusive), the kitchen serves lunch :
      //    Reservation ID : NAME  <email>    Lunch on day DAY @ HOUR : 00 for #PARTY_SIZE people.
      else if (R.m_hour >= 11 && R.m_hour <= 15)
      {
         ostr << "Reservation " << right << setw(10) << R.m_reservationID << ": " << right << setw(22) << R.m_reservationName + "  " << left << setw(24)
            << "<" + R.m_email + ">";
         ostr << "Lunch" << " on day " << R.m_day << " @ " << R.m_hour << ":00 for " << R.m_numPeople << (R.m_numPeople > 1 ? " people." : " person.") << endl;
      }

      //if the hour is between 5PM and 9PM(inclusive), the kitchen serves dinner :
      //    Reservation ID : NAME  <email>    Dinner on day DAY @ HOUR : 00 for #PARTY_SIZE people.
      else if (R.m_hour >= 17 && R.m_hour <= 21)
      {
         ostr << "Reservation " << right << setw(10) << R.m_reservationID << ": " << right << setw(22) << R.m_reservationName + "  " << left << setw(24)
            << "<" + R.m_email + ">";
         ostr << "Dinner" << " on day " << R.m_day << " @ " << R.m_hour << ":00 for " << R.m_numPeople << (R.m_numPeople > 1 ? " people." : " person.") << endl;
      }

      //at any other time the kitchen is closed and only drinks can be served :
      //    Reservation ID : NAME  <email>    Drinks on day DAY @ HOUR : 00 for #PARTY_SIZE people.
      else
      {
         ostr << "Reservation " << right << setw(10) << R.m_reservationID << ": " << right << setw(22) << R.m_reservationName + "  " << left << setw(24)
            << "<" + R.m_email + ">";
         ostr << "Drinks" << " on day " << R.m_day << " @ " << R.m_hour << ":00 for " << R.m_numPeople << (R.m_numPeople > 1 ? " people." : " person.") << endl;
      }
      return ostr;
   }
   void Reservation::trim(std::string& str)
   {
      size_t beginning = str.find_first_not_of(" ");
      size_t last = str.find_last_not_of(" ");
      str = str.substr(beginning, last - beginning + 1);
   }
   Reservation::operator bool() const
   {
      return m_numPeople > 0;
   }
}