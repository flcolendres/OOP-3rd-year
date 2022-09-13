#include <iostream>
#include "carads.h"
using namespace sdds;
using namespace std;
void listArgs(int argc, char* argv[])
{

   cout << "Command Line :" << endl;
   cout << "--------------------------" << endl;
   for (int i{0}; i < argc; i++)
      cout << "   " << i + 1 << " : < " << argv[i] << ">" << endl;

}
Cars::Cars()
{

}

istream& Cars::read(std::istream& is)
{
   if (!is.fail())
   {
      //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
      is >> car_status;
      is.ignore(1000, ',');
      is.clear();
      is >> car_brand;
      is.ignore(1000, ',');
      is.clear();
      is >> car_model;
      is.ignore(1000, ',');
      is.clear();
      is >> car_year;
      is.ignore(1000, ',');
      is.clear();
      is >> car_price;
      is.ignore(1000, ',');
      is.clear();
      is >> car_promo;
      is.ignore(1000, ',');
      is.clear();
   }
   return is;
}

std::ostream& sdds::Cars::display(bool reset)
{
   static int counter{};
   cout.setf(ios::left);
   cout.width(2);
   cout << counter++;
   cout.width(10);
   cout << car_brand;
   cout.width(15);
   cout << car_model;
   cout.unsetf(ios::left);
   cout.width(4);
   cout << car_year;
   cout.setf(ios::left);
   cout.width(12);
   cout.precision(2);
   cout << car_price + (car_price * g_taxrate);

   return cout;
}
//COUNTER.Brand | Model | Year | Price w / Tax | Special Price

