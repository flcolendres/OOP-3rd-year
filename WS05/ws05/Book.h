/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 09, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include <iostream>
namespace sdds
{
   class Book
   {
      std::string m_author{};
      std::string m_title{};
      std::string m_cPub{};
      size_t m_year{};
      double m_price{};
      std::string m_desc{};
   public:
      Book() {};
      const std::string& title() const { return m_title; };
      const std::string& country() const { return m_cPub; };
      const size_t& year() const { return m_year; };
      double& price() { return m_price; };
      Book(const std::string& strBook);
      operator bool()const { return m_price > 0; };
      friend std::ostream& operator<<(std::ostream& ostr, const Book& B);
      template <typename T>
      void fixSpelling(T& spellChecker)
      {
         spellChecker(m_desc);
      }
   };
   void trim(std::string& str);
}
