/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 28, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include<iostream>
#include <string>
namespace sdds
{
   class Dictionary
   {
      std::string m_term{};
      std::string m_definition{};
   public:
      const std::string& getTerm() const { return m_term; }
      const std::string& getDefinition() const { return m_definition; }
      Dictionary() {};
      Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
      void setTerm(const std::string& str) { m_term = str; }
      void setDefinition(const std::string& str) { m_definition = str; }
      std::ostream& display(std::ostream& ostr) const;
      operator bool();
      Dictionary& operator=(const Dictionary& D);
      bool operator==(const Dictionary& D);
   };
   std::ostream& operator<< (std::ostream& ostr, const Dictionary& D);
}