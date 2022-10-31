/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 09, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include<iostream>

namespace sdds
{
   class Movie
   {
      std::string m_title{};
      int m_year{};
      std::string m_desc{};
   public: 
      Movie() {};
      const std::string& title() const { return m_title; };
      Movie(const std::string& strMovie);
      friend std::ostream& operator<<(std::ostream& ostr, const Movie& M);
      operator bool()const { return m_year > 0; };
      template<typename T>
      void fixSpelling(T& spellChecker)
      {
         spellChecker(m_title);
         spellChecker(m_desc);
      }
   };
}