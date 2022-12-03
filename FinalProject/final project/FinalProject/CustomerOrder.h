// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 20, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#include <iostream>
#include "Utilities.h"
#include "Station.h"
namespace sdds
{
   class CustomerOrder
   {
      struct Item
      {
         std::string m_itemName;
         size_t m_serialNumber{ 0 };
         bool m_isFilled{ false };

         Item(const std::string& src) : m_itemName(src) {};
      };
      std::string m_name{};
      std::string m_product{};
      size_t m_cntItemP{};
      Item** m_lstItemP{};
      static size_t m_widthField;
   public:
      CustomerOrder() {};
      CustomerOrder(const std::string& str);
      CustomerOrder(const CustomerOrder& co) { throw("Copy Constructor Error!"); };
      CustomerOrder& operator=(const CustomerOrder& co) = delete;
      CustomerOrder(CustomerOrder&& co) noexcept; // move constructor
      CustomerOrder& operator=(CustomerOrder&& co) noexcept; // move assignment
      ~CustomerOrder();
      bool isOrderFilled() const;
      bool isItemFilled(const std::string& itemName) const;
      void fillItem(Station& station, std::ostream& os);
      void display(std::ostream& os) const;
   };

}