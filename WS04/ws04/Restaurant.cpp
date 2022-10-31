/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 04, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds
{
   Restaurant::~Restaurant()
   {
      for (auto i = 0u; i < m_numRes; ++i)
         delete m_res[i];
      delete[] m_res;
      m_numRes = 0;
   }
   Restaurant::Restaurant(const Restaurant& R)
   {
      operator=(R);
   }
   Restaurant& Restaurant::operator=(const Restaurant& R)
   {
      if (this != &R)
      {
         for (auto i = 0u; i < m_numRes; ++i)
            delete m_res[i];
         delete[] m_res;
         m_numRes = R.m_numRes;
         m_res = new Reservation * [m_numRes];
         for (auto i = 0u; i < m_numRes; ++i)
         {
            m_res[i] = new Reservation();
            *m_res[i] = *R.m_res[i];
         }
      }
      return *this;
   }
   Restaurant::Restaurant(Restaurant&& R) noexcept
   {
      *this = move(R);
   }
   Restaurant& Restaurant::operator=(Restaurant&& R) noexcept
   {
      // 1. check for self-assignment
      if (this != &R)
      {
         // 2. clean-up the resource used by the current instance
         for (auto i = 0u; i < m_numRes; ++i)
            delete m_res[i];
         delete[] m_res;
         // 3. shallow copy
         m_numRes = R.m_numRes;
         // 4. move the resource from parameter into current instance
            // copy address to current object
         m_res = R.m_res;
         //*m_res = *R.m_res;
         // the parameter doesn't have the resource anymore
         R.m_res = nullptr;
         R.m_numRes = 0;
      }

      return *this;
   }
   Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
   {
      m_res = new Reservation * [cnt];
      for (auto i = 0u; i < cnt; ++i)
      {
         m_res[i] = new Reservation();
         *m_res[i] = *reservations[i];
      }
      m_numRes = cnt;
   }
   Restaurant::operator bool() const
   {
      return m_numRes > 0;
   }
   std::ostream& operator<<(std::ostream& ostr, const Restaurant& R)
   {
      static int CALL_INT = 0;
      //overload the insertion operator to 
      //insert the content of a Restaurant object into an ostream object.
      //This operator should use a local to function variable to count how many times 
      //this operator has been called(CALL_CNT below).
      if (R)
      {
         ostr << "--------------------------" << endl
            << "Fancy Restaurant (" << ++CALL_INT << ")" << endl
            << "--------------------------" << endl;
         for (auto i = 0u; i < R.m_numRes; ++i)
         {
            ostr << *R.m_res[i];
         }
         ostr << "--------------------------" << endl;
      }
      else
      {
         ostr << "--------------------------" << endl
            << "Fancy Restaurant (" << ++CALL_INT << ")" << endl
            << "--------------------------" << endl
            << "This restaurant is empty!" << endl
            << "--------------------------" << endl;
      }
      return ostr;
   }
}