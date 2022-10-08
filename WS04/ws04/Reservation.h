/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 04, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
namespace sdds
{
   class Reservation
   {
      std::string m_reservationID{};
      std::string m_reservationName{};
      std::string m_email{};
      int m_numPeople{};
      int m_day{};
      int m_hour{};
   public:
      Reservation() {};
      Reservation& operator=(const Reservation& R);
      void update(int day, int time);
      Reservation(const std::string& res);
      void trim(std::string& str);
      friend std::ostream& operator<<(std::ostream& ostr, const Reservation& R);
      operator bool() const;
   };
}