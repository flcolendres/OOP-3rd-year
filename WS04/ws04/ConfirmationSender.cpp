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
         m_res = new const Reservation * [m_numRes];
         for (auto i = 0; i < m_numRes; ++i)
         {
            m_res[i] = new Reservation();
            m_res[i] = CS.m_res[i];
         }
      }
      return *this;
   }
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& CS) noexcept
   {
      *this = move(CS);
   }
   ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& CS) noexcept
   {
      // 1. check for self-assignment
      if (this != &CS)
      {
         // 2. clean-up the resource used by the current instance
         //for (auto i = 0u; i < CS.m_numRes; ++i)
         //   delete m_res[i];
         delete[] m_res;
         // 3. shallow copy
         m_numRes = CS.m_numRes;
         // 4. move the resource from parameter into current instance
            // copy address to current object
         m_res = CS.m_res;
         //*m_res = *R.m_res;
         // the parameter doesn't have the resource anymore
         CS.m_res = nullptr;
         CS.m_numRes = 0;
      }

      return *this;
   }
   ConfirmationSender::~ConfirmationSender()
   {
      //for (auto i = 0u; i < m_numRes; ++i)
      //   delete m_res[i];
      delete[] m_res;
      m_numRes = 0;
   }
   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
   {
      bool valid = true;
      auto i = 0;
      //stores the address of res in the array(your function should not make copies of the reservation itself)
      // if the array is full, resize
      for (i = 0; i < m_numRes && valid; ++i) //if the address of res is already in the array, this operator does nothing
      {
         if (&res == m_res[i])
            valid = false;
      }
      if (valid)
      {
         if (!m_numRes) //if there is no reservation
         {
            m_res = new const Reservation * [m_numRes + 1];
            m_res[0] = new Reservation();
            m_res[0] = &res;
            m_numRes++;
         }
         else
         {
            if (*m_res[m_numRes - 1]) // if array is full, resize.
               resize();
            for (i = 0; i < m_numRes && valid; ++i) // search for empty element
            {
               if (!*m_res[i])
               {
                  m_res[i] = &res;
                  valid = false;
               }
            }
         }
      }
      return *this;
   }
   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
   {
      bool valid = true;
      //searches the array for the address of res,
      for (auto i = 0; i < m_numRes && valid; ++i)
      {
         if (&res == m_res[i])
         {
            m_res[i] = nullptr;  //sets the pointer in the array to nullptr
            valid = false;
         } 
      }
      return *this;
   }
   void ConfirmationSender::resize(const int size)
   {
      const Reservation** temp = new const Reservation * [m_numRes + size];
      for (auto i = 0; i < m_numRes + size; i++) // dynamically allocate each elements
         temp[i] = new Reservation();
      for (auto i = 0; i < m_numRes; i++) // copy elements to the temp pointer array.
         temp[i] = *&m_res[i];
      //for (auto i = 0; i < m_numRes; i++)
      //   delete m_res[i];
      //delete[] m_res;
      m_res = *&temp;
      m_numRes += size;
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
            if(CS.m_res[i])
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