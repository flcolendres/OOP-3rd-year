// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 20, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <vector>
#include "Workstation.h"
#include "CustomerOrder.h"

namespace sdds
{
   class LineManager
   {
      std::vector<Workstation*> m_activeLine{};  //the collection of workstations for the current assembly line.
      size_t m_cntCustomerOrder{}; //the total number of CustomerOrder objects
      Workstation* m_firstStation{}; //points to the first active station on the current line
   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };

}