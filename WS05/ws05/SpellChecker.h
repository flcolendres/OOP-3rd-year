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
   const int ARR_SIZE = 6;
   class SpellChecker
   {
      std::string m_badWords[ARR_SIZE]{};
      std::string m_goodWords[ARR_SIZE]{};
      int m_numMistakes[ARR_SIZE]{};
   public:
      SpellChecker() {};
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;
   };
}