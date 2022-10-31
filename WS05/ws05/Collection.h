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
#include <string>
#include <exception>
#include "Book.h"
#include "Movie.h"
#include "SpellChecker.h"

namespace sdds
{
   template <typename T>
   class Collection
   {
      std::string m_name;
      T* m_items;
      size_t m_size;
      void (*callBack)(const Collection<T>&, const T&) { nullptr };
   public:
      Collection(const std::string& name)
      {
         m_name = name;
         m_items = nullptr;
         m_size = 0u;
      };
      ~Collection() { delete[] m_items; }
      const std::string& name() const { return m_name; };
      size_t size() const { return m_size; };
      void setObserver(void (*observer)(const Collection<T>&, const T&))
      {
         //stores the address of the callback function(observer) into an attribute.
         // This parameter is a pointer to a function that returns void and accepts two parameters : 
         // a collection and an item that has just been added to the collection.
         //This function is called when an item is added to the collection.
         callBack = observer;
      }
      Collection<T>& operator+=(const T& item)
      {
         bool duplicate = false;
         if (m_items)
         {
            for (size_t i = 0u; i < m_size && !duplicate; ++i)
            {
               if (m_items[i].title() == item.title())
                  duplicate = true;
            }
            if (!duplicate)
            {
               T* temp = new T[m_size + 1];
               for (size_t i = 0u; i < m_size; ++i)
                  temp[i] = m_items[i];
               temp[m_size] = item;
               delete[] m_items;
               m_items = temp;
               m_size++;
               //if an observer has been registered, this operator calls the observer function passing the current object (*this) and the new item as arguments.
               if (callBack != nullptr)
                  callBack(*this, item);
            }
         }
         else
         {
            m_items = new T[m_size + 1];
            m_items[m_size] = item;
            m_size++;
            if (callBack != nullptr)
               callBack(*this, item);
         }

         return *this;
      };
      T& operator[](size_t idx) const
      {
         //if the index is out of range, this operator throws an exception of type std::out_of_range with the message Bad index [IDX]. 
         //Collection has [SIZE] items.. Use operator + to concatenate strings.
         if (idx < 0 || idx >= m_size)
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
         return m_items[idx];
      };
      T* operator[](const std::string& title) const
      {
         //returns the address of the item with the title title 
         // If no such item exists, this function returns nullptr
         for (size_t i = 0; i < m_size; ++i)
         {
            if (m_items[i].title() == title)
               return &m_items[i];
         }
         return nullptr;
      };
   };

   template<typename T>
   std::ostream& operator<<(std::ostream& ostr, const Collection<T>& C) {
      for (size_t i = 0; i < C.size(); ++i)
         ostr << C[i];
      return ostr;
   };
}