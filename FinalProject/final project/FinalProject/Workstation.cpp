// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 20, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <algorithm>
#include <string>
#include "Workstation.h"


std::deque<sdds::CustomerOrder> g_pending{};
std::deque<sdds::CustomerOrder> g_completed{};
std::deque<sdds::CustomerOrder> g_incomplete{};
using namespace std;
namespace sdds
{
   void Workstation::fill(std::ostream& os)
   {
      if (!m_orders.empty())
         m_orders.front().fillItem(*this, os);
   }
   bool Workstation::attemptToMoveOrder()
   {
      bool hasBeenMoved = false;
      if (!m_orders.empty())
      {
         if (m_orders.front().isItemFilled(getItemName()) || !getQuantity()) //if the order requires no more service at this station or cannot be filled (not enough inventory), move to the next station
         {
            if (m_pNextStation) 
               *m_pNextStation += std::move(m_orders.front());
            else if (m_orders.front().isOrderFilled()) //has been filled
               g_completed.push_back(std::move(m_orders.front()));
            else
               g_incomplete.push_back(std::move(m_orders.front()));
            hasBeenMoved = true;
            m_orders.pop_front();
         }
      }
      return hasBeenMoved;
   }
   void Workstation::setNextStation(Workstation* station)
   {
      m_pNextStation = station;
   }
   void Workstation::display(std::ostream& os) const
   {
      //format: ITEM_NAME --> NEXT_ITEM_NAME
      os << Station::getItemName() << " --> ";
      os << (getNextStation() ? getNextStation()->getItemName() : "End of Line") << endl;
   }
   Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
   {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }
}

