/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Oct. 09, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "SpellChecker.h"
#include "Book.h"
using namespace std;

namespace sdds
{
   SpellChecker::SpellChecker(const char* filename)
   {
      ifstream file(filename);
      if (file)
      {
         string str;
         for (auto i = 0; i < ARR_SIZE; ++i)
         {
            getline(file, str, ' ');
            m_badWords[i] = str;
            getline(file, str);
            m_goodWords[i] = str;
            trim(m_goodWords[i]);
         }
      }
      else
         throw("Bad file name!");
   }
   void SpellChecker::operator()(std::string& text)
   {
      for (size_t i = 0; i < ARR_SIZE; ++i)
      {
         int findAt = 0;
         while (findAt > -1)
         {
            findAt = text.find(m_badWords[i]);
            if (findAt != -1)
            {
               text.replace(findAt, m_badWords[i].length(), m_goodWords[i]);
               m_numMistakes[i]++;
            }
         }

      }
   }
   void SpellChecker::showStatistics(std::ostream& out) const
   {
      cout << "Spellchecker Statistics" << endl;
      for (auto i = 0; i < ARR_SIZE; ++i)
         cout << setw(15) << m_badWords[i] << ": " << m_numMistakes[i] << " replacements" << endl;
   }
}