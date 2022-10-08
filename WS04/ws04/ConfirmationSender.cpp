/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 04, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds
{
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& CS)
   {
      operator=(CS);
   }
   ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& CS)
   {
      if (this != &CS)
      {
         for (auto i = 0u; i < m_numRes; ++i)
            delete m_res[i];
         delete[] m_res;
         m_numRes = CS.m_numRes;
         m_res = new Reservation * [m_numRes];
         m_res = CS.m_res; 
         // for(auto i = 0; i < m_numRes; ++i)
         //    m_res[i] = CS.m_res[i]
      }
      return *this;
   }
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& CS) noexcept
   {
      *this = move(CS);
   }
   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& CS) noexcept
   {
      if (this != &CS)
      {
         for (auto i = 0u; i < m_numRes; ++i)
            delete m_res[i];
         delete[] m_res;
         m_numRes = CS.m_numRes;
         m_res = CS.m_res;
         CS.m_res = nullptr;
      }
      return *this;
   }
   ConfirmationSender::~ConfirmationSender()
   {
      for (auto i = 0u; i < m_numRes; ++i)
         delete m_res[i];
      delete[] m_res;
      m_numRes = 0;
   }
   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
   {
      bool valid = true;
      //if the address of res is already in the array, this operator does nothing
      for (auto i = 0; i < m_numRes && valid; ++i)
         if (&res == &*m_res[i])
            valid = false;
      if (valid)
      {
         //resizes the array to make room for res if necessary
         //stores the address of res in the array(your function should not make copies of the reservation itself)
         if (*m_res[m_numRes - 1]) // if the array is full, resize
         {
            Reservation** newArr = new Reservation * [m_numRes + 1];
            for (auto i = 0; i < m_numRes - 1; ++i)
               newArr[i] = m_res[i];
            *newArr[m_numRes] = res;
            m_numRes++;
            delete[] m_res;
            m_res = newArr;
         }
         else // if not, check an empty element.
         {
            for (auto i = 0; i < m_numRes && valid; ++i)
               if (!*m_res[i])
                  *m_res[i] = res;
         }
      }
      return *this;
   }
   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
   {
      bool valid = true;
      //if the address of res is not in the array, this operator does nothing
      for (auto i = 0; i < m_numRes && valid; ++i)
         if (&res != &*m_res[i])
            valid = false;
      if (valid)
      {
         //searches the array for the address of res,
         for (auto i = 0; i < m_numRes; ++i)
            if (&res == &*m_res[i])
               m_res[i] = nullptr;  //sets the pointer in the array to nullptr
         //if res is found.To challenge yourself, try to actually resize the array.
         Reservation** newArr = new Reservation * [m_numRes - 1];
         for (auto i = 0; i < m_numRes - 1; ++i)
            newArr[i] = m_res[i];
         m_numRes--;
         delete[] m_res;
         m_res = newArr;
      }
      return *this;
   }
   std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& CS)
   {
      if (CS)
      {
         ostr << "--------------------------" << endl
            << "Confirmations to Send" << endl
            << "--------------------------" << endl;
         for (auto i = 0; i < CS.m_numRes; ++i)
         {
            ostr << *CS.m_res[i];
         }
      }
      else
      {
         ostr << "--------------------------" << endl
            << "Confirmations to Send" << endl
            << "--------------------------" << endl
            << "There are no confirmations to send!" << endl
            << "--------------------------" << endl;
      }
      return ostr;
   }
}