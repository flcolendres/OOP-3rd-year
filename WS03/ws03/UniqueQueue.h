/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Sept. 28, 2022
* I have done all the coding by myself and only copied the code that
* my professor provided to complete my workshops and assignments.
*/
#pragma once
#include "Queue.h"
namespace sdds
{
   template<typename T>
   class UniqueQueue : public Queue <T, 100>
   {
   public:
      UniqueQueue() {};
      ~UniqueQueue() {};
      bool push(const T& item);
   };
   template<typename T>
   bool UniqueQueue<T>::push(const T& item) // prevent adding an item if it already exists in the UniqueQueue.
   {
      bool valid = false, duplicate = false;
      int currentSize = Queue<T, 100>::size();
      for (int i = 0; i < currentSize && !duplicate; i++) // check if there are duplicates
      {
         if (Queue<T, 100>::operator[](i) == item) // if a duplicate is found, set duplicate to true
            duplicate = true;
      }
      if (!duplicate) //pushes the item if there's no duplicates
      {
         Queue<T, 100>::push(item);
         valid = true; // item has been added to the queue
      }
      return valid;
   }
   template<>
   bool UniqueQueue<double>::push(const double& item)
   {
      bool valid = false, duplicate = false;
      int currentSize = Queue::size();
      for (int i = 0; i < currentSize && !duplicate; i++) // check if there are duplicates
      {
         if (fabs(Queue::operator[](i)) == item ||
            fabs(Queue::operator[](i)) >= item - 0.005 &&
            fabs(Queue::operator[](i)) <= item + 0.005) // if a duplicate is found, set duplicate to true
            duplicate = true;
      }
      if (!duplicate) //pushes the item if there's no duplicates
      {
         Queue::push(item);
         valid = true; // item has been added to the queue
      }
      return valid;
   }
}
