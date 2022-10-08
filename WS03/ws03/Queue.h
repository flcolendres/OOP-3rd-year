/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 28, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include "Dictionary.h"

namespace sdds
{

   template<typename T, unsigned int CAPACITY>
   class Queue
   {
      static T dummy;
      T collection[CAPACITY]{};
   public:
      virtual ~Queue() {};
      virtual bool push(const T& item);
      T pop();
      int size();
      void display(std::ostream& ostr = std::cout);
      T& operator[](int i);
   };

   template<typename T, unsigned int CAPACITY>
   bool Queue<T, CAPACITY>::push(const T& item)
   {
      bool valid = false;
      for (unsigned int i = 0u; i < CAPACITY && !valid; i++)
      {
         if (!collection[i])
         {
            collection[i] = item;
            valid = true;
         }
      }
      return valid;
   }
   template<typename T, unsigned int CAPACITY> 
   T Queue<T, CAPACITY>::pop()
   {
      T copy = collection[0];
      for (unsigned int i = 0u; i < CAPACITY - 1; i++) 
      { 
         collection[i] = collection[i + 1]; 
      }
      return copy;
   }
   template<typename T, unsigned int CAPACITY>
   int Queue<T, CAPACITY>::size()
   {
      unsigned int i;
      bool valid = true;
      for (i = 0; i < CAPACITY && valid; i++)
      {
         collection[i] ? valid = true : valid = false;
      }  
      return i - 1;
   }
   template<typename T, unsigned int CAPACITY>
   void Queue<T, CAPACITY>::display(std::ostream& ostr)
   {
      bool valid = true;
      ostr << "----------------------" << std::endl
         << "| Dictionary Content |" << std::endl
         << "----------------------" << std::endl;
      for (unsigned int i = 0; i < CAPACITY && valid; i++)
      {
         if (collection[i])
            ostr << collection[i] << std::endl;
         else
            valid = false;
      }
      ostr << "----------------------" << std::endl;
   }
   template<typename T, unsigned int CAPACITY>
   T& Queue<T, CAPACITY>::operator[](int i)
   {
      return collection[i] ? collection[i] : dummy;

   }
   template<typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::dummy = T{};
   // Specialize the class-member object when type T = Dictionary and CAPACITY = 100u so the term is "Empty Term" and the definition is "Empty Substitute"
   template<>
   Dictionary Queue<Dictionary, 100u>::dummy = Dictionary("Empty Term", "Empty Substitute"); 
}

//template<typename T, int N>
//int Calculator<T, N>::uses = 0;
//
//
//template<>
//int Calculator<short, 200>::uses = 10;