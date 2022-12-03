// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 20, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
   CustomerOrder::CustomerOrder(const std::string& str)
   {
      Utilities u;
      size_t curr = 0;
      size_t pos = 0;
      bool more = true;
      m_name = u.extractToken(str, pos, more);
      m_product = u.extractToken(str, pos, more);
      curr = pos;
      // count the number of items
      while (more)
      {
         m_cntItemP++;
         u.extractToken(str, pos, more);
      }
      // once number of items has been counted...
      more = true;
      pos = curr;
      m_lstItemP = new Item * [m_cntItemP];
      for (size_t i = 0; i < m_cntItemP; ++i)
         m_lstItemP[i] = new Item(u.extractToken(str, pos, more));
      // the list of items making up the order (at least one item)
      if (m_widthField < u.getFieldWidth())
         m_widthField = u.getFieldWidth();
   }
   CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept
   {
      *this = std::move(co);
   }
   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept
   {
      if (this != &co)
      {
         for (size_t i = 0; i < m_cntItemP; i++)
            delete m_lstItemP[i];
         delete[] m_lstItemP;
         m_name = co.m_name;
         m_product = co.m_product;
         m_cntItemP = co.m_cntItemP;
         m_widthField = co.m_widthField;
         m_lstItemP = co.m_lstItemP;
         co.m_lstItemP = nullptr;
         co.m_cntItemP = 0;
      }
      return *this;
   }
   CustomerOrder::~CustomerOrder()
   {
      for (size_t i = 0; i < m_cntItemP; ++i)
         delete m_lstItemP[i];
      delete[] m_lstItemP;
      m_lstItemP = nullptr;
   }
   bool CustomerOrder::isOrderFilled() const
   {
      bool filled = true;
      for (size_t i = 0; i < m_cntItemP && filled; ++i)
      {
         if (!isItemFilled(m_lstItemP[i]->m_itemName))
            filled = false;
      }
      return filled;
   }
   bool CustomerOrder::isItemFilled(const std::string& itemName) const
   {
      bool filled = true;
      for (size_t i = 0; i < m_cntItemP && filled; ++i)
      {
         if (m_lstItemP[i]->m_itemName == itemName && !m_lstItemP[i]->m_isFilled)
            filled = false;
      }
      return filled;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os)
   {
      size_t i = 0u;
      bool filled = false;
      // this modifier fills one item in the current order that the Station specified in the first parameter handles.
      //    if the order doesn't contain the item handled, 
      //    this function does nothing
      for (i = 0u; i < m_cntItemP && !filled; ++i)
      {
         if (station.getItemName() == m_lstItemP[i]->m_itemName)
         {
            if (!station.getQuantity())
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
            else if(!m_lstItemP[i]->m_isFilled)
            {
               m_lstItemP[i]->m_serialNumber = station.getNextSerialNumber();
               m_lstItemP[i]->m_isFilled = true;
               filled = true;
               station.updateQuantity();
            }
         }
      }
      if (filled)
         os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
   }
   void CustomerOrder::display(std::ostream& os) const
   {
      os << m_name << " - " << m_product << endl;
      for (size_t i = 0; i < m_cntItemP; ++i)
      {
         os << "[" << setw(6) << setfill('0') << m_lstItemP[i]->m_serialNumber << setfill(' ') << "] " << setw(m_widthField) << left << m_lstItemP[i]->m_itemName << right << " - ";
         m_lstItemP[i]->m_isFilled ? os << "FILLED" : os << "TO BE FILLED";
         os << endl;
      }
   }
   size_t CustomerOrder::m_widthField = 0;
}