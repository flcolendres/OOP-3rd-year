// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: November 7, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#include <iostream>
namespace sdds
{
   class Station {
      int m_stationID;
      std::string m_name;
      std::string m_desc;
      size_t m_serialNum;
      size_t m_stock;
      static size_t m_widthField;
      static int id_generator;
   public:
      Station(const std::string& s);
      const std::string& getItemName() const { return m_name; }; //returns the name of the current Station object
      size_t getNextSerialNumber() { return m_serialNum++; }; // returns the next serial number to be used on the assembly line and increments m_serialNumber
      size_t getQuantity() const { return m_stock; }; //returns the remaining quantity of items in the Station object
      void updateQuantity() { if (m_stock > 0) m_stock--; }; // subtracts 1 from the available quantity; should not drop below 0.
      void display(std::ostream& os, bool full) const; // inserts information about the current object into stream os.
   };

}