// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 20, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Utilities.h"

extern std::deque<sdds::CustomerOrder> g_pending; //holds the orders to be placed onto the assembly line at the first station.
extern std::deque<sdds::CustomerOrder> g_completed; //holds the orders that have been removed from the last station and have been completely filled.
extern std::deque<sdds::CustomerOrder> g_incomplete; //holds the orders that have been removed from the last station and could not be filled completely.
namespace sdds
{
   
   //Since a Workstation object represents a single location on the assembly line for filling customer orders with items, 
   //the object cannot be copied or moved.
   //Make sure that this capability is deleted in your definition of the Workstation class.
   class Workstation : public Station
   {
      std::deque<CustomerOrder> m_orders{};
      Workstation* m_pNextStation{}; //a pointer to the next Workstation on the assembly line.
   public:
      Workstation(std::string str) : Station(str){};
      Workstation(const Workstation& W) = delete;
      Workstation& operator=(const Workstation& W) = delete;
      Workstation(Workstation&& W) = delete; //move constructor
      Workstation& operator=(Workstation&& W) = delete; //move assignment
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station = nullptr);
      Workstation* getNextStation() const { return m_pNextStation; };
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder); // moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
   };

}