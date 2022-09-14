#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "carads.h"
using namespace sdds;
using namespace std;
void sdds::listArgs(int argc, char* argv[])
{
   cout << "Command Line:" << endl;
   cout << "--------------------------" << endl;
   for (int i{ 0 }; i < argc; i++)
      cout << "  " << i + 1 << ": " << argv[i] << endl;
   cout << "--------------------------" << endl << endl;
}

std::istream& sdds::operator>>(std::istream& is, Cars& car)
{
   //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
   return car.read(is);
}

void sdds::operator>>(const Cars& car1, Cars& car2)
{
   car2.operator=(car1);
}


Cars::operator bool() const
{
   return car_status == 'N';
}

Cars::Cars()
{
   operator=(*this);
}
Cars& Cars::operator=(const Cars& c)
{
   if (this != &c)
   {
      delete[] car_brand;
      delete[] car_model;
      car_brand = new char[strlen(c.car_brand) + 1];
      car_model = new char[strlen(c.car_model) + 1];
      strcpy(car_brand, c.car_brand);
      strcpy(car_model, c.car_model);
      car_year = c.car_year;
      car_status = c.car_status;
      car_promo = c.car_promo;
   }
   return *this;
}
Cars::~Cars()
{
   delete[] car_brand;
   delete[] car_model;
}
istream& Cars::read(std::istream& is)
{
   if (!is.bad())
   {
      //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
      is.get(car_status);
      is.ignore(1000, ',');
      is.clear();
      is.getline(car_brand, 11, ',');
      is.getline(car_model, 16, ',');
      is >> car_year;
      is.ignore(1000, ',');
      is >> car_price;
      is.ignore(1000, ',');
      is.get() == 'Y' ? car_promo = true : car_promo = false;
      is.ignore(1000, '\n');
   }
   return is;
}

ostream& Cars::display(bool reset)
{
   static int counter{};
   if (reset)
      counter = 0;
   if (car_brand[0] != '\0')
   {
      cout.setf(ios::left);
      cout.width(2);
      cout << ++counter << ". ";
      cout.width(10);
      cout << car_brand << "| ";
      cout.width(15);
      cout << car_model << "| ";
      cout << car_year << " |";
      cout.setf(ios::fixed);
      cout.precision(2);
      cout.setf(ios::right);
      cout.width(12);
      cout << car_price + (car_price * g_taxrate) << "|";
      if (car_promo)
      {
         cout.width(12);
         cout << (car_price + (car_price * g_taxrate)) - ((car_price + (car_price * g_taxrate)) * g_discount);
      }
      cout.unsetf(ios::right);
      cout << "\n";
   }
   return cout;
}
char Cars::getStatus()
{
   return car_status;
}
//COUNTER.Brand | Model | Year | Price w / Tax | Special Price

