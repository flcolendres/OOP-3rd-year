// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 7, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#include <iostream>

namespace sdds
{
   class Utilities
   {
      size_t m_widthField{};
      static char m_delimiter;
   public:
      void setFieldWidth(size_t newWidth) { m_widthField = newWidth; }; //sets the field width of the current object to the value of parameter newWidth
      size_t getFieldWidth() const { return m_widthField; }; //returns the field width of the current object
      std::string extractToken(const std::string& str, size_t& next_pos, bool& more); //extracts a token from string str referred to by the first parameter.
      static void setDelimiter(char newDelimiter); //sets the delimiter for this class to the character received
      static char getDelimiter(); // returns the delimiter for this class.
   };
}