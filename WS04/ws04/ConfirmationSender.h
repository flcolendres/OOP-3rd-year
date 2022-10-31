/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 04, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include "Reservation.h"
#include "Restaurant.h"
// The confirmationSender will store the addresses of the reservation that the client provides
// No copies are made
// The purpose of this module is to receive all the reservations 
// from multiple restaurants, and contact the recipients with a confirmation message.
namespace sdds
{
   class ConfirmationSender
   {
      const Reservation** m_res{};
      size_t m_numRes{};
   public:
      ConfirmationSender() {};
      // Rule of 5
      ConfirmationSender(const ConfirmationSender& CS); //copy constructor
      ConfirmationSender& operator=(const ConfirmationSender& CS); //copy assignment
      ConfirmationSender(ConfirmationSender&& CS) noexcept; //move constructor
      ConfirmationSender& operator=(ConfirmationSender&& CS) noexcept; //move assignment
      ~ConfirmationSender();

      ConfirmationSender& operator+=(const Reservation& res);
      ConfirmationSender& operator-=(const Reservation& res);
      friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& CS);
      operator bool() const { return m_numRes > 0; };
      void resize( const int size = 1);
   };

}