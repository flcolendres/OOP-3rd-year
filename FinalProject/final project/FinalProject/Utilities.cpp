// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 7, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds
{
   char Utilities::m_delimiter = '\0';
   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
   {
      string s{}, s2{};
      //extract a token from str starting at next_pos
      try 
      {
         s = str.substr(next_pos);
         s = s.substr(0, s.find(getDelimiter()));
         more = true; // set more to true if token extraction is successful.
      }
      catch (...) 
      {
         more = false;
      }
      if (more)
      {
         if (str[next_pos] == getDelimiter()) //reports an exception if a delimiter is found at next_pos.
         {
            more = false;
            throw("No token.");
         }
         if (m_widthField < s.length()) //update the current object's m_widthField data member if its current value is less than the size of the token extracted.
            m_widthField = s.length();
         //update next_pos with the position of the next token
         next_pos += s.length() + 1;
         //trim
         size_t beginning = s.find_first_not_of(" ");
         size_t last = s.find_last_not_of(" ");
         s = s.substr(beginning, last - beginning + 1);

      }
      try
      {
         s2 = str.substr(next_pos); // check if there's any tokens left to extract. Will generate exception if there is none.
      }
      catch (...)
      {
         more = false;
      }
      return s;
   }
   void Utilities::setDelimiter(char newDelimiter)
   {
      m_delimiter = newDelimiter;
   }
   char Utilities::getDelimiter()
   {
      return m_delimiter;
   }
}