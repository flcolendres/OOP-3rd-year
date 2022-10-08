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
#include <iostream>

namespace sdds
{
   class Restaurant
   {
      Reservation** m_res{};
      size_t m_numRes{};
   public:
      // a constructor that receives as a parameter an array of pointers to objects of type Reservation (i.e., each element of the array is a pointer). 
      // If you need a refresh on arrays of pointers, 
      // re-read the material from the last term (chapter Abstract Base Classes, section Array of Pointers).
      Restaurant() {};
      // rule 0f 5
      Restaurant(const Restaurant& R); // copy constructor
      Restaurant& operator=(const Restaurant& R); // copy assignment
      Restaurant(Restaurant&& R) noexcept; // move constructor
      Restaurant& operator=(Restaurant&& R) noexcept; // move assignment
      ~Restaurant();
      Restaurant(const Reservation* reservations[], size_t cnt);
      size_t size() { return m_numRes; }
      operator bool() const;
      friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& R);

   };
}