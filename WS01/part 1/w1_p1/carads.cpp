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
