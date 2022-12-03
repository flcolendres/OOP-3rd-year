#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
   template<typename T>
   class GeneratingList {

      std::vector<T> list;
   public:

      GeneratingList() {}
      GeneratingList(const char* f) {
         std::ifstream file(f);
         if (!file)
            throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

         while (file) {
            T t;
            if (t.load(file))
               list.push_back(T(t));
         }
      }

      size_t size() const { return list.size(); }
      const T& operator[](size_t i) const { return list[i]; }

      //TODO: Implement the Luhn Algorithm to check the 
      //      valadity of SIN No's
      // Source: https://rosettacode.org/wiki/Luhn_test_of_credit_card_numbers#C++
      bool validSin(const std::string s)
      {
         int sum = 0;
         bool is_odd_dgt = true;
         std::vector <int> v;
         for (auto& elem : s)
            v.push_back(elem - '0');
         for (size_t i = 0; i < v.size(); ++i)
         {
            if (is_odd_dgt)
               sum += v[i];
            else
               sum += (v[i] != 9) ? (2 * v[i]) % 9 : 9;
            is_odd_dgt = !is_odd_dgt;
         }
         return (sum % 10) == 0;
      }

      //TODO: Overload the += operator with a raw pointer
      // as a second operand.

      void operator+=(T* t)
      {
         list.push_back(*t);
      }

      //TODO: Overload the += operator with a smart pointer
      // as a second operand.
      void operator+=(std::unique_ptr<T>& t)
      {
         list.push_back(*t);
      }

      void print(std::ostream& os) const {
         os << std::fixed << std::setprecision(2);
         for (auto& e : list)
            e.print(os);
      }
   };

   template<typename T>
   std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
      rd.print(os);
      return os;
   }
}
#endif // !SDDS_GENERATINGLIST_H
